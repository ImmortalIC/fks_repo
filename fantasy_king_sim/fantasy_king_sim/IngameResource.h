#pragma once
#include "stdafx.h"
class CIngameResource
{
public:
	CIngameResource(const BYTE type,const char status_index,const char formula_index);
	~CIngameResource();
	static void InitalizeResources();
	static CIngameResource* createResource(const BYTE type);
	const BYTE type;
	const char status_index;
	const char formula_index;
	unsigned int quantity;
	bool operator<=(const CIngameResource& b) const;
	bool operator>=(const CIngameResource& b) const;
private:
	static std::map<BYTE, std::unique_ptr<CIngameResource>> prototypes;

};

bool operator<=(const std::shared_ptr<CIngameResource>& a, const std::shared_ptr<CIngameResource>&  b);
bool operator>=(const std::shared_ptr<CIngameResource>& a, const std::shared_ptr<CIngameResource>&  b);

bool operator==(const std::shared_ptr<CIngameResource>& a, const char& b);
