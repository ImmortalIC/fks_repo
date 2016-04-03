#pragma once
#include "GUIElement.h"
#include "MechanicsSystem.h"

class CGUIStatusPanel : public IGUIElement
{
public:
	CGUIStatusPanel(UINT width, UINT height);
	~CGUIStatusPanel();
	bool Render();
	void ProcessMouseDown(const POINT& point, const BYTE type) ;
	void ProcessMouseUp(const POINT& point, const BYTE type);
	void ShowStatus(const IMechanicsSystem* object);
private:
	std::map<mechanics_types,std::string> templates;
	mechanics_types current_template;
	std::map<char, const unsigned int *> integer_params;
	std::map<char, const double *> float_params;
	std::map<char, const std::string *> string_params;
	template <class T>
	void FillParams(std::string& text, std::map<char, const T *> params);
	std::string ToStr(const std::string& param);
	std::string ToStr(const unsigned int& param);
	std::string ToStr(const double& param);
};

