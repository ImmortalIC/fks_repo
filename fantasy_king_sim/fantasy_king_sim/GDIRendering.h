#pragma once

#include "stdafx.h"

#include "GraphicSystem.h"

#define SPRITE_SIZE 40

typedef std::function<BOOL(HDC, int, int, int, int)> rendering_func;
class CGDIRendering : public IGraphicSystem
{
public:
	CGDIRendering(rendering_func func);
	~CGDIRendering();
	bool Render(CGameObject* object);
private:
	rendering_func _func;

};