#pragma once

#include "GDIGraphicSystem.h"
#include "App.h"


CGDIGraphicSystem::CGDIGraphicSystem(HWND hWnd) :_hWnd(hWnd),bitmap(NULL)
{

}


CGDIGraphicSystem::~CGDIGraphicSystem()
{
	if (_renderStarted)
	{

		RenderEnd();
	}
}

HDC CGDIGraphicSystem::getDc()
{
	if (bitmap != NULL)
		return bitmap_hdc;
	else
		throw "Rendering not started";
}

void CGDIGraphicSystem::RenderStart()
{
	BeginPaint(_hWnd, &_ps);
	bitmap_hdc = CreateCompatibleDC(_ps.hdc);
	bitmap = CreateCompatibleBitmap(_ps.hdc, WIDTH, HEIGHT);
	
	SelectObject(bitmap_hdc, bitmap);
}

void CGDIGraphicSystem::RenderEnd()
{
	BitBlt(_ps.hdc, 0, 0, WIDTH, HEIGHT, bitmap_hdc, 0, 0, SRCCOPY);
	DeleteObject(bitmap_hdc);
	DeleteObject(bitmap);
	EndPaint(_hWnd, &_ps);
	bitmap = NULL;
}