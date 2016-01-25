#pragma once

class IRenderable
{
public:
	IRenderable() {};
	virtual ~IRenderable() = 0;
	virtual void Render() = 0;
};