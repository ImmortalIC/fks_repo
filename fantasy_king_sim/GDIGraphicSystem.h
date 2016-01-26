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
    
    
    
    
};