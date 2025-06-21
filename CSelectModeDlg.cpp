#include "pch.h"
#include "resource.h"
#include "imageYUEE.h"
#include "RCcircuit.h"
#include "afxdialogex.h"
#include "CSelectModeDlg.h"
#include "CImageProcessDlg.h"


// CSelectModeDlg 대화 상자

IMPLEMENT_DYNAMIC(CSelectModeDlg, CDialogEx)

CSelectModeDlg::CSelectModeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SELECT_MODE, pParent)
{

}

CSelectModeDlg::~CSelectModeDlg()
{
}

void CSelectModeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSelectModeDlg, CDialogEx)
    ON_BN_CLICKED(IDC_BTN_SIMULATE, &CSelectModeDlg::OnBnClickedImageProcess)
    ON_BN_CLICKED(IDC_BTN_CIRCUIT, &CSelectModeDlg::OnBnClickedBtnCircuit)
END_MESSAGE_MAP()

void CSelectModeDlg::OnBnClickedImageProcess()
{
    CImageProcessDlg dlg;
    dlg.DoModal();
}

// 이미지 처리기 부분

void CSelectModeDlg::OnBnClickedBtnSimulate()
{
    // 처리 이미지 파일 이름, 저장할 결과 파일 이름
    CString inputFile = _T("na256.pgm");
    CString outputFile = _T("result.pgm");

    // 이미지 처리 모드 설정 (0: 이진화, 1: 반전, 2: 밝기 증가)
    int mode = 1;  

    imageYUEE img(inputFile);
    img.imageProc(mode);
    img.imageWrite(outputFile);

    // 완료 메시지
    AfxMessageBox(_T("이미지 처리가 완료되었습니다."));
}
    // RC 시뮬레이션 부분
void CSelectModeDlg::OnBnClickedBtnCircuit()
{
    // 회로 파라미터 입력
    double R = 1000.0;    // 1k ohm
    double C = 0.001;     // 1mF
    double Vin = 5.0;     // 5V

    // 시뮬 시작
    rc.simulate(R, C, Vin);

    // 결과 가져옴
    const std::vector<double>& voltages = rc.getVoltageArray();

    // 메시지박스에 첫 5개 출력해보기
    CString msg;
    msg += _T("RC Circuit Simulation Result\n");
    for (int i = 0; i < 5 && i < voltages.size(); ++i) {
        CString line;
        line.Format(_T("t=%.1fs, V=%.2fV\n"), i * 0.01, voltages[i]);
        msg += line;
    }
    AfxMessageBox(msg);
}