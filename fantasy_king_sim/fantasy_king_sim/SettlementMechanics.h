#pragma once
#include "MechanicsSystem.h"
#include "FormulaParser.h"

class CSettlementMechanics :
	public IMechanicsSystem
{
public:
	CSettlementMechanics();
	CSettlementMechanics(Formula_ptr &pg, Formula_ptr &fc, UINT start_pop, UINT start_food);
	~CSettlementMechanics();
	void CalcTurn(IGameBoard* world, CGameObject* object) ;
	void CalcFrame(IGameBoard* world, CGameObject* object) ;
	const inline  UINT& getPopulation() const;
	const inline  UINT& getFood() const;
	virtual const mechanics_types getType() const;
	virtual void returnStatus(std::map<char, const unsigned int *> &integer_params, std::map<char, const double *> &float_params, std::map<char, const std::string *> &string_params) const;
private:
	Formula_ptr pop_grow; 
	Formula_ptr food_consuption;
	unsigned int population;
	int food;
	
};

