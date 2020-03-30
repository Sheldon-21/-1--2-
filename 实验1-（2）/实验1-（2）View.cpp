
// 实验1-（2）View.cpp: C实验12View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "实验1-（2）.h"
#endif

#include "实验1-（2）Doc.h"
#include "实验1-（2）View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C实验12View

IMPLEMENT_DYNCREATE(C实验12View, CView)

BEGIN_MESSAGE_MAP(C实验12View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// C实验12View 构造/析构

C实验12View::C实验12View() noexcept
{
	// TODO: 在此处添加构造代码

}

C实验12View::~C实验12View()
{
}

BOOL C实验12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C实验12View 绘图

void C实验12View::OnDraw(CDC* pDC)
{
	C实验12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CPen pen;
	CBrush brush;
	pen.CreatePen(PS_SOLID, 3, RGB(250, 0, 0));
	brush.CreateSolidBrush(RGB(0, 250, 0));
	pDC->SelectObject(pen);
	pDC->SelectObject(brush);
	pDC->Ellipse(100, 200, 300, 300);
	DeleteObject(pen);
	DeleteObject(brush);
	CString str(_T("hello world"));//用UNICODE编码
	pDC->SetTextColor(RGB(0, 0, 250));//字体颜色
	pDC->TextOut(120, 150, str);
	pDC->SetTextColor(RGB(125, 125, 125));
	double a[] = { 31.4,888.54 };
	char ch[10];
	CString str1;
	str1.Format(_T("%f"), a[0]);
	pDC->TextOut(20, 40, str1);//输出的位置
	str1.Format(_T("%f"), a[1]);
	pDC->TextOut(20, 60, str1);


	
}

void C实验12View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C实验12View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C实验12View 诊断

#ifdef _DEBUG
void C实验12View::AssertValid() const
{
	CView::AssertValid();
}

void C实验12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C实验12Doc* C实验12View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C实验12Doc)));
	return (C实验12Doc*)m_pDocument;
}
#endif //_DEBUG


// C实验12View 消息处理程序
