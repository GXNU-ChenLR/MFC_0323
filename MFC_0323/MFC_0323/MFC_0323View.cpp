
// MFC_0323View.cpp : CMFC_0323View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMFC_0323View ����/����

CMFC_0323View::CMFC_0323View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC_0323View::~CMFC_0323View()
{
}

BOOL CMFC_0323View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC_0323View ����

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
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC_0323View ���

#ifdef _DEBUG
void CMFC_0323View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_0323View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_0323Doc* CMFC_0323View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_0323Doc)));
	return (CMFC_0323Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_0323View ��Ϣ�������


void CMFC_0323View::OnShow()
{
	// TODO: �ڴ���������������
	CMFC_0323Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->flag = true;
}


void CMFC_0323View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
