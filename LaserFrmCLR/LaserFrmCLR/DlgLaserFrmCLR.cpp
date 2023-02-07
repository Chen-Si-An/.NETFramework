// LaserFrmCLRDlg.cpp: 實作檔案
//

#include "pch.h"
#include "LaserFrmCLR.h"
#include "afxdialogex.h"
#include "DlgLaserFrmCLR.h"


// CDlgLaserFrmCLR 對話方塊

IMPLEMENT_DYNAMIC(CDlgLaserFrmCLR, CDialog)

CDlgLaserFrmCLR::CDlgLaserFrmCLR(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DLG_LASERFRM_CLR, pParent)
{
	
}

void CDlgLaserFrmCLR::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_ManagedControl(pDX, IDC_BUTTON_DISPLAY, m_TPKLaser);
}


BEGIN_MESSAGE_MAP(CDlgLaserFrmCLR, CDialog)
END_MESSAGE_MAP()


// CDlgLaserFrmCLR 訊息處理常式


void CDlgLaserFrmCLR::OnOK()
{
	//CDialogEx::OnOK();
}


void CDlgLaserFrmCLR::OnCancel()
{
	//CDialogEx::OnCancel();
}


BOOL CDlgLaserFrmCLR::InitWindow(CWnd* pWndParent)
{
	if (!m_hWnd)
		if (!Create(IDD_DLG_LASERFRM_CLR))
			return FALSE;

	ShowWindow(SW_HIDE);

	return TRUE;
}


BOOL CDlgLaserFrmCLR::InitUserControl(int iX, int iY, int iViewWidth, int iViewHeight)
{
	if (m_TPKLaser.m_hWnd)
	{
		MoveWindow(iX, iY, iViewWidth, iViewHeight);
		GetDlgItem(IDC_BUTTON_DISPLAY)->SetWindowPos(NULL, 0, 0, iViewWidth, iViewHeight, SWP_NOMOVE);
	}

	return TRUE;
}


void CDlgLaserFrmCLR::MarkFinderShow()
{
	m_TPKLaser->AOI_MarkFinderShow();
}
