#pragma once


// CSell �Ի���

class CSell : public CDialogEx
{
	DECLARE_DYNAMIC(CSell)

public:
	CSell(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSell();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SELL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
