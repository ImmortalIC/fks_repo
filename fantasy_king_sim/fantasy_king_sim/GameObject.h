#pragma once
#include "stdafx.h"
#include "Renderable.h"
#include "GraphicSystem.h"
class CGameObject :
	public IRenderable
{
public:
	CGameObject();
	~CGameObject();
	void Render();
private:
	std::shared_ptr<IGraphicSystem> _graph;
	unsigned int _x, _y;
};

