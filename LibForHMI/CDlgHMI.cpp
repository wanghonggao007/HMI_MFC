// CDlgHMI.cpp: 实现文件
//

#include "pch.h"
#include "CDlgHMI.h"
#include "afxdialogex.h"


// CDlgHMI 对话框

IMPLEMENT_DYNAMIC(CDlgHMI, CDialogEx)

CDlgHMI::CDlgHMI(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_HMI, pParent)
{

}

CDlgHMI::~CDlgHMI()
{
}

void CDlgHMI::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgHMI, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON_NEW, &CDlgHMI::OnBnClickedButtonNew)
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &CDlgHMI::OnBnClickedButtonOpen)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CDlgHMI::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &CDlgHMI::OnBnClickedButtonClose)
	ON_BN_CLICKED(IDC_BUTTON_PRINT, &CDlgHMI::OnBnClickedButtonPrint)
	ON_BN_CLICKED(IDC_BUTTON_UNDO, &CDlgHMI::OnBnClickedButtonUndo)
	ON_BN_CLICKED(IDC_BUTTON_REDO, &CDlgHMI::OnBnClickedButtonRedo)
	ON_BN_CLICKED(IDC_BUTTON_CUT, &CDlgHMI::OnBnClickedButtonCut)
	ON_BN_CLICKED(IDC_BUTTON_COPY, &CDlgHMI::OnBnClickedButtonCopy)
	ON_BN_CLICKED(IDC_BUTTON_PASTE, &CDlgHMI::OnBnClickedButtonPaste)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CDlgHMI::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_FIND, &CDlgHMI::OnBnClickedButtonFind)
	ON_BN_CLICKED(IDC_BUTTON_REPLACE, &CDlgHMI::OnBnClickedButtonReplace)
	ON_BN_CLICKED(IDC_BUTTON_MOVE_TOP, &CDlgHMI::OnBnClickedButtonMoveTop)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CDlgHMI 消息处理程序


void CDlgHMI::OnClose()
{
	//AfxMessageBox("close");
	//this->ShowWindow(SIZE_MAXHIDE);
	//CDialogEx::OnClose();
	SetWindowPos(NULL, 0, 0, 0, 0, SWP_HIDEWINDOW);
	m_IsHide = true;
}


HRESULT CDlgHMI::accDoDefaultAction(VARIANT varChild)
{
	// TODO: 在此添加专用代码和/或调用基类

	return CDialogEx::accDoDefaultAction(varChild);
}


BOOL CDlgHMI::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//
	CRect recWindow , rec;
	HWND hwnd = ::GetDesktopWindow();
	::GetWindowRect(hwnd, recWindow);
	::GetWindowRect(this->GetSafeHwnd(), rec);	
	//this->MoveWindow(rec.left, rec.top, rec.Width(), rec.Height());
	this->MoveWindow(50, 150, rec.Width(), rec.Height());
	// TODO:  在此添加额外的初始化
	SetTimer(1000, 1000, NULL);
	m_IsHide = false;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDlgHMI::OnBnClickedButtonNew()
{
	SendMsg(HMI_COMMAND_NEW);
}


void CDlgHMI::OnBnClickedButtonOpen()
{
	SendMsg(HMI_COMMAND_OPEN);
}


void CDlgHMI::OnBnClickedButtonSave()
{
	SendMsg(HMI_COMMAND_SAVE);
}


void CDlgHMI::OnBnClickedButtonClose()
{
	SendMsg(HMI_COMMAND_CLOSE);
}


void CDlgHMI::OnBnClickedButtonPrint()
{
	SendMsg(HMI_COMMAND_PRINT);
}

bool CDlgHMI::SendMsg(HMI_COMMAND_CODE code)
{
	switch (code) {
		case HMI_COMMAND_NEW:
			printf("new\n");
			//AfxMessageBox("new");
			m_buffer = HMI_COMMAND_NEW;
			::PostMessage(m_hWnd, WM_COMMAND , 101, 101);
		    break;
		case HMI_COMMAND_OPEN:
			printf("open\n");
			::PostMessage(m_hWnd, WM_COMMAND, 102, 102);
			//AfxMessageBox("open");
			break;
		case HMI_COMMAND_SAVE:
			printf("save\n");
			//AfxMessageBox("save");
			::PostMessage(m_hWnd, WM_COMMAND, 106, 106);
			break;
		case HMI_COMMAND_CLOSE:
			printf("close\n");
			//AfxMessageBox("close");
			::PostMessage(m_hWnd, WM_COMMAND, 105, 105);
			break;
		case HMI_COMMAND_PRINT:
			printf("print\n");
			//AfxMessageBox("print");
			::PostMessage(m_hWnd, WM_COMMAND, 131, 131);
			break;
		case HMI_COMMAND_CUT:
			::PostMessage(m_hWnd, WM_COMMAND, 203, 203);
			break;
		case HMI_COMMAND_COPY:
			::PostMessage(m_hWnd, WM_COMMAND, 204, 204);
			break;
		case HMI_COMMAND_PASTE:
			::PostMessage(m_hWnd, WM_COMMAND, 205, 205);
			break;
		case HMI_COMMAND_DELETE:
			::PostMessage(m_hWnd, WM_COMMAND, 206, 206);
			break;
		case HMI_COMMAND_UNDO:
			::PostMessage(m_hWnd, WM_COMMAND, 201, 201);
			break;
		case HMI_COMMAND_REDO:
			::PostMessage(m_hWnd, WM_COMMAND, 202, 202);
			break;
		case HMI_COMMAND_FIND:
			::PostMessage(m_hWnd, WM_COMMAND, 210, 210);
			break;
		case HMI_COMMAND_REPLACE:
			::PostMessage(m_hWnd, WM_COMMAND, 216, 216);
			break;
		case HMI_COMMAND_MOVETOP:
			//::PostMessage(m_hWnd, WM_COMMAND, 104, 104);
			break;
	}
	m_buffer = code;
	return false;
}


void CDlgHMI::OnBnClickedButtonUndo()
{
	SendMsg(HMI_COMMAND_UNDO);
}


void CDlgHMI::OnBnClickedButtonRedo()
{
	SendMsg(HMI_COMMAND_REDO);
}


void CDlgHMI::OnBnClickedButtonCut()
{
	SendMsg(HMI_COMMAND_CUT);
}


void CDlgHMI::OnBnClickedButtonCopy()
{
	SendMsg(HMI_COMMAND_COPY);
}


void CDlgHMI::OnBnClickedButtonPaste()
{
	SendMsg(HMI_COMMAND_PASTE);
}


void CDlgHMI::OnBnClickedButtonDelete()
{
	SendMsg(HMI_COMMAND_DELETE);
}


void CDlgHMI::OnBnClickedButtonFind()
{
	SendMsg(HMI_COMMAND_FIND);
}


void CDlgHMI::OnBnClickedButtonReplace()
{
	SendMsg(HMI_COMMAND_REPLACE);
}


void CDlgHMI::OnBnClickedButtonMoveTop()
{
	SendMsg(HMI_COMMAND_MOVETOP);
}


void CDlgHMI::OnTimer(UINT_PTR nIDEvent)
{
	HWND activeHwnd = ::GetForegroundWindow();
	if (activeHwnd == m_hWnd)
	{
		//AfxMessageBox("主窗口激活状态");
		if (m_IsHide) {
			this->DoModal();
		}
		CRect rect,rect2;
		GetClientRect(&rect2);
		GetWindowRect(&rect);
		
		//this->SetWindowPos(NULL, 0, 200, rect.Width(), rect.Height(), SWP_SHOWWINDOW);
		this->SetWindowPos(&CWnd::wndTopMost, rect.left, rect.top, rect.Width(), rect.Height(), SWP_NOMOVE | SWP_NOSIZE);

	}
	CDialogEx::OnTimer(nIDEvent);
}
