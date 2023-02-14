#pragma once


// CDlgView 對話方塊

class CDlgView : public CDialog
{
	DECLARE_DYNAMIC(CDlgView)

public:
	CDlgView(CWnd* pParent = NULL);   // 標準建構函式
	virtual ~CDlgView();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_VIEW};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	BOOL	InitWindow(CRect rectPage, CWnd *pParent, HWND hCLRWnd);
};
