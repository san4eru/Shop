
// ShopDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CShopDlg
class CShopDlg : public CDialogEx
{
// Создание
public:
	CShopDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHOP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	BOOL child;
	BOOL school;
	BOOL student;
	BOOL invalid;
	BOOL pensioner;
	float cena;
	float count;
	float summ_no;
	float summ;
	afx_msg void OnBnClickedButton1();
//	int r;
	int r;
};
