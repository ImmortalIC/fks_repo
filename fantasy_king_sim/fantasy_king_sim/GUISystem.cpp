#include "GUISystem.h"
#include "GUIStatusPanel.h"
#include "GUIButton.h"
#include "MapWindow.h"

CGUISystem::CGUISystem()
{
}


CGUISystem::~CGUISystem()
{
}


void CGUISystem::Render()
{
	for (std::vector<GUIE_ptr>::iterator it = elements.begin(); it != elements.end(); it++)
	{
		(*it)->Render();
	}
}

void CGUISystem::ProcessMouseDown(const POINT& point, const BYTE type)
{
	std::vector<GUIE_ptr>::iterator found;
	found = std::find(elements.begin(), elements.end(), point);
	if (found != elements.end())
	{
		(*found)->ProcessMouseDown(point, type);
	}
}




void CGUISystem::ProcessMouseUp(const POINT& point, const BYTE type)
{
	std::vector<GUIE_ptr>::iterator found;
	found = std::find(elements.begin(), elements.end(), point);
	if (found != elements.end())
	{
		(*found)->ProcessMouseUp(point, type);
	}

}

void CGUISystem::InitTestGUI( CWorldBoard* board)
{
	GUIE_ptr panel = GUIE_ptr(new CGUIStatusPanel(200, 400));
	panel->SetPosition(500, 0);
	GUIE_ptr map_view = GUIE_ptr(new CMapWindow(500, 500, (CGUIStatusPanel*)panel.get(), board));
	map_view->SetPosition(0, 0);
	GUIE_ptr btn_endTurn = GUIE_ptr(new CGUIButton(RGB(63, 72, 204), RGB(38, 47,145), 100, 50,
		[=]() {
			board->NextTurn();
		}, "End Turn"));
	btn_endTurn->SetPosition(550, 450);
	elements.push_back(map_view);
	elements.push_back(panel);
	elements.push_back(btn_endTurn);
}