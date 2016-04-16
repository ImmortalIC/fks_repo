#pragma once

#include "ObjectFactory.h"
#include "GDIRendering.h"
#include "GMStorage.h"
#include "resource.h"
#include "SystemLocator.h"
CObjectFactory::CObjectFactory()
{
	std::string food_formula, pop_formula,temp_formula;
	food_formula = CSystemLocator::GetStrings()->GetString(IDS_FOODCONS);
	pop_formula = CSystemLocator::GetStrings()->GetString(IDS_POPGROW);
	
	
	this->food_formula = Formula_ptr(CFormulaParser::ParserFactory(food_formula));
	this->pop_formula = Formula_ptr(CFormulaParser::ParserFactory(pop_formula));
	temp_formula = CSystemLocator::GetStrings()->GetString(IDS_FOODPROD);
	village_production_formulas[1] = Formula_ptr(CFormulaParser::ParserFactory(temp_formula));
	temp_formula = CSystemLocator::GetStrings()->GetString(IDS_GOLDPROD);
	city_production_formulas[2] = Formula_ptr(CFormulaParser::ParserFactory(temp_formula));

	
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
	std::vector<std::pair<BYTE, unsigned int>> storaged, needed, exporting;
	storaged = { std::pair<BYTE,unsigned int>(1,200),std::pair<BYTE,unsigned int>(2,0) };// TODO: change hardcoded constants too loading from settings
	needed = { std::pair<BYTE,unsigned int>(1,100)};
	exporting = {std::pair<BYTE,unsigned int>(2,50) };
	CGMStorage* storage = new CGMStorage(storaged,needed,exporting);

	object->_mechanics = std::unique_ptr<IMechanicsSystem>(new CSettlementMechanics(pop_formula,food_formula,5000,1,storage,city_production_formulas,mechanics_types::MECH_TOWN));
	return object;
}

CGameObject_smart CObjectFactory::CreateVillage(unsigned int x, unsigned int y)
{
	CGameObject_smart object(new CGameObject);
	object->_x = x;
	object->_y = y;
	rendering_func func(Ellipse);
	object->_graph = std::unique_ptr<IGraphicSystem>(new CGDIRendering(func));
	std::vector<std::pair<BYTE, unsigned int>> storaged, needed, exporting;
	storaged = { std::pair<BYTE,unsigned int>(1,200) };// TODO: change hardcoded constants too loading from settings
	needed = { std::pair<BYTE,unsigned int>(1,100) };
	exporting = { std::pair<BYTE,unsigned int>(2,200) };
	CGMStorage* storage = new CGMStorage(storaged, needed, exporting);

	object->_mechanics = std::unique_ptr<IMechanicsSystem>(new CSettlementMechanics(pop_formula, food_formula, 5000, 1, storage, village_production_formulas,mechanics_types::MECH_VILLAGE));
	return object;
}