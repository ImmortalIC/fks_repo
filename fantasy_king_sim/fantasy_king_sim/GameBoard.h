#pragma once

class IGameBoard 
{
public:
    IGameBoard(){};
    virtual ~IGameBoard()=0;
    virtual void Iterate()=0;
   
};