#pragma once
#include "Renderable.h"
class CVillage :
	public IRenderable
{
public:
	CVillage();
	~CVillage();
private:
	unsigned int x, y;
};

