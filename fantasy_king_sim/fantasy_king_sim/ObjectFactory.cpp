#pragma once

#include "ObjectFactory.h"
#include "GDIRendering.h"
#include "resource.h"
#include "SystemLocator.h"
CObjectFactory::CObjectFactory()
{
	std::string food_formula, pop_formula;
	food_formula = CSystemLocator::GetStrings()->GetString(IDS_FOODCONS);
	pop_formula = CSystemLocator::GetStrings()->GetString(IDS_POPGROW);
	Formula_ptr ff, pf;
	ff = Formula_ptr(CFormulaParser::ParserFactory(food_formula));
	pf = Formula_ptr(CFormulaParser::ParserFactory(pop_formula));
	setllement_prototype = CSettlementMechanics(pf, ff, 5000, 200);

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
	object->_mechanics = std::unique_ptr<IMechanicsSystem>(new CSettlementMechanics(setllement_prototype));
	return object;
}

CGameObject_smart CObjectFactory::CreateVillage(unsigned int x, unsigned int y)
{
	CGameObject_smart object(new CGameObject);
	object->_x = x;
	object->_y = y;
	rendering_func func(Ellipse);
	object->_graph = std::unique_ptr<IGraphicSystem>(new CGDIRendering(func));
	object->_mechanics = std::unique_ptr<IMechanicsSystem>(new CSettlementMechanics(setllement_prototype));
	return object;
}