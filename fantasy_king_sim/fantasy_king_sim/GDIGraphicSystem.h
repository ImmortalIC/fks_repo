#pragma once
#include "stdafx.h"

class CGDIGraphicSystem 
{
public:
    CGDIGraphicSystem(HWND hWnd);
    ~CGDIGraphicSystem();
    void RenderStart();
    void RenderEnd();
    HDC getDc();
private:
	HWND _hWnd;
	PAINTSTRUCT _ps;
	bool _renderStarted = false;
	HBITMAP bitmap;
	HDC bitmap_hdc;
    
};