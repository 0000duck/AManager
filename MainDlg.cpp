// MainDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Manager.h"
#include "MainDlg.h"
#include "afxdialogex.h"

#include "Add.h"
#include "Modify.h"
#include "Buy.h"
#include "Sell.h"
#include "SellSearch.h"
#include "ADDSEARCH.h"
#include "stdlib.h"
#include "BuySearch.h"

// CMainDlg �Ի���

IMPLEMENT_DYNAMIC(CMainDlg, CDialogEx)

CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MAINDIALOG, pParent)
	, m_ID(0)
	, m_name(0)
	, m_firm(0)
{

}

CMainDlg::~CMainDlg()
{
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listCtrl);
	DDX_Control(pDX, IDC_ADD, m_add);
	DDX_Control(pDX, IDC_EDIT1, m_EditContral);
	DDX_Control(pDX, IDC_EDIT3, m_amount);
}


BEGIN_MESSAGE_MAP(CMainDlg, CDialogEx)
	ON_BN_CLICKED(IDC_SEARCH, &CMainDlg::OnBnClickedSearch)
	ON_BN_CLICKED(IDC_ADD, &CMainDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_MODIFY, &CMainDlg::OnBnClickedModify)
	ON_BN_CLICKED(IDC_BUY, &CMainDlg::OnBnClickedBuy)
	ON_BN_CLICKED(IDC_DELETE, &CMainDlg::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_SELL, &CMainDlg::OnBnClickedSell)
	ON_BN_CLICKED(IDC_BUTTON5, &CMainDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &CMainDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CMainDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON2, &CMainDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMainDlg ��Ϣ�������

BOOL CMainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_listCtrl.SetExtendedStyle(LVS_EX_FLATSB | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);// | LVS_EX_CHECKBOXES);//ѡ���С����񡢸�ѡ��

	m_listCtrl.InsertColumn(0, _T("���"), LVCFMT_LEFT,80,0);
	m_listCtrl.InsertColumn(1, _T("ҩƷ��"), LVCFMT_LEFT,80,1);
	m_listCtrl.InsertColumn(2, _T("�ۼ�"), LVCFMT_LEFT,80,2);
	m_listCtrl.InsertColumn(3, _T("���"), LVCFMT_LEFT,50,3);
	m_listCtrl.InsertColumn(4, _T("����"), LVCFMT_LEFT,80,4);
	m_listCtrl.InsertColumn(5, _T("������"), LVCFMT_LEFT,80,5);
	m_listCtrl.InsertColumn(6, _T("����ʱ��"), LVCFMT_LEFT,90,6);
	m_listCtrl.InsertColumn(7, _T("����"), LVCFMT_LEFT,80,7);
	m_listCtrl.InsertColumn(8, _T("������Ϣ"), LVCFMT_LEFT,80,8);
	m_listCtrl.SetColumnWidth(0, LVSCW_AUTOSIZE_USEHEADER);
	
	((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE);
	ShowInfo();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CMainDlg::OnBnClickedSearch()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDatabase m_db;
	CRecordset *m_pSet = new CRecordset();
	CStringW sql;
	CStringW keyword;
	CStringW str;

	CStringW ID;
	CStringW name;
	CStringW price;
	CStringW amount;
	CStringW inprice;
	CStringW inamount;
	CStringW indate;
	CStringW firm;
	CStringW info;

	if (!m_db.IsOpen())
		m_db.Open(NULL, FALSE, FALSE, _T("ODBC;FILEDSN=.\\Manager.dsn;UID=admin"), true);

	m_pSet->m_pDatabase = &m_db;
	m_EditContral.GetWindowTextW(keyword);

	int row;
	int itemCount = m_listCtrl.GetItemCount();

	//����Ų�ѯ
	if (((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck())
	{
		sql.Format(_T("select * from ҩƷ��Ϣ�� where ���='%s'"),keyword);
	}
	//�����Ʋ�ѯ
	else if (((CButton *)GetDlgItem(IDC_RADIO2))->GetCheck())
	{
		sql.Format(_T("select * from ҩƷ��Ϣ�� where ҩƷ��='%s'"), keyword);
	}
	//�����̲�ѯ
	else if (((CButton *)GetDlgItem(IDC_RADIO3))->GetCheck())
	{
		sql.Format(_T("select * from ҩƷ��Ϣ�� where ����='%s'"), keyword);
	}

	m_pSet->Open(CRecordset::dynaset, sql);
	m_pSet->MoveFirst();
	while (!m_pSet->IsEOF())
	{
		m_pSet->MoveNext();
	}
	m_pSet->MoveFirst();
	int a = m_pSet->GetRecordCount();
	m_listCtrl.DeleteAllItems();
	for (int i = 0; i < a; i++)
	{
		m_pSet->GetFieldValue(_T("���"), ID);
		m_pSet->GetFieldValue(_T("ҩƷ��"), name);
		m_pSet->GetFieldValue(_T("�ۼ�"), price);
		m_pSet->GetFieldValue(_T("���"), amount);
		m_pSet->GetFieldValue(_T("����"), inprice);
		m_pSet->GetFieldValue(_T("������"), inamount);
		m_pSet->GetFieldValue(_T("��������"), indate);
		m_pSet->GetFieldValue(_T("����"), firm);
		m_pSet->GetFieldValue(_T("������Ϣ"), info);
		m_pSet->MoveNext();

		m_listCtrl.InsertItem(0, ID);
		m_listCtrl.SetItemText(0, 1, name);
		m_listCtrl.SetItemText(0, 2, price);
		m_listCtrl.SetItemText(0, 3, amount);
		m_listCtrl.SetItemText(0, 4, inprice);
		m_listCtrl.SetItemText(0, 5, inamount);
		m_listCtrl.SetItemText(0, 6, indate);
		m_listCtrl.SetItemText(0, 7, firm);
		m_listCtrl.SetItemText(0, 8, info);
	}
}


void CMainDlg::ShowInfo()
{
	CStringW ID;
	CStringW name;
	CStringW price;
	CStringW amount;
	CStringW inprice;
	CStringW inamount;
	CStringW indate;
	CStringW firm;
	CStringW info;
	CStringW sql;

	CDatabase m_db;
	CRecordset *m_pSet = NULL;
	m_db.Open(NULL, FALSE, FALSE, _T("ODBC;FILEDSN=.\\Manager.dsn;UID=admin"), true);
	m_pSet = new CRecordset();
	m_pSet->m_pDatabase = &m_db;
	//sql.Format(_T("select ҩƷ��Ϣ��.���,ҩƷ��,�ۼ�,���,����,������,��������,����,������Ϣ from ҩƷ��Ϣ��"));
	sql.Format(_T("select * from ҩƷ��Ϣ�� order by ���"));
	m_pSet->Open(CRecordset::forwardOnly, sql);
	for (int index = 1; !m_pSet->IsEOF(); m_pSet->MoveNext(),index++)
	//for (int index = 0; index < m_pSet->GetRecordCount(); index++)
	{
			m_pSet->GetFieldValue(_T("���"), ID);
			m_pSet->GetFieldValue(_T("ҩƷ��"), name);
			m_pSet->GetFieldValue(_T("�ۼ�"), price);
			m_pSet->GetFieldValue(_T("���"), amount);
			m_pSet->GetFieldValue(_T("����"), inprice);
			m_pSet->GetFieldValue(_T("������"), inamount);
			m_pSet->GetFieldValue(_T("��������"), indate);
			m_pSet->GetFieldValue(_T("����"), firm);
			m_pSet->GetFieldValue(_T("������Ϣ"), info);
			
			m_listCtrl.InsertItem(index, ID);
			m_listCtrl.SetItemText(index - 1, 1, name);
			m_listCtrl.SetItemText(index-1, 2, price);
			m_listCtrl.SetItemText(index-1, 3, amount);
			m_listCtrl.SetItemText(index - 1, 4, inprice);
			m_listCtrl.SetItemText(index - 1, 5, inamount);
			m_listCtrl.SetItemText(index - 1, 6, indate);
			m_listCtrl.SetItemText(index - 1, 7, firm);
			m_listCtrl.SetItemText(index - 1, 8, info);
	}
}


void CMainDlg::OnBnClickedAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CAdd dlg;
	dlg.DoModal();

	m_listCtrl.DeleteAllItems();
	ShowInfo();
}


void CMainDlg::OnBnClickedModify()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int row = m_listCtrl.GetSelectionMark ();

	if (-1 == row)
	{
		MessageBox(_T("δѡȡ�κ�����"));
	}
	else
	{
		CModify ModDlg;
		ModDlg.DoModal();

		CDatabase m_db;
		CRecordset *m_pSet = new CRecordset();

		CStringW ID;
		CStringW name;
		CStringW price;
		CStringW firm;
		CStringW info;
		CStringW sql;

		CStringW itemID = m_listCtrl.GetItemText(row, 0);
		CStringW itemName = m_listCtrl.GetItemText(row, 1);
		CStringW itemPrice = m_listCtrl.GetItemText(row, 2);
		CStringW itemFirm = m_listCtrl.GetItemText(row, 7);
		CStringW itemInfo = m_listCtrl.GetItemText(row, 8);

		if(!m_db.IsOpen())
			m_db.Open(NULL, FALSE, FALSE, _T("ODBC;FILEDSN=.\\Manager.dsn;UID=admin"), true);
		m_pSet->m_pDatabase = &m_db;

		
		ID = ModDlg.ID;
		name = ModDlg.name;
		price = ModDlg.price;
		firm = ModDlg.firm;
		info = ModDlg.info;

		if ("" == ID && "" == name && "" == price && "" == firm && "" == info)
		{
			MessageBox(_T("δ�����κβ���"));

		}
		else
		{
			if ("" == ID)
				ID = itemID;
			if ("" == name)
				name = itemName;
			if ("" == price)
				price = itemPrice;
			if ("" == firm)
				firm = itemFirm;
			if ("" == info)
				info = itemInfo;

			double dprice;
			swscanf_s(price, _T("%lf"), &dprice);
			if (dprice < 0)
				MessageBox(_T("�۸�����"));
			else
			{
				sql.Format(_T("update ҩƷ��Ϣ�� set ���='%s' where ���='%s'"), ID, itemID);
				m_db.ExecuteSQL(sql);
				sql.Format(_T("update ҩƷ��Ϣ�� set ҩƷ��='%s' where ���='%s'"), name, itemID);
				m_db.ExecuteSQL(sql);
				sql.Format(_T("update ҩƷ��Ϣ�� set �ۼ�='%lf' where ���='%s'"), dprice, itemID);
				m_db.ExecuteSQL(sql);
				sql.Format(_T("update ҩƷ��Ϣ�� set ����='%s' where ���='%s'"), firm, itemID);
				m_db.ExecuteSQL(sql);
				sql.Format(_T("update ҩƷ��Ϣ�� set ������Ϣ='%s' where ���='%s'"), info, itemID);
				m_db.ExecuteSQL(sql);

				m_listCtrl.DeleteAllItems();
				ShowInfo();
				MessageBox(_T("�ɹ�������Ϣ"));
			}
		}
	}

}


void CMainDlg::OnBnClickedBuy()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int row = m_listCtrl.GetSelectionMark();

	if (-1 == row)
	{
		MessageBox(_T("δѡȡ�κ�����"));
	}
	else
	{
		CBuy buyDlg;
		buyDlg.DoModal();
	
		CDatabase m_db;
		CRecordset *m_pSet = new CRecordset();

		CStringW inprice;
		CStringW inamount;
		CStringW firm;
		CStringW info;
		CStringW sql;

		CStringW itemID = m_listCtrl.GetItemText(row, 0);
		CStringW itemName = m_listCtrl.GetItemText(row, 1);
		CStringW itemPrice = m_listCtrl.GetItemText(row, 2);
		CStringW itemAmount = m_listCtrl.GetItemText(row, 3);
		CStringW itemInPrice = m_listCtrl.GetItemText(row, 4);
		CStringW itemInAmount = m_listCtrl.GetItemText(row, 5);
		CStringW itemDate = m_listCtrl.GetItemText(row, 6);
		CStringW itemFirm = m_listCtrl.GetItemText(row, 7);
		CStringW itemInfo = m_listCtrl.GetItemText(row, 8);
		
		if(!m_db.IsOpen())
			m_db.Open(NULL, FALSE, FALSE, _T("ODBC;FILEDSN=.\\Manager.dsn;UID=admin"), true);
		m_pSet->m_pDatabase = &m_db;

		inprice = buyDlg.inprice;
		inamount = buyDlg.inamount;
		firm = buyDlg.firm;
		info = buyDlg.info;

		if ("" == inprice && "" == inamount && "" == firm && "" == info)
		{
			MessageBox(_T("δ�����κβ���"));
		}
		else
		{
			if ("" == inprice)
			{
				MessageBox(_T("����Ϊ0����������д"));
			}
			if ("" == inamount)
			{
				MessageBox(_T("������Ϊ0����������д"));
			}
			if ("" == firm)
				firm = itemFirm;
			if ("" == info)
				info = itemInfo;

			SYSTEMTIME st;
			CStringW date;
			GetLocalTime(&st);
			date.Format(_T("%02d - %02d - %02d %02d: %02d : %02d"), st.wYear, st.wMonth, st.wDay,
				st.wHour, st.wMinute, st.wSecond);

			long count;
			swscanf_s(itemAmount, _T("%ld"), &count);
			long incount;
			swscanf_s(inamount, _T("%ld"), &incount);
			long inItemAmount;
			swscanf_s(itemInAmount, _T("%ld"), &inItemAmount);
			double price;
			swscanf_s(inprice, _T("%lf"), &price);

			if (count < 0 || price < 0)
				MessageBox(_T("������۸��д�"));
			else if("" != inprice && "" != inamount)
			{
				long a = count + incount;
				long b = inItemAmount + incount;

				//����ҩƷ��Ϣ��
				sql.Format(_T("update ҩƷ��Ϣ�� set ����='%s' where ���='%s'"), inprice, itemID);
				m_db.ExecuteSQL(sql);
				sql.Format(_T("update ҩƷ��Ϣ�� set ������='%ld' where ���='%s'"), b, itemID);
				m_db.ExecuteSQL(sql);
				sql.Format(_T("update ҩƷ��Ϣ�� set ���='%ld' where ���='%s'"), a, itemID);
				m_db.ExecuteSQL(sql);
				sql.Format(_T("update ҩƷ��Ϣ�� set ��������='%s' where ���='%s'"), date, itemID);
				m_db.ExecuteSQL(sql);
				sql.Format(_T("update ҩƷ��Ϣ�� set ������Ϣ='%s' where ���='%s'"), info, itemID);
				m_db.ExecuteSQL(sql);

				//���½�����
				sql.Format(_T("insert into ������ values('%s','%s','%s','%s','%s')"), itemID, itemName, itemPrice, inamount, firm);
				m_db.ExecuteSQL(sql);
				//�����б�
				m_listCtrl.DeleteAllItems();
				ShowInfo();
				MessageBox(_T("�ɹ�����ҩƷ"));
			}
		}
	}
}


void CMainDlg::OnBnClickedDelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int row = m_listCtrl.GetSelectionMark();

	if (-1 == row)
	{
		MessageBox(_T("δѡȡ�κ�����"));
	}
	else
	{
		CDatabase m_db;
		if(!m_db.IsOpen ())
			m_db.Open(NULL, FALSE, FALSE, _T("ODBC;FILEDSN=.\\Manager.dsn;UID=admin"), true);

		CStringW sql,itemID;
		itemID = m_listCtrl.GetItemText(row, 0);
		sql.Format(_T("delete from ҩƷ��Ϣ�� where ���='%s'"), itemID);
		m_db.ExecuteSQL(sql);
		sql.Format(_T("delete from ҩƷ��Ϣ�� where ���='%s'"), itemID);
		m_db.ExecuteSQL(sql);

		m_listCtrl.DeleteAllItems();
		ShowInfo();
		MessageBox(_T("�ɹ�ɾ��"));
	}
}


void CMainDlg::OnBnClickedSell()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int row = m_listCtrl.GetSelectionMark();

	if (-1 == row)
	{
		MessageBox(_T("δѡȡ�κ�����"));
	}
	else
	{
		CStringW sql;
		CStringW amount;
		m_amount.GetWindowTextW(amount);

		if ("" == amount)
		{
			MessageBox(_T("����Ϊ��"));
		}
		else
		{
			CStringW itemID = m_listCtrl.GetItemText(row, 0);
			CStringW itemName = m_listCtrl.GetItemText(row, 1);
			CStringW itemPrice = m_listCtrl.GetItemText(row, 2);
			CStringW itemAmount = m_listCtrl.GetItemText(row, 3);
			CStringW cus = _T("����");

			long count, itemcount;
			//ת����long
			swscanf_s(amount, _T("%ld"), &count);
			swscanf_s(itemAmount, _T("%ld"), &itemcount);

			if (0 < count - itemcount)
			{
				MessageBox(_T("�������"));
			}
			else
			{
				CDatabase m_db;
				CRecordset *m_pSet = new CRecordset();

				m_db.Open(NULL, FALSE, FALSE, _T("ODBC;FILEDSN=.\\Manager.dsn;UID=admin"), true);
				m_pSet->m_pDatabase = &m_db;

				long a = itemcount - count;
				//��ȡ��ǰʱ��
				SYSTEMTIME st;
				CStringW date;
				GetLocalTime(&st);
				date.Format(_T("%02d - %02d - %02d %02d: %02d : %02d"), st.wYear, st.wMonth, st.wDay,
					st.wHour, st.wMinute, st.wSecond);
				//���¼�¼
				sql.Format(_T("select * from ҩƷ��Ϣ��"));
				m_db.ExecuteSQL(sql);
				sql.Format(_T("insert into ���۱� values('%s','%s','%s','%s','%s','%s')"), itemID, itemName, itemPrice, amount, cus, date);
				m_db.ExecuteSQL(sql);
				sql.Format(_T("update ҩƷ��Ϣ�� set ���='%ld' where ���='%s'"), a, itemID);
				m_db.ExecuteSQL(sql);
				sql.Format(_T("update ҩƷ��Ϣ�� set ���='%ld' where ���='%s'"), a, itemID);
				m_db.ExecuteSQL(sql);

				MessageBox(_T("�ɹ�����"));
				m_listCtrl.DeleteAllItems();
				ShowInfo();
			}
		}
	}
}


void CMainDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CSellSearch dlg;
	dlg.DoModal();
}


void CMainDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CADDSEARCH dlg;
	dlg.DoModal();
}


void CMainDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CBuySearch dlg;
	dlg.DoModal();
}


void CMainDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_listCtrl.DeleteAllItems();
	ShowInfo();
}
