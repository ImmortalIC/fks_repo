#pragma once
#include "GameObject.h"


class IGraphicSystem
{
public:
	IGraphicSystem() {};
	virtual ~IGraphicSystem() = 0;
	virtual bool Render(CGameObject* object) = 0;
};
