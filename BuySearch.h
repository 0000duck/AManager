#pragma once
#include "afxcmn.h"


// CBuySearch �Ի���

class CBuySearch : public CDialogEx
{
	DECLARE_DYNAMIC(CBuySearch)

public:
	CBuySearch(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBuySearch();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BUYSEARCH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listCtrl;
	virtual BOOL OnInitDialog();
};
