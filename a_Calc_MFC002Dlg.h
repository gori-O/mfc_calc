
// a_Calc_MFC002Dlg.h: 헤더 파일
//

#pragma once


// CaCalcMFC002Dlg 대화 상자
class CaCalcMFC002Dlg : public CDialogEx
{
private:
	CFont myfont;
	char m_op_flag = 0;			// 0 -> none sel, 1 -> PLUS, 2 -> MIN, 3 -> MUL, 4 -> DIV
	char m_reset_mode = 0;
	int first_num = 0;

// 생성입니다.
public:
	CaCalcMFC002Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_A_CALC_MFC002_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void OnSetNum(UINT a_ctrl_id);
	afx_msg void OnBnClickedBtnce();
	afx_msg void OnBnClickedEqualBtn();
	void OnProcessOP(UINT a_ctrl_id);
	afx_msg void OnBnClickedBackBtn();
};
