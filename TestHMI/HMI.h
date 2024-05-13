#pragma once
using namespace std;
#include <string>
#include <windows.h>
extern "C" __declspec(dllimport) bool  __stdcall Init(HWND hwnd);


//extern "C" __declspec(dllimport) bool  __stdcall SendMQMsg(string msg, int number);


extern "C" __declspec(dllimport) bool  __stdcall RecvMQMsg(string msg, int number);


extern "C" __declspec(dllexport) bool  __stdcall Destroy();

