#pragma once


// CCalcDlg dialog

class CCalcDlg : public CDialog
{
	DECLARE_DYNAMIC(CCalcDlg)

public:
	CCalcDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CCalcDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	float m_fCompl1;
	float m_fCompl2;
	int m_nOperType;
	float m_fReal1;
	float m_fReal2;
public:
	afx_msg void OnClickedOblicz();
	afx_msg void DisableSecondCoupled();
	afx_msg void EnableSecondCoupled();
};
