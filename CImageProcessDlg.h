#pragma once
#include "afxdialogex.h"

class CImageProcessDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CImageProcessDlg)

public:
	CImageProcessDlg(CWnd* pParent = nullptr);   // ������
	virtual ~CImageProcessDlg();                 // �Ҹ���

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };                 // ���ҽ� ID: IDD_DIALOG2 �´��� Ȯ���ϰ�
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ������ ��ȯ ����
	DECLARE_MESSAGE_MAP()
};
