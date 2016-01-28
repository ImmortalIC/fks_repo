#pragma once

#include "Map.h"

CMap<typename data>::CMap(unsigned int x, unsigned int y):_x(x),_y(y)
{
    values.reserve(x);
    for(int i=0;i<x;i++)
    {
        values.push_back(new std::vector<data>(y));
    }
}

CMap<typename data>::~CMap()
{
    
}

bool CMap<typename data>::setValue(unsigned int i, unsigned int j, data value)
{
    if(i>_x || j>_y)
    {
        return false;
    }
    values[i][j]=value;
    return true;
}

data CMap<typename data>::getValue(unsigned int i, unsigned int j)
{
    if(i>_x || j>_y)
    {
        return NULL;
    }
    
    return values[i][j];
}