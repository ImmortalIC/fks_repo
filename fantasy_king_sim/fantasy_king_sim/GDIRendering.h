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
	inline UINT getSpriteSize() const
	{
		return SPRITE_SIZE;
	}

private:
	rendering_func _func;

};