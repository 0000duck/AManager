#pragma once
#include "afxcmn.h"


// CADDSEARCH �Ի���

class CADDSEARCH : public CDialogEx
{
	DECLARE_DYNAMIC(CADDSEARCH)

public:
	CADDSEARCH(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CADDSEARCH();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEARCHADD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listCtrl;
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
};
