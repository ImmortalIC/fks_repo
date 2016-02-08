#pragma once

#include "Land.h"
#include "SystemLocator.h"

CLand::CLand(unsigned int x, unsigned int y):_x(x),_y(y)
{
    road_map=std::unique_ptr<CMap<bool>>(new CMap<bool>(x,y));
    
}

POINT CLand::getSize()
{
    POINT result;
    result.x=_x;
    result.y =_y;
    return result;
}

bool CLand::Render()
{
	SelectObject(CSystemLocator::GetGraphics()->getDc(), GetStockObject(BLACK_BRUSH));
	bool res;
    for(unsigned int i=0;i<_x;i++)
    {
        for(unsigned int j=0;j<_y;j++)
        {
			SelectObject(CSystemLocator::GetGraphics()->getDc(), GetStockObject(DC_PEN));
			SetDCPenColor(CSystemLocator::GetGraphics()->getDc(), RGB(127, 127, 127));
			res=Rectangle(CSystemLocator::GetGraphics()->getDc(), i*TILE_SIZE, j*TILE_SIZE, (i + 1)*TILE_SIZE, (j + 1)*TILE_SIZE);
			if (!res)
				return false;
			if (road_map->getValue(i, j))
			{
				DrawRoads(i, j);
				
			}
        }
    }
	return true;
}

void CLand::DrawRoads(int i, int j)
{
	SelectObject(CSystemLocator::GetGraphics()->getDc(), GetStockObject(WHITE_PEN));
	for (int k = -1; k <= 1; k += 2)
	{
		MoveToEx(CSystemLocator::GetGraphics()->getDc(), (i + 0.5)*TILE_SIZE, (j + 0.5)*TILE_SIZE, nullptr);
		if (road_map->getValue(i + k, j))
		{
			LineTo(CSystemLocator::GetGraphics()->getDc(), (i + 0.5 + 0.5*k)*TILE_SIZE, (j + 0.5)*TILE_SIZE);
			MoveToEx(CSystemLocator::GetGraphics()->getDc(), (i + 0.5)*TILE_SIZE, (j + 0.5)*TILE_SIZE, nullptr);
		}
		if (road_map->getValue(i, j + k))
		{
			LineTo(CSystemLocator::GetGraphics()->getDc(), (i + 0.5 )*TILE_SIZE, (j + 0.5 + 0.5*k)*TILE_SIZE);
		}
	}

}

CLand::~CLand()
{

}