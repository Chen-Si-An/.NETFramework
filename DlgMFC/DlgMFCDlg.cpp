
// DlgMFCDlg.cpp: 實作檔案
//

#include "pch.h"
#include "framework.h"
#include "DlgMFC.h"
#include "DlgMFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CDlgMFCDlg* g_pMainDlg;

extern TCHAR g_szModulePath[MAX_PATH];


// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDlgMFCDlg 對話方塊



CDlgMFCDlg::CDlgMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLGMFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	g_pMainDlg = this;
}

void CDlgMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDlgMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_GREEN, &CDlgMFCDlg::OnBnClickedButtonGreen)
	ON_BN_CLICKED(IDC_BUTTON_RED, &CDlgMFCDlg::OnBnClickedButtonRed)
END_MESSAGE_MAP()


// CDlgMFCDlg 訊息處理常式

BOOL CDlgMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 將 [關於...] 功能表加入系統功能表。

	// IDM_ABOUTBOX 必須在系統命令範圍之中。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO: 在此加入額外的初始設定
	LoadUCCLRLib();
	//LoadLaserCLRLib();

	InitCCD();

	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

BOOL CDlgMFCDlg::DestroyWindow()
{
	m_FreeDialog(m_lptrDlgCLR);

	return CDialogEx::DestroyWindow();
}

void CDlgMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CDlgMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CDlgMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CB_Function(int iX, int iY, double dR)
{
	g_pMainDlg->ChangeEditorValue(iX, iY, dR);
};


BOOL CDlgMFCDlg::LoadUCCLRLib()
{
	CString strDll;
	strDll.Format(_T("%sUserControlCLR.dll"), g_szModulePath);

	m_hDriver = LoadLibrary(strDll);
	if (!m_hDriver)
		return FALSE;

	m_CreateDialog = (CREATE_DIALOG)GetProcAddress(m_hDriver, "CLR_CreateDialog");
	m_FreeDialog = (FREE_DIALOG)GetProcAddress(m_hDriver, "CLR_FreeDialog");
	m_InitWindow = (INIT_WINDOW)GetProcAddress(m_hDriver, "CLR_InitWindow");
	m_ShowView = (SHOW_VIEW)GetProcAddress(m_hDriver, "CLR_ShowView");
	m_GetHandle = (GET_HANDLE)GetProcAddress(m_hDriver, "CLR_GetHandle");
	m_InitUserControl = (INIT_USER_CONTROL)GetProcAddress(m_hDriver, "CLR_InitUserControl");
	m_ChangeBtnToGreen = (CHANGE_BTN_TO_GREEN)GetProcAddress(m_hDriver, "CLR_ChangeBtnToGreen");
	m_ChangeBtnToRed = (CHANGE_BTN_TO_RED)GetProcAddress(m_hDriver, "CLR_ChangeBtnToRed");
	m_SetCbFunc = (SET_CB_FUNC)GetProcAddress(m_hDriver, "CLR_SetCallBackFunction");

	return TRUE;
}


BOOL CDlgMFCDlg::LoadLaserCLRLib()
{
	CString strDll;
	strDll.Format(_T("%sLaserFrmCLR.dll"), g_szModulePath);

	m_hDriver = LoadLibrary(strDll);
	if (!m_hDriver)
		return FALSE;

	m_CreateDialog = (CREATE_DIALOG)GetProcAddress(m_hDriver, "CLR_CreateDialog");
	m_FreeDialog = (FREE_DIALOG)GetProcAddress(m_hDriver, "CLR_FreeDialog");
	m_InitWindow = (INIT_WINDOW)GetProcAddress(m_hDriver, "CLR_InitWindow");
	m_ShowView = (SHOW_VIEW)GetProcAddress(m_hDriver, "CLR_ShowView");
	m_GetHandle = (GET_HANDLE)GetProcAddress(m_hDriver, "CLR_GetHandle");
	m_InitUserControl = (INIT_USER_CONTROL)GetProcAddress(m_hDriver, "CLR_InitUserControl");
	m_MarkFinderShow = (MARK_FINDER_SHOW)GetProcAddress(m_hDriver, "CLR_MarkFinderShow");

	return TRUE;
}


void CDlgMFCDlg::InitCCD()
{
	CRect rectView;
	GetDlgItem(IDC_STATIC_CCD)->GetWindowRect(rectView);
	ScreenToClient(rectView);

	m_lptrDlgCLR = m_CreateDialog();
	m_InitWindow(m_lptrDlgCLR, this);
	m_InitUserControl(m_lptrDlgCLR, rectView.left, rectView.top, rectView.Width(), rectView.Height());

	if (m_SetCbFunc)
		m_SetCbFunc(m_lptrDlgCLR, (LONG_PTR)CB_Function);

	HWND hCLRDisplayWnd = (HWND)m_lptrDlgCLR;
	::SetParent(hCLRDisplayWnd, GetDlgItem(IDC_STATIC_CCD)->m_hWnd);
	//CWnd *pWnd = FromHandle(hCLRDisplayWnd);
	//pWnd->ShowWindow(SW_SHOW);
	m_ShowView(m_lptrDlgCLR, TRUE);
}


void CDlgMFCDlg::ChangeEditorValue(int iX, int iY, double dR)
{
	CString str;

	str.Format(_T("%d"), iX);
	GetDlgItem(IDC_EDIT_X)->SetWindowText(str);

	str.Format(_T("%d"), iY);
	GetDlgItem(IDC_EDIT_Y)->SetWindowText(str);

	str.Format(_T("%.3lf"), dR);
	GetDlgItem(IDC_EDIT_R)->SetWindowText(str);
}


void CDlgMFCDlg::OnBnClickedButtonGreen()
{
	m_ChangeBtnToGreen(m_lptrDlgCLR);
}


void CDlgMFCDlg::OnBnClickedButtonRed()
{
	m_ChangeBtnToRed(m_lptrDlgCLR);
}
