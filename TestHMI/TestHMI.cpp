// TestHMI.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "HMI.h"

#pragma comment(lib, "Release/LibForHMI.lib")
int main()
{	
    std::cout << "start......\n";
	Init(NULL);
	RecvMQMsg("456", 0);
}

