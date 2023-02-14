#pragma once
#include "afxwinforms.h"

using namespace TPK_Laser;
//using namespace ClassLibrary1;

typedef void (*CB_FUNCTION)(float, float, float);

// CDlgUserControlCLR 對話方塊

class CDlgUserControlCLR : public CDialog
{
	DECLARE_DYNAMIC(CDlgUserControlCLR)

public:
	CDlgUserControlCLR(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~CDlgUserControlCLR();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_USERCONTROL_CLR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()

public:
	virtual void OnOK();
	virtual void OnCancel();

	CWinFormsControl<frmAOI_UI> m_TPKUC;	//在CLR層宣告C#類別
	//CWinFormsControl<UserControl1> m_TPKUC;	//在CLR層宣告C#類別

	BOOL InitWindow(CWnd* pWndParent);
	BOOL InitUserControl(int iX, int iY, int iViewWidth, int iViewHeight);
	void ChangeBtnToGreen();
	void ChangeBtnToRed();
	void SetCallBackFunction(CB_FUNCTION func);
};
