#pragma once
#include "stdafx.h"
#include "Map.h"

#define TILE_SIZE 10

class CLand 
{
public:
    std::unique_ptr<CMap> road_map;
    CLand(unsigned int x,unsigned int y);
    ~CLand();
    POINT getSize();
    bool Render();
private:
    unsigned int _x,_y;
};
