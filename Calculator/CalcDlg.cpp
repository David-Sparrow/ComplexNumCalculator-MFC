// CalcDlg.cpp : implementation file
//

#include "pch.h"
#include "Calculator.h"
#include "CalcDlg.h"
#include "afxdialogex.h"
#include "CCanonComplex.h"


// CCalcDlg dialog

IMPLEMENT_DYNAMIC(CCalcDlg, CDialog)

CCalcDlg::CCalcDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CALC, pParent)
	, m_fCompl1(0)
	, m_fCompl2(0)
	, m_nOperType(0)
	, m_fReal1(0)
	, m_fReal2(0)
{

}

CCalcDlg::~CCalcDlg()
{
}

void CCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_COMPL_1, m_fCompl1);
	DDX_Text(pDX, IDC_COMPL_2, m_fCompl2);
	DDX_Radio(pDX, IDC_PLUS, m_nOperType);
	DDX_Text(pDX, IDC_REAL_1, m_fReal1);
	DDX_Text(pDX, IDC_REAL_2, m_fReal2);
}


BEGIN_MESSAGE_MAP(CCalcDlg, CDialog)
	ON_BN_CLICKED(IDC_OBLICZ, &CCalcDlg::OnClickedOblicz)
	ON_BN_CLICKED(IDC_MOD, &CCalcDlg::DisableSecondCoupled)
	ON_BN_CLICKED(IDC_COUPL, &CCalcDlg::DisableSecondCoupled)
	ON_BN_CLICKED(IDC_PLUS, &CCalcDlg::EnableSecondCoupled)
	ON_BN_CLICKED(IDC_MINUS, &CCalcDlg::EnableSecondCoupled)
	ON_BN_CLICKED(IDC_MULT, &CCalcDlg::EnableSecondCoupled)
	ON_BN_CLICKED(IDC_DIV, &CCalcDlg::EnableSecondCoupled)
END_MESSAGE_MAP()


// CCalcDlg message handlers


void CCalcDlg::OnClickedOblicz()
{
	// TODO: Add your control notification handler code here

	UpdateData();

	CComplex num1(m_fReal1, m_fCompl1);
	CComplex num2(m_fReal2, m_fCompl2);

	CComplex complRes;
	switch (m_nOperType)
	{
	case 0:
		complRes = num1 + num2;
		break;
	case 1:
		complRes = num1 - num2;
		break;
	case 2:
		complRes = num1 * num2;
		break;
	case 3:
		complRes = num1 / num2;
		break;
	case 4:
		complRes = num1.Module();
		break;
	case 5:
		complRes = num1.Coupled();
		break;
	}

	CCanonComplex result(complRes);
	CString cstrResult;
	cstrResult << result;
	CWnd* pWnd = GetDlgItem(IDC_RESULT);
	pWnd->SetWindowTextW(cstrResult);
}


void CCalcDlg::DisableSecondCoupled()
{
	// TODO: Add your control notification handler code here
	CWnd* pWnd = GetDlgItem(IDC_REAL_2);
	pWnd->EnableWindow(FALSE);
	pWnd = GetDlgItem(IDC_COMPL_2);
	pWnd->EnableWindow(FALSE);
}


void CCalcDlg::EnableSecondCoupled()
{
	// TODO: Add your control notification handler code here
	CWnd* pWnd = GetDlgItem(IDC_REAL_2);
	pWnd->EnableWindow(TRUE);
	pWnd = GetDlgItem(IDC_COMPL_2);
	pWnd->EnableWindow(TRUE);
}

