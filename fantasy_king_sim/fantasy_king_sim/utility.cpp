#pragma once
#include "GameObject.h"
#include "GUIElement.h"

bool operator==(const CGameObject_smart &element, const POINT&  point)
{
	return (*element) == point;
}

bool operator==(const std::shared_ptr<IGUIElement> &element, const POINT&  point)
{
	return (*element) == point;
}
