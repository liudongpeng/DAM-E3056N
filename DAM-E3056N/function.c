//==============================================================================
//
// Title:		function.c
// Purpose:		��װ�����豸�Ľӿ�
//
// Created on:	2022/9/6 at 17:25:18 by liudongpeng
// Copyright:	13289204862@163.com
//
//==============================================================================

//==============================================================================
// Include files

#include "function.h"




//==============================================================================
// Global functions

/**
 * @brief ��鴫����豸����Ƿ�Ϸ�
 * @param dev[IN]			�豸���
 * @retval �豸����Ϸ������棬�Ƿ����ؼ�
 */
BOOL CheckDeviceHandle(HANDLE dev)
{
	if (dev == NULL || dev == (void*)-1)
	{
		return FALSE;
	}
	return TRUE;
}

/**
 * @brief ����DAM-E3056N�豸
 * @param ip[IN]			ip��ַ
 * @param tcpPort[IN]		TCP�˿�
 * @param sendTimeout[IN]	�������ݵĳ�ʱ���
 * @param recvTimeout[IN]	�������ݵĳ�ʱ���
 * @retval HANDLE			�����豸����������豸����ʧ�ܣ��򷵻ؿ�
 */
HANDLE OpenDevice(const char* devIP, unsigned short devTcpPort, int sendTimeout, int recvTimeout)
{
	if (devIP == NULL)
		return 0;
	
	return DAME3000N_CreateDevice(devIP, devTcpPort, sendTimeout, recvTimeout);
}

/**
 * @brief �Ͽ�DAM-E3056N�豸
 * @param dev[IN]			�豸���
 * @retval �ɹ��ͷ��豸���󷵻��棬���򷵻ؼ�
 */
BOOL CloseDevice(HANDLE dev)
{
	if (!CheckDeviceHandle(dev))
		return FALSE;
	
	// �ͷ��豸����
	return DAME3000N_ReleaseDevice(dev);
}

/**
 * @brief ����豸�Ƿ�����
 * @param devIP[IN]			�豸IP��ַ
 * @param devName[OUT]		�����豸����
 * @param devMAC[IN]		�豸MAC��ַ
 * @param devUdpPort[IN]	�豸UDP�˿ں�
 * @param devNum[OUT]		�����豸����
 * @param sendTimeout[IN]	�������ݵĳ�ʱ���
 * @param recvTimeout[IN]	�������ݵĳ�ʱ���
 * @retval �����豸����������Ҫֻ�÷���ֵ�ж��豸�Ƿ����ߣ���Ӧ���жϴ�����devName��devNum
 */
int CheckDevice(const char* devIP, char* devName, const char* devMAC, long devUdpPort, long* devNum, long sendTimeout, long recvTimeout)
{
	if (devIP == NULL || devName == NULL || devMAC == NULL || devNum == NULL)
		return -1;
	
	return DAME3000N_SearchDevice(devIP, devName, devMAC, devUdpPort, devNum, sendTimeout, recvTimeout);
}

/**
 * @brief ����AIͨ������
 * @param dev[IN]			�豸���
 * @param AIRangeArr[IN]	ÿ��ͨ�������̣������С��ӦҪ���õ�ͨ�����������磺long arr[8] = {0}�������8��ͨ��������
 * @param firstChannel[IN]	��һ��ͨ����� 0~7
 * @param lastChannel[IN]	���һ��ͨ����� 0~7
 * @example long arr[8] = {1, 2, 3, 4, 5, 6, 7, 8}, firstChannel = 0, lastChannel = 7; ����0~7ͨ��������Ϊָ��ֵ
 *			long arr[4] = {1, 2, 3, 4}, firstChannel = 1, lastChannel = 4; ����1~4ͨ��������Ϊָ��ֵ
 * @retval �ɹ������棬ʧ�ܷ��ؼ�
 */
BOOL SetAIChannelRange(HANDLE dev, const long* AIRangeArr, long firstChannel, long lastChannel)
{
	if (!CheckDeviceHandle(dev) || AIRangeArr == NULL)
		return FALSE;
	
	return DAME3000N_AISetRange(dev, AIRangeArr, firstChannel, lastChannel);
}

/**
 * @brief ʹ��AIͨ��
 * @param dev[IN]					�豸���
 * @param AIRangeArr[IN]			ͨ�����
 * @param AIChannelEnableArr[IN]	��Ӧ��ͨ���Ƿ����ܣ�1ʹ�ܣ�0��ʹ��
 * @param channelNum[IN]			ͨ������
 * @example long AIChannelArr[8] = 		 {0, 1, 2, 3, 4, 5, 6, 7} // 8��ͨ���ı��
 *			BYTE AIChannelEnableArr[8] = {1, 1, 0, 1, 0, 1, 0, 1} // 8��ͨ�����Ե�ʹ��״̬
 * @retval �ɹ������棬ʧ�ܷ��ؼ�
 */
BOOL SetAIChannelEnable(HANDLE dev, long* AIChannelArr, BYTE* AIChannelEnableArr, int channelNum)
{
	BOOL ret = FALSE;
	
	if (!CheckDeviceHandle(dev) || AIChannelArr == NULL || AIChannelEnableArr == NULL)
		return FALSE;
	
	for (int i = 0; i < channelNum; i++)
	{
		ret = DAME3000N_AISetEnable(dev, AIChannelArr[i], AIChannelEnableArr[i]);
		if (!ret)
			return FALSE;
	}
	
	return TRUE;
}

/**
 * @brief ����AIͨ������ֵ����
 * @param dev[IN]						�豸���
 * @param AIchannelArr[IN]				ͨ�����
 * @param AIchannelUpperLimitArr[IN]	��Ӧͨ���ľ�ֵ����
 * @param n[IN]							ͨ������
 * @example long AIchannelArr[8] = 		 	{0, 1, 2, 3, 4, 5, 6, 7} // 8��ͨ���ı��
 *			int AIchannelUpperLimitArr[8] = {1, 4, 2, 3, 4, 2, 1, 1} // 8��ͨ�����Եľ�ֵ����
 * @retval �ɹ������棬ʧ�ܷ��ؼ�
 */
BOOL SetAIChannelAlarmUpperLimit(HANDLE dev, long* AIchannelArr, USHORT* AIchannelUpperLimitArr, int n)
{
	BOOL err = FALSE;
	
	
	if (!CheckDeviceHandle(dev) || AIchannelArr == NULL || AIchannelUpperLimitArr == NULL)
		return FALSE;
	
	for (int i = 0; i < n; i++)
	{
		err = DAME3000N_AISetLimitVal(dev, AIchannelUpperLimitArr[i], UPPER_LIMIT, AIchannelArr[i]);
		if (!err)
			return FALSE;
	}
	
	return TRUE;
}

/**
 * @brief ����AIͨ������ֵ����
 * @param dev[IN]						�豸���
 * @param AIchannelArr[IN]				ͨ�����
 * @param AIchannelUpperLimitArr[IN]	��Ӧͨ���ľ�ֵ����
 * @param n[IN]							ͨ������
 * @example long AIchannelArr[8] = 		 	{0, 1, 2, 3, 4, 5, 6, 7} // 8��ͨ���ı��
 *			int AIchannelLowerLimitArr[8] = {1, 4, 2, 3, 4, 2, 1, 1} // 8��ͨ�����Եľ�ֵ����
 * @retval �ɹ������棬ʧ�ܷ��ؼ�
 */
BOOL SetAIChannelAlarmLowerLimit(HANDLE dev, long* AIchannelArr, USHORT* AIchannelLowerLimitArr, int n)
{
	BOOL err = FALSE;
	
	
	if (!CheckDeviceHandle(dev) || AIchannelArr == NULL || AIchannelLowerLimitArr == NULL)
		return FALSE;
	
	for (int i = 0; i < n; i++)
	{
		err = DAME3000N_AISetLimitVal(dev, AIchannelLowerLimitArr[i], LOWER_LIMIT, AIchannelArr[i]);
		if (!err)
			return FALSE;
	}
	
	return TRUE;
}

/**
 * @brief ����AIͨ�����ޱ���ģʽΪʵʱģʽ
 * @param dev[IN]						�豸���
 * @param AIchannelArr[IN]				ͨ�����
 * @param n[IN]							ͨ������
 * @example long AIchannelArr[8] = {0, 1, 2, 3, 4, 5, 6, 7} // 8��ͨ���ı��
 * @retval �ɹ������棬ʧ�ܷ��ؼ�
 */
BOOL SetAIChannelAlarmUpperLimitModeRealTime(HANDLE dev, long* AIchannelArr, int n)
{
	BOOL err = FALSE;
	
	
	if (!CheckDeviceHandle(dev))
		return FALSE;
	
	for (int i = 0; i < n; i++)
	{
		err = DAME3000N_AISetAlarmMode(dev, ALARM_REAL_TIME, UPPER_LIMIT, AIchannelArr[i]);
		if (!err)
			return FALSE;
	}
	
	return TRUE;
}

/**
 * @brief ����AIͨ�����ޱ���ģʽΪʵʱģʽ
 * @param dev[IN]						�豸���
 * @param AIchannelArr[IN]				ͨ�����
 * @param n[IN]							ͨ������
 * @example long AIchannelArr[8] = {0, 1, 2, 3, 4, 5, 6, 7} // 8��ͨ���ı��
 * @retval �ɹ������棬ʧ�ܷ��ؼ�
 */
BOOL SetAIChannelAlarmLowerLimitModeRealTime(HANDLE dev, long* AIchannelArr, int n)
{
	BOOL err = FALSE;
	
	
	if (!CheckDeviceHandle(dev))
		return FALSE;
	
	for (int i = 0; i < n; i++)
	{
		err = DAME3000N_AISetAlarmMode(dev, ALARM_REAL_TIME, LOWER_LIMIT, AIchannelArr[i]);
		if (!err)
			return FALSE;
	}
	
	return TRUE;
}


