//==============================================================================
//
// Title:		function.h
// Purpose:		��װ�����豸�Ľӿ�
//
// Created on:	2022/9/6 at 17:25:18 by liudongpeng
// Copyright:	13289204862@163.com
//
//==============================================================================

#ifndef __work_H__
#define __work_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files

#include "DAME3000N.h" // ���������windows.hͷ�ļ������������ǰ��

#include "cvidef.h"
		
		
//==============================================================================
// Constants

/* ʵʱ���� */
#define ALARM_REAL_TIME	0x02
/* �������� */
#define UPPER_LIMIT 1
/* �������� */
#define LOWER_LIMIT 2


//==============================================================================
// Global functions		
		
/**
 * @brief ��鴫����豸����Ƿ�Ϸ�
 * @param dev[IN]			�豸���
 * @retval �豸����Ϸ������棬�Ƿ����ؼ�
 */
BOOL CheckDeviceHandle(HANDLE dev);
		
/**
 * @brief ����DAM-E3056N�豸
 * @param devIP[IN]			ip��ַ
 * @param devTcpPort[IN]	TCP�˿�
 * @param sendTimeout[IN]	�������ݵĳ�ʱ���
 * @param recvTimeout[IN]	�������ݵĳ�ʱ���
 * @retval HANDLE			�����豸���
 */
HANDLE OpenDevice(const char* devIP, unsigned short devTcpPort, int sendTimeout, int recvTimeout);

/**
 * @brief �Ͽ�DAM-E3056N�豸
 * @param dev[IN]			�豸���
 * @retval �ɹ��ͷ��豸���󷵻��棬���򷵻ؼ�
 */
BOOL CloseDevice(HANDLE dev);

/**
 * @brief ����豸�Ƿ�����
 * @param devIP[IN]			�豸IP��ַ
 * @param devName[OUT]		�����豸����
 * @param devMAC[IN]		�豸MAC��ַ
 * @param devNum[OUT]		�����豸����
 * @param sendTimeout[IN]	�������ݵĳ�ʱ���
 * @param recvTimeout[IN]	�������ݵĳ�ʱ���
 * @retval �����豸����������Ҫֻ�÷���ֵ�ж��豸�Ƿ����ߣ���Ӧ���жϴ�����devName��devNum
 */
int CheckDevice(const char* devIP, char* devName, const char* devMAC, long devUdpPort, long* devNum, long sendTimeout, long recvTimeout);

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
BOOL SetAIChannelRange(HANDLE dev, const long* AIRangeArr, long firstChannel, long lastChannel);

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
BOOL SetAIChannelEnable(HANDLE dev, long* AIChannelArr, BYTE* AIChannelEnableArr, int channelNum);

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
BOOL SetAIChannelAlarmUpperLimit(HANDLE dev, long* AIchannelArr, USHORT* AIchannelUpperLimitArr, int n);

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
BOOL SetAIChannelAlarmLowerLimit(HANDLE dev, long* AIchannelArr, USHORT* AIchannelLowerLimitArr, int n);

/**
 * @brief ����AIͨ�����ޱ���ģʽΪʵʱģʽ
 * @param dev[IN]						�豸���
 * @param AIchannelArr[IN]				ͨ�����
 * @param n[IN]							ͨ������
 * @example long AIchannelArr[8] = {0, 1, 2, 3, 4, 5, 6, 7} // 8��ͨ���ı��
 * @retval �ɹ������棬ʧ�ܷ��ؼ�
 */
BOOL SetAIChannelAlarmUpperLimitModeRealTime(HANDLE dev, long* AIchannelArr, int n);

/**
 * @brief ����AIͨ�����ޱ���ģʽΪʵʱģʽ
 * @param dev[IN]						�豸���
 * @param AIchannelArr[IN]				ͨ�����
 * @param n[IN]							ͨ������
 * @example long AIchannelArr[8] = {0, 1, 2, 3, 4, 5, 6, 7} // 8��ͨ���ı��
 * @retval �ɹ������棬ʧ�ܷ��ؼ�
 */
BOOL SetAIChannelAlarmLowerLimitModeRealTime(HANDLE dev, long* AIchannelArr, int n);

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __work_H__ */
