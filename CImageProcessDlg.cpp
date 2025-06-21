#include "pch.h"
#include "CImageProcessDlg.h"

IMPLEMENT_DYNAMIC(CImageProcessDlg, CDialogEx)

CImageProcessDlg::CImageProcessDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{
}

CImageProcessDlg::~CImageProcessDlg()
{
}

void CImageProcessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CImageProcessDlg, CDialogEx)
END_MESSAGE_MAP()
