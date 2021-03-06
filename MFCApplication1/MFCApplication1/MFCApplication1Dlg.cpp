
// MFCApplication1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#include <ctime>
#include <string>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CMFCApplication1Dlg dialog



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMFCApplication1Dlg message handlers

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCApplication1Dlg::OnBnClickedbtnprocess()
{
	
}

void CMFCApplication1Dlg::OnBnClickedCancel()
{

}

void CMFCApplication1Dlg::OnBnClickedButton1()
{
	CString textInput;

	//Employee ID
	GetDlgItemText(txtEmployeeID, textInput);
	double dEmployeeID = _ttof(textInput);
	//Hourly Wage
	GetDlgItemText(txtHourlyWage, textInput);
	double dHourlyWage = _ttof(textInput);

	//First Week
	GetDlgItemText(txtFirstMon, textInput);
	double dFirstMon = _ttof(textInput);
	GetDlgItemText(txtFirstTue, textInput);
	double dFirstTue = _ttof(textInput);
	GetDlgItemText(txtFirstWed, textInput);
	double dFirstWed = _ttof(textInput);
	GetDlgItemText(txtFirstThu, textInput);
	double dFirstThu = _ttof(textInput);
	GetDlgItemText(txtFirstFri, textInput);
	double dFirstFri = _ttof(textInput);
	GetDlgItemText(txtFirstSat, textInput);
	double dFirstSat = _ttof(textInput);
	GetDlgItemText(txtFirstSun, textInput);
	double dFirstSun = _ttof(textInput);

	//Second Week
	GetDlgItemText(txtSecondMon, textInput);
	double dSecondMon = _ttof(textInput);
	GetDlgItemText(txtSecondTue, textInput);
	double dSecondTue = _ttof(textInput);
	GetDlgItemText(txtSecondWed, textInput);
	double dSecondWed = _ttof(textInput);
	GetDlgItemText(txtSecondThu, textInput);
	double dSecondThu = _ttof(textInput);
	GetDlgItemText(txtSecondFri, textInput);
	double dSecondFri = _ttof(textInput);
	GetDlgItemText(txtSecondSat, textInput);
	double dSecondSat = _ttof(textInput);
	GetDlgItemText(txtSecondSun, textInput);
	double dSecondSun = _ttof(textInput);

	// *** Hours calculation
	double week1hour = 0;
	double week2hour = 0;
	week1hour = dFirstMon + dFirstTue + dFirstWed + dFirstThu + dFirstFri + dFirstSat + dFirstSun;
	week2hour = dSecondMon + dSecondTue + dSecondWed + dSecondThu + dSecondFri + dSecondSat + dSecondSun;
	double regularHoursWeek1 = 0;
	double regularHoursWeek2 = 0;
	double totalHours = 0;
	double overtimeHoursWeek1 = 0;
	double overtimeHoursWeek2 = 0;
	double totalOvertime = 0;

	// *** Amount Calculation: dHourlyWage
	double regularAmountPay = 0;
	double overtimeAmoutPay = 0;
	double totalEarnings = 0;

	if (week1hour > 40)
	{
		regularHoursWeek1 = 40;
		overtimeHoursWeek1 = week1hour - 40;
	}
	else
	{
		regularHoursWeek1 = week1hour;
	}
	if (week2hour > 40)
	{
		regularHoursWeek2 = 40;
		overtimeHoursWeek2 = week2hour - 40;
	}
	else
	{
		regularHoursWeek2 = week2hour;
	}

	// Total Work Hours
	totalHours = regularHoursWeek1 + regularHoursWeek2;
	totalOvertime = overtimeHoursWeek1 + overtimeHoursWeek2;

	// Get Amount
	regularAmountPay = dHourlyWage * totalHours;
	overtimeAmoutPay = (dHourlyWage * 1.5) * totalOvertime;
	totalEarnings = regularAmountPay + overtimeAmoutPay;

	// Set Regular Hours
	string strTotalHours = to_string(totalHours);
	CString totalRegularHours(strTotalHours.c_str());
	SetDlgItemText(txtRegularHours, totalRegularHours);

	// Set Overtime Hours
	string strOvertimeHours = to_string(totalOvertime);
	CString totalOvertimeHours(strOvertimeHours.c_str());
	SetDlgItemText(txtOvertimeHours, totalOvertimeHours);
}
