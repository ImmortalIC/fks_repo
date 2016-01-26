#pragma once

#include "GDIGraphicSystem.h"



CGDIGraphicSystem::CGDIGraphicSystem(HWND hWnd) :_hWnd(hWnd)
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
	return _ps.hdc;
}

void CGDIGraphicSystem::RenderStart()
{
	BeginPaint(_hWnd, &_ps);
}

void CGDIGraphicSystem::RenderEnd()
{
	EndPaint(_hWnd, &_ps);
}