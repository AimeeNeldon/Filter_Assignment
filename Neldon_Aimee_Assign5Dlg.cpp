
// Neldon_Aimee_Assign5Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Neldon_Aimee_Assign5.h"
#include "Neldon_Aimee_Assign5Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CNeldon_Aimee_Assign5Dlg dialog




CNeldon_Aimee_Assign5Dlg::CNeldon_Aimee_Assign5Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNeldon_Aimee_Assign5Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNeldon_Aimee_Assign5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, edgeDetection);
	DDX_Control(pDX, IDC_BUTTON2, blur);
	DDX_Control(pDX, IDC_BUTTON3, rotateVertical);
	DDX_Control(pDX, IDC_BUTTON4, rotateHorizontal);
	DDX_Control(pDX, IDC_BUTTON5, undo);
	DDX_Control(pDX, IDC_BUTTON6, save);
	DDX_Control(pDX, IDC_BUTTON7, folder);
	DDX_Control(pDX, IDC_PIC, m_pic);
	DDX_Control(pDX, IDC_SLIDER1, m_slider);
}

BEGIN_MESSAGE_MAP(CNeldon_Aimee_Assign5Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CNeldon_Aimee_Assign5Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CNeldon_Aimee_Assign5Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CNeldon_Aimee_Assign5Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CNeldon_Aimee_Assign5Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CNeldon_Aimee_Assign5Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CNeldon_Aimee_Assign5Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CNeldon_Aimee_Assign5Dlg::OnBnClickedButton7)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER1, &CNeldon_Aimee_Assign5Dlg::OnNMReleasedcaptureSlider1)
END_MESSAGE_MAP()


// CNeldon_Aimee_Assign5Dlg message handlers

BOOL CNeldon_Aimee_Assign5Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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
	m_slider.SetPos(50);
	oldPos = 50;

	// TODO: Add extra initialization here

	//image on buttons
	
	CBitmap bmp1;
	bmp1.LoadBitmapW(IDB_BITMAP1);
	edgeDetection.SetBitmap(bmp1);

	CBitmap bmp2;
	bmp2.LoadBitmapW(IDB_BITMAP2);
	blur.SetBitmap(bmp2);

	CBitmap bmp3;
	bmp3.LoadBitmapW(IDB_BITMAP3);
	rotateHorizontal.SetBitmap(bmp3);

	CBitmap bmp4;
	bmp4.LoadBitmapW(IDB_BITMAP4);
	rotateVertical.SetBitmap(bmp4);

	CBitmap bmp5;
	bmp5.LoadBitmapW(IDB_BITMAP5);
	undo.SetBitmap(bmp5);


	CBitmap bmp6;
	bmp6.LoadBitmapW(IDB_BITMAP6);
	save.SetBitmap(bmp6);

	CBitmap bmp7;
	bmp7.LoadBitmapW(IDB_BITMAP7);
	folder.SetBitmap(bmp7);



	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CNeldon_Aimee_Assign5Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CNeldon_Aimee_Assign5Dlg::OnPaint()
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
HCURSOR CNeldon_Aimee_Assign5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//edgeDetection
/*
The purpose for breaking down the pixels being 
read that surround the existing pixels is to ensure 
that the pixels along the border are read and also changed
*/
void CNeldon_Aimee_Assign5Dlg::OnBnClickedButton1()
{

CImage img2;
	img2.Create(img.GetWidth(),img.GetHeight(),24);
	
	for(int i=0; i < img.GetWidth(); i++)
		for(int j=0; j < img.GetHeight(); j++)
		{
			COLORREF c1 = img.GetPixel(i,j);
			int r = GetRValue(c1);
			int g = GetGValue(c1);
			int b = GetBValue(c1);

			if(i> 0)
			{
				//left
				COLORREF c = img.GetPixel(i-1,j);
				int r2 = GetRValue(c);
				int g2 = GetGValue(c);
				int b2 = GetBValue(c);
				c = r2+g2+b2/3;
			
				if(c > 100)
					c1= RGB(255,255,255);
				else 
					c1=RGB(0,0,0);
			}

			if(i < img.GetWidth()-1)
			{
				//right
				COLORREF c= img.GetPixel(i+1,j);
				int r2 = GetRValue(c);
				int g2 = GetGValue(c);
				int b2 = GetBValue(c);
				c = r2+g2+b2/3;
				
				if(c > 100)
					c1= RGB(255,255,255);
				else 
					c1=RGB(0,0,0);
			}

			if(j>0 )
			{
				//down
				COLORREF c = img.GetPixel(i,j-1);
				int r2 = GetRValue(c);
				int g2 = GetGValue(c);
				int b2 = GetBValue(c);
				c = r2+g2+b2/3;
			
				if(c > 100)
					c1= RGB(255,255,255);
				else 
					c1=RGB(0,0,0);
			}
			if(j < img.GetHeight()-1)
			{
				//up
				COLORREF c = img.GetPixel(i,j+1);
				int r2 = GetRValue(c);
				int g2 = GetGValue(c);
				int b2 = GetBValue(c);
				c = r2+g2+b2/3;
			
				if(c > 100)
					c1= RGB(255,255,255);
				else 
					c1=RGB(0,0,0);
			}
			img2.SetPixel(i,j,c1);
		}
		m_pic.SetBitmap(img2);
}

//blur
/*
The purpose for breaking down the pixels being 
read that surround the existing pixels is to ensure 
that the pixels along the border are read and also changed
*/
void CNeldon_Aimee_Assign5Dlg::OnBnClickedButton2()
{
	CImage img2;
	img2.Create(img.GetWidth(),img.GetHeight(),24);
	
	for(int i=0; i < img.GetWidth(); i++)
		for(int j=0; j < img.GetHeight(); j++)
		{
			COLORREF c1 = img.GetPixel(i,j);

			int r = GetRValue(c1);
			int g = GetGValue(c1);
			int b = GetBValue(c1);
			int counter =1;

			if(i> 0)
			{
				//left
				COLORREF c = img.GetPixel(i-1,j);
				int r2 = GetRValue(c);
				int g2 = GetGValue(c);
				int b2 = GetBValue(c);
				r += r2;
				g += g2;
				b += b2;
				counter++;
			}

			if(i < img.GetWidth()-1)
			{
				//right
				COLORREF c= img.GetPixel(i+1,j);
				int r2 = GetRValue(c);
				int g2 = GetGValue(c);
				int b2 = GetBValue(c);
				r += r2;
				g += g2;
				b += b2;
				counter++;
			}

			if(j>0 )
			{
				//down
				COLORREF c = img.GetPixel(i,j-1);
				int r2 = GetRValue(c);
				int g2 = GetGValue(c);
				int b2 = GetBValue(c);
				r += r2;
				g += g2;
				b += b2;
				counter++;
			}
			if(j < img.GetHeight()-1)
			{
				//up
				COLORREF c = img.GetPixel(i,j+1);
				int r2 = GetRValue(c);
				int g2 = GetGValue(c);
				int b2 = GetBValue(c);
				r += r2;
				g += g2;
				b += b2;
				counter++;
			}
			
			r = r/counter;
			g = g/counter;
			b = b/counter;

			img2.SetPixel(i,j,RGB(r,g,b));
		}
	m_pic.SetBitmap(img2);
}


//flipVertical
void CNeldon_Aimee_Assign5Dlg::OnBnClickedButton3()
{
	CImage img2;
	img2.Create(img.GetWidth(),img.GetHeight(),24);
	
		for(int x=0; x < img.GetWidth(); x++)
			for(int y=0; y < img.GetHeight(); y++)
			{
				if(y>0)
				{
				COLORREF color = img.GetPixel(x,img.GetHeight()-y-1);
				img2.SetPixel(x,y,color);
				}
			}
		m_pic.SetBitmap(img2);
}


//flipHorizontal
void CNeldon_Aimee_Assign5Dlg::OnBnClickedButton4()
{
	CImage img2;
	img2.Create(img.GetWidth(),img.GetHeight(),24);
	
		for(int x=0; x < img.GetWidth(); x++)
			for(int y=0; y < img.GetHeight(); y++)
			{
				if(x>0)
				{
				COLORREF color = img.GetPixel(img.GetWidth()-x-1,y);
				img2.SetPixel(x,y,color);
				}
			}
		m_pic.SetBitmap(img2);
}


//undo
void CNeldon_Aimee_Assign5Dlg::OnBnClickedButton5()
{
	m_pic.SetBitmap(img);
	//destroying my image in the open function nullifies this function
}


//save
void CNeldon_Aimee_Assign5Dlg::OnBnClickedButton6()
{
	CFileDialog fd2(false);
	fd2.DoModal();
	img.Save(fd2.GetPathName());

}

//open
void CNeldon_Aimee_Assign5Dlg::OnBnClickedButton7()
{
	//img.Destroy();
	CFileDialog fd(true);
	int result = fd.DoModal();

	if(result == IDOK)
	{
		CString cs = fd.GetPathName();

		img.Load(cs);

		HDC hDC = img.GetDC();
		img.BitBlt(hDC,0,0);
		img.ReleaseDC();
		m_pic.SetBitmap(img);
	}
}

//brightness
void CNeldon_Aimee_Assign5Dlg::OnNMReleasedcaptureSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	int p = m_slider.GetPos();
	int d = p - oldPos;

	CImage img2;
	img2.Create(img.GetWidth(),img.GetHeight(),24);
	for(int i=0; i < img.GetWidth(); i++)
			for(int j=0; j < img.GetHeight(); j++)
			{
				COLORREF c1 = img.GetPixel(i,j);
				int r = GetRValue(c1);
				int g = GetGValue(c1);
				int b = GetBValue(c1);

				if(r+d >255)
					r=255;
				else if(r+d < 0)
					r=0;
				else
					r+=d;

				if(g+d >255)
					g=255;
				else if(g+d < 0)
					g=0;
				else
					g+=d;

				if(b+d >255)
					b=255;
				else if(b+d < 0)
					b=0;
				else
					b+=d;
				
				img.SetPixel(i,j,RGB(r,g,b));
			}
	m_pic.SetBitmap(img);
	oldPos = p;
	*pResult = 0;
}
