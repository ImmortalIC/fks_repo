#include "GameObject.h"
#include "stdafx.h"


CGameObject::CGameObject()
{

}


CGameObject::~CGameObject()
{
    
}

bool CGameObject::Render()
{
    return _graph->Render(this);
}


POINT CGameObject::getPosition()
{
    POINT result;
    result.x=_x;
    result.y =_y;
    return result;
}