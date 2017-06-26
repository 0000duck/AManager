
// ManagerSet.cpp : CManagerSet ���ʵ��
//

#include "stdafx.h"
#include "Manager.h"
#include "ManagerSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CManagerSet ʵ��

// ���������� 2017��6��23��, ������, 17:16

IMPLEMENT_DYNAMIC(CManagerSet, CRecordset)

CManagerSet::CManagerSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = L"";
	column2 = L"";
	column3 = 0.0;
	column4 = L"";
	column5 = L"";
	column6 = L"";
	column7 = 0.0;
	column8 = 0;
	column9 = 0.0;
	column10 = 0;
	column11;
	column12 = L"";
	column13 = L"";
	column14 = L"";
	column15 = L"";
	column16 = 0.0;
	column17 = L"";
	column18 = L"";
	column19 = L"";
	column20 = L"";
	column21 = 0.0;
	column22 = 0;
	column23 = L"";
	column24;
	m_nFields = 24;
	m_nDefaultType = dynaset;
}
// #error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CManagerSet::GetDefaultConnect()
{
	return _T("DBQ=Manager.mdb;Driver={Microsoft Access Driver (*.mdb)};DriverId=25;FIL=MS Access;FILEDSN=.\\Manager.dsn;MaxBufferSize=2048;MaxScanRows=8;PageTimeout=5;SafeTransactions=0;Threads=3;UID=admin;UserCommitSync=Yes;");
}

CString CManagerSet::GetDefaultSQL()
{
	return _T("[������],[ҩƷ��Ϣ��],[������],[���۱�]");
}

void CManagerSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[������].[���]"), column1);
	RFX_Text(pFX, _T("[������].[ҩƷ��]"), column2);
	RFX_Double(pFX, _T("[������].[�ۼ�]"), column3);
	RFX_Text(pFX, _T("[������].[����]"), column4);
	RFX_Text(pFX, _T("[ҩƷ��Ϣ��].[���]"), column5);
	RFX_Text(pFX, _T("[ҩƷ��Ϣ��].[ҩƷ��]"), column6);
	RFX_Double(pFX, _T("[ҩƷ��Ϣ��].[�ۼ�]"), column7);
	RFX_Long(pFX, _T("[ҩƷ��Ϣ��].[���]"), column8);
	RFX_Double(pFX, _T("[ҩƷ��Ϣ��].[����]"), column9);
	RFX_Long(pFX, _T("[ҩƷ��Ϣ��].[������]"), column10);
	RFX_Date(pFX, _T("[ҩƷ��Ϣ��].[��������]"), column11);
	RFX_Text(pFX, _T("[ҩƷ��Ϣ��].[����]"), column12);
	RFX_Text(pFX, _T("[ҩƷ��Ϣ��].[������Ϣ]"), column13);
	RFX_Text(pFX, _T("[������].[���]"), column14);
	RFX_Text(pFX, _T("[������].[ҩƷ��]"), column15);
	RFX_Double(pFX, _T("[������].[����]"), column16);
	RFX_Text(pFX, _T("[������].[������]"), column17);
	RFX_Text(pFX, _T("[������].[����]"), column18);
	RFX_Text(pFX, _T("[���۱�].[���]"), column19);
	RFX_Text(pFX, _T("[���۱�].[ҩƷ��]"), column20);
	RFX_Double(pFX, _T("[���۱�].[�ۼ�]"), column21);
	RFX_Long(pFX, _T("[���۱�].[������]"), column22);
	RFX_Text(pFX, _T("[���۱�].[���]"), column23);
	RFX_Date(pFX, _T("[���۱�].[����ʱ��]"), column24);

}
/////////////////////////////////////////////////////////////////////////////
// CManagerSet ���

#ifdef _DEBUG
void CManagerSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CManagerSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

