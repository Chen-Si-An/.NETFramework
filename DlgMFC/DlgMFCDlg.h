
// DlgMFCDlg.h: 標頭檔
//

#pragma once

typedef LONG_PTR(__stdcall* CREATE_DIALOG)();
typedef void(__stdcall* FREE_DIALOG)(LONG_PTR lLibPtr);
typedef BOOL(__stdcall* INIT_WINDOW)(LONG_PTR lLibPtr, CWnd* pWndParent);
typedef void(__stdcall* SHOW_VIEW)(LONG_PTR lLibPtr, BOOL bShow);
typedef HWND(__stdcall* GET_HANDLE)(LONG_PTR lLibPtr);
typedef BOOL(__stdcall* INIT_USER_CONTROL)(LONG_PTR lLibPtr, int iX, int iY, int iViewWidth, int iViewHeight);

typedef void(__stdcall* CHANGE_BTN_TO_GREEN)(LONG_PTR lLibPtr);
typedef void(__stdcall* CHANGE_BTN_TO_RED)(LONG_PTR lLibPtr);
typedef void(__stdcall* SET_CB_FUNC)(LONG_PTR lLibPtr, LONG_PTR func);

typedef void(__stdcall* MARK_FINDER_SHOW)(LONG_PTR lLibPtr, LONG_PTR func);


// CDlgMFCDlg 對話方塊
class CDlgMFCDlg : public CDialogEx
{
// 建構
public:
	CDlgMFCDlg(CWnd* pParent = nullptr);	// 標準建構函式

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLGMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援


// 程式碼實作
protected:
	HICON m_hIcon;

	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
	virtual BOOL DestroyWindow();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	HINSTANCE  m_hDriver;
	CREATE_DIALOG m_CreateDialog;
	FREE_DIALOG m_FreeDialog;
	INIT_WINDOW m_InitWindow;
	SHOW_VIEW m_ShowView;
	GET_HANDLE m_GetHandle;
	INIT_USER_CONTROL m_InitUserControl;

	CHANGE_BTN_TO_GREEN m_ChangeBtnToGreen;
	CHANGE_BTN_TO_RED m_ChangeBtnToRed;
	SET_CB_FUNC m_SetCbFunc;
	BOOL LoadUCCLRLib();

	MARK_FINDER_SHOW m_MarkFinderShow;
	BOOL LoadLaserCLRLib();

	LONG_PTR m_lptrDlgCLR;
	void InitCCD();
	void ChangeEditorValue(int iX, int iY, double dR);

	afx_msg void OnBnClickedButtonGreen();
	afx_msg void OnBnClickedButtonRed();
};
