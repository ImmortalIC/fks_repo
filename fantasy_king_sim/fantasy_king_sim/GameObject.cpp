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


POINT CGameObject::getPosition() const
{
    POINT result;
    result.x=_x;
    result.y =_y;
    return result;
}

void CGameObject::CalcFrame(IGameBoard* world)
{
	_mechanics->CalcFrame(world, this);
}

void CGameObject::CalcTurn(IGameBoard* world)
{
	_mechanics->CalcTurn(world, this);
}


bool CGameObject::operator==(const POINT& point)
{
	UINT size = _graph->getSpriteSize();
	return abs(point.x - (long)_x) <= size / 2 && abs(point.y - (long)_y) <= size / 2;
}

const IMechanicsSystem* CGameObject::getMechanics() const
{
	return _mechanics.get();
}