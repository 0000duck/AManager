#pragma once
#include "afxwin.h"


// CBuy �Ի���

class CBuy : public CDialogEx
{
	DECLARE_DYNAMIC(CBuy)

public:
	CBuy(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBuy();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BUY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_inprice;
	CEdit m_inamount;
	CEdit m_firm;
	CEdit m_info;
	afx_msg void OnBnClickedOk();
	CString inprice;
	CString inamount;
	CString firm;
	CString info;
};
