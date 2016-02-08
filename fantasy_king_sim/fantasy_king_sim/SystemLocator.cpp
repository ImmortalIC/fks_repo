#pragma once
#include "SystemLocator.h"
CGDIGraphicSystem* CSystemLocator::graph;

void CSystemLocator::Locate(CGDIGraphicSystem* object)
{
    CSystemLocator::graph=object;
}

CGDIGraphicSystem* CSystemLocator::GetGraphics()
{
    return CSystemLocator::graph;
}