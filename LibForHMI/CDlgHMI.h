#pragma once


// CDlgHMI 对话框
#include "resource.h"
#include <afxcontrolbars.h> //很重要，缺省会找不到基类
typedef enum HMI_COMMAND_CODE {
	HMI_COMMAND_NEW = 100,
	HMI_COMMAND_OPEN ,
	HMI_COMMAND_SAVE ,
	HMI_COMMAND_CLOSE ,
	HMI_COMMAND_PRINT ,
	HMI_COMMAND_CUT,
	HMI_COMMAND_COPY,
	HMI_COMMAND_PASTE,
	HMI_COMMAND_DELETE,
	HMI_COMMAND_UNDO,
	HMI_COMMAND_REDO,
	HMI_COMMAND_FIND,
	HMI_COMMAND_REPLACE,
	HMI_COMMAND_MOVETOP
};
class CDlgHMI : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgHMI)

public:
	CDlgHMI(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgHMI();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_HMI };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	virtual HRESULT accDoDefaultAction(VARIANT varChild);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonNew();
	afx_msg void OnBnClickedButtonOpen();
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonClose();
	afx_msg void OnBnClickedButtonPrint();
	bool SendMsg(HMI_COMMAND_CODE code);
public:
	int m_buffer;
	HWND m_hWnd;
	bool m_IsHide;
	afx_msg void OnBnClickedButtonUndo();
	afx_msg void OnBnClickedButtonRedo();
	afx_msg void OnBnClickedButtonCut();
	afx_msg void OnBnClickedButtonCopy();
	afx_msg void OnBnClickedButtonPaste();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonFind();
	afx_msg void OnBnClickedButtonReplace();
	afx_msg void OnBnClickedButtonMoveTop();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
