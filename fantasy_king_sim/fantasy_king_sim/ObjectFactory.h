#pragma once
#include "GameObject.h"
#include "SettlementMechanics.h"
class CObjectFactory
{
public:
	CObjectFactory();
	~CObjectFactory();
	CGameObject_smart CreateVillage(unsigned int x,unsigned int y);
	CGameObject_smart CreateTown(unsigned int x, unsigned int y);
private:
	CSettlementMechanics setllement_prototype;
};