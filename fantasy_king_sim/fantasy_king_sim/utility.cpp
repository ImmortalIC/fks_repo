#pragma once
#include "GameObject.h"
#include "GUIElement.h"
#include "IngameResource.h"
bool operator==(const CGameObject_smart &element, const POINT&  point)
{
	return (*element) == point;
}

bool operator==(const std::shared_ptr<IGUIElement> &element, const POINT&  point)
{
	return (*element) == point;
}


bool operator<=(const std::shared_ptr<CIngameResource>& a, const std::shared_ptr<CIngameResource>&  b)
{
	return *a <= *b;
}
bool operator>=(const std::shared_ptr<CIngameResource>& a, const std::shared_ptr<CIngameResource>&  b)
{
	return *a >= *b;
}

bool operator==(const std::shared_ptr<CIngameResource>& a, const char&  b)
{
	return b == a->type;
}