#include "HMI.h"
#include "CDlgHMI.h"
CDlgHMI g_dlg;
HANDLE g_myThread;
extern "C" __declspec(dllexport) bool  __stdcall Init(HWND hwnd)
{
	if (hwnd == NULL) {
		AfxMessageBox("主窗口句柄NULL");
		g_dlg.m_hWnd = 0;
		return false;
	}
	g_dlg.m_hWnd = hwnd;
	//AfxMessageBox("主窗口句柄非空");
	return true;
}
/*
bool __stdcall SendMQMsg(string msg, int number)
{
	switch (number) {
	case 1:
		break;
	case 2:
		break;
	}
	
	g_dlg.DoModal();
	printf("ShowWindow\n");
	printf("send msg: %s\n", msg.c_str());
	return true;
}
*/
////////////////////////////////////
UINT MyThreadFunction(LPVOID pParam)
{
	g_dlg.DoModal();
	printf("ShowWindow\n");
	return 0;
}

bool __stdcall RecvMQMsg(string msg, int number)
{
	if (g_dlg.m_hWnd == NULL)
	{
		AfxMessageBox("无目标窗口");
		return false;
	}
	switch (number) {
	case 1:
		break;
	case 2:
		break;
	}
	//
	g_myThread = AfxBeginThread(MyThreadFunction, 0, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
	
	//
	
	printf("receive msg: %s\n", msg.c_str());
	return false;
}

bool __stdcall Destroy()
{
	g_dlg.OnClose();
	SendMessage(g_dlg.GetSafeHwnd(), WM_CLOSE, 0, 0);
	//::AfxEndThread(g_myThread);
	return false;
}