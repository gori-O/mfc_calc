
// a_Calc_MFC002Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "a_Calc_MFC002.h"
#include "a_Calc_MFC002Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CaCalcMFC002Dlg 대화 상자



CaCalcMFC002Dlg::CaCalcMFC002Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_A_CALC_MFC002_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CaCalcMFC002Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CaCalcMFC002Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND_RANGE(IDC_BTN0, IDC_BTN9, OnSetNum)
	ON_COMMAND_RANGE(IDC_PLUS_BTN, IDC_DIV_BTN, OnProcessOP)
	ON_BN_CLICKED(IDC_BTNCE, &CaCalcMFC002Dlg::OnBnClickedBtnce)
	ON_BN_CLICKED(IDC_EQUAL_BTN, &CaCalcMFC002Dlg::OnBnClickedEqualBtn)
	ON_BN_CLICKED(IDC_BACK_BTN, &CaCalcMFC002Dlg::OnBnClickedBackBtn)
END_MESSAGE_MAP()


// CaCalcMFC002Dlg 메시지 처리기

BOOL CaCalcMFC002Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	myfont.CreatePointFont(200, L"굴림");
	GetDlgItem(IDC_DISPLAY_EDIT)->SetFont(&myfont);
	SetDlgItemInt(IDC_DISPLAY_EDIT, 0);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CaCalcMFC002Dlg::OnPaint()
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
HCURSOR CaCalcMFC002Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CaCalcMFC002Dlg::OnSetNum(UINT a_ctrl_id)
{
	int num = GetDlgItemInt(IDC_DISPLAY_EDIT) * 10;
	if (m_reset_mode == 0)
	{
		SetDlgItemInt(IDC_DISPLAY_EDIT, a_ctrl_id - 1001 + num);
	}
	else
	{
		m_reset_mode = 0;
		SetDlgItemInt(IDC_DISPLAY_EDIT, a_ctrl_id - IDC_BTN0);
	}
}



void CaCalcMFC002Dlg::OnBnClickedBtnce()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetDlgItemInt(IDC_DISPLAY_EDIT, 0);
}


void CaCalcMFC002Dlg::OnBnClickedEqualBtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int second_num = GetDlgItemInt(IDC_DISPLAY_EDIT);
	int result = 0;
	switch (m_op_flag)
	{
	case 1:
		result = first_num + second_num;
		break;
	case 2:
		result = first_num - second_num;
		break;
	case 3:
		result = first_num * second_num;
		break;
	case 4:
		result = (second_num != 0) ? first_num / second_num : 0;
	default:
		break;
	}
	SetDlgItemInt(IDC_DISPLAY_EDIT, result);
	m_reset_mode = 1;
}

void CaCalcMFC002Dlg::OnProcessOP(UINT a_ctrl_id)
{
		m_op_flag = a_ctrl_id - 1012 + 1;
		m_reset_mode = 1;
		first_num = GetDlgItemInt(IDC_DISPLAY_EDIT);
}


void CaCalcMFC002Dlg::OnBnClickedBackBtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int num = GetDlgItemInt(IDC_DISPLAY_EDIT);
	SetDlgItemInt(IDC_DISPLAY_EDIT, num / 10);
}
