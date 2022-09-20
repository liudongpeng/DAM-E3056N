//==============================================================================
//
// Title:		DAM-E3056N
// Purpose:		DAM-E3056N�ɼ�����λ������
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
/* �豸�Ͽ����Ӻ󣬳��������������� */
//#define RECONNEC_TTIMES	5	// ��δʹ��

/* ������ʾ��ʽ */
static const char* gsc_dataFormat = "%.1f";

/* �����豸������Ҫ�Ĳ����������޸� */
static const char 		gsc_IP[32] = "192.168.2.80";		// IP��ַ
static const char 		gsc_MAC[32] = "88-e1-61-00-54-20";	// MAC��ַ	���棡���� MAC��ַȫ��Ψһ����Ҫ�����ģ�����
static const uint16_t	gsc_tcpPort = 502;				// TCP�˿ں�
static const uint16_t	gsc_udpPort = 5001;				// UDP�˿ں�
static const long 		gsc_sendTimeout = 1000;			// �������ݵĳ�ʱ���
static const long 		gsc_recvTimeout = 1000;			// �������ݵĳ�ʱ���

/* ͨ������Ϊ0~+5V */
static const int gsc_channelRange = 5;

/* AIN6ͨ����ѹ���ޣ���ת��Ϊ0~5V���̵ĵ�ѹ��ֵ */
static const USHORT gsc_AIN6UpperLimit = (USHORT)(800.0 / 1000.0 * gsc_channelRange);


//==============================================================================
// Static global variables
static int panelHandle = 0;				// �������

volatile HANDLE gs_dev; 				// �豸���
volatile BOOL gsv_connectState;			// �豸����״̬

/* ���ݴ�����Ҫ�õ������� */
static uint16_t gs_AIRawDataArr[8];		// 8��AIͨ����ȡ����ԭʼ����
static double gs_targetData[8];			// �����������

/* �����±���ͨ�����ܵ�ӳ���ϵ */
typedef enum
{
	AIN_A_ACV_INDEX = 0,	// ��������A���ѹ��0~5V��Ӧ0V~300V
	AIN_B_ACV_INDEX,		// ��������B���ѹ��0~5V��Ӧ0V~300V
	AIN_C_ACV_INDEX,		// ��������C���ѹ��0~5V��Ӧ0V~300V

	AIN_A_ACI_INDEX,		// ��������A�������0~5V��Ӧ0V~800A
	AIN_B_ACI_INDEX,		// ��������B�������0~5V��Ӧ0V~800A
	AIN_C_ACI_INDEX,		// ��������C�������0~5V��Ӧ0V~800A

	OUT_DCV_INDEX,			// ֱ�������ѹ��0~5V��Ӧ0~1000V
	OUT_DCI_INDEX			// ֱ�����������0~5V��Ӧ0~1000A
};

/* ������Ŀ��Ӧ��ԭʼ������Ŀ�����ݵ�ת��ϵ�����õ�ԭʼ����ֻ��Ҫ���Զ�Ӧ��ϵ������ */
typedef enum
{
	AIN_V_PROPORTION = 300 / gsc_channelRange,		// ���ཻ�������ѹ��Ӧ��ת��ϵ��
	AIN_I_PROPORTION = 800 / gsc_channelRange,		// ���ཻ�����������Ӧ��ת��ϵ��

	OUT_V_PROPORTION = 1000 / gsc_channelRange,		// ֱ����ѹ��Ӧ��ת��ϵ��
	OUT_I_PROPORTION = 1000 / gsc_channelRange		// ֱ��������Ӧ��ת��ϵ��
};



/*************************************** �������� ***************************************/
int CVICALLBACK SamplingThread(void *functionData);		// �����߳�
int CVICALLBACK CheckConnectThread(void *functionData);	// �豸����״̬����߳�

/**
 * @brief ����8������ͨ��������Ϊ0~5V
 * @param None
 * @retval None
 */
void SetAIChannelRangeVoltN0P5();

/**
 * @brief ʹ��8������ͨ���Ĳɼ�����
 */
void SetAllAIChannelEnable();

/**
 * @brief ��ȡD0�ڱ���״̬
 */
int GetD0PortAlarmState();

/**
 * @brief ��ԭʼ���ݰ��ն�Ӧ��ϵת��Ϊ��Ҫ��ʾ������
 * @param rawDataArr[IN]		8��ͨ���ɼ�����ԭʼ����
 * @param targetDataArr[OUT]	ת����������ʾ������
 * @param n[IN]					���ݸ���
 * @retval ת���ɹ�����true��ʧ�ܷ���false
 */
BOOL ParseData(uint16_t* rawDataArr, double* targetDataArr, int n);

/**
 * @brief AIͨ����ѹ��⣬����һ��ͨ����ѹ��Ƿѹ������
 * @retval ����һ��ͨ�� ��ѹ �� Ƿѹ ����true��ȫ��ͨ������Ƿѹ�Ҳ���ѹ����false
 */
BOOL AIChannelMnoitor();

/**
 * @brief ��������ʾ���û�������
 */
void ShowDataOnString();


/*************************************** ����ʵ�� ***************************************/
int main (int argc, char *argv[])
{
	int error = 0;
	int startPagePanelHandle = 0;

	/* initialize and load resources */
	nullChk (InitCVIRTE (0, argv, 0));
	errChk (panelHandle = LoadPanel (0, "DAM-E3056N.uir", PANEL));

	/* ���ز���ʾ��ʼ������ */
	startPagePanelHandle = LoadPanel(0, "DAM-E3056N.uir", PANEL_INIT);
	DisplayPanel(startPagePanelHandle);


	/* �����豸 */
	gs_dev = OpenDevice(gsc_IP, gsc_tcpPort, gsc_sendTimeout, gsc_recvTimeout);
	if (!CheckDeviceHandle(gs_dev))
	{
		/* �����豸ʧ�ܣ�����������û�Ӻ� */
		MessagePopup("���棡", "�޷������豸�����������̫��IPv4�����е�IP��ַ�����������Ƿ����쳣");
		/* �����豸ʧ�� */
		return -1;
	}

	/* �ٴμ���豸�Ƿ����� */
	long devNum = 0;
	char devName[1024] = {0};
	if (CheckDevice(gsc_IP, devName, gsc_MAC, gsc_udpPort, &devNum, gsc_sendTimeout, gsc_recvTimeout) > 0)
	{
		if (devNum > 0 && strcmp(devName, "DAM-E3056N") == 0)
		{
			/* �豸���ߣ��豸����״̬��ɫָʾ���� */
			SetCtrlAttribute(panelHandle, PANEL_LED_CONNECT_STATE, ATTR_ON_COLOR, VAL_GREEN);
			SetCtrlVal(panelHandle, PANEL_LED_CONNECT_STATE, 1);
			/* �����豸����״̬��־ */
			gsv_connectState = TRUE;
		}
		else
		{
			/* �豸�����ߣ�����������û�Ӻ� */
			MessagePopup("���棡", "�豸�����ߣ�����������û�Ӻã������������Ӳ�����");
			return -1;
		}
	}

	/* ���ٳ�ʼ������ */
	DiscardPanel(startPagePanelHandle);

	/* ����AIͨ������Ϊ0��+5V */
	SetAIChannelRangeVoltN0P5();
	/* ʹ��8��AI�ɼ�ͨ�� */
	SetAllAIChannelEnable();

	/* ������ѹ�ɼ��߳� */
	CmtScheduleThreadPoolFunction(DEFAULT_THREAD_POOL_HANDLE, SamplingThread, NULL, NULL);
	/* �����豸����״̬����߳� */
	CmtScheduleThreadPoolFunction(DEFAULT_THREAD_POOL_HANDLE, CheckConnectThread, NULL, NULL);


	/* display the panel and run the user interface */
	errChk (DisplayPanel (panelHandle));
	errChk (RunUserInterface ());

Error:
	/* clean up */
	if (panelHandle > 0)
		DiscardPanel (panelHandle);

	/* �ͷ��豸���� */
	if (CheckDeviceHandle(gs_dev))
		return CloseDevice(gs_dev);

	return 0;
}

/**
 * @brief ���Ͻ��˳���ť�ص�
 */
int CVICALLBACK panelCB (int panel, int event, void *callbackData,
						 int eventData1, int eventData2)
{
	if (event == EVENT_CLOSE)
		QuitUserInterface(0);
	return 0;
}


/**
 * @brief ��ԭʼ���ݰ��ն�Ӧ��ϵת��Ϊ��Ҫ��ʾ������
 * @param rawDataArr[IN]		8��ͨ���ɼ�����ԭʼ����
 * @param targetDataArr[OUT]	ת����������ʾ������
 * @param n[IN]					���ݸ���
 * @retval ת���ɹ�����true��ʧ�ܷ���false
 */
BOOL ParseData(uint16_t* rawDataArr, double* targetDataArr, int n)
{
	if (rawDataArr == NULL || targetDataArr == NULL)
		return FALSE;

	/* ʵ�ʵ�ѹ = AI�ɼ���ѹ * ת��ϵ�� */

	/* A B C �����ѹ */
	//gs_targetData[AIN_A_ACV_INDEX] = gs_AIRawDataArr[AIN_A_ACV_INDEX] / 65535.0 * gsc_channelRange; // ������
	gs_targetData[AIN_A_ACV_INDEX] = (gs_AIRawDataArr[AIN_A_ACV_INDEX] / 65535.0 * gsc_channelRange) * AIN_V_PROPORTION;
	gs_targetData[AIN_B_ACV_INDEX] = (gs_AIRawDataArr[AIN_B_ACV_INDEX] / 65535.0 * gsc_channelRange) * AIN_V_PROPORTION;
	gs_targetData[AIN_C_ACV_INDEX] = (gs_AIRawDataArr[AIN_C_ACV_INDEX] / 65535.0 * gsc_channelRange) * AIN_V_PROPORTION;

	/* A B C ������� */
	gs_targetData[AIN_A_ACI_INDEX] = (gs_AIRawDataArr[AIN_A_ACI_INDEX] / 65535.0 * gsc_channelRange) * AIN_I_PROPORTION;
	gs_targetData[AIN_B_ACI_INDEX] = (gs_AIRawDataArr[AIN_B_ACI_INDEX] / 65535.0 * gsc_channelRange) * AIN_I_PROPORTION;
	gs_targetData[AIN_C_ACI_INDEX] = (gs_AIRawDataArr[AIN_C_ACI_INDEX] / 65535.0 * gsc_channelRange) * AIN_I_PROPORTION;

	/* 6��7ͨ���ӵ�Դ��ֱ����� */
	//gs_targetData[OUT_DCV_INDEX] = gs_AIRawDataArr[OUT_DCV_INDEX] / 65535.0 * gsc_channelRange; // ������
	gs_targetData[OUT_DCV_INDEX] = (gs_AIRawDataArr[OUT_DCV_INDEX] / 65535.0 * gsc_channelRange) * OUT_V_PROPORTION;
	gs_targetData[OUT_DCI_INDEX] = (gs_AIRawDataArr[OUT_DCI_INDEX] / 65535.0 * gsc_channelRange) * OUT_I_PROPORTION;

	return TRUE;
}

/**
 * @brief AIͨ����ѹ��⣬����һ��ͨ����ѹ��Ƿѹ������
 * @retval ����һ��ͨ�� ��ѹ �� Ƿѹ ����true��ȫ��ͨ������Ƿѹ�Ҳ���ѹ����false
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
	 * A0~A2��	����һ· С��180V �� ����280V
	 * A6��		С��600V �� ����800V
	 * A7��		����690A
	 * ��������һ·����Ҫ����D0, D1����ͬʱ��ͨ���жϵ�Դ���ⷢ��Σ��
	 *
	 * A7��		����10A��D2��ͨ
	 *
	 * A6��		��600V��800V֮�䣬D3��ͨ
	 *
	 * A6��		С��600V�����800V��D4��ͨ
	 *
	 * ע�⣺		DOUT�ڽ��ⲿ������B�������͵�ѹ��NPN�����ܲ���ͨ��DOUT������ߵ�ѹ
	 */
	if (	(gs_targetData[AIN_A_ACV_INDEX] >= 180 && gs_targetData[AIN_A_ACV_INDEX] <= 280) &&
			(gs_targetData[AIN_B_ACV_INDEX] >= 180 && gs_targetData[AIN_B_ACV_INDEX] <= 280) &&
			(gs_targetData[AIN_C_ACV_INDEX] >= 180 && gs_targetData[AIN_C_ACV_INDEX] <= 280) &&

			(gs_targetData[OUT_DCV_INDEX] >= 600 && gs_targetData[OUT_DCV_INDEX] <= 800) &&

			(gs_targetData[OUT_DCI_INDEX] <= 690)
	   )
	{
		/* AIͨ�����������ݶ��Ƿ��ϱ�׼�ģ�״̬���� */

		/* �豸����״̬���� ��ɫ���������ʾ�������� */
		SetCtrlAttribute(panelHandle, PANEL_STRING_WORK_STATE, ATTR_TEXT_COLOR, VAL_GREEN);
		SetCtrlVal(panelHandle, PANEL_STRING_WORK_STATE, "����");

		/* A7����10A��D2��ͨ */
		if (gs_targetData[OUT_DCI_INDEX] >= 10)
		{
			DAME3000N_DOSetValue_Line(gs_dev, NPN_OPEN, DOUT2);
		}

		/* A6��600V��800V֮�䣬D3��ͨ */
		if (gs_targetData[OUT_DCV_INDEX] >= 600 && gs_targetData[OUT_DCV_INDEX] <= 800)
		{
			DAME3000N_DOSetValue_Line(gs_dev, NPN_OPEN, DOUT3);
		}
	}
	else
	{
		/* AIͨ��������������Щ�����ϱ�׼��״̬�쳣 */

		/* �豸����״̬���� ��ɫ���������ʾ�����ϡ� */
		SetCtrlAttribute(panelHandle, PANEL_STRING_WORK_STATE, ATTR_TEXT_COLOR, VAL_RED);
		SetCtrlVal(panelHandle, PANEL_STRING_WORK_STATE, "����");

		/* D0��D1����ͬʱ��ͨ */
		DAME3000N_DOSetValue_Line(gs_dev, NPN_OPEN, DOUT0);
		DAME3000N_DOSetValue_Line(gs_dev, NPN_OPEN, DOUT1);

		/* A6С��600V�����800V��D4��ͨ */
		if (gs_targetData[OUT_DCV_INDEX] < 600 || gs_targetData[OUT_DCV_INDEX] > 800)
		{
			DAME3000N_DOSetValue_Line(gs_dev, NPN_OPEN, DOUT4);
		}
	}

	return FALSE;
}

/**
 * @brief ��������ʾ���û�������
 */
void ShowDataOnString()
{
	char buf[64] = {0};

	// ��������A���ѹ
	sprintf(buf, gsc_dataFormat, gs_targetData[AIN_A_ACV_INDEX]);
	SetCtrlVal(panelHandle, PANEL_STRING_A_IN_ACV, buf);
	// ��������B���ѹ
	sprintf(buf, gsc_dataFormat, gs_targetData[AIN_B_ACV_INDEX]);
	SetCtrlVal(panelHandle, PANEL_STRING_B_IN_ACV, buf);
	// ��������C���ѹ
	sprintf(buf, gsc_dataFormat, gs_targetData[AIN_C_ACV_INDEX]);
	SetCtrlVal(panelHandle, PANEL_STRING_C_IN_ACV, buf);

	// ��������A�����
	sprintf(buf, gsc_dataFormat, gs_targetData[AIN_A_ACI_INDEX]);
	SetCtrlVal(panelHandle, PANEL_STRING_A_IN_ACI, buf);
	// ��������B�����
	sprintf(buf, gsc_dataFormat, gs_targetData[AIN_B_ACI_INDEX]);
	SetCtrlVal(panelHandle, PANEL_STRING_B_IN_ACI, buf);
	// ��������C�����
	sprintf(buf, gsc_dataFormat, gs_targetData[AIN_C_ACI_INDEX]);
	SetCtrlVal(panelHandle, PANEL_STRING_C_IN_ACI, buf);

	// ֱ�������ѹ
	sprintf(buf, gsc_dataFormat, gs_targetData[OUT_DCV_INDEX]);
	SetCtrlVal(panelHandle, PANEL_STRING_OUT_DCV, buf);
	// ֱ���������
	sprintf(buf, gsc_dataFormat, gs_targetData[OUT_DCI_INDEX]);
	SetCtrlVal(panelHandle, PANEL_STRING_OUT_DCI, buf);
}

/**
 * @brief ��������ʾ���ݵĹ����̣߳�ֻҪ�豸���Ͽ����ӣ���һֱ����
 * @param functionData[IN]	��Ҫ���������
 * @retval ѭ���ɼ����ݣ�һ�㲻�᷵��
 */
int CVICALLBACK SamplingThread(void *functionData)
{
	while (1)
	{
		while (gsv_connectState)
		{
			/* ��8��ͨ�������� */
			DAME3000N_AIReadData(gs_dev, gs_AIRawDataArr, 0, 7);

			/* ����8��ͨ���ɼ������� */
			ParseData(gs_AIRawDataArr, gs_targetData, 8);

			/* ����ͨ����ѹ������ */
			/*
			 * A0~A2��	����һ· С��180V �� ����280V
			 * A6��		С��600V �� ����800V
			 * A7��		����690A
			 * ��������һ·����Ҫ����D0, D1����ͬʱ��ͨ���жϵ�Դ���ⷢ��Σ��
			 */
			AIChannelMnoitor();

			/* ���û������Ӧ��λ����ʾ����������� */
			ShowDataOnString();

			/* һ��������� */
			Sleep(500);
		}

		/* �豸�Ͽ���ÿ��1�����ԣ�����豸�Ƿ��������ӳɹ� */
		Sleep(1000);
	}

	//return 0;
}

/**
 * @brief �豸����״̬����̣߳��ӳ������п�ʼֱ������������豸����ԶϿ����Ӻ�᳢�������豸
 * @param functionData[IN]	��Ҫ���������
 * @retval ѭ������豸����״̬��һ�㲻�����
 */
int CVICALLBACK CheckConnectThread(void *functionData)
{
	char devName[64] = {0};
	long devNum = 0;
	int retryTimes = 5;

	while (1)
	{
		/* ÿ����һ���豸����״̬ */
		if (CheckDevice(gsc_IP, devName, gsc_MAC, gsc_udpPort, &devNum, gsc_sendTimeout, gsc_recvTimeout) <= 0)
		{
			/* �ٴ�ȷ���ǲ������û���豸��������� */
			if (devNum <= 0 && gsv_connectState)
			{
				/* ���֮ǰ�ɼ������� */
				memset(gs_AIRawDataArr, 0, sizeof(uint16_t) * 8);
				memset(gs_targetData, 0, sizeof(double) * 8);
				/* ����ϵ�8��ͨ��������ȫ����ʾ0 */
				ShowDataOnString();

				/* �豸����״̬�ĺ�ɫָʾ���� */
				SetCtrlAttribute(panelHandle, PANEL_LED_CONNECT_STATE, ATTR_ON_COLOR, VAL_RED);
				SetCtrlVal(panelHandle, PANEL_LED_CONNECT_STATE, 1);

				/* �ͷ��豸��Դ */
				CloseDevice(gs_dev);
				gs_dev = (void*)-1;

				/* �����豸����״̬��־ */
				gsv_connectState = FALSE;
			}
		}
		else
		{
			/* �ٴ�ȷ���ǲ���������豸��������� */
			if (devNum > 0 && !gsv_connectState)
			{
				retryTimes = 5;

				do
				{
					/* �����豸 */
					gs_dev = OpenDevice(gsc_IP, gsc_tcpPort, gsc_sendTimeout, gsc_recvTimeout);
					if (CheckDeviceHandle(gs_dev))
					{
						break;
					}
					Sleep(100);
				}
				while (retryTimes-- > 0);

				/* ����Ƿ����ӳɹ� */
				if (!CheckDeviceHandle(gs_dev))
				{
					/* �����豸ʧ�ܣ�����������û�Ӻ� */
					MessagePopup("���棡", "�޷������豸�����������̫��IPv4�����е�IP��ַ�����������Ƿ����쳣");
					/* �����豸ʧ�� */
					return -1;
				}

				/* �豸����״̬����ɫָʾ���� */
				SetCtrlAttribute(panelHandle, PANEL_LED_CONNECT_STATE, ATTR_ON_COLOR, VAL_GREEN);
				SetCtrlVal(panelHandle, PANEL_LED_CONNECT_STATE, 1);

				/* �����豸����״̬��־ */
				gsv_connectState = TRUE;
			}
		}

		Sleep(1000);
	}

	//return 0;
}

/**
 * @brief ����8������ͨ��������Ϊ0~5V
 */
void SetAIChannelRangeVoltN0P5()
{
	/* ��ͨ������ */
	long AIChannelRangeArr[8] = {DAME3000N_VOLT_N0_P5};

	for (int i = 0; i < 8; i++)
	{
		AIChannelRangeArr[i] = DAME3000N_VOLT_N0_P5;
	}
	
	/* ���ø�ͨ������ */
	SetAIChannelRange(gs_dev, AIChannelRangeArr, 0, 7);
}

/**
 * @brief ʹ��8������ͨ���Ĳɼ�����
 */
void SetAllAIChannelEnable()
{
	long AIChannelArr[8] = {0, 1, 2, 3, 4, 5, 6, 7}; 		// 8��ͨ���ı��
	BYTE AIChannelEnableArr[8] = {1, 1, 1, 1, 1, 1, 1, 1};	// 8��ͨ�����Ե�ʹ��״̬

	SetAIChannelEnable(gs_dev, AIChannelArr, AIChannelEnableArr, 8);
}

/**
 * @brief ��ȡD0�ڱ���״̬
 */
int GetD0PortAlarmState()
{
	BYTE D0State = 0;

	/* ��ȡD0�ڱ���״̬ */
	DAME3000N_AIGetAlarmStatus(gs_dev, &D0State, UPPER_LIMIT, 6, 6);

	return D0State;
}
