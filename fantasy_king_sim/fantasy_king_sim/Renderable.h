#pragma once

class IRenderable
{
public:
	IRenderable() {};
	virtual ~IRenderable() {};
	virtual bool Render() = 0;
};