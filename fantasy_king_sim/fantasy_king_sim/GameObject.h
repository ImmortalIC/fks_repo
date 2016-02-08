#pragma once
#include "stdafx.h"
#include "Renderable.h"
#include "GraphicSystem.h"


class CObjectFactory;
typedef std::shared_ptr<CGameObject> CGameObject_smart;
class CGameObject :	public IRenderable
{
	friend CObjectFactory;
public:
	
	CGameObject();
	~CGameObject();
	bool Render();
       POINT getPosition();
protected:
	
	std::unique_ptr<IGraphicSystem> _graph;
	unsigned int _x, _y;
};

