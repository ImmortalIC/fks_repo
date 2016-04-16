#pragma once
#include "stdafx.h"
#include "IngameResource.h"
#include "utility.h"
/*
Storage in meaning storage of resources in object
*/
typedef std::shared_ptr<CIngameResource> GMResource;
class CGMStorage
{
public:
	CGMStorage(const std::vector<std::pair<BYTE, unsigned int>>& storaged_resources, const std::vector<std::pair<BYTE,unsigned int>>& needed_resources, const std::vector<std::pair<BYTE, unsigned int>>& exported_resources);
	~CGMStorage();
	const std::vector<GMResource>& getStoraged() const;
	const std::vector<GMResource> getNeeded() const;
	const std::vector<GMResource> getExport() const;
	std::map<char, double> formatFormulaParams() const;
private:
	std::vector<GMResource> storaged;
	std::vector<GMResource> needed;
	std::vector<GMResource> exporting;
	void fillVector(std::vector<GMResource>& resources, const std::vector<std::pair<BYTE, unsigned int>>& indicies);
	void intersectResources(std::vector<GMResource>&, const std::vector<GMResource>&, const std::vector<GMResource>&,  binary_function< GMResource, GMResource,bool>*) const; 
};