#pragma once
#include "afxcmn.h"


// CSellSearch �Ի���

class CSellSearch : public CDialogEx
{
	DECLARE_DYNAMIC(CSellSearch)

public:
	CSellSearch(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSellSearch();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEARCHBYSELL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_listCtrl;
};
