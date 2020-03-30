
// 实验1-（2）View.h: C实验12View 类的接口
//

#pragma once


class C实验12View : public CView
{
protected: // 仅从序列化创建
	C实验12View() noexcept;
	DECLARE_DYNCREATE(C实验12View)

// 特性
public:
	C实验12Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C实验12View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 实验1-（2）View.cpp 中的调试版本
inline C实验12Doc* C实验12View::GetDocument() const
   { return reinterpret_cast<C实验12Doc*>(m_pDocument); }
#endif

