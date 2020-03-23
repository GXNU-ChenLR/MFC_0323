
// MFC_0323View.cpp : CMFC_0323View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_0323.h"
#endif

#include "MFC_0323Doc.h"
#include "MFC_0323View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_0323View

IMPLEMENT_DYNCREATE(CMFC_0323View, CView)

BEGIN_MESSAGE_MAP(CMFC_0323View, CView)
	ON_COMMAND(ID_SHOW, &CMFC_0323View::OnShow)
END_MESSAGE_MAP()

// CMFC_0323View 构造/析构

CMFC_0323View::CMFC_0323View()
{
	// TODO: 在此处添加构造代码

}

CMFC_0323View::~CMFC_0323View()
{
}

BOOL CMFC_0323View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC_0323View 绘制

void CMFC_0323View::OnDraw(CDC* /*pDC*/)
{
	CMFC_0323Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC_0323View 诊断

#ifdef _DEBUG
void CMFC_0323View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_0323View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_0323Doc* CMFC_0323View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_0323Doc)));
	return (CMFC_0323Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_0323View 消息处理程序


void CMFC_0323View::OnShow()
{
	// TODO: 在此添加命令处理程序代码
	/*CString s = _T("123");
	CClientDC dc(this);
	dc.TextOutW(200, 300, s);*/
	int r,t;
	CRect cr;
	this->GetClientRect(&cr);
	int x = cr.Width() / 2;
	int y = cr.Height() / 2;
	if (x < y)t = x;
	else t = y;
	
	//CPen newPen(PS_SOLID, 1, color);
	//CPen*oldPen = pDC->SelectObject(&newPen);
	CClientDC dc(this);
	for (r = 1; r <= t; r++)
	{
		dc.Ellipse(x - r, y - r, x + r, y + r);
		//Invalidate();
	}
}
