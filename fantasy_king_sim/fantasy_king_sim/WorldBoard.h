#pragma once

#include "stdafx.h"
#include "GameBoard.h"
#include "GameObject.h"
#include "Map.h"

class CWorldBoard : public IGameBoard 
{
    public:
        CWorldBoard();
        void Iterate();
    private:
        std::vector<CGameObject_smart> objects;
        std::unique_ptr<CLand> landscape;
         void InitTestEnviroment();   
};