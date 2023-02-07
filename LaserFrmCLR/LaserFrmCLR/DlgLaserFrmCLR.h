#pragma once
#include "afxwinforms.h"

using namespace TPK_Laser;

// CDlgLaserFrmCLR 對話方塊

class CDlgLaserFrmCLR : public CDialog
{
	DECLARE_DYNAMIC(CDlgLaserFrmCLR)

// 建構
public:
	CDlgLaserFrmCLR(CWnd* pParent = nullptr);	// 標準建構函式

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_LASERFRM_CLR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援

	DECLARE_MESSAGE_MAP()

public:
	virtual void OnOK();
	virtual void OnCancel();

	CWinFormsControl<frmTPK_Laser> m_TPKLaser;	//在CLR層宣告C#類別

	BOOL InitWindow(CWnd* pWndParent);
	BOOL InitUserControl(int iX, int iY, int iViewWidth, int iViewHeight);
	void MarkFinderShow();
};
