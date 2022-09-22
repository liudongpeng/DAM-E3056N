#ifndef  __DAME3000N_LIB__
#define __DAME3000N_LIB__

#include <windows.h>

// ģ������������(��ѹ����) ��DAME3000N_SetModeAD�����е�nADMode����ʹ��
#define DAME3000N_VOLT_N15_P15					0x01	//  -15��+15mV
#define DAME3000N_VOLT_N50_P50					0x02	//  -50��+50mV
#define DAME3000N_VOLT_N100_P100				0x03	// -100��+100mV
#define DAME3000N_VOLT_N150_P150				0x04	// -150��+150mV
#define DAME3000N_VOLT_N500_P500				0x05	// -500��+500mV
#define DAME3000N_VOLT_N1_P1					0x06	//   -1��+1V
#define DAME3000N_VOLT_N25_P25					0x07	// -2.5��+2.5V
#define DAME3000N_VOLT_N5_P5					0x08	//   -5��+5V
#define DAME3000N_VOLT_N10_P10					0x09	//  -10��+10V
#define DAME3000N_VOLT_N0_P5					0x0D	//    0��+5V
#define DAME3000N_VOLT_N0_P10					0x0E	//    0��+10V
#define DAME3000N_VOLT_N0_P25					0x0F	//    0��+2.5V
#define DAME3000N_VOLT_P1_P5					0x82	//    1��+5.0V
// ģ������������(��������) ��DAME3000N_SetModeAD�����е�nADMode����ʹ��
#define DAME3000N_CUR_N0_P10					0x00	//   0��10mA
#define DAME3000N_CUR_N20_P20					0x0A	// -20��+20mA
#define DAME3000N_CUR_N0_P20					0x0B	//   0��20mA
#define DAME3000N_CUR_P4_P20					0x0C	//   4��20mA
#define DAME3000N_CUR_N0_P22					0x80	//   0��22mA

// ģ������������(�ȵ�������) ��DAME3000N_SetModeAD�����е�nADMode����ʹ��
#define DAME3000N_RTD_CU50						0x40	// Cu50�ȵ���        -50�桫150��
#define DAME3000N_RTD_CU100					0x41	// Cu100�ȵ���       -50�桫150��
#define DAME3000N_RTD_PT100_385_N200_P850		0x20	// Pt100(385)�ȵ��� -200�桫850��
#define DAME3000N_RTD_PT100_385_N100_P100		0x21	// Pt100(385)�ȵ��� -100�桫100��
#define DAME3000N_RTD_PT100_385_N0_P100		0x22	// Pt100(385)�ȵ���    0�桫100��
#define DAME3000N_RTD_PT100_385_N0_P200		0x23	// Pt100(385)�ȵ���    0�桫200��
#define DAME3000N_RTD_PT100_385_N0_P600		0x24	// Pt100(385)�ȵ���    0�桫600��
#define DAME3000N_RTD_PT100_3916_N200_P850		0x25	// Pt100(3916)�ȵ���-200�桫850��
#define DAME3000N_RTD_PT100_3916_N100_P100		0x26	// Pt100(3916)�ȵ���-100�桫100��
#define DAME3000N_RTD_PT100_3916_N0_P100		0x27	// Pt100(3916)�ȵ���   0�桫100��
#define DAME3000N_RTD_PT100_3916_N0_P200		0x28	// Pt100(3916)�ȵ���   0�桫200��
#define DAME3000N_RTD_PT100_3916_N0_P600		0x29	// Pt100(3916)�ȵ���   0�桫600��
#define DAME3000N_RTD_PT1000					0x30	// Pt1000�ȵ���     -200�桫850��
#define DAME3000N_RTD_BA1						0x42	// BA1�ȵ���        -200�桫650��
#define DAME3000N_RTD_BA2						0x43	// BA2�ȵ���        -200�桫650��
#define DAME3000N_RTD_G53						0x44	// G53�ȵ���         -50�桫150��
#define DAME3000N_RTD_Ni50						0x45	// Ni50�ȵ���        100�桫
#define DAME3000N_RTD_Ni508					0x46	// Ni508�ȵ���         0�桫100��
#define DAME3000N_RTD_Ni1000					0x47	// Ni1000�ȵ���      -60�桫160��

// ģ������������(�ȵ�ż����) ��DAME3000N_SetModeAD�����е�nADMode����ʹ��
#define DAME3000N_THERMOCOUPLE_J					0x10	// J���ȵ�ż			0�桫1200��
#define DAME3000N_THERMOCOUPLE_K					0x11	// K���ȵ�ż			0�桫1300��
#define DAME3000N_THERMOCOUPLE_T					0x12	// T���ȵ�ż			-200�桫400��
#define DAME3000N_THERMOCOUPLE_E					0x13	// E���ȵ�ż			0�桫1000��
#define DAME3000N_THERMOCOUPLE_R					0x14	// R���ȵ�ż		  500�桫1700��
#define DAME3000N_THERMOCOUPLE_S					0x15	// S���ȵ�ż		  500�桫1768��
#define DAME3000N_THERMOCOUPLE_B					0x16	// B���ȵ�ż		  500�桫1800��
#define DAME3000N_THERMOCOUPLE_N					0x17	// N���ȵ�ż			0�桫1300��
#define DAME3000N_THERMOCOUPLE_C					0x18	// C���ȵ�ż			0�桫2090��

// �������������ʹ��
#define DAME3000N_OUTPUT_TYPE_DIGIT				0		// ���������
#define DAME3000N_OUTPUT_TYPE_PULSE				1		// �������

// �������������� ��DAME3000N_SetModeCNT�����е�lCNTMode����ʹ��
#define	DAME3000N_DI_MODE_CNT_RISING				1		// �����ؼ���
#define	DAME3000N_DI_MODE_CNT_FALLING				0		// �½��ؼ���

// ���������Դ״̬ ��DAME3000N_DOGetSourceStatus����lSourceSts����ʹ��
#define DAME3000N_DO_SOURCE_STATUS_FAILED			0	// ״̬�쳣
#define DAME3000N_DO_SOURCE_STATUS_NORMAL			1	// ״̬����



// DIģ��Ĺ���ģʽ ��DAME3000N_DISetMode(DAME3000N_DIGetMode)�����е�lMode����ʹ��
#define DAME3000N_DIMODE_DI					0x01 // ��ͨDI������ģʽ
#define DAME3000N_DIMODE_LATCH_LOWTOHIGH		0x02 // �͵�������ģʽ
#define DAME3000N_DIMODE_LATCH_HIGHTOLOW		0x03 // �͵�������ģʽ
#define DAME3000N_DIMODE_CNT					0x04 // ��������ģʽ
#define DAME3000N_DIMODE_FREQ					0x05 // Ƶ�ʹ���ģʽ

// DOģ��Ĺ���ģʽ ��DAME3000N_DOSetMode(DAME3000N_DOGetMode)�����е�lMode����ʹ��
#define DAME3000N_DOMODE_DO				1	// �������
#define DAME3000N_DOMODE_LOWTOHIGH		2	// �͵�����ʱ���
#define DAME3000N_DOMODE_HIGHTOLOW		3	// �ߵ�����ʱ���
#define DAME3000N_DOMODE_PULSE			4	// �������


// �豸������Ϣ
typedef struct _DEVICE_NET_INFO
{
	char    szIP[16];					// IP��ַ, // IP��ַ, "192.168.2.70"
	char	SubnetMask[16];				// ��������, "255.255.255.255"
	char	Gateway[16];				// ����, "192.168.2.1"
	char	MAC[20];					// ���������ַ,  "00-01-02-03-04-05",�û�һ�㲻���޸�
	LONG	lTCPPort;					// TCP�˿ں�
	LONG    lHTTPPort;					// HTTP�˿ں�
	LONG	lUDPPort;					// UDP�˿ں�
	LONG	lMode;						// ����ģʽ(0: ��̬ģʽ  1: DHCP��̬ģʽ)
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
	//####################### ��ѯģ���豸�Ƿ�����(DHCP) #######################
	int  DEVAPI FAR PASCAL  DAME3000N_SearchDevice(
		char	szIP[],			// �豸IP�б�
		char	szName[],		// �豸����
		char	szMAC[],		// MAC��ַ
		LONG	lPort,			// UDP�˿�
		PLONG	plCount,		// �豸����
		LONG	lSendTimeout,	// �������ݵĳ�ʱ���
		LONG	lRcvTimeout);	// �������ݵĳ�ʱ���

	//####################### �豸��������� #################################
	HANDLE  DEVAPI FAR PASCAL  DAME3000N_CreateDevice(		// �����豸
		char	szIP[],			// �豸IP(��"192.168.1.2")
		LONG	lPort,			// TCP�˿�
		LONG	lSendTimeout,	// �������ݵĳ�ʱ���
		LONG	lRcvTimeout);	// �������ݵĳ�ʱ���

	BOOL DEVAPI	FAR	PASCAL  DAME3000N_ReleaseDevice(HANDLE hDevice);	// �ͷ��豸����

	BOOL DEVAPI FAR PASCAL  DAME3000N_GetDeviceVersion(		// ȡ���豸�汾��Ϣ
		HANDLE	hDevice,			// �豸���
		char	szVersion[]);		// �豸�汾��Ϣ

	BOOL DEVAPI FAR PASCAL  DAME3000N_GetNetworkConfig(		// ����豸������������Ϣ
		HANDLE	 hDevice,			// �豸���
		PDEVICE_NET_INFO pNetInfo);	// ����������Ϣ

	BOOL DEVAPI FAR PASCAL  DAME3000N_GetNetworkConfigEx(	// ����豸������������Ϣ
		HANDLE	hDevice,		// �豸���
		char	szIP[16],		// IP��ַ, IP��ַ, "192.168.2.70"
		char	SubnetMask[16],	// ��������, "255.255.255.255"
		char	Gateway[16],	// ����, "192.168.2.1"
		char	MAC[20],		// ���������ַ,  "00-01-02-03-04-05",�û�һ�㲻���޸�
		PLONG	lpTCPPort,		// TCP�˿ں�
		PLONG	lpHTTPPort,		// HTTP�˿ں�
		PLONG	lpUDPPort,		// UDP�˿ں�
		PLONG	lpMode);		// ����ģʽ(0: ��̬ģʽ  1: DHCP��̬ģʽ)

	BOOL DEVAPI FAR PASCAL  DAME3000N_SetNetworkConfig(		// �����豸������������Ϣ
		HANDLE	 hDevice,			// �豸���
		PDEVICE_NET_INFO NetInfo);	// ����������Ϣ

	BOOL DEVAPI FAR PASCAL  DAME3000N_SetNetworkConfigEx(		// �����豸������������Ϣ
		HANDLE	hDevice,			// �豸���
		char	szIP[16],			// IP��ַ, // IP��ַ, "192.168.2.70"
		char	SubnetMask[16],		// ��������, "255.255.255.255"
		char	Gateway[16],		// ����, "192.168.2.1"
		char	MAC[20],			// ���������ַ,  "00-01-02-03-04-05",�û�һ�㲻���޸�
		LONG	lTCPPort,			// TCP�˿ں�
		LONG	lHTTPPort,			// HTTP�˿ں�
		LONG	lUDPPort,			// UDP�˿ں�
		LONG	lMode);				// ����ģʽ(0: ��̬ģʽ  1: DHCP��̬ģʽ)

	BOOL DEVAPI FAR PASCAL DAME3000N_SetNetworkInfo(				// ��������IP-��������-���� �ɿ�����
		char	MAC[18],				// MAC��ַ
		char	szIP[16],				// IP��ַ "192.168.2.70"
		char	SubnetMask[16],			// �������� "255.255.255.255"
		char	Gateway[16],			// ���� "192.168.2.1"
		LONG	udpPort);				// UDP�˿ں�

	BOOL DEVAPI	FAR	PASCAL  DAME3000N_SaveIPAddress(char szIP[]);		// ����IP��ע���

	BOOL DEVAPI	FAR	PASCAL  DAME3000N_LoadIPAddress(char szIP[]);		// ����IP��Ӧ�ó���

	BOOL DEVAPI FAR PASCAL  DAME3000N_DeviceRestart(HANDLE hDevice);	// �豸����

	BOOL DEVAPI FAR PASCAL  DAME3000N_DeviceFacDefault(HANDLE hDevice);// �ָ�����

	BOOL DEVAPI FAR PASCAL DAME3000N_GetLastErrorCode(		// ��ȡ���һ��ͨ�Ŵ����룬windowsϵͳ����
		HANDLE	hDevice,
		LONG	lStsCode);

	//################################### AI ���� ####################################
	BOOL DEVAPI FAR PASCAL DAME3000N_AIReadData(			// ���ģ����ͨ������ֵ��������ƽ��ֵͨ����
		HANDLE hDevice,				// �豸���
		USHORT lAIValue[],			// ���ص�AI���ݣ�lAIValue[0]=ͨ��0���ݣ�lAIValue[1]=ͨ��1���ݣ�...��lAIValue[7]=ͨ��7���ݣ�ÿ�ζ�ȡ���´�lFirstChannel��lLastChannelͨ���ڵ�����
		LONG lFirstChannel,		// ��ͨ���� 0=ͨ��0,1=ͨ��1,...,7=ͨ��7
		LONG lLastChannel);		// ĩͨ���� 0=ͨ��0,1=ͨ��1,...,7=ͨ��7

	BOOL DEVAPI FAR PASCAL  DAME3000N_AIReadData_Ex(			// ���ģ��������ֵ������ƽ��ֵͨ����
		HANDLE	hDevice,			// �豸���
		USHORT	lAIValue[],			// ���ص�AI���ݣ�lAIValue��ά��Ϊ�豸֧�ֵ�ͨ������+1ά��lAIValue[0]=ƽ��ֵͨ�����ݣ�lAIValue[1]=ͨ��0���ݣ�lAIValue[2]=ͨ��2���ݣ�...��lAIValue[8]=ͨ��7���ݡ���������ƽ��ֵ�ʹ�lFirstChannel��lLastChannelͨ���ڵ����ݡ�
		LONG	lFirstChannel,	// ��ͨ���� 0=ͨ��0,1=ͨ��1,...,7=ͨ��7
		LONG	lLastChannel);	// ĩͨ���� 0=ͨ��0,1=ͨ��1,...,7=ͨ��7

	BOOL DEVAPI FAR PASCAL DAME3000N_AIReadData_Avg(		// ���ģ��������ƽ��ֵͨ������
		HANDLE	hDevice,			// �豸���
		USHORT*	wAIAverValue);		// ����AIƽ��ֵ

	BOOL DEVAPI FAR PASCAL DAME3000N_AISetEnableForAvg(		// ʹ��AI��ƽ��ֵ
		HANDLE	hDevice,			// �豸���
		LONG	lChannel,			// ͨ����	0=ͨ��0,1=ͨ��1,...,7=ͨ��7
		BYTE	lValue);			// �Ƿ�ʹ�� 0-��ʹ�� 1-ʹ��

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetEnableForAvg(		// ��ȡAIͨ��ƽ��ֵ�Ƿ�ʹ��
		HANDLE	hDevice,			// �豸���
		BYTE	lValue[],			// ʹ���������飬�����СΪ�豸֧�ֵ�ͨ�����������ص�����ֻ�����˴�lFirstChannel��lLastChannelͨ���ڵ����ݣ�1-ʹ�� 0-δʹ��
		LONG	lFirstChannel,		// ��ͨ���� 0=ͨ��0,1=ͨ��1,...,7=ͨ��7
		LONG	lLastChannel);		// ĩͨ���� 0=ͨ��0,1=ͨ��1,...,7=ͨ��7

	BOOL DEVAPI FAR PASCAL DAME3000N_AISetEnable(		// ʹ��AI�ɼ�ͨ��
		HANDLE hDevice,		// �豸���
		LONG lChannel,		// ͨ���� 0=ͨ��0,1=ͨ��1,...,7=ͨ��7
		BYTE lValue);		// �Ƿ�ʹ�� 0-��ʹ�� 1-ʹ��

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetEnable(		// ��ȡAIͨ���ɼ��Ƿ�ʹ��
		HANDLE hDevice,			// �豸���
		BYTE lValue[],			// ʹ���������飬�����СΪ�豸֧�ֵ���ͨ���������ص�����ֻ�����˴�lFirstChannel��lLastChannelͨ���ڵ����ݣ�1-ʹ�� 0-δʹ��
		LONG lFirstChannel,		// ��ͨ���� 0=ͨ��0,1=ͨ��1,...,7=ͨ��7
		LONG lLastChannel);		// ĩͨ���� 0=ͨ��0,1=ͨ��1,...,7=ͨ��7

	BOOL DEVAPI FAR PASCAL DAME3000N_AIReadHistData(		// ��ȡAIͨ����ʷ���ֵ��Сֵ��������ƽ��ֵ
		HANDLE hDevice,			// �豸���
		USHORT lHistData[],		// ���ݣ������СΪ�豸֧�ֵ�ͨ�����������ص�����ֻ�����˴�lFirstChannel��lLastChannelͨ���ڵ�����
		LONG lTypeChoose,		// ѡ���ȡ���ֵ������Сֵ,1-���ֵ��2-��Сֵ
		LONG lFirstChannel,		// ��ͨ���� 0=ͨ��0,1=ͨ��1,...,7=ͨ��7
		LONG lLastChannel);		// ĩͨ���� 0=ͨ��0,1=ͨ��1,...,7=ͨ��7

	BOOL DEVAPI FAR PASCAL DAME3000N_AIReadHistData_Avg(	// ��ȡAIͨ����ʷ���(��С)ֵƽ��ֵ
		HANDLE hDevice,				// �豸���
		USHORT* wAIHistAverValue,	// ƽ��ֵ
		LONG lTypeChoose);			// ѡ���ȡ���ֵ������Сֵ,1-���ֵ��2-��Сֵ

	BOOL DEVAPI FAR PASCAL DAME3000N_AIReadHistData_Ex(	// ��ȡAIͨ����ʷ���ֵ(��Сֵ)������ƽ��ֵͨ��
		HANDLE hDevice,			// �豸���
		USHORT lHistData[],		// ���ݣ������СΪ�豸֧�ֵ�ͨ������+1��lHistData[0]Ϊƽ��ֵͨ�����ݣ�lHistData[1]Ϊͨ��0���ݣ�,,,��lHistData[8]Ϊͨ��7���ݣ����ص�����ֻ�����˴�lFirstChannel��lLastChannelͨ���ڵ�����
		LONG lDataType,			// ѡ���ȡ���ֵ������Сֵ,1-���ֵ��2-��Сֵ
		LONG lFirstChannel,		// ��ͨ���� 0=ͨ��0,1=ͨ��1,...,7=ͨ��7
		LONG lLastChannel);		// ĩͨ���� 0=ͨ��0,1=ͨ��1,...,7=ͨ��7

	BOOL DEVAPI FAR PASCAL DAME3000N_AISetRange(			// ����ģ��������ģʽ
		HANDLE hDevice,			// �豸���
		LONG lAIMode[],			// �������飬�����СΪ�豸֧�ֵ���ͨ����
		LONG lFirstChannel,		// ��ͨ���� 0=ͨ��0,1=ͨ��1,...,7=ͨ��7
		LONG lLastChannel);		// ĩͨ���� 0=ͨ��0,1=ͨ��1,...,7=ͨ��7

	BOOL DEVAPI FAR PASCAL  DAME3000N_AIGetRange(				// ���ģ��������ģʽ
		HANDLE	hDevice,			// �豸���
		LONG	lAIMode[],			// ���صĸ���ͨ����AIģʽ�������СΪ�豸֧�ֵ���ͨ����
		LONG	lFirstChannel,	// ��ͨ���� 0=ͨ��0,1=ͨ��1,...,7=ͨ��7
		LONG	lLastChannel);	// ĩͨ���� 0=ͨ��0,1=ͨ��1,...,7=ͨ��7

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetLimitVal(				// ��������ޱ���ֵ��������ƽ��ֵͨ������ֵ
		HANDLE hDevice,				// �豸���
		USHORT lLimitValue[],		// ����ֵ�������СΪ�豸֧�ֵ���ͨ���������ص�����ֻ���´�lFirstChannel��lLastChannelͨ���ڵ�����
		LONG lTypeChose,			// ������ѡ�� 1-���� 2-����
		LONG lFirstChannel,			// ��ͨ���� 0=ͨ��0,1=ͨ��1,...,7=ͨ��7
		LONG lLastChannel);			// ĩͨ���� 0=ͨ��0,1=ͨ��1,...,7=ͨ��7

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetLimitVal_Avg(		// ���ƽ��ֵͨ�������ޱ���ֵ
		HANDLE hDevice,				// �豸���
		USHORT* wLimitAverValue,	// ����ֵ
		LONG lTypeChose);			// ������ѡ�� 1-���� 2-����

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetLimitVal_Ex(		// ��������ޱ���ֵ������ƽ��ֵͨ������ֵ
		HANDLE hDevice,			// �豸���
		USHORT lLimitValue[],	// ����ֵ�������СΪ�豸֧�ֵ���ͨ����+1��lLimitValue[0]Ϊƽ��ֵͨ������ֵ��lLimitValue[1]Ϊͨ��0���ݣ�,,,��lLimitValue[8]Ϊͨ��7���ݣ����ص�����ֻ���´�lFirstChannel��lLastChannelͨ���ڵ�����
		LONG lTypeChose,		// ������ѡ�� 1-���� 2-����
		LONG lFirstChannel,		// ��ͨ���� 0=ͨ��0,1=ͨ��1,...,7=ͨ��7
		LONG lLastChannel);		// ĩͨ���� 0=ͨ��0,1=ͨ��1,...,7=ͨ��7

	BOOL DEVAPI FAR PASCAL DAME3000N_AISetLimitVal(			// ���ñ���ֵ
		HANDLE hDevice,			// �豸���
		USHORT lLimitValue,		// ����ֵ
		LONG lLimitType,		// ������ѡ�� 1-���� 2-����
		LONG lChannel);			// ͨ���� 0=ͨ��0 1=ͨ��1... 7=ͨ��7

	BOOL DEVAPI FAR PASCAL DAME3000N_AISetLimitVal_Ex(		// ���ñ���ֵ(��ƽ��ֵͨ��)
		HANDLE hDevice,			// �豸���
		USHORT lLimitValue,		// ����ֵ
		LONG lLimitType,		// ������ѡ�� 1-���� 2-����
		LONG lChannel);			// ͨ���� 0=ƽ��ֵͨ�� 1=ͨ��0 2=ͨ��1... 8=ͨ��7

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetAlarmStatus_Avg(	// ��ȡģ����ƽ��ֵͨ������״̬
		HANDLE	hDevice,		// �豸���
		BYTE*	lStatus,		// ����״̬
		LONG lLimitType);		// ������ѡ�� 1-���� 2-����

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetAlarmStatus(			// ��ȡͨ������״̬��������ƽ��ֵͨ������״̬
		HANDLE hDevice,			// �豸���
		BYTE lStatus[],			// ����״̬�������СΪ�豸֧�ֵ���ͨ����
		LONG lLimitType,		// ������ѡ�� 1-���� 2-����
		LONG lFirstChannel,		// ��ͨ�� 0=ͨ��0 1=ͨ��1... 7=ͨ��7
		LONG lLastChannel);		// ĩͨ�� 0=ͨ��0 1=ͨ��1... 7=ͨ��7

	BOOL DEVAPI FAR PASCAL DAME3000N_AIClearLatchStatus(		// �������
		HANDLE	hDevice,		// �豸���
		BYTE	lStatus,		// ����״̬
		LONG lLimitType,		// ����/����
		LONG lChannel);			// ͨ���� 0=ͨ��0 1=ͨ��1... 7=ͨ��7

	BOOL DEVAPI FAR PASCAL DAME3000N_AIClearLatchSts_Avg(		// ���ƽ��ֵͨ������
		HANDLE	hDevice,		// �豸���
		BYTE	lStatus,		// ����״̬
		LONG lLimitType);		// ����/����

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetAlarmMode(		// ��ñ���ģʽ��������ƽ��ֵͨ������ģʽ 0x00-������ 0x01-���� 0x02-ʵʱ����
		HANDLE hDevice,			// �豸���
		USHORT lMode[],			// ����ģʽ�������СΪ�豸֧�ֵ���ͨ���������ص�����ֻ���´�lFirstChannel��lLastChannelͨ��������
		LONG lTypeChose,		// ������ѡ��1-���� 2-����
		LONG lFirstChannel,		// ��ͨ���� 0=ͨ��0 1=ͨ��1... 7=ͨ��7
		LONG lLastChannel);		// ĩͨ���� 0=ͨ��0 1=ͨ��1... 7=ͨ��7

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetAlarmMode_Avg(	// ���ƽ��ֵͨ������ģʽ
		HANDLE hDevice,			// �豸���
		USHORT* lAlarmMode_Avg,	// ����ģʽ
		LONG lTypeChose);		// ������ѡ��1-���� 2-����

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetAlarmMode_Ex(		// ��ñ���ģʽ������ƽ��ֵͨ������ģʽ 0x00-������ 0x01-���� 0x02-ʵʱ����
		HANDLE hDevice,			// �豸���
		USHORT lMode[],			// ����ģʽ�������СΪ�豸֧�ֵ���ͨ����+1��lMode[0]Ϊƽ��ֵͨ������ģʽ��ʣ�෵�ص�����ֻ���´�lFirstChannel��lLastChannelͨ��������
		LONG lTypeChose,		// ������ѡ��1-���� 2-����
		LONG lFirstChannel,		// ��ͨ���� 0=ͨ��0 1=ͨ��1... 7=ͨ��7
		LONG lLastChannel);		// ĩͨ���� 0=ͨ��0 1=ͨ��1... 7=ͨ��7

	BOOL DEVAPI FAR PASCAL DAME3000N_AISetAlarmMode(		// ���ñ���ģʽ
		HANDLE hDevice,		// �豸���
		SHORT lAlarmMode,	// ����ģʽ 0x00-������ 0x01-���� 0x02-ʵʱ����
		LONG lLimitType,	// ������ѡ��1-���� 2-����
		LONG lChannel);		// ͨ���� 0=ͨ��0 1= ͨ��1 ... 7=ͨ��7

	BOOL DEVAPI FAR PASCAL DAME3000N_AISetAlarmMode_Ex(		// ���ñ���ģʽ (����ƽ��ֵͨ��)
		HANDLE hDevice,		// �豸���
		SHORT lAlarmMode,	// ����ģʽ 0x00-������ 0x01-���� 0x02-ʵʱ����
		LONG lLimitType,	// ������ѡ��1-���� 2-����
		LONG lChannel);		// ͨ���� 0=ƽ��ֵͨ�� 1= ͨ��0 2= ͨ��1 ... 8=ͨ��7

	BOOL DEVAPI FAR PASCAL DAME3000N_AIResetHistValue_Ex(	// ��λͨ����ʷ���ֵ/��Сֵ
		HANDLE hDevice,			// �豸���
		LONG lValueType,		// ���ֵ/��Сֵ/ƽ��ֵ,1-���ֵ,2-��Сֵ,3-ƽ��ֵͨ�����ֵ,4-ƽ��ֵͨ����Сֵ
		LONG lChannel);			// ͨ����, 0=ͨ��0 1= ͨ��1 ... 7=ͨ��7. ��lValueTypeΪƽ��ֵͨ��ʱ����ֵ������

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetBrokenLotusSts(	// ��ȡ��ź״̬
		HANDLE hDevice,			// �豸���
		BYTE lValue[],			// ��ź״̬, 1=��ż, 0=����, �����СΪ�豸֧�ֵ���ͨ���������ص�����ֻ���´�lFirstChannel��lLastChannelͨ��������
		LONG lFirstChannel,		// ��ͨ���� 0=ͨ��0 1= ͨ��1 ... 7=ͨ��7
		LONG lLastChannel);		// ĩͨ���� 0=ͨ��0 1= ͨ��1 ... 7=ͨ��7

	BOOL DEVAPI	FAR	PASCAL	DAME3000N_AISetGroundRef(		// ����ͨ���ӵ�ģʽ(ֻ�Կ�������õ�/˫������ģ����Ч)
		HANDLE	hDevice,		// �豸������
		LONG	lGroundRef,		// AIͨ���ӵ�ģʽ
		LONG	lChannel);	// ͨ���� 0=ͨ��0 1= ͨ��1 ... 7=ͨ��7

	BOOL DEVAPI	FAR	PASCAL	DAME3000N_AIGetGroundRef(		// ���ͨ���ӵ�ģʽ(ֻ�Կ�������õ�/˫������ģ����Ч)
		HANDLE	hDevice,		// �豸������
		PLONG	lGroundRef,		// AIͨ���ӵ�ģʽ
		LONG	lChannel);	// ͨ���� 0=ͨ��0 1= ͨ��1 ... 7=ͨ��7

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetAlarmBindingStatus_Ex(	// ��ȡDO��״̬����ͨ��Ϊƽ��ֵͨ��
		HANDLE hDevice,				// �豸���
		USHORT	lStsValue[],		// �󶨵ı���ͨ��(DOͨ��)�ţ������СΪ�豸֧�ֵ�AIͨ������+1��lStsValue[0]��Ӧƽ��ֵͨ�� lStsValue[1]��ӦAI0ͨ�� lStsValue[2]��ӦAI1ͨ�� ... lStsValue[8]��ӦAI7ͨ��
		LONG	lTypeChose,			// ������ѡ�� 1-���� 2-����
		LONG	lFirstChannel,		// AI��ͨ����
		LONG	lLastChannel);		// AIĩͨ����

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetAlarmBindingStatus(	// ��ȡDO��״̬��������ƽ��ֵͨ��
		HANDLE	hDevice,			// �豸���
		USHORT	lStsValue[],		// ״̬�������СΪ�豸֧�ֵ�ͨ��������lStsValue[0]��ӦAI0ͨ�� lStsValue[1]��ӦAI1ͨ�� ... lStsValue[7]��ӦAI7ͨ��
		LONG	lTypeChose,			// ������ѡ�� 1-���� 2-����
		LONG	lFirstChannel,		// AI��ͨ����
		LONG	lLastChannel);		// AIĩͨ����

	BOOL DEVAPI FAR PASCAL DAME3000N_AIGetAlarmBindingStatus_Avg(	// ��ȡƽ��ֵͨ��DO��״̬
		HANDLE hDevice,					// �豸���
		USHORT* lStsValue_Avg,			// ƽ��ֵͨ�������󶨵�DOͨ��ֵ
		LONG	lTypeChose);			// ������ѡ�� 1-���� 2-����

	BOOL DEVAPI FAR PASCAL DAME3000N_AISetAlarmBindingStatus(		// ����DO��״̬
		HANDLE hDevice,					// �豸���
		SHORT lMode,					// ��DOͨ���� 0=���� 1=DO0 2=DO2
		LONG lTypeChose,				// ������ѡ��
		LONG lChannel);					// AIͨ���� 0=ƽ��ֵͨ�� 1=AI0 2=AI1 ... 8=AI7

	//################################### DA ���� ####################################
	BOOL DEVAPI	FAR	PASCAL	DAME3000N_AOReadData(		// �ض�DA���ֵ
		HANDLE	hDevice,	// �豸������
		PLONG	lpDAValue,	// DA�����ǰֵ
		LONG	lChannel);	// ͨ����

	BOOL DEVAPI	FAR	PASCAL	DAME3000N_AOWriteData(		// �趨��ͨ��DA
		HANDLE	 hDevice,	// �豸������
		LONG	 lDAData,	// DA���ֵ
		LONG	 lChannel);	// ͨ����

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOGetRange(	// ��ȡģ�����������
		HANDLE	 hDevice,		// �豸������
		PLONG	 lpRange,		// �������
		LONG	 lChannel);		// ͨ����

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOSetRange(	// ����ģ�����������
		HANDLE	 hDevice,		// �豸������
		LONG	 lRange,		// �������
		LONG	 lChannel);		// ͨ����

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOGetPowerOnValue(	// ���DA�ϵ�ֵ
		HANDLE	 hDevice,		// �豸������
		PLONG	 lpPowerOnVal,	// �ϵ�ֵ
		LONG	 lChannel);		// ͨ����

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOSetPowerOnValue(	// ����DA�ϵ�ֵ
		HANDLE	hDevice,		// �豸������
		LONG	lPowerOnVal,	// �ϵ�ֵ
		LONG	lChannel);		// ͨ����

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOGetSafeValue(		// ���DA��ȫֵ
		HANDLE	 hDevice,		// �豸������
		PLONG	 lpSafeVal,		// ��ȫֵ
		LONG	 lChannel);		// ͨ����

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOSetSafeValue(		// ����DA��ȫֵ
		HANDLE	 hDevice,		// �豸������
		LONG	 lSafeVal,		// ��ȫֵ
		LONG	 lChannel);		// ͨ����

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOGetSlope(			// ��ģ�������б��
		HANDLE	 hDevice,		// �豸������
		PLONG	 lpSlopeType,	// ���б������
		LONG	 lChannel);		// ͨ����

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOSetSlope(			// �޸�ģ�������б��
		HANDLE	 hDevice,		// �豸������
		LONG	 lSlopeType,	// ���б������
		LONG	 lChannel);		// ͨ����

	// -----------------------------------------------------------------------------------------------------
	BOOL DEVAPI	FAR	PASCAL	DAME3000N_AOReadData_Addr(		// �ض�DA���ֵ
		HANDLE	hDevice,		// �豸������
		LONG	lAddr,			// ��ͨ����ַ
		PLONG	lpDAValue,		// DA�����ǰֵ
		LONG	lFirstChannel,		// A0��ͨ����
		LONG	lLastChannel);		// A0ĩͨ����

	BOOL DEVAPI	FAR	PASCAL	DAME3000N_AOWriteData_Addr(		// �趨��ͨ��DA
		HANDLE	hDevice,		// �豸������
		LONG	lAddr,			// ��ͨ����ַ
		LONG	lDAData[],		// DA���ֵ
		LONG	lFirstChannel,	// A0��ͨ����
		LONG	lLastChannel);	// A0ĩͨ����

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOGetRange_Addr(		// ��ȡģ�����������
		HANDLE	hDevice,		// �豸������
		LONG	lAddr,			// ��ͨ����ַ
		PLONG	lpRange,		// �������
		LONG	lFirstChannel,	// A0��ͨ����
		LONG	lLastChannel);	// A0ĩͨ����

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOSetRange_Addr(		// ����ģ�����������
		HANDLE	hDevice,		// �豸������
		LONG	lAddr,			// ��ͨ����ַ
		LONG	lRange[],			// �������
		LONG	lFirstChannel,	// A0��ͨ����
		LONG	lLastChannel);	// A0ĩͨ����

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOGetPowerOnValue_Addr(// ���DA�ϵ�ֵ
		HANDLE	hDevice,		// �豸������
		LONG	lAddr,			// ��ͨ����ַ
		PLONG	lpPowerOnVal,	// �ϵ�ֵ
		LONG	lFirstChannel,	// A0��ͨ����
		LONG	lLastChannel);	// A0ĩͨ����

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOSetPowerOnValue_Addr(	// ����DA�ϵ�ֵ
		HANDLE	hDevice,		// �豸������
		LONG	lAddr,			// ��ͨ����ַ
		LONG	lPowerOnVal[],	// �ϵ�ֵ
		LONG	lFirstChannel,	// A0��ͨ����
		LONG	lLastChannel);	// A0ĩͨ����

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOGetSafeValue_Addr(	// ���DA��ȫֵ
		HANDLE	hDevice,		// �豸������
		LONG	lAddr,			// ��ͨ����ַ
		PLONG	lpSafeVal,		// ��ȫֵ
		LONG	lFirstChannel,	// A0��ͨ����
		LONG	lLastChannel);	// A0ĩͨ����

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOSetSafeValue_Addr(	// ����DA��ȫֵ
		HANDLE	hDevice,		// �豸������
		LONG	lAddr,			// ��ͨ����ַ
		LONG	lSafeVal[],		// ��ȫֵ
		LONG	lFirstChannel,	// A0��ͨ����
		LONG	lLastChannel);	// A0ĩͨ����

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOGetSlope_Addr(		// ��ģ�������б��
		HANDLE	hDevice,		// �豸������
		LONG	lAddr,			// ��ͨ����ַ
		PLONG	lpSlopeType,	// ���б������
		LONG	lFirstChannel,	// A0��ͨ����
		LONG	lLastChannel);	// A0ĩͨ����

	BOOL DEVAPI	FAR PASCAL	DAME3000N_AOSetSlope_Addr(		// �޸�ģ�������б��
		HANDLE	hDevice,		// �豸������
		LONG	lAddr,			// ��ͨ����ַ
		LONG	lSlopeType[],		// ���б������
		LONG	lFirstChannel,	// A0��ͨ����
		LONG	lLastChannel);	// A0ĩͨ����

	//################################### DI ���� ####################################
	BOOL DEVAPI FAR PASCAL  DAME3000N_DISetMode(			// ����DIģʽ״̬
		HANDLE	 hDevice,			// �豸���
		LONG	 Mode[],			// ģʽ(0x01 ��ͨDI������ģʽ;0x02 �͵�������;0x03 �ߵ�������;0x4 ��������ģʽ;0x5 Ƶ�ʹ���ģʽ;)
		LONG lFirstChannel,			// ��ͨ����
		LONG lLastChannel);		// ĩͨ����

	BOOL DEVAPI FAR PASCAL DAME3000N_DIGetMode(			// ��ȡDI����ģʽ
		HANDLE	 hDevice,			// �豸���
		LONG pMode[],				// ģʽ�������СΪ�豸֧�ֵ���ͨ���������ص�����ֻ�����˴�lFirstChannel��lLastChannelͨ��������
		LONG lFirstChannel,			// ��ͨ����
		LONG lLastChannel);		// ĩͨ����

	BOOL DEVAPI FAR PASCAL  DAME3000N_DISetInvert(	// ����DI�����߼�
		HANDLE	 hDevice,			// �豸���
		BYTE	 bInversion[],		// �Ƿ����߼�����
		LONG     lFirstChannel,	// ��ͨ����
		LONG	 lLastChannel);	// ĩͨ����

	BOOL DEVAPI FAR PASCAL  DAME3000N_DIGetInvert(	// ��ȡDI�����߼�
		HANDLE	 hDevice,			// �豸���
		BYTE	 bInversion[],		// �Ƿ����߼����룬�����СΪ�豸֧�ֵ���ͨ���������ص�����ֻ���´�lFirstChannel��lLastChannelͨ��������
		LONG     lFirstChannel,	// ��ͨ����
		LONG	 lLastChannel);	// ĩͨ����

	BOOL DEVAPI FAR PASCAL  DAME3000N_DIGetValue(				// ���DIֵ
		HANDLE	 hDevice,			// �豸���
		BYTE	 byDIStatus[],		// DI״̬�������СΪ�豸֧�ֵ���ͨ���������ص�����ֻ���´�lFirstChannel��lLastChannelͨ��������
		LONG     lFirstChannel,	// ��ͨ����
		LONG	 lLastChannel);	// ĩͨ����

	BOOL DEVAPI FAR PASCAL DAME3000N_DISetEnableFilter(			// �˲�ʹ��
		HANDLE	hDevice,			// �豸���
		BOOL	 bEnPulse,			// �˲�ʹ��
		LONG	lChannel);			// ͨ����

	BOOL DEVAPI FAR PASCAL DAME3000N_DIGetEnableFilter(		// ��ȡ�˲�ʹ��
		HANDLE	hDevice,			// �豸���
		PBOOL	bEnPulse,			// �˲�ʹ��
		LONG	lChannel);			// ͨ����

	BOOL DEVAPI FAR PASCAL  DAME3000N_DISetPulseWidth(			// �����˲�����
		HANDLE	 hDevice,			// �豸���
		ULONG	 lLowWidth[],		// �͵�ƽ��С���
		ULONG	 lHighWidth[],		// ���ź���С���
		LONG     lFirstChannel,	// ��ͨ����
		LONG	 lLastChannel);	// ĩͨ����

	BOOL DEVAPI FAR PASCAL  DAME3000N_DIGetPulseWidth(			// ��ȡ�˲�����
		HANDLE	 hDevice,			// �豸���
		ULONG	 lLowWidth[],		// �͵�ƽ��С���
		ULONG	 lHighWidth[],		// ���ź���С���
		LONG     lFirstChannel,	// ��ͨ����
		LONG	 lLastChannel);	// ĩͨ����

	BOOL DEVAPI FAR PASCAL  DAME3000N_DIEnablePoweroffSaveforCNT(	// ʹ��(����)�ϵ籣�������ֵ
		HANDLE	 hDevice,				// �豸���
		BOOL     bEnPowSave,			// �ϵ籣��ʹ�� 1=ʹ�� 0=����
		LONG	 Channel);			// ͨ����

	BOOL DEVAPI FAR PASCAL  DAME3000N_DIGetEnablePoweroffSaveforCNT(	// ��ȡ�ϵ籣�������ֵʹ��״̬
		HANDLE	hDevice,					// �豸���
		PBOOL	bEnPowSave,					// �ϵ籣��ʹ��
		LONG	Channel);				// ͨ����

	BOOL DEVAPI FAR PASCAL DAME3000N_DISetCNTInitialValue(		// ���ü�����ֵ
		HANDLE	hDevice,			// �豸���
		ULONG	lInitialValue[],	// ��������ֵ
		LONG	lFirstChannel,		// ��ͨ����
		LONG	lLastChannel);		// ĩͨ����

	BOOL DEVAPI FAR PASCAL  DAME3000N_DIGetCNTorFreqValue(		// ��ü���ֵ(Ƶ��ֵ)
		HANDLE	 hDevice,			// �豸���
		ULONG	 lCurrentVal[],		// ��ǰֵ������ֵ��Ƶ��ֵ��������ֵ�������ݵ�ǰDI����ģʽ���壩
		LONG     lFirstChannel,	// ��ͨ����
		LONG	 lLastChannel);	// ĩͨ����

	BOOL DEVAPI FAR PASCAL  DAME3000N_DIGetCNTOverFlg(			// ��ü����������־
		HANDLE	 hDevice,			// �豸���
		BYTE	 bOverFlg[],		// �����־��0x01 ��������ֵ�����  0x00 ��������ֵ�����
		LONG     lFirstChannel,	// ��ͨ����
		LONG	 lLastChannel);	// ĩͨ����

	BOOL DEVAPI FAR PASCAL DAME3000N_DIClearCNTOverFlg(		// ��������������־
		HANDLE hDevice,				// �豸���
		LONG	lFirstChannel,	// ��ͨ����
		LONG	lLastChannel);	// ĩͨ����

	BOOL DEVAPI FAR PASCAL DAME3000N_DISetStartCNT(			// ���ü�������ʼ��ֹͣ
		HANDLE	 hDevice,			// �豸���
		BYTE bDICNTSts[],			// ������״̬ 0-ֹͣ 1-����
		LONG lFirstChannel,		// ��ͨ����
		LONG lLastChannel);		// ĩͨ����

	BOOL DEVAPI FAR PASCAL DAME3000N_DIGetStartCNT(			// ��ȡ��������ʼ��ֹͣ״̬
		HANDLE	 hDevice,			// �豸���
		BYTE bDICNTSts[],			// ������״̬�������СΪ�豸֧�ֵ���ͨ���� 0-ֹͣ 1-����
		LONG lFirstChannel,		// ��ͨ����
		LONG lLastChannel);		// ĩͨ����

	BOOL DEVAPI FAR PASCAL  DAME3000N_DIClearCNTValue(			// �������ֵ
		HANDLE	 hDevice,			// �豸���
		LONG	 lChannel);		// ͨ����

	BOOL DEVAPI FAR PASCAL  DAME3000N_DIGetLatchStatus(			// ���DI����״̬(DAM3201A)
		HANDLE	 hDevice,			// �豸���
		BYTE	 byLowLatchSts[],	// �½�������״̬�������СΪ�豸֧�ֵ���ͨ����
		LONG     lFirstChannel,	// ��ͨ����
		LONG	 lLastChannel);	// ĩͨ����

	BOOL DEVAPI FAR PASCAL DAME3000N_DIClearLatchStatus(			// �������״̬
		HANDLE hDevice,				// �豸���
		LONG lChannel);				// ͨ����

	//################################### DO ���� ####################################
	BOOL DEVAPI FAR PASCAL  DAME3000N_DOSetMode(				// ����DOģʽ״̬
		HANDLE	hDevice,			// �豸���
		LONG	Mode[],				// ģʽ0x01ֱ�����ģʽ 0x02�͵�����ʱ��� 0x03�ߵ�����ʱ��� 0x04 ����������� 0x05-����̶����
		LONG	lFirstChannel,	// ��ͨ����
		LONG	lLastChannel);	// ĩͨ����

	BOOL DEVAPI FAR PASCAL DAME3000N_DOGetMode(				// ��ȡDOģʽ
		HANDLE	hDevice,			// �豸���
		LONG	Mode[],				// ģʽ�������СΪ�豸֧�ֵ���ͨ���������ص�����ֻ���´�lFirstChannel��lLastChannelͨ�������ݣ�0x01ֱ�����ģʽ 0x02�͵�����ʱ��� 0x03�ߵ�����ʱ��� 0x04 ����������� 0x05-����̶����
		LONG	lFirstChannel,	// ��ͨ����
		LONG	lLastChannel);	// ĩͨ����

	BOOL DEVAPI FAR PASCAL  DAME3000N_DOGetValue(				// ��õ�ǰ���������
		HANDLE	 hDevice,			// �豸���
		BYTE     byDOSts[],			// DO״̬�������СΪ�豸֧�ֵ���ͨ���������ص�����ֻ���´�lFirstChannel��lLastChannelͨ��������
		LONG     lFirstChannel,	// ��ͨ����
		LONG	 lLastChannel);	// ĩͨ����

	BOOL DEVAPI FAR PASCAL  DAME3000N_DOSetValue(				// ����DO���ֵ(DAME3021A)
		HANDLE	 hDevice,			// �豸���
		BYTE	 byDOSts[],			// ����DO���ֵ
		LONG     lFirstChannel,	// ��ͨ����
		LONG	 lLastChannel);	// ĩͨ����

	BOOL DEVAPI FAR PASCAL DAME3000N_DOSetValue_Line(			// ����DO�������ͨ�����ã�
		HANDLE	hDevice,			// �豸���
		BOOL	bDOSts,				// DO״̬
		LONG    lChannel);			// ͨ����

	BOOL DEVAPI FAR PASCAL DAME3000N_DOSetPowerOnValue(	// ����DO�ϵ�ֵ
		HANDLE	hDevice,		// �豸���
		BYTE	bDOSts[],		// �ϵ�ֵ
		LONG	lFirstChannel,	// ��ͨ����
		LONG	lLastChannel);	// ĩͨ����

	BOOL DEVAPI FAR PASCAL DAME3000N_DOGetPowerOnValue(		// ��ȡDO�ϵ�״̬
		HANDLE	hDevice,		// �豸���
		BYTE	bDOSts[],		// �ϵ�ֵ�������СΪ�豸֧�ֵ���ͨ���������ص�����ֻ���´�lFirstChannel��lLastChannelͨ��������
		LONG	lFirstChannel,	// ��ͨ����
		LONG	lLastChannel);	// ĩͨ����

	BOOL DEVAPI FAR PASCAL DAME3000N_DOSetSafeValue(		// ����DO��ȫ״̬
		HANDLE	hDevice,		// �豸���
		BYTE	bDOSts[],		// ��ȫֵ
		LONG lFirstChannel,		// ��ͨ����
		LONG	lLastChannel);	// ĩͨ����

	BOOL DEVAPI FAR PASCAL DAME3000N_DOGetSafeValue(		// ��ȡDO��ȫ״̬
		HANDLE	hDevice,		// �豸���
		BYTE	bDOSts[],		// DO��ȫ״̬�������СΪ����֧�ֵ���ͨ���������ص�����ֻ���´�lFirstChannel��lLastChannelͨ��������
		LONG	lFirstChannel,	// ��ͨ����
		LONG lLastChannel);		// ĩͨ����

	BOOL DEVAPI FAR PASCAL  DAME3000N_3021N_DOStartPulseOutput(		// ��ʼ�������
		HANDLE	 hDevice,			// �豸���
		LONG	 lChannel);		// ͨ����

	BOOL DEVAPI FAR PASCAL  DAME3000N_3021N_DOStopPulseOutput(		// ֹͣ�������
		HANDLE	 hDevice,			// �豸���
		LONG	 lChannel);		// ͨ����

	BOOL DEVAPI FAR PASCAL DAME3000N_3021N_DOGetPulseOutputStatus(	// ��ȡ�����������ֹͣ״̬
		HANDLE hDevice,				// �豸���
		BYTE bStatus[],				// ���ص�״̬�������СΪ�豸֧�ֵ�ͨ�����������ص����ݸ��´�lFirstChannel��lLastChannelͨ��������
		LONG lFirstChannel,		// ��ͨ����
		LONG lLastChannel);		// ĩͨ����

	BOOL DEVAPI FAR PASCAL  DAME3000N_DOSetPulseWidth(		// ����DO�������ռ�ձ�
		HANDLE	 hDevice,			// �豸���
		ULONG	 lLowWidth[],		// ��������͵�ƽ���
		ULONG	 lHighWidth[],		// ��������ߵ�ƽ���
		LONG     lFirstChannel,	// ��ͨ����
		LONG	 lLastChannel);	// ĩͨ����

	BOOL DEVAPI FAR PASCAL  DAME3000N_DOGetPulseWidth(		// ��ȡDO�������ռ�ձ�
		HANDLE	 hDevice,			// �豸���
		ULONG	 lLowWidth[],		// ��������͵�ƽ��ȣ������СΪ�豸֧�ֵ���ͨ���������ص�����ֻ���´�lFirstChannel��lLastChannelͨ��������
		ULONG	 lHighWidth[],		// ��������ߵ�ƽ��ȣ������СΪ�豸֧�ֵ���ͨ���������ص�����ֻ���´�lFirstChannel��lLastChannelͨ��������
		LONG	lFirstChannel,	// ��ͨ����
		LONG	 lLastChannel);	// ĩͨ����

	BOOL DEVAPI FAR PASCAL DAME3000N_3021N_DOSetPulseAddCount(		// ����������������
		HANDLE	hDevice,			// �豸���
		LONG	PuAddNum[],			// �����������
		LONG     lFirstChannel,	// ��ͨ����
		LONG	 lLastChannel);	// ĩͨ����

	BOOL DEVAPI FAR PASCAL DAME3000N_3021N_GetDOPulseAddCount(		// ��ȡ���ӵ���������
		HANDLE	hDevice,			// �豸���
		LONG	PuAddNum[],			// ������������������СΪ�豸֧�ֵ�ͨ�����������ص�����ֻ���´�lFirstChannel��lLastChannelͨ��������
		LONG     lFirstChannel,	// ��ͨ����
		LONG	 lLastChannel);	// ĩͨ����

	BOOL DEVAPI FAR PASCAL DAME3000N_DOSetPulseOutputAddCount(  // ������������
		HANDLE	hDevice,		// �豸���
		ULONG	PuAddNum[],		// �����������
		LONG   lFirstChannel,		// ��ͨ����
		LONG	lLastChannel);		// ĩͨ����

	BOOL DEVAPI FAR PASCAL DAME3000N_DOGetPulseOutputAddCount(  // ������������
		HANDLE	hDevice,		// �豸���
		ULONG	PuAddNum[],		// �����������
		LONG   lFirstChannel,		// ��ͨ����
		LONG	lLastChannel);		// ĩͨ����

	BOOL DEVAPI FAR PASCAL DAME3000N_DOSetPulseOutputCount(	// DO0�̶��������(0x0ʱ�������������������ֵʱ���������������ֵ)
		HANDLE	hDevice,			// �豸���
		ULONG	PuOutPutNum[],		// �������
		LONG     lFirstChannel,	// ��ͨ����
		LONG	 lLastChannel);	// ĩͨ����

	BOOL DEVAPI FAR PASCAL DAME3000N_DOGetPulseOutputCountLeft(	// DO0�̶��������(0x0ʱ�������������������ֵʱ�����������ʣ���������)
		HANDLE	hDevice,			// �豸���
		ULONG	PuOutPutNum[],		// �������ʣ������������СΪ�豸֧�ֵ�ͨ���������ص�����ֻ���´�lFirstChannel��lLastChannelͨ��������
		LONG     lFirstChannel,	// ��ͨ����
		LONG	 lLastChannel);	// ĩͨ����

// 	BOOL DEVAPI FAR PASCAL DAME3000N_GetDevicePulseOutputLeftNum(	//��ȡ�������ʣ�����
// 									HANDLE	hDevice,				// �豸���
// 									ULONG	lOutputLeftNum[],		// ��ͨ��ʣ����������������СΪ�豸֧�ֵ�ͨ�����������ص�����ֻ���´�lFirstChannel��lLastChannelͨ��������
// 									LONG	lFirstChannel,			// ��ͨ����
// 									LONG	lLastChannel);			// ĩͨ����

	BOOL DEVAPI FAR PASCAL  DAME3000N_3021N_DOSetDelayTime(				// ����DI�ߵͱ仯��ʱʱ��
		HANDLE	 hDevice,				// �豸���
		WORD	 DelayTime[],			// �ߵ�������ӳ�ʱ��
		LONG     lFirstChannel,		// ��ͨ����
		LONG	 lLastChannel);		// ĩͨ����

	BOOL DEVAPI FAR PASCAL DAME3000N_3021N_DOGetDelayTime(				// ��ȡ��ʱʱ��
		HANDLE	 hDevice,				// �豸���
		WORD	 DelayTime[],			// �ߵ�������ӳ�ʱ�䣬�����СΪ�豸֧�ֵ�ͨ���������ص����ݸ��µ��Ǵ�lFirstChannel��lLastChannelͨ��������
		LONG     lFirstChannel,		// ��ͨ����
		LONG	 lLastChannel);		// ĩͨ����

	// ����DO�͵�������ӳ�ʱ��
	BOOL DEVAPI FAR PASCAL DAME3000N_DOSetLowToHighTime(		// �����ӳ�ʱ��(DO�ɵ͵���)
		HANDLE	hDevice,				// �豸���
		ULONG	DelayTime[],			// �͵�������ӳ�ʱ��
		LONG	lFirstChannel,			// ��ͨ����
		LONG	lLastChannel);			// ĩͨ����


	// ��ȡDO�͵�������ӳ�ʱ��
	BOOL DEVAPI FAR PASCAL DAME3000N_DOGetLowToHighTime(	// ��ȡ�ӳ�ʱ��(DO�ɵ͵���)
		HANDLE	hDevice,			// �豸���
		ULONG	DelayTime[],		// �͵�������ӳ�ʱ�䣬�����СΪ�豸֧�ֵ�ͨ�����������ص����ݸ��µ��Ǵ�lFirstChannel��lLastChannelͨ��������
		LONG	lFirstChannel,		// ��ͨ����
		LONG	lLastChannel);		// ĩͨ����

	// ����DO����ߵ����ӳ�ʱ��
	BOOL DEVAPI FAR PASCAL DAME3000N_DOSetHighToLowTime(	// �����ӳ�ʱ��(DO�ɸߵ���)
		HANDLE	hDevice,			// �豸���
		ULONG	DelayTime[],		// �ߵ�������ӳ�ʱ��
		LONG	lFirstChannel,		// ��ͨ����
		LONG	lLastChannel);		// ĩͨ����

	// ��ȡDO�ߵ�������ӳ�ʱ��
	BOOL DEVAPI FAR PASCAL DAME3000N_DOGetHighToLowTime(	// ��ȡ�ӳ�ʱ��(DO�ɸߵ���)
		HANDLE	hDevice,			// �豸���
		ULONG	DelayTime[],		// �ߵ�������ӳ�ʱ�䣬�����СΪ�豸֧�ֵ�ͨ�����������ص����ݸ��µ��Ǵ�lFirstChannel��lLastChannelͨ��������
		LONG	lFirstChannel,		// ��ͨ����
		LONG	lLastChannel);		// ĩͨ����

	// ��ȡDOԴ״̬ DAME3022N(Դ����DIO)
	BOOL DEVAPI FAR PASCAL DAME3000N_DOGetSourceStatus(			// ��ȡDOԴ״̬
		HANDLE	hDevice,			// �豸���
		LONG	lSourceCh,			// DO Source ͨ���� ��DAME3022N��DO0~DO3 SourceChannel=0; DO4~DO5 SourceChannel=1��
		LONG*	lSourceSts);		// DO Source ״̬ 0=Failed 1=Normal


	//#############################  ������  ###################################


	//#############################  ͨ�ù���  ###################################
	BOOL DEVAPI FAR PASCAL DAME3000N_AdjustTemperature(	// �¶�У׼
		HANDLE hDevice,			// �豸���
		BYTE lTempValue);		// �¶�ֵ

	BOOL DEVAPI FAR PASCAL DAME3000N_ReadTemperature(		// ��ȡ�����¶�
		HANDLE	hDevice,		// �豸���
		double*	lTempValue);	// �¶�ֵ

	BOOL DEVAPI FAR PASCAL DAME3000N_SetUDPSearchPort(		// ����UDP�����˿ں�
		HANDLE hDevice,			// �豸���
		SHORT lPortNum);		// �˿ں�

	BOOL DEVAPI FAR PASCAL DAME3000N_GetUDPSearchPort(		// ��ȡUDP�����˿ں�
		HANDLE hDevice,			// �豸���
		PUSHORT pPortNum);		// �˿ں�

	BOOL DEVAPI FAR PASCAL DAME3000N_SetTCPConnectControl(	// ����TCP���ӿ��г�ʱ����
		HANDLE hDevice,			// �豸���
		USHORT lEnable);		// �Ƿ�ʹ�� 1-ʹ��(����Ϊ1)

	BOOL DEVAPI FAR PASCAL DAME3000N_GetTCPConnectControl(	// ��ȡTCP���ӿ��г�ʱ����ʹ��״̬
		HANDLE hDevice,			// �豸���
		PUSHORT pEnable);		// �Ƿ�ʹ�� 0-���� 1-ʹ��

	BOOL DEVAPI FAR PASCAL DAME3000N_SetTCPConnectTime(	// ����TCP���ӿ��г�ʱʱ��
		HANDLE hDevice,			// �豸���
		USHORT lTime);			// ��ʱʱ��

	BOOL DEVAPI FAR PASCAL DAME3000N_GetTCPConnectTime(	// ��ȡTCP���ӿ��г�ʱʱ��
		HANDLE hDevice,			// �豸���
		PUSHORT pTime);			// �˿ں�

	BOOL DEVAPI FAR PASCAL DAME3000N_RestartBoard(			// �����Ƿ����������Ĵ���
		HANDLE hDevice,			// �豸���
		USHORT lRestart);		// 0-������ 1-��������

	BOOL DEVAPI FAR PASCAL DAME3000N_Reset(			// �����Ƿ�ָ���������
		HANDLE hDevice,		// �豸���
		USHORT lReSet);		// 0-���ָ� 1-�ָ�

	BOOL DEVAPI FAR PASCAL DAME3000N_DevCalibration(	// �����Ƿ�У׼
		HANDLE hDevice,		// �豸���
		USHORT Calibration);// 0-��У׼ 1-У׼

	BOOL DEVAPI FAR PASCAL DAME3000N_SetIPMACFilter(		// ����IP/MAC����
		HANDLE hDevice,			// �豸���
		USHORT lFilterType,		// ����ģʽ 0-�޹���ģʽ 1-IP���� 2-MAC����
		USHORT lIPEnableNum,	// IPʹ����� bit7 ~bit0��0x01��ʾ0��IP���ã�0x03��ʾ0�ź�1��IP���ã�0xFF��ʾ8��ȫ��ʹ��
		USHORT lMACEnableNum,	// MACʹ����� bit7 ~bit0��0x01��ʾ0��IP���ã�0x03��ʾ0�ź�1��IP���ã�0xFF��ʾ8��ȫ��ʹ��
		BYTE bIPData[],			// ��Ҫ���õ�IP����
		BYTE bMACData[]);		// ��Ҫ���õ�MAC����

	BOOL DEVAPI FAR PASCAL DAME3000N_GetIPMACFilter(		// ��ȡIP/MAC����
		HANDLE hDevice,			// �豸���
		USHORT* lFilterType,	// ����ģʽ 0-�޹���ģʽ 1-IP���� 2-MAC����
		USHORT* lIPEnableNum,	// IPʹ����� bit7 ~bit0��0x01��ʾ0��IP���ã�0x03��ʾ0�ź�1��IP���ã�0xFF��ʾ8��ȫ��ʹ��
		USHORT* lMACEnableNum,	// MACʹ����� bit7 ~bit0��0x01��ʾ0��IP���ã�0x03��ʾ0�ź�1��IP���ã�0xFF��ʾ8��ȫ��ʹ��
		BYTE bIPData[],			// ��ȡ��IP����
		BYTE bMACData[]);		// ��ȡ��MAC����

	BOOL DEVAPI FAR PASCAL DAME3000N_SetSendToIP(			// ���ö�ʱ�������ݲ���
		HANDLE hDevice,			// �豸���
		USHORT lEnableNum,		// IPʹ����� bit7 ~bit0��0x01��ʾ0��IP���ã�0x03��ʾ0�ź�1��IP���ã�0xFF��ʾ8��ȫ��ʹ��
		BYTE bIPData[],			// ��Ҫ���õ�IP����
		USHORT lTime[]);		// ��Ҫ���õ���ѯʱ��

	BOOL DEVAPI FAR PASCAL DAME3000N_GetSendToIP(			// ��ȡ��ʱ�������ݲ���
		HANDLE hDevice,			// �豸���
		USHORT* pEnableNum,		// IPʹ����� bit7 ~bit0��0x01��ʾ0��IP���ã�0x03��ʾ0�ź�1��IP���ã�0xFF��ʾ8��ȫ��ʹ��
		BYTE bIPData[],			// ��ȡ��IP����
		USHORT pTime[]);		// ��ȡ����ѯʱ��

	BOOL DEVAPI FAR PASCAL DAME3000N_PasswordOperation(	// ���ü��ж������Ƿ���ȷ
		HANDLE hDevice,			// �豸���
		WORD lOptionType,		// �������ͣ�1-��¼ 2-�������� �ظ���ʱ��3-��¼ʧ��
		BYTE bOldPassword[],	// ������
		BYTE bNewPassword[]);	// ������

	//################################# ���Ź� ���� ##################################
	BOOL DEVAPI FAR PASCAL  DAME3000N_HostIsOK(		// Host Is OK
		HANDLE	 hDevice);	// �豸������

	BOOL DEVAPI FAR PASCAL  DAME3000N_EnableWatchdog(	// ʹ�ܿ��Ź�
		HANDLE	 hDevice);	// �豸������

	BOOL DEVAPI FAR PASCAL  DAME3000N_CloseWatchdog(	// �رտ��Ź�
		HANDLE	 hDevice);	// �豸������

	BOOL DEVAPI FAR PASCAL  DAME3000N_GetWatchdogSts(		// ��ÿ��Ź�״̬
		HANDLE	 hDevice,		// �豸������
		LONG	 lpDogStatus[]);// ���Ź�״̬,lpDogStatus[0]-���Ź��Ƿ�ʹ��,lpDogStatus[1]-���Ź�״̬,lpDogStatus[2]-���Ź��Ƿ�λ

	BOOL DEVAPI FAR PASCAL  DAME3000N_ResetWatchdog(		// ��λ���Ź�
		HANDLE	 hDevice);		// �豸������

	BOOL DEVAPI FAR PASCAL  DAME3000N_SetWatchdogTimeoutVal(	// ���ÿ��Ź���ʱʱ��
		HANDLE	 hDevice,			// �豸������
		LONG	 lTimeOutVal);		// ��ʱʱ��

	BOOL DEVAPI FAR PASCAL DAME3000N_GetWatchdogTimeout(		// ��ȡ���Ź���ʱʱ��
		HANDLE hDevice,				// �豸������
		PLONG pTimeOut);			// ��ʱʱ��

	//#########################################################################################
	//********************************* ֱ�������� *********************************
	int	DEVAPI	FAR	PASCAL	DAME3000N_WriteDeviceChar(
		HANDLE	 hDevice, 		// �豸���
		char*	 szwriteBuffer,	// д�������
		LONG	 llength);		// ֱ��д�豸

	int	DEVAPI	FAR	PASCAL	DAME3000N_ReadDeviceChar(
		HANDLE   hDevice,		// �豸���
		char*	 szreadBuffer,	// ��ȡ������
		LONG	 llength);		// ֱ�Ӷ��豸

	//#########################################################################################
	//********************************* ͨ������ *************************************
	BOOL DEVAPI FAR PASCAL ReadCoils(						// ���̵���״̬
		HANDLE	 hDevice,		// �豸���
		int		 addr,			// ���ܵ�ַ
		int		 len,			// ��ȡ����
		BYTE	 bCoilsFlag[]);	// ��ȡ�ļ̵���״̬

	BOOL DEVAPI FAR PASCAL ReadDiscretes(					// ������������
		HANDLE	 hDevice,		// �豸���
		int		 addr,			// ���ܵ�ַ
		int		 len,			// ��ȡ����
		BYTE	 bDIState[]);	// ��ȡ��DI״̬

	BOOL DEVAPI FAR PASCAL ReadMultiRegs(					// �����ּĴ���
		HANDLE	 hDevice,  		// �豸���
		int		 addr, 			// ���ܵ�ַ
		int		 len, 			// ��ȡ����
		BYTE	 buf[]);		// ��ȡ������

	BOOL DEVAPI FAR PASCAL ReadInputRegs(					// ������Ĵ���
		HANDLE	 hDevice,  		// �豸���
		int		 addr, 			// ���ܵ�ַ
		int		 len, 			// ��ȡ����
		BYTE	 buf[]);		// ��ȡ������

	BOOL DEVAPI FAR PASCAL WriteCoil(						// ���õ����̵���
		HANDLE	 hDevice,  		// �豸���
		int		 addr, 			// ���ܵ�ַ
		BYTE	 status); 		// д�������

	BOOL DEVAPI FAR PASCAL WriteSingleReg(					// ���õ������ּĴ���
		HANDLE	 hDevice,  		// �豸���
		int		 addr, 			// ���ܵ�ַ
		short	 val);  		// д�������

	BOOL DEVAPI FAR PASCAL ForceMultiCoils(					// ���ö���̵���
		HANDLE	 hDevice,  		// �豸���
		int		 addr, 			// ���ܵ�ַ
		int		 len, 			// ��ȡ����
		BYTE	 bDOState[]);  	// д�������

	BOOL DEVAPI FAR PASCAL WriteMultiRegs(					// ���ö�����ּĴ���
		HANDLE	 hDevice,  		// �豸���
		int		 addr, 			// ���ܵ�ַ
		int		 len, 			// ��ȡ����
		BYTE	 buf[]);  		// д�������

	BOOL DEVAPI FAR PASCAL ReadRegFile(						// ��ȡ�ļ���¼
		HANDLE	 hDevice,  		// �豸���
		int		 index,			// �ļ�������
		int		 addr, 			// ���ܵ�ַ
		int		 len, 			// ��ȡ����
		BYTE	 buf[]);  		// ��ȡ������

	BOOL DEVAPI FAR PASCAL WriteRegFile(					// д�ļ���¼
		HANDLE	 hDevice,  		// �豸���
		int		 index, 		// �ļ�������
		int		 addr, 			// ���ܵ�ַ
		int		 len,			// ��ȡ����
		BYTE	 buf[]);  		// д�������

#ifdef __cplusplus
}
#endif
#endif

/*
// �Զ������������������
#ifndef _DAME3000N_DRIVER_
#ifndef _WIN64
#pragma comment(lib, "DAME3000N_32.lib")
#else
#pragma comment(lib, "DAME3000N_64.lib")
#endif // _WIN64
#endif // _DAME3000N_DRIVER_
*/