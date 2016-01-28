#pragma once
#include "SystemLocator.h"


static void CSystemLocator::Locate(CGDIGraphicSystem* object)
{
    CSystemLocator::graph=object;
}

static CGDIGraphicSystem* CSystemLocator::GetGraphics()
{
    return CSystemLocator::graph;
}