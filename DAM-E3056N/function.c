//==============================================================================
//
// Title:		function.c
// Purpose:		封装操作设备的接口
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
 * @brief 检查传入的设备句柄是否合法
 * @param dev[IN]			设备句柄
 * @retval 设备句柄合法返回真，非法返回假
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
 * @brief 连接DAM-E3056N设备
 * @param ip[IN]			ip地址
 * @param tcpPort[IN]		TCP端口
 * @param sendTimeout[IN]	发送数据的超时间隔
 * @param recvTimeout[IN]	接收数据的超时间隔
 * @retval HANDLE			返回设备句柄，创建设备对象失败，则返回空
 */
HANDLE OpenDevice(const char* devIP, unsigned short devTcpPort, int sendTimeout, int recvTimeout)
{
	if (devIP == NULL)
		return 0;
	
	return DAME3000N_CreateDevice(devIP, devTcpPort, sendTimeout, recvTimeout);
}

/**
 * @brief 断开DAM-E3056N设备
 * @param dev[IN]			设备句柄
 * @retval 成功释放设备对象返回真，否则返回假
 */
BOOL CloseDevice(HANDLE dev)
{
	if (!CheckDeviceHandle(dev))
		return FALSE;
	
	// 释放设备对象
	return DAME3000N_ReleaseDevice(dev);
}

/**
 * @brief 检查设备是否在线
 * @param devIP[IN]			设备IP地址
 * @param devName[OUT]		在线设备名称
 * @param devMAC[IN]		设备MAC地址
 * @param devUdpPort[IN]	设备UDP端口号
 * @param devNum[OUT]		在线设备数量
 * @param sendTimeout[IN]	发送数据的超时间隔
 * @param recvTimeout[IN]	接收数据的超时间隔
 * @retval 在线设备的数量，不要只用返回值判断设备是否在线，还应该判断传出的devName和devNum
 */
int CheckDevice(const char* devIP, char* devName, const char* devMAC, long devUdpPort, long* devNum, long sendTimeout, long recvTimeout)
{
	if (devIP == NULL || devName == NULL || devMAC == NULL || devNum == NULL)
		return -1;
	
	return DAME3000N_SearchDevice(devIP, devName, devMAC, devUdpPort, devNum, sendTimeout, recvTimeout);
}

/**
 * @brief 设置AI通道量程
 * @param dev[IN]			设备句柄
 * @param AIRangeArr[IN]	每个通道的量程，数组大小对应要设置的通道数量，例如：long arr[8] = {0}，即最多8个通道的量程
 * @param firstChannel[IN]	第一个通道编号 0~7
 * @param lastChannel[IN]	最后一个通道编号 0~7
 * @example long arr[8] = {1, 2, 3, 4, 5, 6, 7, 8}, firstChannel = 0, lastChannel = 7; 设置0~7通道的量程为指定值
 *			long arr[4] = {1, 2, 3, 4}, firstChannel = 1, lastChannel = 4; 设置1~4通道的量程为指定值
 * @retval 成功返回真，失败返回假
 */
BOOL SetAIChannelRange(HANDLE dev, const long* AIRangeArr, long firstChannel, long lastChannel)
{
	if (!CheckDeviceHandle(dev) || AIRangeArr == NULL)
		return FALSE;
	
	return DAME3000N_AISetRange(dev, AIRangeArr, firstChannel, lastChannel);
}

/**
 * @brief 使能AI通道
 * @param dev[IN]					设备句柄
 * @param AIRangeArr[IN]			通道编号
 * @param AIChannelEnableArr[IN]	对应的通道是否是能，1使能，0不使能
 * @param channelNum[IN]			通道数量
 * @example long AIChannelArr[8] = 		 {0, 1, 2, 3, 4, 5, 6, 7} // 8个通道的编号
 *			BYTE AIChannelEnableArr[8] = {1, 1, 0, 1, 0, 1, 0, 1} // 8个通道各自的使能状态
 * @retval 成功返回真，失败返回假
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
 * @brief 设置AI通道报警值上限
 * @param dev[IN]						设备句柄
 * @param AIchannelArr[IN]				通道编号
 * @param AIchannelUpperLimitArr[IN]	对应通道的警值上限
 * @param n[IN]							通道数量
 * @example long AIchannelArr[8] = 		 	{0, 1, 2, 3, 4, 5, 6, 7} // 8个通道的编号
 *			int AIchannelUpperLimitArr[8] = {1, 4, 2, 3, 4, 2, 1, 1} // 8个通道各自的警值上限
 * @retval 成功返回真，失败返回假
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
 * @brief 设置AI通道报警值下限
 * @param dev[IN]						设备句柄
 * @param AIchannelArr[IN]				通道编号
 * @param AIchannelUpperLimitArr[IN]	对应通道的警值下限
 * @param n[IN]							通道数量
 * @example long AIchannelArr[8] = 		 	{0, 1, 2, 3, 4, 5, 6, 7} // 8个通道的编号
 *			int AIchannelLowerLimitArr[8] = {1, 4, 2, 3, 4, 2, 1, 1} // 8个通道各自的警值下限
 * @retval 成功返回真，失败返回假
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
 * @brief 设置AI通道上限报警模式为实时模式
 * @param dev[IN]						设备句柄
 * @param AIchannelArr[IN]				通道编号
 * @param n[IN]							通道数量
 * @example long AIchannelArr[8] = {0, 1, 2, 3, 4, 5, 6, 7} // 8个通道的编号
 * @retval 成功返回真，失败返回假
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
 * @brief 设置AI通道下限报警模式为实时模式
 * @param dev[IN]						设备句柄
 * @param AIchannelArr[IN]				通道编号
 * @param n[IN]							通道数量
 * @example long AIchannelArr[8] = {0, 1, 2, 3, 4, 5, 6, 7} // 8个通道的编号
 * @retval 成功返回真，失败返回假
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


