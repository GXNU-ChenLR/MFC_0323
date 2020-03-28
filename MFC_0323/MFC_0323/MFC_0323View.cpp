
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
	ON_WM_TIMER()
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
	SetTimer(pDoc->radius, 1000, NULL);
	int t;
	CRect cr;
	this->GetClientRect(&cr);
	pDoc->x = cr.Width() / 2;
	pDoc->y = cr.Height() / 2;
	if (pDoc->x < pDoc->y)t = pDoc->x;
	else t = pDoc->y;

	if (pDoc->flag && pDoc->radius <= t)
	{
		CClientDC dc(this);
		CBrush cbrush;
		int color;
		color = RGB(pDoc->r, pDoc->g, pDoc->b);
		cbrush.CreateSolidBrush(color);
		dc.SelectObject(&cbrush);
		dc.Ellipse(pDoc->x - pDoc->radius, pDoc->y - pDoc->radius, pDoc->x + pDoc->radius, pDoc->y + pDoc->radius);
		//pDoc->flag = false;
	}
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
	CMFC_0323Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->flag = true;
}


void CMFC_0323View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC_0323Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->radius += 1;
	pDoc->r += 1;
	pDoc->g += 2;
	pDoc->b += 3;
	if(pDoc->r >= 255|| pDoc->g >= 255|| pDoc->b >= 255)
	{
		pDoc->r = 0;
		pDoc->g = 0;
		pDoc->b = 0;
	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}
