#pragma once
#include "stdafx.h"

class CStringManager
{
public:
	CStringManager(HINSTANCE hInst);
	~CStringManager();
	std::string GetString(UINT id);
private:
	HINSTANCE inst;
};

