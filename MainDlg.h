#pragma once
#include "afxwin.h"
#include "afxcmn.h"

// CMainDlg �Ի���

class CMainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMainDlg)

public:
	CMainDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMainDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAINDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
//	CListBox m_ListBox;
	CButton m_Update;
	CListCtrl m_listCtrl;
//	virtual BOOL OnInitDialog();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedSearch();
	void ShowInfo();
	CButton m_add;
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedModify();
	afx_msg void OnBnClickedBuy();
	int m_ID;
	int m_name;
	int m_firm;
	CEdit m_EditContral;
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedSell();
	CEdit m_amount;
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton2();
};
