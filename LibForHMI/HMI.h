#pragma once
using namespace std;
#include "CDlgHMI.h"
#include <string>
extern "C" __declspec(dllexport) bool  __stdcall Init(HWND hwnd);


//extern "C" __declspec(dllexport) bool  __stdcall SendMQMsg(string msg, int number);


extern "C" __declspec(dllexport) bool  __stdcall RecvMQMsg(string msg, int number);


extern "C" __declspec(dllexport) bool  __stdcall Destroy();
