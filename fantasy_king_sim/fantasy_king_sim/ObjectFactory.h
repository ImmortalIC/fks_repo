#pragma once
#include "GameObject.h"

class ObjectFactory
{
public:
	ObjectFactory();
	~ObjectFactory();
	CGameObject* CreateVillage(unsigned x,unsigned y);
	CGameObject* CreateTown(unsigned x, unsigned y);
};