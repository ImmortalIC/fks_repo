#pragma once
#include "GDIGraphicSystem.h"
#include "StringManager.h"

class CSystemLocator
{
public:
	static CGDIGraphicSystem* GetGraphics();
	static void Locate(CGDIGraphicSystem* object);
	static void Locate(CStringManager* object);
	static CStringManager* GetStrings();
private:
	static CGDIGraphicSystem* graph;
	static CStringManager* string;
};
