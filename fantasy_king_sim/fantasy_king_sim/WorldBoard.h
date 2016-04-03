#pragma once

#include "stdafx.h"
#include "GameBoard.h"
#include "GameObject.h"
#include "Land.h"

class CWorldBoard : public IGameBoard 
{
    public:
        CWorldBoard();
        void Iterate();
		void NextTurn();
		const CGameObject* checkPoint(const POINT& point);
    private:
        std::vector<CGameObject_smart> objects;
        std::unique_ptr<CLand> landscape;
         void InitTestEnviroment();   
};