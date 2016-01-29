#pragma once
#include "stdafx.h"
#include "Map.h"
#include "Renderable.h"
#define TILE_SIZE 10

class CLand :public IRenderable
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
