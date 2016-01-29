#pragma once

class IRenderable
{
public:
	IRenderable() {};
	virtual ~IRenderable() = 0;
	virtual bool Render() = 0;
};