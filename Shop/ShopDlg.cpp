﻿
// ShopDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "Shop.h"
#include "ShopDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CShopDlg



CShopDlg::CShopDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHOP_DIALOG, pParent)
	, child(FALSE)
	, school(FALSE)
	, student(FALSE)
	, invalid(FALSE)
	, pensioner(FALSE)
	, cena(0)
	, count(0)
	, summ_no(0)
	, summ(0)
	, r(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShopDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, child);
	DDX_Check(pDX, IDC_CHECK2, school);
	DDX_Check(pDX, IDC_CHECK3, student);
	DDX_Check(pDX, IDC_CHECK4, invalid);
	DDX_Check(pDX, IDC_CHECK5, pensioner);
	DDX_Text(pDX, IDC_EDIT1, cena);
	DDX_Text(pDX, IDC_EDIT2, count);
	DDX_Text(pDX, IDC_EDIT3, summ_no);
	DDX_Text(pDX, IDC_EDIT4, summ);
	DDX_Radio(pDX, IDC_RADIO1, r);
	DDX_Radio(pDX, IDC_RADIO1, r);
}

BEGIN_MESSAGE_MAP(CShopDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CShopDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Обработчики сообщений CShopDlg

BOOL CShopDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CShopDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CShopDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CShopDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CShopDlg::OnBnClickedButton1()
{
	UpdateData();
	if ((child == 1) && (school == 1)) {
		MessageBox(L"Ребенок не может быть школьником");
		summ = summ_no = 0;
		return;
	}
	if ((child == 1) && (student == 1)) {
		MessageBox(L"Ребенок не может быть студентом");
		summ = summ_no = 0;
		return;
	}
	if ((school == 1) && (student == 1)) {
		MessageBox(L"Школьник не может быть студентом");
		summ = summ_no = 0;
		return;
	}
	if ((cena == 0) || (count == 0)) {
		MessageBox(L"Введите число");
		return;
	}
	
	float skidka = 0;
	if (child == 1)
		skidka = skidka + 0.05;
	if (school == 1)
		skidka = skidka + 0.02;
	if (student == 1)
		skidka = skidka + 0.01;
	if (invalid == 1)
		skidka = skidka + 0.1;
	if (pensioner == 1)
		skidka = skidka + 0.15;
	if (r == 0)
		skidka = skidka + 0.1;
	
	summ_no = cena * count;
	summ = summ_no - skidka * cena * count;
	UpdateData(false);
}
