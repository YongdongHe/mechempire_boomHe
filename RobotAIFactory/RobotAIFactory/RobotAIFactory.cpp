// RobotAIFactory.cpp : 定义 DLL 应用程序的导出函数。

#include "sys/RobotAI_Interface.h"
#include "myAI/RobotAI.h"

extern "C" _declspec(dllexport) RobotAI_Interface* Export()
{
	return (RobotAI_Interface*)new RobotAI();
}

extern "C" _declspec(dllexport) void FreeRobotAIPointer(RobotAI_Interface* p)
{
	delete p;
}