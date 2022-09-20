//==============================================================================
//
// Title:		DAM-E3056N
// Purpose:		DAM-E3056N采集卡上位机程序
//
// Created on:	2022/9/6 at 17:25:18 by liudongpeng
// Copyright:	13289204862@163.com
//
//==============================================================================

//==============================================================================
// Include files

#include "function.h"

#include <ansi_c.h>
#include <cvirte.h>
#include <userint.h>
#include "DAM-E3056N.h"
#include "toolbox.h"


//==============================================================================
// Constants
/* 设备断开连接后，尝试重连的最大次数 */
//#define RECONNEC_TTIMES	5	// 暂未使用

/* 数据显示格式 */
static const char* gsc_dataFormat = "%.1f";

/* 创建设备对象需要的参数，慎重修改 */
static const char 		gsc_IP[32] = "192.168.2.80";		// IP地址
static const char 		gsc_MAC[32] = "88-e1-61-00-54-20";	// MAC地址	警告！！！ MAC地址全球唯一，不要随便更改！！！
static const uint16_t	gsc_tcpPort = 502;				// TCP端口号
static const uint16_t	gsc_udpPort = 5001;				// UDP端口号
static const long 		gsc_sendTimeout = 1000;			// 发送数据的超时间隔
static const long 		gsc_recvTimeout = 1000;			// 接收数据的超时间隔

/* 通道量程为0~+5V */
static const int gsc_channelRange = 5;

/* AIN6通道电压上限，已转换为0~5V量程的电压数值 */
static const USHORT gsc_AIN6UpperLimit = (USHORT)(800.0 / 1000.0 * gsc_channelRange);


//==============================================================================
// Static global variables
static int panelHandle = 0;				// 主面板句柄

volatile HANDLE gs_dev; 				// 设备句柄
volatile BOOL gsv_connectState;			// 设备连接状态

/* 数据处理需要用到的数组 */
static uint16_t gs_AIRawDataArr[8];		// 8个AI通道读取到的原始数据
static double gs_targetData[8];			// 解析后的数据

/* 数组下标与通道功能的映射关系 */
typedef enum
{
	AIN_A_ACV_INDEX = 0,	// 交流输入A相电压，0~5V对应0V~300V
	AIN_B_ACV_INDEX,		// 交流输入B相电压，0~5V对应0V~300V
	AIN_C_ACV_INDEX,		// 交流输入C相电压，0~5V对应0V~300V

	AIN_A_ACI_INDEX,		// 交流输入A相电流，0~5V对应0V~800A
	AIN_B_ACI_INDEX,		// 交流输入B相电流，0~5V对应0V~800A
	AIN_C_ACI_INDEX,		// 交流输入C相电流，0~5V对应0V~800A

	OUT_DCV_INDEX,			// 直流输出电压，0~5V对应0~1000V
	OUT_DCI_INDEX			// 直流输出电流，0~5V对应0~1000A
};

/* 测量项目对应的原始数据与目标数据的转换系数，拿到原始数据只需要乘以对应的系数即可 */
typedef enum
{
	AIN_V_PROPORTION = 300 / gsc_channelRange,		// 三相交流输入电压对应的转换系数
	AIN_I_PROPORTION = 800 / gsc_channelRange,		// 三相交流输入电流对应的转换系数

	OUT_V_PROPORTION = 1000 / gsc_channelRange,		// 直流电压对应的转换系数
	OUT_I_PROPORTION = 1000 / gsc_channelRange		// 直流电流对应的转换系数
};



/*************************************** 函数声明 ***************************************/
int CVICALLBACK SamplingThread(void *functionData);		// 采样线程
int CVICALLBACK CheckConnectThread(void *functionData);	// 设备链接状态监测线程

/**
 * @brief 设置8个输入通道的量程为0~5V
 * @param None
 * @retval None
 */
void SetAIChannelRangeVoltN0P5();

/**
 * @brief 使能8个输入通道的采集功能
 */
void SetAllAIChannelEnable();

/**
 * @brief 获取D0口报警状态
 */
int GetD0PortAlarmState();

/**
 * @brief 把原始数据按照对应关系转化为需要显示的数据
 * @param rawDataArr[IN]		8个通道采集到的原始数据
 * @param targetDataArr[OUT]	转换后用来显示的数据
 * @param n[IN]					数据个数
 * @retval 转换成功返回true，失败返回false
 */
BOOL ParseData(uint16_t* rawDataArr, double* targetDataArr, int n);

/**
 * @brief AI通道电压监测，任意一个通道过压或欠压都报警
 * @retval 任意一个通道 过压 或 欠压 返回true，全部通道都不欠压且不过压返回false
 */
BOOL AIChannelMnoitor();

/**
 * @brief 把数据显示在用户界面上
 */
void ShowDataOnString();


/*************************************** 函数实现 ***************************************/
int main (int argc, char *argv[])
{
	int error = 0;
	int startPagePanelHandle = 0;

	/* initialize and load resources */
	nullChk (InitCVIRTE (0, argv, 0));
	errChk (panelHandle = LoadPanel (0, "DAM-E3056N.uir", PANEL));

	/* 加载并显示初始化界面 */
	startPagePanelHandle = LoadPanel(0, "DAM-E3056N.uir", PANEL_INIT);
	DisplayPanel(startPagePanelHandle);


	/* 创建设备 */
	gs_dev = OpenDevice(gsc_IP, gsc_tcpPort, gsc_sendTimeout, gsc_recvTimeout);
	if (!CheckDeviceHandle(gs_dev))
	{
		/* 连接设备失败，可能是网线没接好 */
		MessagePopup("警告！", "无法连接设备，请检查电脑以太网IPv4属性中的IP地址和子网掩码是否有异常");
		/* 创建设备失败 */
		return -1;
	}

	/* 再次检查设备是否在线 */
	long devNum = 0;
	char devName[1024] = {0};
	if (CheckDevice(gsc_IP, devName, gsc_MAC, gsc_udpPort, &devNum, gsc_sendTimeout, gsc_recvTimeout) > 0)
	{
		if (devNum > 0 && strcmp(devName, "DAM-E3056N") == 0)
		{
			/* 设备在线，设备连接状态绿色指示灯亮 */
			SetCtrlAttribute(panelHandle, PANEL_LED_CONNECT_STATE, ATTR_ON_COLOR, VAL_GREEN);
			SetCtrlVal(panelHandle, PANEL_LED_CONNECT_STATE, 1);
			/* 更新设备连接状态标志 */
			gsv_connectState = TRUE;
		}
		else
		{
			/* 设备不在线，可能是网线没接好 */
			MessagePopup("警告！", "设备不在线，可能是网线没接好，请检查线缆连接并重试");
			return -1;
		}
	}

	/* 销毁初始化界面 */
	DiscardPanel(startPagePanelHandle);

	/* 设置AI通道量程为0～+5V */
	SetAIChannelRangeVoltN0P5();
	/* 使能8个AI采集通道 */
	SetAllAIChannelEnable();

	/* 开启电压采集线程 */
	CmtScheduleThreadPoolFunction(DEFAULT_THREAD_POOL_HANDLE, SamplingThread, NULL, NULL);
	/* 开启设备连接状态监测线程 */
	CmtScheduleThreadPoolFunction(DEFAULT_THREAD_POOL_HANDLE, CheckConnectThread, NULL, NULL);


	/* display the panel and run the user interface */
	errChk (DisplayPanel (panelHandle));
	errChk (RunUserInterface ());

Error:
	/* clean up */
	if (panelHandle > 0)
		DiscardPanel (panelHandle);

	/* 释放设备对象 */
	if (CheckDeviceHandle(gs_dev))
		return CloseDevice(gs_dev);

	return 0;
}

/**
 * @brief 右上角退出按钮回调
 */
int CVICALLBACK panelCB (int panel, int event, void *callbackData,
						 int eventData1, int eventData2)
{
	if (event == EVENT_CLOSE)
		QuitUserInterface(0);
	return 0;
}


/**
 * @brief 把原始数据按照对应关系转化为需要显示的数据
 * @param rawDataArr[IN]		8个通道采集到的原始数据
 * @param targetDataArr[OUT]	转换后用来显示的数据
 * @param n[IN]					数据个数
 * @retval 转换成功返回true，失败返回false
 */
BOOL ParseData(uint16_t* rawDataArr, double* targetDataArr, int n)
{
	if (rawDataArr == NULL || targetDataArr == NULL)
		return FALSE;

	/* 实际电压 = AI采集电压 * 转换系数 */

	/* A B C 三相电压 */
	//gs_targetData[AIN_A_ACV_INDEX] = gs_AIRawDataArr[AIN_A_ACV_INDEX] / 65535.0 * gsc_channelRange; // 测试用
	gs_targetData[AIN_A_ACV_INDEX] = (gs_AIRawDataArr[AIN_A_ACV_INDEX] / 65535.0 * gsc_channelRange) * AIN_V_PROPORTION;
	gs_targetData[AIN_B_ACV_INDEX] = (gs_AIRawDataArr[AIN_B_ACV_INDEX] / 65535.0 * gsc_channelRange) * AIN_V_PROPORTION;
	gs_targetData[AIN_C_ACV_INDEX] = (gs_AIRawDataArr[AIN_C_ACV_INDEX] / 65535.0 * gsc_channelRange) * AIN_V_PROPORTION;

	/* A B C 三相电流 */
	gs_targetData[AIN_A_ACI_INDEX] = (gs_AIRawDataArr[AIN_A_ACI_INDEX] / 65535.0 * gsc_channelRange) * AIN_I_PROPORTION;
	gs_targetData[AIN_B_ACI_INDEX] = (gs_AIRawDataArr[AIN_B_ACI_INDEX] / 65535.0 * gsc_channelRange) * AIN_I_PROPORTION;
	gs_targetData[AIN_C_ACI_INDEX] = (gs_AIRawDataArr[AIN_C_ACI_INDEX] / 65535.0 * gsc_channelRange) * AIN_I_PROPORTION;

	/* 6、7通道接电源的直流输出 */
	//gs_targetData[OUT_DCV_INDEX] = gs_AIRawDataArr[OUT_DCV_INDEX] / 65535.0 * gsc_channelRange; // 测试用
	gs_targetData[OUT_DCV_INDEX] = (gs_AIRawDataArr[OUT_DCV_INDEX] / 65535.0 * gsc_channelRange) * OUT_V_PROPORTION;
	gs_targetData[OUT_DCI_INDEX] = (gs_AIRawDataArr[OUT_DCI_INDEX] / 65535.0 * gsc_channelRange) * OUT_I_PROPORTION;

	return TRUE;
}

/**
 * @brief AI通道电压监测，任意一个通道过压或欠压都报警
 * @retval 任意一个通道 过压 或 欠压 返回true，全部通道都不欠压且不过压返回false
 */
BOOL AIChannelMnoitor()
{
	#define NPN_OPEN	1
	#define NPN_CLOSE	0

	#define DOUT0	0
	#define DOUT1	1
	#define DOUT2	2
	#define DOUT3	3
	#define DOUT4	4

	/*
	 * A0~A2：	任意一路 小于180V 或 大于280V
	 * A6：		小于600V 或 大于800V
	 * A7：		大于690A
	 * 以上任意一路满足要求，则D0, D1立刻同时接通，切断电源以免发生危险
	 *
	 * A7：		大于10A，D2接通
	 *
	 * A6：		在600V到800V之间，D3接通
	 *
	 * A6：		小于600V或大于800V，D4接通
	 *
	 * 注意：		DOUT口接外部上拉，B基极给低电压，NPN三极管不导通，DOUT口输出高电压
	 */
	if (	(gs_targetData[AIN_A_ACV_INDEX] >= 180 && gs_targetData[AIN_A_ACV_INDEX] <= 280) &&
			(gs_targetData[AIN_B_ACV_INDEX] >= 180 && gs_targetData[AIN_B_ACV_INDEX] <= 280) &&
			(gs_targetData[AIN_C_ACV_INDEX] >= 180 && gs_targetData[AIN_C_ACV_INDEX] <= 280) &&

			(gs_targetData[OUT_DCV_INDEX] >= 600 && gs_targetData[OUT_DCV_INDEX] <= 800) &&

			(gs_targetData[OUT_DCI_INDEX] <= 690)
	   )
	{
		/* AI通道测量的数据都是符合标准的，状态正常 */

		/* 设备工作状态栏用 绿色大号字体显示“正常” */
		SetCtrlAttribute(panelHandle, PANEL_STRING_WORK_STATE, ATTR_TEXT_COLOR, VAL_GREEN);
		SetCtrlVal(panelHandle, PANEL_STRING_WORK_STATE, "正常");

		/* A7大于10A，D2接通 */
		if (gs_targetData[OUT_DCI_INDEX] >= 10)
		{
			DAME3000N_DOSetValue_Line(gs_dev, NPN_OPEN, DOUT2);
		}

		/* A6在600V到800V之间，D3接通 */
		if (gs_targetData[OUT_DCV_INDEX] >= 600 && gs_targetData[OUT_DCV_INDEX] <= 800)
		{
			DAME3000N_DOSetValue_Line(gs_dev, NPN_OPEN, DOUT3);
		}
	}
	else
	{
		/* AI通道测量的数据有些不符合标准，状态异常 */

		/* 设备工作状态栏用 红色大号字体显示“故障” */
		SetCtrlAttribute(panelHandle, PANEL_STRING_WORK_STATE, ATTR_TEXT_COLOR, VAL_RED);
		SetCtrlVal(panelHandle, PANEL_STRING_WORK_STATE, "故障");

		/* D0、D1立刻同时接通 */
		DAME3000N_DOSetValue_Line(gs_dev, NPN_OPEN, DOUT0);
		DAME3000N_DOSetValue_Line(gs_dev, NPN_OPEN, DOUT1);

		/* A6小于600V或大于800V，D4接通 */
		if (gs_targetData[OUT_DCV_INDEX] < 600 || gs_targetData[OUT_DCV_INDEX] > 800)
		{
			DAME3000N_DOSetValue_Line(gs_dev, NPN_OPEN, DOUT4);
		}
	}

	return FALSE;
}

/**
 * @brief 把数据显示在用户界面上
 */
void ShowDataOnString()
{
	char buf[64] = {0};

	// 交流输入A相电压
	sprintf(buf, gsc_dataFormat, gs_targetData[AIN_A_ACV_INDEX]);
	SetCtrlVal(panelHandle, PANEL_STRING_A_IN_ACV, buf);
	// 交流输入B相电压
	sprintf(buf, gsc_dataFormat, gs_targetData[AIN_B_ACV_INDEX]);
	SetCtrlVal(panelHandle, PANEL_STRING_B_IN_ACV, buf);
	// 交流输入C相电压
	sprintf(buf, gsc_dataFormat, gs_targetData[AIN_C_ACV_INDEX]);
	SetCtrlVal(panelHandle, PANEL_STRING_C_IN_ACV, buf);

	// 交流输入A相电流
	sprintf(buf, gsc_dataFormat, gs_targetData[AIN_A_ACI_INDEX]);
	SetCtrlVal(panelHandle, PANEL_STRING_A_IN_ACI, buf);
	// 交流输入B相电流
	sprintf(buf, gsc_dataFormat, gs_targetData[AIN_B_ACI_INDEX]);
	SetCtrlVal(panelHandle, PANEL_STRING_B_IN_ACI, buf);
	// 交流输入C相电流
	sprintf(buf, gsc_dataFormat, gs_targetData[AIN_C_ACI_INDEX]);
	SetCtrlVal(panelHandle, PANEL_STRING_C_IN_ACI, buf);

	// 直流输出电压
	sprintf(buf, gsc_dataFormat, gs_targetData[OUT_DCV_INDEX]);
	SetCtrlVal(panelHandle, PANEL_STRING_OUT_DCV, buf);
	// 直流输出电流
	sprintf(buf, gsc_dataFormat, gs_targetData[OUT_DCI_INDEX]);
	SetCtrlVal(panelHandle, PANEL_STRING_OUT_DCI, buf);
}

/**
 * @brief 采样并显示数据的工作线程，只要设备不断开连接，就一直采样
 * @param functionData[IN]	需要传入的数据
 * @retval 循环采集数据，一般不会返回
 */
int CVICALLBACK SamplingThread(void *functionData)
{
	while (1)
	{
		while (gsv_connectState)
		{
			/* 读8个通道的数据 */
			DAME3000N_AIReadData(gs_dev, gs_AIRawDataArr, 0, 7);

			/* 解析8个通道采集的数据 */
			ParseData(gs_AIRawDataArr, gs_targetData, 8);

			/* 监测各通道电压上下限 */
			/*
			 * A0~A2：	任意一路 小于180V 或 大于280V
			 * A6：		小于600V 或 大于800V
			 * A7：		大于690A
			 * 以上任意一路满足要求，则D0, D1立刻同时接通，切断电源以免发生危险
			 */
			AIChannelMnoitor();

			/* 在用户界面对应的位置显示解析后的数据 */
			ShowDataOnString();

			/* 一秒采样两次 */
			Sleep(500);
		}

		/* 设备断开后每隔1秒重试，检测设备是否重新连接成功 */
		Sleep(1000);
	}

	//return 0;
}

/**
 * @brief 设备连接状态监测线程，从程序运行开始直到程序结束，设备与电脑断开连接后会尝试重连设备
 * @param functionData[IN]	需要传入的数据
 * @retval 循环监测设备连接状态，一般不会结束
 */
int CVICALLBACK CheckConnectThread(void *functionData)
{
	char devName[64] = {0};
	long devNum = 0;
	int retryTimes = 5;

	while (1)
	{
		/* 每秒检测一次设备连接状态 */
		if (CheckDevice(gsc_IP, devName, gsc_MAC, gsc_udpPort, &devNum, gsc_sendTimeout, gsc_recvTimeout) <= 0)
		{
			/* 再次确认是不是真的没有设备与电脑连接 */
			if (devNum <= 0 && gsv_connectState)
			{
				/* 清空之前采集的数据 */
				memset(gs_AIRawDataArr, 0, sizeof(uint16_t) * 8);
				memset(gs_targetData, 0, sizeof(double) * 8);
				/* 面板上的8个通道的数据全部显示0 */
				ShowDataOnString();

				/* 设备连接状态的红色指示灯亮 */
				SetCtrlAttribute(panelHandle, PANEL_LED_CONNECT_STATE, ATTR_ON_COLOR, VAL_RED);
				SetCtrlVal(panelHandle, PANEL_LED_CONNECT_STATE, 1);

				/* 释放设备资源 */
				CloseDevice(gs_dev);
				gs_dev = (void*)-1;

				/* 更新设备连接状态标志 */
				gsv_connectState = FALSE;
			}
		}
		else
		{
			/* 再次确认是不是真的有设备与电脑连接 */
			if (devNum > 0 && !gsv_connectState)
			{
				retryTimes = 5;

				do
				{
					/* 创建设备 */
					gs_dev = OpenDevice(gsc_IP, gsc_tcpPort, gsc_sendTimeout, gsc_recvTimeout);
					if (CheckDeviceHandle(gs_dev))
					{
						break;
					}
					Sleep(100);
				}
				while (retryTimes-- > 0);

				/* 检查是否连接成功 */
				if (!CheckDeviceHandle(gs_dev))
				{
					/* 连接设备失败，可能是网线没接好 */
					MessagePopup("警告！", "无法重连设备，请检查电脑以太网IPv4属性中的IP地址和子网掩码是否有异常");
					/* 创建设备失败 */
					return -1;
				}

				/* 设备连接状态的绿色指示灯亮 */
				SetCtrlAttribute(panelHandle, PANEL_LED_CONNECT_STATE, ATTR_ON_COLOR, VAL_GREEN);
				SetCtrlVal(panelHandle, PANEL_LED_CONNECT_STATE, 1);

				/* 更新设备连接状态标志 */
				gsv_connectState = TRUE;
			}
		}

		Sleep(1000);
	}

	//return 0;
}

/**
 * @brief 设置8个输入通道的量程为0~5V
 */
void SetAIChannelRangeVoltN0P5()
{
	/* 各通道量程 */
	long AIChannelRangeArr[8] = {DAME3000N_VOLT_N0_P5};

	for (int i = 0; i < 8; i++)
	{
		AIChannelRangeArr[i] = DAME3000N_VOLT_N0_P5;
	}
	
	/* 设置各通道量程 */
	SetAIChannelRange(gs_dev, AIChannelRangeArr, 0, 7);
}

/**
 * @brief 使能8个输入通道的采集功能
 */
void SetAllAIChannelEnable()
{
	long AIChannelArr[8] = {0, 1, 2, 3, 4, 5, 6, 7}; 		// 8个通道的编号
	BYTE AIChannelEnableArr[8] = {1, 1, 1, 1, 1, 1, 1, 1};	// 8个通道各自的使能状态

	SetAIChannelEnable(gs_dev, AIChannelArr, AIChannelEnableArr, 8);
}

/**
 * @brief 获取D0口报警状态
 */
int GetD0PortAlarmState()
{
	BYTE D0State = 0;

	/* 获取D0口报警状态 */
	DAME3000N_AIGetAlarmStatus(gs_dev, &D0State, UPPER_LIMIT, 6, 6);

	return D0State;
}
