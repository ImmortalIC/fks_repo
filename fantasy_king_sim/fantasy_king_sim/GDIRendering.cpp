#include "GDIRendering.h"
#include "SystemLocator.h"
#include "GameObject.h"
CGDIRendering::CGDIRendering(rendering_func func):_func(func)
{
    
}

bool CGDIRendering::Render(CGameObject* object)
{
    POINT position=object->getPosition();
    int a,b,c,d;
    a=position.x-SPRITE_SIZE/2;
    b=position.y-SPRITE_SIZE/2;
    c=position.x+SPRITE_SIZE/2;
    d=position.y+SPRITE_SIZE/2;
	SelectObject(CSystemLocator::GetGraphics()->getDc(), GetStockObject(DC_BRUSH));
	SetDCBrushColor(CSystemLocator::GetGraphics()->getDc(), RGB(255, 0, 0));
	return _func(CSystemLocator::GetGraphics()->getDc(), a, b, c, d);
}


CGDIRendering::~CGDIRendering()
{
	

}