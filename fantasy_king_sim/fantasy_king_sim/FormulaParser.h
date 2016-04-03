#pragma once
#include "stdafx.h"
#include <stack>
#include "utility.h"
struct logic_contruct
{
	char operandA;
	char operandB;
	std::function<bool(double, double)> function;
	std::string trueFormula;
	std::string falseFormula;
};

class CFormulaParser
{
public:
	CFormulaParser();
	CFormulaParser(std::string formula);
	virtual ~CFormulaParser();
	virtual double Calculate(std::map<char, double> params);
	static CFormulaParser* ParserFactory(std::string formula);
protected:
	virtual void startParsing(std::string formula);
	double calcFormula(std::string formula, std::map<char, double> params);
	std::string makePolandNotation(std::string formula);
	char makeOperand(std::string str);
	std::map<char, double> _constants;
	char last_const_index;
	void mergeParams(std::map<char, double> &params);
private:
	std::string _preparedFormula;	
	std::map<char, std::map<char, char>> makePriorityList();
	double makeAction(std::stack<double>* stack, binary_function<double,double,double>* func);
	
};
typedef std::shared_ptr<CFormulaParser> Formula_ptr;
class CConditionalFormulaParser : public CFormulaParser
{
public:
	CConditionalFormulaParser();
	~CConditionalFormulaParser();
	double Calculate(std::map<char, double> params);
private:
	void startParsing(std::string formula);
	logic_contruct _preparedFormula;
	
};

