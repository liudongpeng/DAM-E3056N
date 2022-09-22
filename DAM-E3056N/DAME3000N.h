#ifndef  __DAME3000N_LIB__
#define __DAME3000N_LIB__

#include <windows.h>

// 模拟量输入类型(电压类型) 供DAME3000N_SetModeAD函数中的nADMode参数使用
#define DAME3000N_VOLT_N15_P15					0x01	//  -15～+15mV
#define DAME3000N_VOLT_N50_P50					0x02	//  -50～+50mV
#define DAME3000N_VOLT_N100_P100				0x03	// -100～+100mV
#define DAME3000N_VOLT_N150_P150				0x04	// -150～+150mV
#define DAME3000N_VOLT_N500_P500				0x05	// -500～+500mV
#define DAME3000N_VOLT_N1_P1					0x06	//   -1～+1V
#define DAME3000N_VOLT_N25_P25					0x07	// -2.5～+2.5V
#define DAME3000N_VOLT_N5_P5					0x08	//   -5～+5V
#define DAME3000N_VOLT_N10_P10					0x09	//  -10～+10V
#define DAME3000N_VOLT_N0_P5					0x0D	//    0～+5V
#define DAME3000N_VOLT_N0_P10					0x0E	//    0～+10V
#define DAME3000N_VOLT_N0_P25					0x0F	//    0～+2.5V
#define DAME3000N_VOLT_P1_P5					0x82	//    1～+5.0V
// 模拟量输入类型(电流类型) 供DAME3000N_SetModeAD函数中的nADMode参数使用
#define DAME3000N_CUR_N0_P10					0x00	//   0～10mA
#define DAME3000N_CUR_N20_P20					0x0A	// -20～+20mA
#define DAME3000N_CUR_N0_P20					0x0B	//   0～20mA
#define DAME3000N_CUR_P4_P20					0x0C	//   4～20mA
#define DAME3000N_CUR_N0_P22					0x80	//   0～22mA

// 模拟量输入类型(热电阻类型) 供DAME3000N_SetModeAD函数中的nADMode参数使用
#define DAME3000N_RTD_CU50						0x40	// Cu50热电阻        -50℃～150℃
#define DAME3000N_RTD_CU100					0x41	// Cu100热电阻       -50℃～150℃
#define DAME3000N_RTD_PT100_385_N200_P850		0x20	// Pt100(385)热电阻 -200℃～850℃
#define DAME3000N_RTD_PT100_385_N100_P100		0x21	// Pt100(385)热电阻 -100℃～100℃
#define DAME3000N_RTD_PT100_385_N0_P100		0x22	// Pt100(385)热电阻    0℃～100℃
#define DAME3000N_RTD_PT100_385_N0_P200		0x23	// Pt100(385)热电阻    0℃～200℃
#define DAME3000N_RTD_PT100_385_N0_P600		0x24	// Pt100(385)热电阻    0℃～600℃
#define DAME3000N_RTD_PT100_3916_N200_P850		0x25	// Pt100(3916)热电阻-200℃～850℃
#define DAME3000N_RTD_PT100_3916_N100_P100		0x26	// Pt100(3916)热电阻-100℃～100℃
#define DAME3000N_RTD_PT100_3916_N0_P100		0x27	// Pt100(3916)热电阻   0℃～100℃
#define DAME3000N_RTD_PT100_3916_N0_P200		0x28	// Pt100(3916)热电阻   0℃～200℃
#define DAME3000N_RTD_PT100_3916_N0_P600		0x29	// Pt100(3916)热电阻   0℃～600℃
#define DAME3000N_RTD_PT1000					0x30	// Pt1000热电阻     -200℃～850℃
#define DAME3000N_RTD_BA1						0x42	// BA1热电阻        -200℃～650℃
#define DAME3000N_RTD_BA2						0x43	// BA2热电阻        -200℃～650℃
#define DAME3000N_RTD_G53						0x44	// G53热电阻         -50℃～150℃
#define DAME3000N_RTD_Ni50						0x45	// Ni50热电阻        100℃～
#define DAME3000N_RTD_Ni508					0x46	// Ni508热电阻         0℃～100℃
#define DAME3000N_RTD_Ni1000					0x47	// Ni1000热电阻      -60℃～160℃

// 模拟量输入类型(热电偶类型) 供DAME3000N_SetModeAD函数中的nADMode参数使用
#define DAME3000N_THERMOCOUPLE_J					0x10	// J型热电偶			0℃～1200℃
#define DAME3000N_THERMOCOUPLE_K					0x11	// K型热电偶			0℃～1300℃
#define DAME3000N_THERMOCOUPLE_T					0x12	// T型热电偶			-200℃～400℃
#define DAME3000N_THERMOCOUPLE_E					0x13	// E型热电偶			0℃～1000℃
#define DAME3000N_THERMOCOUPLE_R					0x14	// R型热电偶		  500℃～1700℃
#define DAME3000N_THERMOCOUPLE_S					0x15	// S型热电偶		  500℃～1768℃
#define DAME3000N_THERMOCOUPLE_B					0x16	// B型热电偶		  500℃～1800℃
#define DAME3000N_THERMOCOUPLE_N					0x17	// N型热电偶			0℃～1300℃
#define DAME3000N_THERMOCOUPLE_C					0x18	// C型热电偶			0℃～2090℃

// 数字量输出类型使用
#define DAME3000N_OUTPUT_TYPE_DIGIT				0		// 数字量输出
#define DAME3000N_OUTPUT_TYPE_PULSE				1		// 脉冲输出

// 数字量输入类型 供DAME3000N_SetModeCNT函数中的lCNTMode参数使用
#define	DAME3000N_DI_MODE_CNT_RISING				1		// 上升沿计数
#define	DAME3000N_DI_MODE_CNT_FALLING				0		// 下降沿计数

// 数字量输出源状态 供DAME3000N_DOGetSourceStatus函数lSourceSts参数使用
#define DAME3000N_DO_SOURCE_STATUS_FAILED			0	// 状态异常
#define DAME3000N_DO_SOURCE_STATUS_NORMAL			1	// 状态正常



// DI模块的工作模式 供DAME3000N_DISetMode(DAME3000N_DIGetMode)函数中的lMode参数使用
#define DAME3000N_DIMODE_DI					0x01 // 普通DI量输入模式
#define DAME3000N_DIMODE_LATCH_LOWTOHIGH		0x02 // 低到高锁存模式
#define DAME3000N_DIMODE_LATCH_HIGHTOLOW		0x03 // 低到高锁存模式
#define DAME3000N_DIMODE_CNT					0x04 // 计数工作模式
#define DAME3000N_DIMODE_FREQ					0x05 // 频率工作模式

// DO模块的工作模式 供DAME3000N_DOSetMode(DAME3000N_DOGetMode)函数中的lMode参数使用
#define DAME3000N_DOMODE_DO				1	// 立即输出
#define DAME3000N_DOMODE_LOWTOHIGH		2	// 低到高延时输出
#define DAME3000N_DOMODE_HIGHTOLOW		3	// 高到低延时输出
#define DAME3000N_DOMODE_PULSE			4	// 脉冲输出


// 设备网络信息
typedef struct _DEVICE_NET_INFO
{
	char    szIP[16];					// IP地址, // IP地址, "192.168.2.70"
	char	SubnetMask[16];				// 子网掩码, "255.255.255.255"
	char	Gateway[16];				// 网关, "192.168.2.1"
	char	MAC[20];					// 网卡物理地址,  "00-01-02-03-04-05",用户一般不可修改
	LONG	lTCPPort;					// TCP端口号
	LONG    lHTTPPort;					// HTTP端口号
	LONG	lUDPPort;					// UDP端口号
	LONG	lMode;						// 连接模式(0: 静态模式  1: DHCP动态模式)
	char	chDevName[32];				// Device self name
} DEVICE_NET_INFO, *PDEVICE_NET_INFO;

#ifndef _DAME3000N_DRIVER_
#define DEVAPI	__declspec(dllimport)
#else
#define DEVAPI  __declspec(dllexport)
#endif

#ifdef __cplusplus
extern "C" {
#endif
	//####################### 查询模块设备是否在线(DHCP) #######################
	int  DEVAPI FAR PASCAL  DAME3000N_SearchDevice(
		char	szIP[],			// 设备IP列表
		char	szName[],		// 设备名称
		char	szMAC[],		// MAC地址
		LONG	lPort,			// UDP端口
		PLONG	plCount,		// 设备数量
		LONG	lSendTimeout,	// 发送数据的超时间隔
		LONG	lRcvTimeout);	// 接收数据的超时间隔

	//####################### 设备对象管理函数 #################################
	HANDLE  DEVAPI FAR PASCAL  DAME3000N_CreateDevice(		// 创建设备
		char	szIP[],			// 设备IP(如"192.168.1.2")
		LONG	lPort,			// TCP端口
		LONG	lSendTimeout,	// 发送数据的超时间隔
		LONG	lRcvTimeout);	// 接收数据的超时间隔

	BOOL DEVAPI	FAR	PASCAL  DAME3000N_ReleaseDevice(HANDLE hDevice);	// 释放设备对象

	BOOL DEVAPI FAR PASCAL  DAME3000N_GetDeviceVersion(		// 取得设备版本信息
		HANDLE	hDevice,			// 设备句柄
		char	szVersion[]);		// 设备版本信息

	BOOL DEVAPI FAR PASCAL  DAME3000N_GetNetworkConfig(		// 获得设备的网络配置信息
		HANDLE	 hDevice,			// 设备句柄
		PDEVICE_NET_INFO pNetInfo);	// 网络配置信息

	BOOL DEVAPI FAR PASCAL  DAME3000N_GetNetworkConfigEx(	// 获得设备的网络配置信息
		HANDLE	hDevice,		// 设备句柄
		char	szIP[16],		// IP地址, IP地址, "192.168.2.70"
		char	SubnetMask[16],	// 子网掩码, "255.255.255.255"
		char	Gateway[16],	// 网关, "192.168.2.1"
		char	MAC[20],		// 网卡物理地址,  "00-01-02-03-04-05",用户一般不可修改
		PLONG	lpTCPPort,		// TCP端口号
		PLONG	lpHTTPPort,		// HTTP端口号
		PLONG	lpUDPPort,		// UDP端口号
		PLONG	lpMode);		// 连接模式(0: 静态模式  1: DHCP动态模式)

	BOOL DEVAPI FAR PASCAL  DAME3000N_SetNetworkConfig(		// 设置设备的网络配置信息
		HANDLE	 hDevice,			// 设备句柄
		PDEVICE_NET_INFO NetInfo);	// 网络配置信息

	BOOL DEVAPI FAR PASCAL  DAME3000N_SetNetworkConfigEx(		// 设置设备的网络配置信息
		HANDLE	hDevice,			// 设备句柄
		char	szIP[16],			// IP地址, // IP地址, "192.168.2.70"
		char	SubnetMask[16],		// 子网掩码, "255.255.255.255"
		char	Gateway[16],		// 网关, "192.168.2.1"
		char	MAC[20],			// 网卡物理地址,  "00-01-02-03-04-05",用户一般不可修改
		LONG	lTCPPort,			// TCP端口号
		LONG	lHTTPPort,			// HTTP端口号
		LONG	lUDPPort,			// UDP端口号
		LONG	lMode);				// 连接模式(0: 静态模式  1: DHCP动态模式)

	BOOL DEVAPI FAR PASCAL DAME3000N_SetNetworkInfo(				// 设置网络IP-子网掩码-网关 可跨网段
		char	MAC[18],				// MAC地址
		char	szIP[16],				// IP地址 "192.168.2.70"
		char	SubnetMask[16],			// 子网掩码 "255.255.255.255"
		char	Gateway[16],			// 网关 "192.168.2.1"
		LONG	udpPort);				// UDP端口号

	BOOL DEVAPI	FAR	PASCAL  DAME3000N_SaveIPAddress(char szIP[]);		// 保存IP到注册表

	BOOL DEVAPI	FAR	PASCAL  DAME3000N_LoadIPAddress(char szIP[]);		// 载入IP到应用程序

	BOOL DEVAPI FAR PASCAL  DAME3000N_DeviceRestart(HANDLE hDevice);	// 设备重启

	BOOL DEVAPI FAR PASCAL  DAME3000N_DeviceFacDefault(HANDLE hDevice);// 恢复出厂

	BOOL DEVAPI FAR PASCAL DAME3000N_GetLastErrorCode(		// 获取最近一次通信错误码，windows系统定义
		HANDLE	hDevice,
		LONG	lStsCode);

	//################################### AI 函数 ####################################
	BOOL DEVAPI FAR PASCAL DAME3000N_AIReadData(			// 获得模拟量通道输入值（不包括平均值通道）
		HANDLE hDevice,				// 设备句柄
		USHORT lAIValue[],			// 返回的AI数据，lAIValue[0]=通道0数据，lAIValue[1]=通道1数据，...，lAIValue[7]=通道7数据，每次读取更新从lFirstChannel到lLastChannel通道内的数据
		LONG lFirstChannel,		// 首通道号 0=通道0,1=通道1,...,7=通道7
		LONG lLastChannel);		// 末通道号 0=通道0,1=通道1,...,7=通道7

	BOOL DEVAPI FAR PASCAL  DAME3000N_AIReadData_Ex(			// 获得模拟量输入值（包括平均值通道）
		HANDLE	hDevice,			// 设备句柄
		USHORT	lAIValue[],			// 返回的AI数据，lAIValue的维数为设备支持的通道总数+1维，lAIValue[0]=平均值通道数据，lAIValue[1]=通道0数据，lAIValue[2]=通道2数据，...，lAIValue[8]=通道7数据。函数更新平均值和从lFirstChannel到lLastChannel通道内的数据。
		LONG	lFirstChannel,	// 首通道号 0=通道0,1=通道1,...,7=通道7
		LONG	lLastChannel);	// 末通道号 0=通道0,1=通道1,...,7=通道7

	BOOL DEVAPI FAR PASCAL DAME3000N_AIReadData_Avg(		// 获得模拟量输入平均值通道数据
		HANDLE	hDevice,			// 设备句柄
		USHORT*	wAIAverValue);		// 返回AI平均值

	BOOL DEVAPI FAR PASCAL DAME3000N_AISetEnableForAvg(		// 使能AI求平均值
		HANDLE	hDevice,			// 设备句柄
		LONG	lChannel,			// 通道号	0=通道0,1=通道1,...,7=通道7
		BYTE	lValue);			// 是否使能 0-不使能 1-使能

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetEnableForAvg(		// 获取AI通道平均值是否使能
		HANDLE	hDevice,			// 设备句柄
		BYTE	lValue[],			// 使能数据数组，数组大小为设备支持的通道总数，返回的数据只更新了从lFirstChannel到lLastChannel通道内的数据，1-使能 0-未使能
		LONG	lFirstChannel,		// 首通道号 0=通道0,1=通道1,...,7=通道7
		LONG	lLastChannel);		// 末通道号 0=通道0,1=通道1,...,7=通道7

	BOOL DEVAPI FAR PASCAL DAME3000N_AISetEnable(		// 使能AI采集通道
		HANDLE hDevice,		// 设备句柄
		LONG lChannel,		// 通道号 0=通道0,1=通道1,...,7=通道7
		BYTE lValue);		// 是否使能 0-不使能 1-使能

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetEnable(		// 获取AI通道采集是否使能
		HANDLE hDevice,			// 设备句柄
		BYTE lValue[],			// 使能数据数组，数组大小为设备支持的总通道数，返回的数据只更新了从lFirstChannel到lLastChannel通道内的数据，1-使能 0-未使能
		LONG lFirstChannel,		// 首通道号 0=通道0,1=通道1,...,7=通道7
		LONG lLastChannel);		// 末通道号 0=通道0,1=通道1,...,7=通道7

	BOOL DEVAPI FAR PASCAL DAME3000N_AIReadHistData(		// 读取AI通道历史最大值最小值，不包括平均值
		HANDLE hDevice,			// 设备句柄
		USHORT lHistData[],		// 数据，数组大小为设备支持的通道总数，返回的数据只更新了从lFirstChannel到lLastChannel通道内的数据
		LONG lTypeChoose,		// 选择读取最大值还是最小值,1-最大值，2-最小值
		LONG lFirstChannel,		// 首通道号 0=通道0,1=通道1,...,7=通道7
		LONG lLastChannel);		// 末通道号 0=通道0,1=通道1,...,7=通道7

	BOOL DEVAPI FAR PASCAL DAME3000N_AIReadHistData_Avg(	// 读取AI通道历史最大(最小)值平均值
		HANDLE hDevice,				// 设备句柄
		USHORT* wAIHistAverValue,	// 平均值
		LONG lTypeChoose);			// 选择读取最大值还是最小值,1-最大值，2-最小值

	BOOL DEVAPI FAR PASCAL DAME3000N_AIReadHistData_Ex(	// 读取AI通道历史最大值(最小值)，包括平均值通道
		HANDLE hDevice,			// 设备句柄
		USHORT lHistData[],		// 数据，数组大小为设备支持的通道总数+1，lHistData[0]为平均值通道数据，lHistData[1]为通道0数据，,,,，lHistData[8]为通道7数据，返回的数据只更新了从lFirstChannel到lLastChannel通道内的数据
		LONG lDataType,			// 选择读取最大值还是最小值,1-最大值，2-最小值
		LONG lFirstChannel,		// 首通道号 0=通道0,1=通道1,...,7=通道7
		LONG lLastChannel);		// 末通道号 0=通道0,1=通道1,...,7=通道7

	BOOL DEVAPI FAR PASCAL DAME3000N_AISetRange(			// 设置模拟量输入模式
		HANDLE hDevice,			// 设备句柄
		LONG lAIMode[],			// 量程数组，数组大小为设备支持的总通道数
		LONG lFirstChannel,		// 首通道号 0=通道0,1=通道1,...,7=通道7
		LONG lLastChannel);		// 末通道号 0=通道0,1=通道1,...,7=通道7

	BOOL DEVAPI FAR PASCAL  DAME3000N_AIGetRange(				// 获得模拟量输入模式
		HANDLE	hDevice,			// 设备句柄
		LONG	lAIMode[],			// 返回的各个通道的AI模式，数组大小为设备支持的总通道数
		LONG	lFirstChannel,	// 首通道号 0=通道0,1=通道1,...,7=通道7
		LONG	lLastChannel);	// 末通道号 0=通道0,1=通道1,...,7=通道7

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetLimitVal(				// 获得上下限报警值，不包括平均值通道报警值
		HANDLE hDevice,				// 设备句柄
		USHORT lLimitValue[],		// 报警值，数组大小为设备支持的总通道数，返回的数据只更新从lFirstChannel到lLastChannel通道内的数据
		LONG lTypeChose,			// 上下限选项 1-上限 2-下限
		LONG lFirstChannel,			// 首通道号 0=通道0,1=通道1,...,7=通道7
		LONG lLastChannel);			// 末通道号 0=通道0,1=通道1,...,7=通道7

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetLimitVal_Avg(		// 获得平均值通道上下限报警值
		HANDLE hDevice,				// 设备句柄
		USHORT* wLimitAverValue,	// 报警值
		LONG lTypeChose);			// 上下限选项 1-上限 2-下限

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetLimitVal_Ex(		// 获得上下限报警值，包括平均值通道报警值
		HANDLE hDevice,			// 设备句柄
		USHORT lLimitValue[],	// 报警值，数组大小为设备支持的总通道数+1，lLimitValue[0]为平均值通道报警值，lLimitValue[1]为通道0数据，,,,，lLimitValue[8]为通道7数据，返回的数据只更新从lFirstChannel到lLastChannel通道内的数据
		LONG lTypeChose,		// 上下限选项 1-上限 2-下限
		LONG lFirstChannel,		// 首通道号 0=通道0,1=通道1,...,7=通道7
		LONG lLastChannel);		// 末通道号 0=通道0,1=通道1,...,7=通道7

	BOOL DEVAPI FAR PASCAL DAME3000N_AISetLimitVal(			// 设置报警值
		HANDLE hDevice,			// 设备句柄
		USHORT lLimitValue,		// 报警值
		LONG lLimitType,		// 上下限选项 1-上限 2-下限
		LONG lChannel);			// 通道号 0=通道0 1=通道1... 7=通道7

	BOOL DEVAPI FAR PASCAL DAME3000N_AISetLimitVal_Ex(		// 设置报警值(含平均值通道)
		HANDLE hDevice,			// 设备句柄
		USHORT lLimitValue,		// 报警值
		LONG lLimitType,		// 上下限选项 1-上限 2-下限
		LONG lChannel);			// 通道号 0=平均值通道 1=通道0 2=通道1... 8=通道7

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetAlarmStatus_Avg(	// 获取模拟量平均值通道报警状态
		HANDLE	hDevice,		// 设备句柄
		BYTE*	lStatus,		// 报警状态
		LONG lLimitType);		// 上下限选择 1-上限 2-下限

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetAlarmStatus(			// 获取通道报警状态，不包括平均值通道报警状态
		HANDLE hDevice,			// 设备句柄
		BYTE lStatus[],			// 报警状态，数组大小为设备支持的总通道数
		LONG lLimitType,		// 上下限选择 1-上限 2-下限
		LONG lFirstChannel,		// 首通道 0=通道0 1=通道1... 7=通道7
		LONG lLastChannel);		// 末通道 0=通道0 1=通道1... 7=通道7

	BOOL DEVAPI FAR PASCAL DAME3000N_AIClearLatchStatus(		// 清除锁存
		HANDLE	hDevice,		// 设备句柄
		BYTE	lStatus,		// 报警状态
		LONG lLimitType,		// 上限/下限
		LONG lChannel);			// 通道号 0=通道0 1=通道1... 7=通道7

	BOOL DEVAPI FAR PASCAL DAME3000N_AIClearLatchSts_Avg(		// 清除平均值通道锁存
		HANDLE	hDevice,		// 设备句柄
		BYTE	lStatus,		// 报警状态
		LONG lLimitType);		// 上限/下限

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetAlarmMode(		// 获得报警模式，不包括平均值通道报警模式 0x00-不报警 0x01-锁存 0x02-实时报警
		HANDLE hDevice,			// 设备句柄
		USHORT lMode[],			// 报警模式，数组大小为设备支持的总通道数，返回的数据只更新从lFirstChannel到lLastChannel通道内数据
		LONG lTypeChose,		// 上下限选择，1-上限 2-下限
		LONG lFirstChannel,		// 首通道号 0=通道0 1=通道1... 7=通道7
		LONG lLastChannel);		// 末通道号 0=通道0 1=通道1... 7=通道7

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetAlarmMode_Avg(	// 获得平均值通道报警模式
		HANDLE hDevice,			// 设备句柄
		USHORT* lAlarmMode_Avg,	// 报警模式
		LONG lTypeChose);		// 上下限选择，1-上限 2-下限

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetAlarmMode_Ex(		// 获得报警模式，包括平均值通道报警模式 0x00-不报警 0x01-锁存 0x02-实时报警
		HANDLE hDevice,			// 设备句柄
		USHORT lMode[],			// 报警模式，数组大小为设备支持的总通道数+1，lMode[0]为平均值通道报警模式，剩余返回的数据只更新从lFirstChannel到lLastChannel通道内数据
		LONG lTypeChose,		// 上下限选择，1-上限 2-下限
		LONG lFirstChannel,		// 首通道号 0=通道0 1=通道1... 7=通道7
		LONG lLastChannel);		// 末通道号 0=通道0 1=通道1... 7=通道7

	BOOL DEVAPI FAR PASCAL DAME3000N_AISetAlarmMode(		// 设置报警模式
		HANDLE hDevice,		// 设备句柄
		SHORT lAlarmMode,	// 报警模式 0x00-不报警 0x01-锁存 0x02-实时报警
		LONG lLimitType,	// 上下限选择，1-上限 2-下限
		LONG lChannel);		// 通道号 0=通道0 1= 通道1 ... 7=通道7

	BOOL DEVAPI FAR PASCAL DAME3000N_AISetAlarmMode_Ex(		// 设置报警模式 (包含平均值通道)
		HANDLE hDevice,		// 设备句柄
		SHORT lAlarmMode,	// 报警模式 0x00-不报警 0x01-锁存 0x02-实时报警
		LONG lLimitType,	// 上下限选择，1-上限 2-下限
		LONG lChannel);		// 通道号 0=平均值通道 1= 通道0 2= 通道1 ... 8=通道7

	BOOL DEVAPI FAR PASCAL DAME3000N_AIResetHistValue_Ex(	// 复位通道历史最大值/最小值
		HANDLE hDevice,			// 设备句柄
		LONG lValueType,		// 最大值/最小值/平均值,1-最大值,2-最小值,3-平均值通道最大值,4-平均值通道最小值
		LONG lChannel);			// 通道号, 0=通道0 1= 通道1 ... 7=通道7. 当lValueType为平均值通道时，此值无意义

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetBrokenLotusSts(	// 获取断藕状态
		HANDLE hDevice,			// 设备句柄
		BYTE lValue[],			// 断藕状态, 1=断偶, 0=正常, 数组大小为设备支持的总通道数，返回的数据只更新从lFirstChannel到lLastChannel通道内数据
		LONG lFirstChannel,		// 首通道号 0=通道0 1= 通道1 ... 7=通道7
		LONG lLastChannel);		// 末通道号 0=通道0 1= 通道1 ... 7=通道7

	BOOL DEVAPI	FAR	PASCAL	DAME3000N_AISetGroundRef(		// 设置通道接地模式(只对可软件配置单/双端输入模块有效)
		HANDLE	hDevice,		// 设备对象句柄
		LONG	lGroundRef,		// AI通道接地模式
		LONG	lChannel);	// 通道号 0=通道0 1= 通道1 ... 7=通道7

	BOOL DEVAPI	FAR	PASCAL	DAME3000N_AIGetGroundRef(		// 获得通道接地模式(只对可软件配置单/双端输入模块有效)
		HANDLE	hDevice,		// 设备对象句柄
		PLONG	lGroundRef,		// AI通道接地模式
		LONG	lChannel);	// 通道号 0=通道0 1= 通道1 ... 7=通道7

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetAlarmBindingStatus_Ex(	// 获取DO绑定状态，首通道为平均值通道
		HANDLE hDevice,				// 设备句柄
		USHORT	lStsValue[],		// 绑定的报警通道(DO通道)号，数组大小为设备支持的AI通道总数+1，lStsValue[0]对应平均值通道 lStsValue[1]对应AI0通道 lStsValue[2]对应AI1通道 ... lStsValue[8]对应AI7通道
		LONG	lTypeChose,			// 上下限选择 1-上限 2-下限
		LONG	lFirstChannel,		// AI首通道号
		LONG	lLastChannel);		// AI末通道号

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetAlarmBindingStatus(	// 获取DO绑定状态，不包括平均值通道
		HANDLE	hDevice,			// 设备句柄
		USHORT	lStsValue[],		// 状态，数组大小为设备支持的通道总数，lStsValue[0]对应AI0通道 lStsValue[1]对应AI1通道 ... lStsValue[7]对应AI7通道
		LONG	lTypeChose,			// 上下限选择 1-上限 2-下限
		LONG	lFirstChannel,		// AI首通道号
		LONG	lLastChannel);		// AI末通道号

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetAlarmBindingStatus_Avg(	// 获取平均值通道DO绑定状态
		HANDLE hDevice,					// 设备句柄
		USHORT* lStsValue_Avg,			// 平均值通道报警绑定的DO通道值
		LONG	lTypeChose);			// 上下限选择 1-上限 2-下限

	BOOL DEVAPI FAR PASCAL DAME3000N_AISetAlarmBindingStatus(		// 设置DO绑定状态
		HANDLE hDevice,					// 设备句柄
		SHORT lMode,					// 绑定DO通道号 0=不绑定 1=DO0 2=DO2
		LONG lTypeChose,				// 上下限选择
		LONG lChannel);					// AI通道号 0=平均值通道 1=AI0 2=AI1 ... 8=AI7

	//################################### DA 函数 ####################################
	BOOL DEVAPI	FAR	PASCAL	DAME3000N_AOReadData(		// 回读DA输出值
		HANDLE	hDevice,	// 设备对象句柄
		PLONG	lpDAValue,	// DA输出当前值
		LONG	lChannel);	// 通道号

	BOOL DEVAPI	FAR	PASCAL	DAME3000N_AOWriteData(		// 设定单通道DA
		HANDLE	 hDevice,	// 设备对象句柄
		LONG	 lDAData,	// DA输出值
		LONG	 lChannel);	// 通道号

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOGetRange(	// 读取模拟量输出量程
		HANDLE	 hDevice,		// 设备对象句柄
		PLONG	 lpRange,		// 输出量程
		LONG	 lChannel);		// 通道号

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOSetRange(	// 设置模拟量输出量程
		HANDLE	 hDevice,		// 设备对象句柄
		LONG	 lRange,		// 输出量程
		LONG	 lChannel);		// 通道号

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOGetPowerOnValue(	// 获得DA上电值
		HANDLE	 hDevice,		// 设备对象句柄
		PLONG	 lpPowerOnVal,	// 上电值
		LONG	 lChannel);		// 通道号

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOSetPowerOnValue(	// 设置DA上电值
		HANDLE	hDevice,		// 设备对象句柄
		LONG	lPowerOnVal,	// 上电值
		LONG	lChannel);		// 通道号

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOGetSafeValue(		// 获得DA安全值
		HANDLE	 hDevice,		// 设备对象句柄
		PLONG	 lpSafeVal,		// 安全值
		LONG	 lChannel);		// 通道号

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOSetSafeValue(		// 设置DA安全值
		HANDLE	 hDevice,		// 设备对象句柄
		LONG	 lSafeVal,		// 安全值
		LONG	 lChannel);		// 通道号

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOGetSlope(			// 读模拟量输出斜率
		HANDLE	 hDevice,		// 设备对象句柄
		PLONG	 lpSlopeType,	// 输出斜率类型
		LONG	 lChannel);		// 通道号

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOSetSlope(			// 修改模拟量输出斜率
		HANDLE	 hDevice,		// 设备对象句柄
		LONG	 lSlopeType,	// 输出斜率类型
		LONG	 lChannel);		// 通道号

	// -----------------------------------------------------------------------------------------------------
	BOOL DEVAPI	FAR	PASCAL	DAME3000N_AOReadData_Addr(		// 回读DA输出值
		HANDLE	hDevice,		// 设备对象句柄
		LONG	lAddr,			// 首通道地址
		PLONG	lpDAValue,		// DA输出当前值
		LONG	lFirstChannel,		// A0首通道号
		LONG	lLastChannel);		// A0末通道号

	BOOL DEVAPI	FAR	PASCAL	DAME3000N_AOWriteData_Addr(		// 设定单通道DA
		HANDLE	hDevice,		// 设备对象句柄
		LONG	lAddr,			// 首通道地址
		LONG	lDAData[],		// DA输出值
		LONG	lFirstChannel,	// A0首通道号
		LONG	lLastChannel);	// A0末通道号

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOGetRange_Addr(		// 读取模拟量输出量程
		HANDLE	hDevice,		// 设备对象句柄
		LONG	lAddr,			// 首通道地址
		PLONG	lpRange,		// 输出量程
		LONG	lFirstChannel,	// A0首通道号
		LONG	lLastChannel);	// A0末通道号

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOSetRange_Addr(		// 设置模拟量输出量程
		HANDLE	hDevice,		// 设备对象句柄
		LONG	lAddr,			// 首通道地址
		LONG	lRange[],			// 输出量程
		LONG	lFirstChannel,	// A0首通道号
		LONG	lLastChannel);	// A0末通道号

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOGetPowerOnValue_Addr(// 获得DA上电值
		HANDLE	hDevice,		// 设备对象句柄
		LONG	lAddr,			// 首通道地址
		PLONG	lpPowerOnVal,	// 上电值
		LONG	lFirstChannel,	// A0首通道号
		LONG	lLastChannel);	// A0末通道号

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOSetPowerOnValue_Addr(	// 设置DA上电值
		HANDLE	hDevice,		// 设备对象句柄
		LONG	lAddr,			// 首通道地址
		LONG	lPowerOnVal[],	// 上电值
		LONG	lFirstChannel,	// A0首通道号
		LONG	lLastChannel);	// A0末通道号

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOGetSafeValue_Addr(	// 获得DA安全值
		HANDLE	hDevice,		// 设备对象句柄
		LONG	lAddr,			// 首通道地址
		PLONG	lpSafeVal,		// 安全值
		LONG	lFirstChannel,	// A0首通道号
		LONG	lLastChannel);	// A0末通道号

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOSetSafeValue_Addr(	// 设置DA安全值
		HANDLE	hDevice,		// 设备对象句柄
		LONG	lAddr,			// 首通道地址
		LONG	lSafeVal[],		// 安全值
		LONG	lFirstChannel,	// A0首通道号
		LONG	lLastChannel);	// A0末通道号

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOGetSlope_Addr(		// 读模拟量输出斜率
		HANDLE	hDevice,		// 设备对象句柄
		LONG	lAddr,			// 首通道地址
		PLONG	lpSlopeType,	// 输出斜率类型
		LONG	lFirstChannel,	// A0首通道号
		LONG	lLastChannel);	// A0末通道号

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOSetSlope_Addr(		// 修改模拟量输出斜率
		HANDLE	hDevice,		// 设备对象句柄
		LONG	lAddr,			// 首通道地址
		LONG	lSlopeType[],		// 输出斜率类型
		LONG	lFirstChannel,	// A0首通道号
		LONG	lLastChannel);	// A0末通道号

	//################################### DI 函数 ####################################
	BOOL DEVAPI FAR PASCAL  DAME3000N_DISetMode(			// 设置DI模式状态
		HANDLE	 hDevice,			// 设备句柄
		LONG	 Mode[],			// 模式(0x01 普通DI量输入模式;0x02 低到高锁存;0x03 高到低锁存;0x4 计数工作模式;0x5 频率工作模式;)
		LONG lFirstChannel,			// 首通道号
		LONG lLastChannel);		// 末通道号

	BOOL DEVAPI FAR PASCAL DAME3000N_DIGetMode(			// 获取DI工作模式
		HANDLE	 hDevice,			// 设备句柄
		LONG pMode[],				// 模式，数组大小为设备支持的总通道数，返回的数据只更新了从lFirstChannel到lLastChannel通道内数据
		LONG lFirstChannel,			// 首通道号
		LONG lLastChannel);		// 末通道号

	BOOL DEVAPI FAR PASCAL  DAME3000N_DISetInvert(	// 设置DI反向逻辑
		HANDLE	 hDevice,			// 设备句柄
		BYTE	 bInversion[],		// 是否反向逻辑输入
		LONG     lFirstChannel,	// 首通道号
		LONG	 lLastChannel);	// 末通道号

	BOOL DEVAPI FAR PASCAL  DAME3000N_DIGetInvert(	// 获取DI反向逻辑
		HANDLE	 hDevice,			// 设备句柄
		BYTE	 bInversion[],		// 是否反向逻辑输入，数组大小为设备支持的总通道数，返回的数据只更新从lFirstChannel到lLastChannel通道内数据
		LONG     lFirstChannel,	// 首通道号
		LONG	 lLastChannel);	// 末通道号

	BOOL DEVAPI FAR PASCAL  DAME3000N_DIGetValue(				// 获得DI值
		HANDLE	 hDevice,			// 设备句柄
		BYTE	 byDIStatus[],		// DI状态，数组大小为设备支持的总通道数，返回的数据只更新从lFirstChannel到lLastChannel通道内数据
		LONG     lFirstChannel,	// 首通道号
		LONG	 lLastChannel);	// 末通道号

	BOOL DEVAPI FAR PASCAL DAME3000N_DISetEnableFilter(			// 滤波使能
		HANDLE	hDevice,			// 设备句柄
		BOOL	 bEnPulse,			// 滤波使能
		LONG	lChannel);			// 通道号

	BOOL DEVAPI FAR PASCAL DAME3000N_DIGetEnableFilter(		// 获取滤波使能
		HANDLE	hDevice,			// 设备句柄
		PBOOL	bEnPulse,			// 滤波使能
		LONG	lChannel);			// 通道号

	BOOL DEVAPI FAR PASCAL  DAME3000N_DISetPulseWidth(			// 设置滤波参数
		HANDLE	 hDevice,			// 设备句柄
		ULONG	 lLowWidth[],		// 低电平最小宽度
		ULONG	 lHighWidth[],		// 高信号最小宽度
		LONG     lFirstChannel,	// 首通道号
		LONG	 lLastChannel);	// 末通道号

	BOOL DEVAPI FAR PASCAL  DAME3000N_DIGetPulseWidth(			// 获取滤波参数
		HANDLE	 hDevice,			// 设备句柄
		ULONG	 lLowWidth[],		// 低电平最小宽度
		ULONG	 lHighWidth[],		// 高信号最小宽度
		LONG     lFirstChannel,	// 首通道号
		LONG	 lLastChannel);	// 末通道号

	BOOL DEVAPI FAR PASCAL  DAME3000N_DIEnablePoweroffSaveforCNT(	// 使能(禁用)断电保存计数器值
		HANDLE	 hDevice,				// 设备句柄
		BOOL     bEnPowSave,			// 断电保存使能 1=使能 0=禁用
		LONG	 Channel);			// 通道号

	BOOL DEVAPI FAR PASCAL  DAME3000N_DIGetEnablePoweroffSaveforCNT(	// 获取断电保存计数器值使能状态
		HANDLE	hDevice,					// 设备句柄
		PBOOL	bEnPowSave,					// 断电保存使能
		LONG	Channel);				// 通道号

	BOOL DEVAPI FAR PASCAL DAME3000N_DISetCNTInitialValue(		// 设置计数初值
		HANDLE	hDevice,			// 设备句柄
		ULONG	lInitialValue[],	// 计数器初值
		LONG	lFirstChannel,		// 首通道号
		LONG	lLastChannel);		// 末通道号

	BOOL DEVAPI FAR PASCAL  DAME3000N_DIGetCNTorFreqValue(		// 获得计数值(频率值)
		HANDLE	 hDevice,			// 设备句柄
		ULONG	 lCurrentVal[],		// 当前值（计数值或频率值，具体数值含义依据当前DI工作模式定义）
		LONG     lFirstChannel,	// 首通道号
		LONG	 lLastChannel);	// 末通道号

	BOOL DEVAPI FAR PASCAL  DAME3000N_DIGetCNTOverFlg(			// 获得计数器溢出标志
		HANDLE	 hDevice,			// 设备句柄
		BYTE	 bOverFlg[],		// 溢出标志（0x01 超出计数值不清除  0x00 超出计数值清除）
		LONG     lFirstChannel,	// 首通道号
		LONG	 lLastChannel);	// 末通道号

	BOOL DEVAPI FAR PASCAL DAME3000N_DIClearCNTOverFlg(		// 清除计数器溢出标志
		HANDLE hDevice,				// 设备句柄
		LONG	lFirstChannel,	// 首通道号
		LONG	lLastChannel);	// 末通道号

	BOOL DEVAPI FAR PASCAL DAME3000N_DISetStartCNT(			// 设置计数器开始或停止
		HANDLE	 hDevice,			// 设备句柄
		BYTE bDICNTSts[],			// 计数器状态 0-停止 1-启动
		LONG lFirstChannel,		// 首通道号
		LONG lLastChannel);		// 末通道号

	BOOL DEVAPI FAR PASCAL DAME3000N_DIGetStartCNT(			// 获取计数器开始或停止状态
		HANDLE	 hDevice,			// 设备句柄
		BYTE bDICNTSts[],			// 计数器状态，数组大小为设备支持的总通道数 0-停止 1-启动
		LONG lFirstChannel,		// 首通道号
		LONG lLastChannel);		// 末通道号

	BOOL DEVAPI FAR PASCAL  DAME3000N_DIClearCNTValue(			// 清除计数值
		HANDLE	 hDevice,			// 设备句柄
		LONG	 lChannel);		// 通道号

	BOOL DEVAPI FAR PASCAL  DAME3000N_DIGetLatchStatus(			// 获得DI锁存状态(DAM3201A)
		HANDLE	 hDevice,			// 设备句柄
		BYTE	 byLowLatchSts[],	// 下降沿锁存状态，数组大小为设备支持的总通道数
		LONG     lFirstChannel,	// 首通道号
		LONG	 lLastChannel);	// 末通道号

	BOOL DEVAPI FAR PASCAL DAME3000N_DIClearLatchStatus(			// 清除锁存状态
		HANDLE hDevice,				// 设备句柄
		LONG lChannel);				// 通道号

	//################################### DO 函数 ####################################
	BOOL DEVAPI FAR PASCAL  DAME3000N_DOSetMode(				// 设置DO模式状态
		HANDLE	hDevice,			// 设备句柄
		LONG	Mode[],				// 模式0x01直接输出模式 0x02低到高延时输出 0x03高到低延时输出 0x04 脉冲连续输出 0x05-脉冲固定输出
		LONG	lFirstChannel,	// 首通道号
		LONG	lLastChannel);	// 末通道号

	BOOL DEVAPI FAR PASCAL DAME3000N_DOGetMode(				// 获取DO模式
		HANDLE	hDevice,			// 设备句柄
		LONG	Mode[],				// 模式，数组大小为设备支持的总通道数，返回的数据只更新从lFirstChannel到lLastChannel通道内数据，0x01直接输出模式 0x02低到高延时输出 0x03高到低延时输出 0x04 脉冲连续输出 0x05-脉冲固定输出
		LONG	lFirstChannel,	// 首通道号
		LONG	lLastChannel);	// 末通道号

	BOOL DEVAPI FAR PASCAL  DAME3000N_DOGetValue(				// 获得当前数字量输出
		HANDLE	 hDevice,			// 设备句柄
		BYTE     byDOSts[],			// DO状态，数组大小为设备支持的总通道数，返回的数据只更新从lFirstChannel到lLastChannel通道内数据
		LONG     lFirstChannel,	// 首通道号
		LONG	 lLastChannel);	// 末通道号

	BOOL DEVAPI FAR PASCAL  DAME3000N_DOSetValue(				// 设置DO输出值(DAME3021A)
		HANDLE	 hDevice,			// 设备句柄
		BYTE	 byDOSts[],			// 设置DO输出值
		LONG     lFirstChannel,	// 首通道号
		LONG	 lLastChannel);	// 末通道号

	BOOL DEVAPI FAR PASCAL DAME3000N_DOSetValue_Line(			// 设置DO输出（单通道设置）
		HANDLE	hDevice,			// 设备句柄
		BOOL	bDOSts,				// DO状态
		LONG    lChannel);			// 通道号

	BOOL DEVAPI FAR PASCAL DAME3000N_DOSetPowerOnValue(	// 设置DO上电值
		HANDLE	hDevice,		// 设备句柄
		BYTE	bDOSts[],		// 上电值
		LONG	lFirstChannel,	// 首通道号
		LONG	lLastChannel);	// 末通道号

	BOOL DEVAPI FAR PASCAL DAME3000N_DOGetPowerOnValue(		// 获取DO上电状态
		HANDLE	hDevice,		// 设备句柄
		BYTE	bDOSts[],		// 上电值，数组大小为设备支持的总通道数，返回的数据只更新从lFirstChannel到lLastChannel通道内数据
		LONG	lFirstChannel,	// 首通道号
		LONG	lLastChannel);	// 末通道号

	BOOL DEVAPI FAR PASCAL DAME3000N_DOSetSafeValue(		// 设置DO安全状态
		HANDLE	hDevice,		// 设备句柄
		BYTE	bDOSts[],		// 安全值
		LONG lFirstChannel,		// 首通道号
		LONG	lLastChannel);	// 末通道号

	BOOL DEVAPI FAR PASCAL DAME3000N_DOGetSafeValue(		// 获取DO安全状态
		HANDLE	hDevice,		// 设备句柄
		BYTE	bDOSts[],		// DO安全状态，数组大小为设置支持的总通道数，返回的数据只更新从lFirstChannel到lLastChannel通道内数据
		LONG	lFirstChannel,	// 首通道号
		LONG lLastChannel);		// 末通道号

	BOOL DEVAPI FAR PASCAL  DAME3000N_3021N_DOStartPulseOutput(		// 开始脉冲输出
		HANDLE	 hDevice,			// 设备句柄
		LONG	 lChannel);		// 通道号

	BOOL DEVAPI FAR PASCAL  DAME3000N_3021N_DOStopPulseOutput(		// 停止脉冲输出
		HANDLE	 hDevice,			// 设备句柄
		LONG	 lChannel);		// 通道号

	BOOL DEVAPI FAR PASCAL DAME3000N_3021N_DOGetPulseOutputStatus(	// 读取脉冲输出启动停止状态
		HANDLE hDevice,				// 设备句柄
		BYTE bStatus[],				// 返回的状态，数组大小为设备支持的通道总数，返回的数据更新从lFirstChannel到lLastChannel通道内数据
		LONG lFirstChannel,		// 首通道号
		LONG lLastChannel);		// 末通道号

	BOOL DEVAPI FAR PASCAL  DAME3000N_DOSetPulseWidth(		// 设置DO脉冲输出占空比
		HANDLE	 hDevice,			// 设备句柄
		ULONG	 lLowWidth[],		// 脉冲输出低电平宽度
		ULONG	 lHighWidth[],		// 脉冲输出高电平宽度
		LONG     lFirstChannel,	// 首通道号
		LONG	 lLastChannel);	// 末通道号

	BOOL DEVAPI FAR PASCAL  DAME3000N_DOGetPulseWidth(		// 获取DO脉冲输出占空比
		HANDLE	 hDevice,			// 设备句柄
		ULONG	 lLowWidth[],		// 脉冲输出低电平宽度，数组大小为设备支持的总通道数，返回的数据只更新从lFirstChannel到lLastChannel通道内数据
		ULONG	 lHighWidth[],		// 脉冲输出高电平宽度，数组大小为设备支持的总通道数，返回的数据只更新从lFirstChannel到lLastChannel通道内数据
		LONG	lFirstChannel,	// 首通道号
		LONG	 lLastChannel);	// 末通道号

	BOOL DEVAPI FAR PASCAL DAME3000N_3021N_DOSetPulseAddCount(		// 设置续加脉冲数量
		HANDLE	hDevice,			// 设备句柄
		LONG	PuAddNum[],			// 续加脉冲个数
		LONG     lFirstChannel,	// 首通道号
		LONG	 lLastChannel);	// 末通道号

	BOOL DEVAPI FAR PASCAL DAME3000N_3021N_GetDOPulseAddCount(		// 获取续加的脉冲数量
		HANDLE	hDevice,			// 设备句柄
		LONG	PuAddNum[],			// 续加脉冲个数，数组大小为设备支持的通道总数，返回的数据只更新从lFirstChannel到lLastChannel通道内数据
		LONG     lFirstChannel,	// 首通道号
		LONG	 lLastChannel);	// 末通道号

	BOOL DEVAPI FAR PASCAL DAME3000N_DOSetPulseOutputAddCount(  // 续加脉冲数量
		HANDLE	hDevice,		// 设备句柄
		ULONG	PuAddNum[],		// 续加脉冲个数
		LONG   lFirstChannel,		// 首通道号
		LONG	lLastChannel);		// 末通道号

	BOOL DEVAPI FAR PASCAL DAME3000N_DOGetPulseOutputAddCount(  // 续加脉冲数量
		HANDLE	hDevice,		// 设备句柄
		ULONG	PuAddNum[],		// 续加脉冲个数
		LONG   lFirstChannel,		// 首通道号
		LONG	lLastChannel);		// 末通道号

	BOOL DEVAPI FAR PASCAL DAME3000N_DOSetPulseOutputCount(	// DO0固定脉冲输出(0x0时，连续脉冲输出，其他值时，是配置脉冲输出值)
		HANDLE	hDevice,			// 设备句柄
		ULONG	PuOutPutNum[],		// 脉冲个数
		LONG     lFirstChannel,	// 首通道号
		LONG	 lLastChannel);	// 末通道号

	BOOL DEVAPI FAR PASCAL DAME3000N_DOGetPulseOutputCountLeft(	// DO0固定脉冲输出(0x0时，连续脉冲输出，其他值时，是脉冲输出剩余脉冲个数)
		HANDLE	hDevice,			// 设备句柄
		ULONG	PuOutPutNum[],		// 脉冲输出剩余个数，数组大小为设备支持的通道数，返回的数据只更新从lFirstChannel到lLastChannel通道内数据
		LONG     lFirstChannel,	// 首通道号
		LONG	 lLastChannel);	// 末通道号

// 	BOOL DEVAPI FAR PASCAL DAME3000N_GetDevicePulseOutputLeftNum(	//获取脉冲输出剩余个数
// 									HANDLE	hDevice,				// 设备句柄
// 									ULONG	lOutputLeftNum[],		// 各通道剩余脉冲个数，数组大小为设备支持的通道总数，返回的数据只更新从lFirstChannel到lLastChannel通道内数据
// 									LONG	lFirstChannel,			// 首通道号
// 									LONG	lLastChannel);			// 末通道号

	BOOL DEVAPI FAR PASCAL  DAME3000N_3021N_DOSetDelayTime(				// 设置DI高低变化延时时间
		HANDLE	 hDevice,				// 设备句柄
		WORD	 DelayTime[],			// 高到低输出延迟时间
		LONG     lFirstChannel,		// 首通道号
		LONG	 lLastChannel);		// 末通道号

	BOOL DEVAPI FAR PASCAL DAME3000N_3021N_DOGetDelayTime(				// 获取延时时间
		HANDLE	 hDevice,				// 设备句柄
		WORD	 DelayTime[],			// 高到低输出延迟时间，数组大小为设备支持的通道数，返回的数据更新的是从lFirstChannel到lLastChannel通道内数据
		LONG     lFirstChannel,		// 首通道号
		LONG	 lLastChannel);		// 末通道号

	// 设置DO低到高输出延迟时间
	BOOL DEVAPI FAR PASCAL DAME3000N_DOSetLowToHighTime(		// 设置延迟时间(DO由低到高)
		HANDLE	hDevice,				// 设备句柄
		ULONG	DelayTime[],			// 低到高输出延迟时间
		LONG	lFirstChannel,			// 首通道号
		LONG	lLastChannel);			// 末通道号


	// 获取DO低到高输出延迟时间
	BOOL DEVAPI FAR PASCAL DAME3000N_DOGetLowToHighTime(	// 获取延迟时间(DO由低到高)
		HANDLE	hDevice,			// 设备句柄
		ULONG	DelayTime[],		// 低到高输出延迟时间，数组大小为设备支持的通道总数，返回的数据更新的是从lFirstChannel到lLastChannel通道内数据
		LONG	lFirstChannel,		// 首通道号
		LONG	lLastChannel);		// 末通道号

	// 设置DO输出高到低延迟时间
	BOOL DEVAPI FAR PASCAL DAME3000N_DOSetHighToLowTime(	// 设置延迟时间(DO由高到低)
		HANDLE	hDevice,			// 设备句柄
		ULONG	DelayTime[],		// 高到低输出延迟时间
		LONG	lFirstChannel,		// 首通道号
		LONG	lLastChannel);		// 末通道号

	// 获取DO高到低输出延迟时间
	BOOL DEVAPI FAR PASCAL DAME3000N_DOGetHighToLowTime(	// 获取延迟时间(DO由高到低)
		HANDLE	hDevice,			// 设备句柄
		ULONG	DelayTime[],		// 高到低输出延迟时间，数组大小为设备支持的通道总数，返回的数据更新的是从lFirstChannel到lLastChannel通道内数据
		LONG	lFirstChannel,		// 首通道号
		LONG	lLastChannel);		// 末通道号

	// 获取DO源状态 DAME3022N(源点型DIO)
	BOOL DEVAPI FAR PASCAL DAME3000N_DOGetSourceStatus(			// 获取DO源状态
		HANDLE	hDevice,			// 设备句柄
		LONG	lSourceCh,			// DO Source 通道号 （DAME3022N：DO0~DO3 SourceChannel=0; DO4~DO5 SourceChannel=1）
		LONG*	lSourceSts);		// DO Source 状态 0=Failed 1=Normal


	//#############################  计数器  ###################################


	//#############################  通用功能  ###################################
	BOOL DEVAPI FAR PASCAL DAME3000N_AdjustTemperature(	// 温度校准
		HANDLE hDevice,			// 设备句柄
		BYTE lTempValue);		// 温度值

	BOOL DEVAPI FAR PASCAL DAME3000N_ReadTemperature(		// 读取环境温度
		HANDLE	hDevice,		// 设备句柄
		double*	lTempValue);	// 温度值

	BOOL DEVAPI FAR PASCAL DAME3000N_SetUDPSearchPort(		// 设置UDP搜索端口号
		HANDLE hDevice,			// 设备句柄
		SHORT lPortNum);		// 端口号

	BOOL DEVAPI FAR PASCAL DAME3000N_GetUDPSearchPort(		// 读取UDP搜索端口号
		HANDLE hDevice,			// 设备句柄
		PUSHORT pPortNum);		// 端口号

	BOOL DEVAPI FAR PASCAL DAME3000N_SetTCPConnectControl(	// 设置TCP连接空闲超时控制
		HANDLE hDevice,			// 设备句柄
		USHORT lEnable);		// 是否使能 1-使能(必须为1)

	BOOL DEVAPI FAR PASCAL DAME3000N_GetTCPConnectControl(	// 读取TCP连接空闲超时控制使能状态
		HANDLE hDevice,			// 设备句柄
		PUSHORT pEnable);		// 是否使能 0-除能 1-使能

	BOOL DEVAPI FAR PASCAL DAME3000N_SetTCPConnectTime(	// 设置TCP连接空闲超时时间
		HANDLE hDevice,			// 设备句柄
		USHORT lTime);			// 超时时间

	BOOL DEVAPI FAR PASCAL DAME3000N_GetTCPConnectTime(	// 读取TCP连接空闲超时时间
		HANDLE hDevice,			// 设备句柄
		PUSHORT pTime);			// 端口号

	BOOL DEVAPI FAR PASCAL DAME3000N_RestartBoard(			// 设置是否重新启动寄存器
		HANDLE hDevice,			// 设备句柄
		USHORT lRestart);		// 0-不启动 1-重新启动

	BOOL DEVAPI FAR PASCAL DAME3000N_Reset(			// 设置是否恢复出厂设置
		HANDLE hDevice,		// 设备句柄
		USHORT lReSet);		// 0-不恢复 1-恢复

	BOOL DEVAPI FAR PASCAL DAME3000N_DevCalibration(	// 设置是否校准
		HANDLE hDevice,		// 设备句柄
		USHORT Calibration);// 0-不校准 1-校准

	BOOL DEVAPI FAR PASCAL DAME3000N_SetIPMACFilter(		// 设置IP/MAC过滤
		HANDLE hDevice,			// 设备句柄
		USHORT lFilterType,		// 过滤模式 0-无过滤模式 1-IP过滤 2-MAC过滤
		USHORT lIPEnableNum,	// IP使能序号 bit7 ~bit0：0x01表示0号IP设置，0x03表示0号和1号IP设置，0xFF表示8个全部使能
		USHORT lMACEnableNum,	// MAC使能序号 bit7 ~bit0：0x01表示0号IP设置，0x03表示0号和1号IP设置，0xFF表示8个全部使能
		BYTE bIPData[],			// 需要设置的IP数据
		BYTE bMACData[]);		// 需要设置的MAC数据

	BOOL DEVAPI FAR PASCAL DAME3000N_GetIPMACFilter(		// 读取IP/MAC过滤
		HANDLE hDevice,			// 设备句柄
		USHORT* lFilterType,	// 过滤模式 0-无过滤模式 1-IP过滤 2-MAC过滤
		USHORT* lIPEnableNum,	// IP使能序号 bit7 ~bit0：0x01表示0号IP设置，0x03表示0号和1号IP设置，0xFF表示8个全部使能
		USHORT* lMACEnableNum,	// MAC使能序号 bit7 ~bit0：0x01表示0号IP设置，0x03表示0号和1号IP设置，0xFF表示8个全部使能
		BYTE bIPData[],			// 读取的IP数据
		BYTE bMACData[]);		// 读取的MAC数据

	BOOL DEVAPI FAR PASCAL DAME3000N_SetSendToIP(			// 设置定时发送数据参数
		HANDLE hDevice,			// 设备句柄
		USHORT lEnableNum,		// IP使能序号 bit7 ~bit0：0x01表示0号IP设置，0x03表示0号和1号IP设置，0xFF表示8个全部使能
		BYTE bIPData[],			// 需要设置的IP数据
		USHORT lTime[]);		// 需要设置的轮询时间

	BOOL DEVAPI FAR PASCAL DAME3000N_GetSendToIP(			// 读取定时发送数据参数
		HANDLE hDevice,			// 设备句柄
		USHORT* pEnableNum,		// IP使能序号 bit7 ~bit0：0x01表示0号IP设置，0x03表示0号和1号IP设置，0xFF表示8个全部使能
		BYTE bIPData[],			// 读取的IP数据
		USHORT pTime[]);		// 读取的轮询时间

	BOOL DEVAPI FAR PASCAL DAME3000N_PasswordOperation(	// 设置及判断密码是否正确
		HANDLE hDevice,			// 设备句柄
		WORD lOptionType,		// 操作类型，1-登录 2-更改密码 回复的时候3-登录失败
		BYTE bOldPassword[],	// 旧密码
		BYTE bNewPassword[]);	// 新密码

	//################################# 看门狗 函数 ##################################
	BOOL DEVAPI FAR PASCAL  DAME3000N_HostIsOK(		// Host Is OK
		HANDLE	 hDevice);	// 设备对象句柄

	BOOL DEVAPI FAR PASCAL  DAME3000N_EnableWatchdog(	// 使能看门狗
		HANDLE	 hDevice);	// 设备对象句柄

	BOOL DEVAPI FAR PASCAL  DAME3000N_CloseWatchdog(	// 关闭看门狗
		HANDLE	 hDevice);	// 设备对象句柄

	BOOL DEVAPI FAR PASCAL  DAME3000N_GetWatchdogSts(		// 获得看门狗状态
		HANDLE	 hDevice,		// 设备对象句柄
		LONG	 lpDogStatus[]);// 看门狗状态,lpDogStatus[0]-看门狗是否使能,lpDogStatus[1]-看门狗状态,lpDogStatus[2]-看门狗是否复位

	BOOL DEVAPI FAR PASCAL  DAME3000N_ResetWatchdog(		// 复位看门狗
		HANDLE	 hDevice);		// 设备对象句柄

	BOOL DEVAPI FAR PASCAL  DAME3000N_SetWatchdogTimeoutVal(	// 设置看门狗超时时间
		HANDLE	 hDevice,			// 设备对象句柄
		LONG	 lTimeOutVal);		// 超时时间

	BOOL DEVAPI FAR PASCAL DAME3000N_GetWatchdogTimeout(		// 获取看门狗超时时间
		HANDLE hDevice,				// 设备对象句柄
		PLONG pTimeOut);			// 超时时间

	//#########################################################################################
	//********************************* 直接命令行 *********************************
	int	DEVAPI	FAR	PASCAL	DAME3000N_WriteDeviceChar(
		HANDLE	 hDevice, 		// 设备句柄
		char*	 szwriteBuffer,	// 写入的数据
		LONG	 llength);		// 直接写设备

	int	DEVAPI	FAR	PASCAL	DAME3000N_ReadDeviceChar(
		HANDLE   hDevice,		// 设备句柄
		char*	 szreadBuffer,	// 读取的数据
		LONG	 llength);		// 直接读设备

	//#########################################################################################
	//********************************* 通用命令 *************************************
	BOOL DEVAPI FAR PASCAL ReadCoils(						// 读继电器状态
		HANDLE	 hDevice,		// 设备句柄
		int		 addr,			// 功能地址
		int		 len,			// 读取长度
		BYTE	 bCoilsFlag[]);	// 读取的继电器状态

	BOOL DEVAPI FAR PASCAL ReadDiscretes(					// 读开关量输入
		HANDLE	 hDevice,		// 设备句柄
		int		 addr,			// 功能地址
		int		 len,			// 读取长度
		BYTE	 bDIState[]);	// 读取的DI状态

	BOOL DEVAPI FAR PASCAL ReadMultiRegs(					// 读保持寄存器
		HANDLE	 hDevice,  		// 设备句柄
		int		 addr, 			// 功能地址
		int		 len, 			// 读取长度
		BYTE	 buf[]);		// 读取的数据

	BOOL DEVAPI FAR PASCAL ReadInputRegs(					// 读输入寄存器
		HANDLE	 hDevice,  		// 设备句柄
		int		 addr, 			// 功能地址
		int		 len, 			// 读取长度
		BYTE	 buf[]);		// 读取的数据

	BOOL DEVAPI FAR PASCAL WriteCoil(						// 设置单个继电器
		HANDLE	 hDevice,  		// 设备句柄
		int		 addr, 			// 功能地址
		BYTE	 status); 		// 写入的数据

	BOOL DEVAPI FAR PASCAL WriteSingleReg(					// 设置单个保持寄存器
		HANDLE	 hDevice,  		// 设备句柄
		int		 addr, 			// 功能地址
		short	 val);  		// 写入的数据

	BOOL DEVAPI FAR PASCAL ForceMultiCoils(					// 设置多个继电器
		HANDLE	 hDevice,  		// 设备句柄
		int		 addr, 			// 功能地址
		int		 len, 			// 读取长度
		BYTE	 bDOState[]);  	// 写入的数据

	BOOL DEVAPI FAR PASCAL WriteMultiRegs(					// 设置多个保持寄存器
		HANDLE	 hDevice,  		// 设备句柄
		int		 addr, 			// 功能地址
		int		 len, 			// 读取长度
		BYTE	 buf[]);  		// 写入的数据

	BOOL DEVAPI FAR PASCAL ReadRegFile(						// 读取文件记录
		HANDLE	 hDevice,  		// 设备句柄
		int		 index,			// 文件索引号
		int		 addr, 			// 功能地址
		int		 len, 			// 读取长度
		BYTE	 buf[]);  		// 读取的数据

	BOOL DEVAPI FAR PASCAL WriteRegFile(					// 写文件记录
		HANDLE	 hDevice,  		// 设备句柄
		int		 index, 		// 文件索引号
		int		 addr, 			// 功能地址
		int		 len,			// 读取长度
		BYTE	 buf[]);  		// 写入的数据

#ifdef __cplusplus
}
#endif
#endif

/*
// 自动包含驱动函数导入库
#ifndef _DAME3000N_DRIVER_
#ifndef _WIN64
#pragma comment(lib, "DAME3000N_32.lib")
#else
#pragma comment(lib, "DAME3000N_64.lib")
#endif // _WIN64
#endif // _DAME3000N_DRIVER_
*/