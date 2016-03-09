#pragma once
#include "GameBoard.h"

class CGameObject;

class IMechanicsSystem
{
public:
	IMechanicsSystem() {};
	virtual ~IMechanicsSystem() {};
	virtual void CalcTurn(IGameBoard* world, CGameObject* object) = 0;
			


};