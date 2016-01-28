#pragma once

#include "Land.h"


CLand::CLand(unsigned int x, unsigned int y):_x(x),_y(y)
{
    road_map=new CMap(x,y);
    
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
    for(int i=0;i<_x;i++)
    {
        for(int j=0;j<_y;j++)
        {
            
        }
    }
}