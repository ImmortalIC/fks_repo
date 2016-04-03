#pragma once


class CGameObject;
class IGraphicSystem
{
public:
	virtual ~IGraphicSystem() {};
	virtual bool Render(CGameObject* object)=0;
	virtual UINT getSpriteSize() const=0;
};
