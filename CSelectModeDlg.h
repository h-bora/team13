#pragma once
#include "RCcircuit.h" 
#include "afxdialogex.h"


// CSelectModeDlg 대화 상자

class CSelectModeDlg : public CDialogEx
{
    DECLARE_DYNAMIC(CSelectModeDlg)

public:
    CSelectModeDlg(CWnd* pParent = nullptr);
    virtual ~CSelectModeDlg();

    afx_msg void OnBnClickedImageProcess();  //버튼클릭-이미지처리 다이얼로그 전환

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_SELECT_MODE };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);

    afx_msg void OnBnClickedBtnSimulate();  

    DECLARE_MESSAGE_MAP()

private:
    RCcircuit rc;  
public:
    afx_msg void OnBnClickedBtnCircuit();
};
