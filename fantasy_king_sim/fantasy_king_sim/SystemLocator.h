#pragma once
#include "GDIGraphicSystem.h"


class CSystemLocator
{
public:
	static CGDIGraphicSystem* GetGraphics();
	static void Locate(CGDIGraphicSystem* object);
private:
	static CGDIGraphicSystem* graph;
};
