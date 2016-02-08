#pragma once

class IGameBoard 
{
public:
    IGameBoard(){};
	virtual ~IGameBoard() {};
    virtual void Iterate()=0;
   
};