#include "pch.h"
#include "CSelectModeDlg.h"

class CTeam13App : public CWinApp
{
public:
    virtual BOOL InitInstance();
};

CTeam13App theApp;

BOOL CTeam13App::InitInstance()
{
    CWinApp::InitInstance();

    CSelectModeDlg dlg;
    m_pMainWnd = &dlg;
    dlg.DoModal();

    return FALSE;
}
