#pragma once
#include "stdafx.h"
#include "GameBoard.h"
/*ID of types of mechanics*/
#define IDT_SETTLEMENT 0
class CGameObject;
enum mechanics_types {EMPTY_MECH, MECH_TOWN,MECH_VILLAGE };
class IMechanicsSystem
{
public:
	IMechanicsSystem() {};
	virtual ~IMechanicsSystem() {};
	virtual void CalcTurn(IGameBoard* world, CGameObject* object) = 0;
	virtual void CalcFrame(IGameBoard* world, CGameObject* object) = 0;
	virtual const mechanics_types getType() const=0;
	virtual void returnStatus(std::map<char, const unsigned int *> &integer_params, std::map<char, const double *> &float_params, std::map<char, const std::string *> &string_params) const=0;

};