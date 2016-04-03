#pragma once
#include "stdafx.h"
#include "GUIElement.h"
typedef std::shared_ptr<IGUIElement> GUIE_ptr; 
class CWorldBoard;
class CGUISystem
{
public:
	CGUISystem();
	~CGUISystem();
	void InitTestGUI(CWorldBoard* board);
	void Render();
	void ProcessMouseDown(const POINT& point, const BYTE type);
	void ProcessMouseUp(const POINT& point, const BYTE type);
private:
	std::vector<GUIE_ptr> elements;

};

