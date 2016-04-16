#pragma once

#include "MechanicsSystem.h"
#include "FormulaParser.h"
#include "GMStorage.h"
class CSettlementMechanics :
	public IMechanicsSystem
{
public:
	CSettlementMechanics();
	CSettlementMechanics(Formula_ptr &pg, Formula_ptr &fc, UINT start_pop,const BYTE food_type,CGMStorage* const storage,const std::map<char,Formula_ptr> &prod,mechanics_types tp);
	~CSettlementMechanics();
	void CalcTurn(IGameBoard* world, CGameObject* object) ;
	void CalcFrame(IGameBoard* world, CGameObject* object) ;
	const inline  UINT& getPopulation() const;
	const inline  UINT& getFood() const;
	virtual const mechanics_types getType() const;
	const CGMStorage& getStorage() const;

	virtual void returnStatus(std::map<char, const unsigned int *> &integer_params, std::map<char, const double *> &float_params, std::map<char, const std::string *> &string_params) const;
private:
	Formula_ptr pop_grow; 
	Formula_ptr food_consuption;
	unsigned int population;
	unsigned int* food;
	std::unique_ptr<CGMStorage> _storage;
	std::map<char, Formula_ptr> _production_formulas;
	void calcProduction();
	const mechanics_types type;
};

