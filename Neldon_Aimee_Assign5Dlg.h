
// Neldon_Aimee_Assign5Dlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CNeldon_Aimee_Assign5Dlg dialog
class CNeldon_Aimee_Assign5Dlg : public CDialogEx
{
// Construction
public:
	CNeldon_Aimee_Assign5Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_NELDON_AIMEE_ASSIGN5_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton edgeDetection;
	CButton blur;
	CButton rotateVertical;
	CButton rotateHorizontal;
	CButton undo;
	CButton save;
	CButton folder;
	CImage img;
	int oldPos;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	CStatic m_pic;
	CSliderCtrl m_slider;
	afx_msg void OnNMReleasedcaptureSlider1(NMHDR *pNMHDR, LRESULT *pResult);
};
