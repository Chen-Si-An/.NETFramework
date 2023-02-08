// DlgUserControlCLR.cpp: 實作檔案
//

#include "pch.h"
#include "UserControlCLR.h"
#include "afxdialogex.h"
#include "DlgUserControlCLR.h"


// CDlgUserControlCLR 對話方塊

CB_FUNCTION g_cbFunction = NULL;

//void CB_Event(int iX, int iY, double dR)
//{
//	if (g_cbFunction)
//		g_cbFunction(iX, iY, dR);
//}

void CB_MoveEvent(float fX, float fY, float fR)
{
	if (g_cbFunction)
		g_cbFunction(fX, fY, fR);
}

bool CB_MoveDoneEvent()
{
	return false;
}

IMPLEMENT_DYNAMIC(CDlgUserControlCLR, CDialog)

CDlgUserControlCLR::CDlgUserControlCLR(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DLG_USERCONTROL_CLR, pParent)
{

}

CDlgUserControlCLR::~CDlgUserControlCLR()
{
}

void CDlgUserControlCLR::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_ManagedControl(pDX, IDC_BUTTON_DISPLAY, m_TPKUC);
}


BEGIN_MESSAGE_MAP(CDlgUserControlCLR, CDialog)
END_MESSAGE_MAP()


// CDlgUserControlCLR 訊息處理常式


void CDlgUserControlCLR::OnOK()
{
	//CDialog::OnOK();
}


void CDlgUserControlCLR::OnCancel()
{
	//CDialog::OnCancel();
}


BOOL CDlgUserControlCLR::InitWindow(CWnd* pWndParent)
{
	if (!m_hWnd)
		if (!Create(IDD_DLG_USERCONTROL_CLR))
			return FALSE;

	ShowWindow(SW_HIDE);

	//m_TPKUC->DoCallbackEvent += gcnew UserControl1::DelCallback(CB_Event);
	m_TPKUC->AOI_Move += gcnew frmAOI_UI::DelMoveCallback(CB_MoveEvent);
	m_TPKUC->AOI_MoveDone += gcnew frmAOI_UI::DelMoveDoneCallback(CB_MoveDoneEvent);

	return TRUE;
}


BOOL CDlgUserControlCLR::InitUserControl(int iX, int iY, int iViewWidth, int iViewHeight)
{
	if (m_TPKUC.m_hWnd)
	{
		MoveWindow(iX, iY, iViewWidth, iViewHeight);
		GetDlgItem(IDC_BUTTON_DISPLAY)->SetWindowPos(NULL, 0, 0, iViewWidth, iViewHeight, SWP_NOMOVE);
	}

	return TRUE;
}


void CDlgUserControlCLR::ChangeBtnToGreen()
{
	/*
	if (m_TPKUC.m_hWnd)
		m_TPKUC->ChangeBtnToGreen();
	*/
	//m_TPKUC->btn->BackColor = System::Drawing::Color().Green;
}


void CDlgUserControlCLR::ChangeBtnToRed()
{
	/*
	if (m_TPKUC.m_hWnd)
		m_TPKUC->ChangeBtnToRed();
	*/
	//m_TPKUC->btn->BackColor = System::Drawing::Color().Red;
}


void CDlgUserControlCLR::SetCallBackFunction(CB_FUNCTION func)
{
	g_cbFunction = func;
}
