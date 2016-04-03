#pragma once
#include "stdafx.h"
#include "Renderable.h"
#include "GraphicSystem.h"
#include "MechanicsSystem.h"
#include "GameBoard.h"

class CObjectFactory;
typedef std::shared_ptr<CGameObject> CGameObject_smart;
class CGameObject :	public IRenderable
{
	friend CObjectFactory;
public:
	
	CGameObject();
	~CGameObject();
	bool Render();
	void CalcFrame(IGameBoard* world);
	void CalcTurn(IGameBoard* world);
       POINT getPosition() const;
	   inline UINT getVisualSize() const {
		   return _graph->getSpriteSize();
	   }
	   const IMechanicsSystem* getMechanics() const;
	   bool operator ==(const POINT& point);
protected:
	
	std::unique_ptr<IGraphicSystem> _graph;
	std::unique_ptr<IMechanicsSystem> _mechanics;
	unsigned int _x, _y;
};


bool operator==(const CGameObject_smart &element, const POINT&  point);
