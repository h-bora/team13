#pragma once
#include "afxdialogex.h"

class CImageProcessDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CImageProcessDlg)

public:
	CImageProcessDlg(CWnd* pParent = nullptr);   // 생성자
	virtual ~CImageProcessDlg();                 // 소멸자

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };                 // 리소스 ID: IDD_DIALOG2 맞는지 확인하고
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // 데이터 교환 과정
	DECLARE_MESSAGE_MAP()
};
