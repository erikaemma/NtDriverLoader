// NtDriverLoaderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NtDriverLoader.h"
#include "NtDriverLoaderDlg.h"

#include "MD5Checksum.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNtDriverLoaderDlg dialog

CNtDriverLoaderDlg::CNtDriverLoaderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNtDriverLoaderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNtDriverLoaderDlg)
	m_SysFile = _T("");
	m_Status = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_SrvName = _T("");
	m_bHasSeled = FALSE;
}

void CNtDriverLoaderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNtDriverLoaderDlg)
	DDX_Control(pDX, IDC_Btn_SCM, m_BtnSCM);
	DDX_Control(pDX, IDC_BTN_LOOKFOR, m_Btn_Lookfor);
	DDX_Control(pDX, IDC_BTN_INSTALL, m_Btn_Install);
	DDX_Control(pDX, IDC_BTN_START, m_Btn_Start);
	DDX_Control(pDX, IDC_BTN_STOP, m_Btn_Stop);
	DDX_Control(pDX, IDC_BTN_UNINSTALL, m_Btn_Uninstall);
	DDX_Text(pDX, IDC_EDIT_SYSFILE, m_SysFile);
	DDX_Text(pDX, IDC_STATIC_STATUS, m_Status);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNtDriverLoaderDlg, CDialog)
	//{{AFX_MSG_MAP(CNtDriverLoaderDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_LOOKFOR, OnBtnLookfor)
	ON_BN_CLICKED(IDC_BTN_INSTALL, OnBtnInstall)
	ON_BN_CLICKED(IDC_BTN_START, OnBtnStart)
	ON_BN_CLICKED(IDC_BTN_STOP, OnBtnStop)
	ON_BN_CLICKED(IDC_BTN_UNINSTALL, OnBtnUninstall)
	ON_BN_CLICKED(IDC_BTN_HELP, OnBtnHelp)
	ON_BN_CLICKED(IDC_BTN_EXIT, OnBtnExit)
	ON_BN_CLICKED(IDC_BTN_ABOUT, OnBtnAbout)
	ON_BN_CLICKED(IDC_Btn_SCM, OnBtnSCM)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNtDriverLoaderDlg message handlers

BOOL CNtDriverLoaderDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	InitSCMgr();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNtDriverLoaderDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CNtDriverLoaderDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CNtDriverLoaderDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CNtDriverLoaderDlg::OnBtnLookfor() 
{
	SwitchEnable();
	CFileDialog SysFileObj(TRUE, "sys", NULL, OFN_FILEMUSTEXIST, _T("�ں������ļ�(*.sys)|*.sys||"), NULL);
	if(SysFileObj.DoModal() == IDOK)
	{
		m_SysFile = SysFileObj.GetPathName();
		m_SrvName = SysFileObj.GetFileTitle();
		m_bHasSeled = TRUE;
		m_Status = _T("��Ҫ��װ��������Ϊ��") + m_SrvName;
		UpdateData(FALSE);
		SwitchEnable(NULL, TRUE);
		AfxMessageBox(_T("���ļ���MD5Ϊ��") + CMD5Checksum::GetMD5(m_SysFile));
	}
	else
	{
		m_Status = _T("��ȡ����ѡ���ļ���");
		m_bHasSeled = FALSE;
		UpdateData(FALSE);
	}
}

void CNtDriverLoaderDlg::OnBtnInstall() 
{
	SwitchEnable(&m_Btn_Uninstall);
	if(!m_hScm)
		if(!InitSCMgr())
			return;
	SC_HANDLE hNtDrv = CreateService(m_hScm,
									(LPSTR)(LPCSTR)m_SrvName,
									(LPSTR)(LPCSTR)m_SrvName,
									SERVICE_ALL_ACCESS,
									SERVICE_KERNEL_DRIVER,
									SERVICE_DEMAND_START,
									SERVICE_ERROR_IGNORE,
									(LPSTR)(LPCSTR)m_SysFile,
									NULL,
									NULL,
									NULL,
									NULL,
									NULL);
	if(hNtDrv == NULL)
	{
		DWORD dwRtn = GetLastError();
		if(dwRtn != ERROR_IO_PENDING && dwRtn != ERROR_SERVICE_EXISTS)
			m_Status.Format(_T("��������װʧ�ܣ�%d"), dwRtn);
		else
			m_Status = _T("��������װʧ�ܣ������Ѵ��ڣ�");
	}
	else
	{
		m_Status = _T("��������װ�ɹ���");
	}
	UpdateData(FALSE);
	CloseServiceHandle(hNtDrv);
	SwitchEnable(NULL, TRUE);
}

void CNtDriverLoaderDlg::OnBtnStart() 
{
	SwitchEnable(&m_Btn_Start);
	if(!m_hScm)
		if(!InitSCMgr())
			return;
	SC_HANDLE hNtDrv = OpenService(m_hScm, (LPSTR)(LPCSTR)m_SrvName, SERVICE_ALL_ACCESS);
	if(hNtDrv == NULL)
	{
		m_Status.Format(_T("����������ʧ�ܣ�%d"), GetLastError());
	}
	else
	{
		if(!StartService(hNtDrv, NULL, NULL))
		{
			DWORD dwRtn = GetLastError();
			if(dwRtn != ERROR_IO_PENDING && dwRtn != ERROR_SERVICE_ALREADY_RUNNING)
				m_Status.Format(_T("������������ʧ�ܣ�%d"), dwRtn);
			else
			{
				if(dwRtn == ERROR_IO_PENDING)
					m_Status = _T("������������ʧ�ܣ�ERROR_IO_PENDING");
				else
					m_Status = _T("������������ʧ�ܣ�ERROR_SERVICE_ALREADY_RUNNING");
			}
		}
		else
		{
			m_Status = _T("������������ɹ���");
		}
	}
	UpdateData(FALSE);
	CloseServiceHandle(hNtDrv);
	SwitchEnable(NULL, TRUE);
}

void CNtDriverLoaderDlg::OnBtnStop() 
{
	SwitchEnable(&m_Btn_Stop);
	if(!m_hScm)
		if(!InitSCMgr())
			return;
	SC_HANDLE hNtDrv = OpenService(m_hScm, (LPSTR)(LPCSTR)m_SrvName, SERVICE_ALL_ACCESS);
	if(hNtDrv == NULL)
	{
		m_Status.Format(_T("����������ʧ�ܣ�%d"), GetLastError());
	}
	else
	{
		SERVICE_STATUS SrvSta;
		int i;
		for(i = 1; i <= 5; ++i)
			if(ControlService(hNtDrv, SERVICE_CONTROL_STOP, &SrvSta))
				if(SrvSta.dwCurrentState == SERVICE_STOPPED)
					break;
		if(SrvSta.dwCurrentState == SERVICE_STOPPED)
			m_Status.Format(_T("ֹͣ��������ɹ���%d�Σ�"), i);
		else
			m_Status = _T("ֹͣ��������ʧ�ܣ��Ѿ�������5�Σ�");
	}
	UpdateData(FALSE);
	CloseServiceHandle(hNtDrv);
	SwitchEnable(NULL, TRUE);
}

void CNtDriverLoaderDlg::OnBtnUninstall() 
{
	
	SwitchEnable(&m_Btn_Uninstall);
	if(!m_hScm)
		if(!InitSCMgr())
			return;
	SC_HANDLE hNtDrv = OpenService(m_hScm, (LPSTR)(LPCSTR)m_SrvName, SERVICE_ALL_ACCESS);
	if(hNtDrv == NULL)
	{
		m_Status.Format(_T("����������ʧ�ܣ�%d"), GetLastError());
	}
	else
	{
		if(DeleteService(hNtDrv))
			m_Status = _T("��������ж�سɹ���");
		else
			m_Status.Format(_T("��������ж��ʧ�ܣ�%d"), GetLastError());
	}
	UpdateData(FALSE);
	CloseServiceHandle(hNtDrv);
	SwitchEnable(NULL, TRUE);
}

void CNtDriverLoaderDlg::OnBtnHelp() 
{
	AfxMessageBox(_T("������δʵ�֣�"));
}

void CNtDriverLoaderDlg::OnBtnExit() 
{
	if(AfxMessageBox(_T("��ȷ��Ҫ�˳���"), MB_YESNO) == IDYES)
	{
		if(m_hScm)
			CloseServiceHandle(m_hScm);
		ExitProcess(0);
	}
}

void CNtDriverLoaderDlg::OnBtnAbout() 
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

VOID CNtDriverLoaderDlg::SwitchEnable(CButton * btn, BOOL toEnable)
{
	m_Btn_Install.EnableWindow(toEnable);
	m_Btn_Uninstall.EnableWindow(toEnable);
	m_Btn_Start.EnableWindow(toEnable);
	m_Btn_Stop.EnableWindow(toEnable);
	if(btn)
		btn->EnableWindow(!toEnable);
}

BOOL CNtDriverLoaderDlg::InitSCMgr()
{
	m_hScm = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if(m_hScm == NULL)
	{
		m_Status = _T("��SCM����ʧ�ܣ������»���������SCM���񡱰�ť��һ�ԣ�");
		SwitchEnable();
		m_Btn_Lookfor.EnableWindow(FALSE);
		m_BtnSCM.SetWindowText(_T("����SCM����(&B)"));
		UpdateData(FALSE);
		return FALSE;
	}
	else
	{
		m_Status = _T("��ӭʹ�ã�SCM����������");
		SwitchEnable();
		m_Btn_Lookfor.EnableWindow(TRUE);
		m_BtnSCM.SetWindowText(_T("������SCM����(&B)"));
		UpdateData(FALSE);
		return TRUE;
	}
}

BOOL CNtDriverLoaderDlg::PreTranslateMessage(MSG* pMsg) 
{
	if(pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)return TRUE;
	if(pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)return TRUE;
	
	return CDialog::PreTranslateMessage(pMsg);
}

void CNtDriverLoaderDlg::OnBtnSCM() 
{
	if(m_hScm)
	{
		CloseServiceHandle(m_hScm);
		if(InitSCMgr())
		{
			m_Status = _T("������SCM����ɹ���");
			m_BtnSCM.SetWindowText(_T("������SCM����(&B)"));
		}
		else
		{
			m_Status = _T("������SCM����ʧ�ܣ����ù���ԱȨ����һ�ԣ�");
			m_BtnSCM.SetWindowText(_T("����SCM����(&B)"));
		}
	}
	else
	{
		if(InitSCMgr())
		{
			m_Status = _T("����SCM����ɹ���");
			m_BtnSCM.SetWindowText(_T("����SCM����(&B)"));
		}
		else
		{
			m_Status = _T("����SCM����ʧ�ܣ����ù���ԱȨ����һ�ԣ�");
			m_BtnSCM.SetWindowText(_T("����SCM����(&B)"));
		}
	}
	UpdateData(FALSE);
}
