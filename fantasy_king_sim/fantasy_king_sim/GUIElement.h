#pragma once
#include "stdafx.h"

/***mouse button constants***/
#define MBC_LEFT 0
#define MBC_RIGHT 1
#define MBC_MIDDLE 2
#define MBC_MOUSE4 3
#define MBC_MOUSE5 4
class IGUIElement {
public:
	IGUIElement() {};
	virtual ~IGUIElement() {};
	bool operator==(const POINT& point)
	{
		return point.x > x && point.x<x + width && point.y>y && point.y < y + height;
	}
	inline void SetPosition(UINT pos_x, UINT pos_y)
	{
		x = pos_x; y = pos_y;
	}

	virtual bool Render()=0;
	virtual void ProcessMouseDown(const POINT& point, const BYTE type) = 0;
	virtual void ProcessMouseUp(const POINT& point, const BYTE type) = 0;
protected:
	UINT x, y, width, height;
};

bool operator==(const std::shared_ptr<IGUIElement> &element, const POINT&  point);
