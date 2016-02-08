#pragma once
#include "stdafx.h"


template <class data>
class CMap 
{
    public:
        CMap(unsigned int x,unsigned int y);
        ~CMap();
        data getValue(unsigned int i,unsigned int j);
        bool setValue(unsigned int i,unsigned int j,data value);
   private:
       std::vector<std::vector<data>> values;
       unsigned int _x,_y;//размеры
            
                
};
template<class data>
CMap<data>::CMap(unsigned int x, unsigned int y) :_x(x), _y(y)
{
	values.reserve(x);
	for (unsigned int i = 0; i<x; i++)
	{
		values.push_back(std::vector<data>(y));
	}
}
template<class data>
CMap<data>::~CMap()
{

}
template<class data>
bool CMap<data>::setValue(unsigned int i, unsigned int j, data value)
{
	if (i>_x || j>_y)
	{
		return false;
	}
	values[i][j] = value;
	return true;
}
template<class data>
data CMap<data>::getValue(unsigned int i, unsigned int j)
{
	if (i>_x || j>_y)
	{
		return NULL;
	}

	return values[i][j];
}