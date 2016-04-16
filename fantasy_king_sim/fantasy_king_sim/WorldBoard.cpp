#pragma once
#include <algorithm>
#include "WorldBoard.h"
#include "ObjectFactory.h"

CWorldBoard::CWorldBoard()
{
    InitTestEnviroment();
}

void CWorldBoard::Iterate()
{
	
    landscape->Render();
	 for(std::vector<CGameObject_smart>::iterator it=objects.begin();it!=objects.end();it++)
    {
		(*it)->CalcFrame(this);
        (*it)->Render();
    }
}

void CWorldBoard::InitTestEnviroment()
{
    landscape=std::unique_ptr<CLand>(new CLand(50,50));
    CObjectFactory factory;
	CIngameResource::InitalizeResources();
    objects.push_back(factory.CreateTown(100,100));
    objects.push_back(factory.CreateTown(450,140));
    objects.push_back(factory.CreateVillage(170,450));
    objects.push_back(factory.CreateVillage(50,250));
    objects.push_back(factory.CreateVillage(170,150));
	landscape->road_map->setValue(11, 11, 1);
	landscape->road_map->setValue(11, 12, 1);
	landscape->road_map->setValue(11, 13, 1);
	landscape->road_map->setValue(11, 14,1);
	landscape->road_map->setValue(11, 15, 1);
	landscape->road_map->setValue(12, 15, 1);
	landscape->road_map->setValue(13, 15, 1);
	landscape->road_map->setValue(14, 15, 1);
	landscape->road_map->setValue(15, 15, 1);
	landscape->road_map->setValue(19, 15, 1);
	landscape->road_map->setValue(18, 15, 1);
	landscape->road_map->setValue(20, 15, 1);
	landscape->road_map->setValue(21, 15, 1);
	landscape->road_map->setValue(22, 15, 1);
	landscape->road_map->setValue(23, 15, 1);
	landscape->road_map->setValue(24, 15, 1);
	landscape->road_map->setValue(25, 15, 1);
	landscape->road_map->setValue(26, 15, 1);
	landscape->road_map->setValue(27, 15, 1);
	landscape->road_map->setValue(28, 15, 1);
	landscape->road_map->setValue(29, 15, 1);
	landscape->road_map->setValue(30, 15, 1);
	landscape->road_map->setValue(31, 15, 1);
	landscape->road_map->setValue(32, 15, 1);
	landscape->road_map->setValue(33, 15, 1);
	landscape->road_map->setValue(34, 15, 1);
	landscape->road_map->setValue(35, 15, 1);
	landscape->road_map->setValue(36, 15, 1);
	landscape->road_map->setValue(37, 15, 1);
	landscape->road_map->setValue(38, 15, 1);
	landscape->road_map->setValue(39, 15, 1);
	landscape->road_map->setValue(40, 15, 1);
	landscape->road_map->setValue(41, 15, 1);
	landscape->road_map->setValue(42, 15, 1);
	landscape->road_map->setValue(43, 15, 1);

}

void CWorldBoard::NextTurn()
{
	for (std::vector<CGameObject_smart>::iterator it = objects.begin(); it != objects.end(); it++)
	{
		(*it)->CalcTurn(this);
	}
}

const CGameObject* CWorldBoard::checkPoint(const POINT& point) 
{
	std::vector<CGameObject_smart>::iterator found = find(objects.begin(), objects.end(), point);
	if (found == objects.end())
		return NULL;
	return found->get();
}