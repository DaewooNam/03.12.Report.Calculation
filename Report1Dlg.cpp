
// Report1Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "Report1.h"
#include "Report1Dlg.h"
#include "afxdialogex.h"
#include "Resource.h";

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CReport1Dlg 대화 상자



CReport1Dlg::CReport1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_REPORT1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CReport1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_ADD1, m_strADD1);
	DDX_Text(pDX, IDC_EDIT_ADD2, m_strADD2);
	DDX_Text(pDX, IDC_EDIT_ADD_RESULT, m_strADD_Result);

	DDX_Text(pDX, IDC_EDIT_MIN1, m_strMIN1);
	DDX_Text(pDX, IDC_EDIT_MIN2, m_strMIN2);
	DDX_Text(pDX, IDC_EDIT_MIN_RESULT, m_strMIN_Result);

	DDX_Text(pDX, IDC_EDIT_MUL1, m_strMUL1);
	DDX_Text(pDX, IDC_EDIT_MUL2, m_strMUL2);
	DDX_Text(pDX, IDC_EDIT_MUL_RESULT, m_strMUL_Result);

}

BEGIN_MESSAGE_MAP(CReport1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CReport1Dlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_MIN, &CReport1Dlg::OnBnClickedButtonMin)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CReport1Dlg::OnBnClickedButtonMul)
END_MESSAGE_MAP()


// CReport1Dlg 메시지 처리기

BOOL CReport1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CReport1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CReport1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CReport1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CReport1Dlg::OnBnClickedButtonAdd()
{
	UpdateData(true);
	int nVal;
	nVal =_ttoi(m_strADD1)+_ttoi(m_strADD2);
	m_strADD_Result.Format(("%d"),nVal);
	UpdateData(false);


}


void CReport1Dlg::OnBnClickedButtonMin()
{
	UpdateData(true);
	int nVal;
	nVal = _ttoi(m_strMIN1) - _ttoi(m_strMIN2);
	m_strMIN_Result.Format(("%d"), nVal);
	UpdateData(false);
}


void CReport1Dlg::OnBnClickedButtonMul()
{
	UpdateData(true);
	int nVal;
	nVal = _ttoi(m_strMUL1) * _ttoi(m_strMUL2);
	m_strMUL_Result.Format(("%d"), nVal);
	UpdateData(false);
}
