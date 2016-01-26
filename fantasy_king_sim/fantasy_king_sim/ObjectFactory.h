#pragma once
#include "GameObject.h"

class CObjectFactory
{
public:
	CObjectFactory();
	~CObjectFactory();
	CGameObject_smart CreateVillage(unsigned x,unsigned y);
	CGameObject_smart CreateTown(unsigned x, unsigned y);
};