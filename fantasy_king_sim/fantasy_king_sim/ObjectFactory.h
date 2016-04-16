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
	Formula_ptr food_formula;
	Formula_ptr pop_formula;
	std::map<char,Formula_ptr> village_production_formulas;
	std::map<char, Formula_ptr> city_production_formulas;
};