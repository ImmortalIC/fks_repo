#pragma once
#include "stdafx.h"
#include "GUIElement.h"
#include "GUIStatusPanel.h"
#include "WorldBoard.h"
class CMapWindow :
	public IGUIElement
{
public:
	CMapWindow(UINT width,UINT height,CGUIStatusPanel* linked_panel,CWorldBoard* sorce_board);
	~CMapWindow();
	bool Render() ;
	void ProcessMouseDown(const POINT& point, const BYTE type);
	void ProcessMouseUp(const POINT& point, const BYTE type);
private:
	CGUIStatusPanel* _panel;
	CWorldBoard* _board;
	POINT selection_frame;
	UINT sf_size;


};

