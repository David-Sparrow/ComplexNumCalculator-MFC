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
	int m_nCompl1;
	int m_nCompl2;
	int m_nOperType;
	int m_nReal1;
	int m_nReal2;
public:
	afx_msg void OnClickedOblicz();
};
