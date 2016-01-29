#pragma once
#include "stdafx.h"


template <typename data>
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
