#include "GameObject.h"
#include "stdafx.h"
#include <functional>

CGameObject::CGameObject()
{
	std::function<BOOL(HDC, int, int, int, int)> func = Ellipse;
	func = Rectangle;
	HDC abs;
	func(abs,1,2,3,4);
}


CGameObject::~CGameObject()
{
}
