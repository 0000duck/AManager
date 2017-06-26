// Add.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Manager.h"
#include "Add.h"
#include "afxdialogex.h"
#include "MainDlg.h"

// CAdd �Ի���

IMPLEMENT_DYNAMIC(CAdd, CDialogEx)

CAdd::CAdd(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADD, pParent)
{

}

CAdd::~CAdd()
{
}

void CAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_ID);
	DDX_Control(pDX, IDC_EDIT2, m_name);
	DDX_Control(pDX, IDC_EDIT3, m_price);
	DDX_Control(pDX, IDC_EDIT4, m_firm);
}


BEGIN_MESSAGE_MAP(CAdd, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAdd::OnBnClickedOk)
END_MESSAGE_MAP()


// CAdd ��Ϣ�������


void CAdd::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDatabase m_db;
	m_db.Open(NULL, FALSE, FALSE, _T("ODBC;FILEDSN=.\\Manager.dsn;UID=admin"),true);
	CRecordset *m_pSet = new CRecordset();
	m_pSet->m_pDatabase = &m_db;

	CStringW ID, name, strPrice, firm;
	CStringW sql;
	m_ID.GetWindowTextW(ID);
	m_name.GetWindowTextW(name);
	m_price.GetWindowTextW(strPrice);
	m_firm.GetWindowTextW(firm);

	//�ж��Ƿ�������Ϊ��
	if ("" == ID)
	{
		MessageBox(_T("���Ϊ�գ��������"));
		EndDialog(0);
	}
	if ("" == name)
	{
		MessageBox(_T("ҩƷ��Ϊ�գ��������"));
		EndDialog(0);
	}
	if ("" == strPrice)
	{
		strPrice.Format(_T("0"));
	}
	if ("" == firm)
	{
		firm.Format(_T("δ��д"));
	}

	if ("" != ID || "" != name)
	{
		sql.Format(_T("select ��� from ҩƷ��Ϣ�� where ���='%s'"), ID);
		m_pSet->Open(CRecordset::dynaset, sql);

		double price;
		swscanf_s(strPrice, _T("%lf"), &price);
		if (price < 0)
		{
			MessageBox(_T("�۸�����"));
		}
		else if (0 == m_pSet->GetRecordCount())
		{
			//ʱ��
			SYSTEMTIME st;
			CStringW date;
			GetLocalTime(&st);
			date.Format(_T("%02d - %02d - %02d %02d: %02d : %02d"), st.wYear, st.wMonth, st.wDay,
				st.wHour, st.wMinute, st.wSecond);

			sql.Format(_T("insert into ������ values('%s','%s','%lf','%s')"), ID, name, price, firm);
			m_db.ExecuteSQL(sql);
			sql.Format(_T("insert into ҩƷ��Ϣ�� values('%s','%s','%lf',0,0,0,'%s','%s',0)"), ID, name, price, date, firm);
			m_db.ExecuteSQL(sql);
			MessageBox(_T("�ɹ����"));
		}
		else
		{
			MessageBox(_T("���и�ҩƷ��Ϣ"));
		}
	}
	CDialogEx::OnOK();
}
