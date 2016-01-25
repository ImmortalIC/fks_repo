#pragma once


class CGraphObject {
public:
	CGraphObject() {};
	virtual ~CGraphObject()=0;
	virtual void Render()=0;
	
protected:
	unsigned int x, y;
};