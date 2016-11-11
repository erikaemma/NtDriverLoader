// NtDriverLoaderDlg.h : header file
//

#if !defined(AFX_NTDRIVERLOADERDLG_H__9FF41546_81F0_4FD8_9C16_BC54601A3E2E__INCLUDED_)
#define AFX_NTDRIVERLOADERDLG_H__9FF41546_81F0_4FD8_9C16_BC54601A3E2E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <winsvc.h>

/////////////////////////////////////////////////////////////////////////////
// CNtDriverLoaderDlg dialog

class CNtDriverLoaderDlg : public CDialog
{
// Construction
public:
	CNtDriverLoaderDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNtDriverLoaderDlg)
	enum { IDD = IDD_NTDRIVERLOADER_DIALOG };
	CButton	m_BtnSCM;
	CButton	m_Btn_Lookfor;
	CButton	m_Btn_Install;
	CButton	m_Btn_Start;
	CButton	m_Btn_Stop;
	CButton	m_Btn_Uninstall;
	CString	m_SysFile;
	CString	m_Status;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNtDriverLoaderDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNtDriverLoaderDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnLookfor();
	afx_msg void OnBtnInstall();
	afx_msg void OnBtnStart();
	afx_msg void OnBtnStop();
	afx_msg void OnBtnUninstall();
	afx_msg void OnBtnHelp();
	afx_msg void OnBtnExit();
	afx_msg void OnBtnAbout();
	afx_msg void OnBtnSCM();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_SrvName;
	BOOL m_bHasSeled;
	VOID SwitchEnable(CButton * btn = NULL, BOOL toEnable = FALSE);
	SC_HANDLE m_hScm;
	BOOL InitSCMgr();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NTDRIVERLOADERDLG_H__9FF41546_81F0_4FD8_9C16_BC54601A3E2E__INCLUDED_)
