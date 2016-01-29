#pragma once

#include "WorldBoard.h"

void CWorldBoard::CWorldBoard()
{
    InitTestEnviroment();
}

void CWorldBoard::Iterate()
{
    landscape->Render();
    for(std::iterator<CGameObject_smart> it=objects.begin();it!=objects.end();it++)
    {
        *it->Render();
    }
}

void CWorldBoard::InitTestEnviroment()
{
    landscape=new CLand(50,50);
    CObjectFactory factory;
    
    objects.push_back(factory.CreateTown(100,100));
    objects.push_back(factory.CreateTown(450,140));
    objects.push_back(factory.CreateVillage(170,450));
    objects.push_back(factory.CreateVillage(50,250));
    objects.push_back(factory.CreateVillage(170,150));
}