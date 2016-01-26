#pragma once

#include "ObjectFactory.h"
#include "GDIRendering.h"

CObjectFactory::CObjectFactory()
{

}

CObjectFactory::~CObjectFactory()
{

}

CGameObject_smart CObjectFactory::CreateTown(unsigned int x, unsigned int y)
{
	CGameObject_smart object(new CGameObject);
	object->_x = x;
	object->_y = y;
	rendering_func func(Rectangle);
	object->_graph = std::unique_ptr<IGraphicSystem>(new CGDIRendering(func));
	return object;
}

CGameObject_smart CObjectFactory::CreateVillage(unsigned int x, unsigned int y)
{
	CGameObject_smart object(new CGameObject);
	object->_x = x;
	object->_y = y;
	rendering_func func(Ellipse);
	object->_graph = std::unique_ptr<IGraphicSystem>(new CGDIRendering(func));
	return object;
}