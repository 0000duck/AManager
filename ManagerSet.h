
// ManagerSet.h: CManagerSet ��Ľӿ�
//


#pragma once

// ���������� 2017��6��23��, ������, 17:16

class CManagerSet : public CRecordset
{
public:
	CManagerSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CManagerSet)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	CStringW	column1;
	CStringW	column2;
	double	column3;
	CStringW	column4;
	CStringW	column5;
	CStringW	column6;
	double	column7;
	long	column8;
	double	column9;
	long	column10;
	CTime	column11;
	CStringW	column12;
	CStringW	column13;
	CStringW	column14;
	CStringW	column15;
	double	column16;
	CStringW	column17;
	CStringW	column18;
	CStringW	column19;
	CStringW	column20;
	double	column21;
	long	column22;
	CStringW	column23;
	CTime	column24;

// ��д
	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���

	virtual CString GetDefaultSQL(); 	// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

