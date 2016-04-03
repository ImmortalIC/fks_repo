#pragma once
#include "GUIElement.h"
class CGUIButton :
	public IGUIElement
{
public:

	CGUIButton(COLORREF primary_color, COLORREF secondary_color,UINT btn_width, UINT btn_height);
	CGUIButton(const CGUIButton& orig,std::string text,std::function<void()> func);
	CGUIButton(COLORREF primary_color, COLORREF secondary_color, UINT btn_width, UINT btn_height, std::function<void()> func, std::string text);
	~CGUIButton();
	bool Render();

	void ProcessMouseDown(const POINT& point, const BYTE type);
	void ProcessMouseUp(const POINT& point, const BYTE type);

private:
	std::function<void()> action;
	COLORREF prim_clr, sec_clr;
	bool state;
	std::string label;

};

