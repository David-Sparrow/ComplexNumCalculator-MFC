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
	, m_nCompl1(0)
	, m_nCompl2(0)
	, m_nOperType(0)
	, m_nReal1(0)
	, m_nReal2(0)
{

}

CCalcDlg::~CCalcDlg()
{
}

void CCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_COMPL_1, m_nCompl1);
	DDX_Text(pDX, IDC_COMPL_2, m_nCompl2);
	DDX_Radio(pDX, IDC_PLUS, m_nOperType);
	DDX_Text(pDX, IDC_REAL_1, m_nReal1);
	DDX_Text(pDX, IDC_REAL_2, m_nReal2);
}


BEGIN_MESSAGE_MAP(CCalcDlg, CDialog)
	ON_BN_CLICKED(IDC_OBLICZ, &CCalcDlg::OnClickedOblicz)
END_MESSAGE_MAP()


// CCalcDlg message handlers


void CCalcDlg::OnClickedOblicz()
{
	// TODO: Add your control notification handler code here

	UpdateData();

	CComplex num1(m_nReal1, m_nCompl1);
	CComplex num2(m_nReal2, m_nCompl2);

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
	std::string str; 
	str << result; //Przeciazony operator <<
	CString cstrResult(str.c_str());
	CWnd* pWnd = GetDlgItem(IDC_RESULT);
	pWnd->SetWindowTextW(cstrResult);
}
