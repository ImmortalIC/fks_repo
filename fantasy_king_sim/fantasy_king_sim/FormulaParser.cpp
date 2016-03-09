#include "FormulaParser.h"
#include <regex>






CFormulaParser::~CFormulaParser()
{


}


void CFormulaParser::startParsing(std::string formula)
{
	_preparedFormula = this->makePolandNotation(formula);
}

std::string CFormulaParser::makePolandNotation(std::string formula)
{
	std::stack<char> stack;
	std::string result,num;
	std::map<char, std::map<char, char>> priorities = makePriorityList();
	char signs_raw[] = { '+','-','*','/','^','(',')' };
	std::vector<char> signs(signs_raw, signs_raw + 7);
	bool stacked=false;
	for (std::string::iterator it = formula.begin(); it != formula.end(); it++)
	{
		if (*it >= '0' && *it <= '9' || *it == '.' || (*it=='-' &&  (it==formula.begin() || std::find(signs.begin(), signs.end(), *(it-1)) != signs.end())))
		{
			num.push_back(*it);

		} else {
			if (num.length() > 0)
			{
				result.push_back(makeOperand(num));
				num.erase();
			}
			if (std::find(signs.begin(), signs.end(), *it) != signs.end())
			{
				stacked = false;
				while (!stacked)
				{
					switch (priorities[!stack.empty() ? stack.top() : 0][*it])
					{
					case 4:
						throw "Error in parsing formula";
						break;
					case 1:
						stack.push(*it);
						stacked = true;
						break;
					case 2:
						result.push_back(stack.top());
						stack.pop();
						break;
					case 3:
						stack.pop();
						stacked = true;
						break;
					default:
						throw "Error in parsing formula";
					}
				}
			}
			else {
				result.push_back(*it);
			}
		}
	}
	if (num.length() > 0)
	{
		result.push_back(makeOperand(num));
		num.erase();
	}
	while (!stack.empty())
	{
		result.push_back(stack.top());
		stack.pop();
	}
	return result;
}



std::map<char, std::map<char, char>> CFormulaParser::makePriorityList()
{

	std::map<char, std::map<char, char>> priorities;
	priorities[0]['+'] = 1;
	priorities[0]['-'] = 1;
	priorities[0]['*'] = 1;
	priorities[0]['/'] = 1;
	priorities[0]['^'] = 1;
	priorities[0]['('] = 1;
	priorities[0][')'] = 4;
	priorities['+']['+'] = 2;
	priorities['+']['-'] = 2;
	priorities['+']['*'] = 1;
	priorities['+']['/'] = 1;
	priorities['+']['^'] = 1;
	priorities['+']['('] = 1;
	priorities['+'][')'] = 2;
	priorities['-']['+'] = 2;
	priorities['-']['-'] = 2;
	priorities['-']['*'] = 1;
	priorities['-']['/'] = 1;
	priorities['-']['^'] = 1;
	priorities['-']['('] = 1;
	priorities['-'][')'] = 2;
	priorities['*']['+'] = 2;
	priorities['*']['-'] = 2;
	priorities['*']['*'] = 2;
	priorities['*']['/'] = 2;
	priorities['*']['^'] = 1;
	priorities['*']['('] = 1;
	priorities['*'][')'] = 2;
	priorities['/']['+'] = 2;
	priorities['/']['-'] = 2;
	priorities['/']['*'] = 2;
	priorities['/']['/'] = 2;
	priorities['/']['^'] = 1;
	priorities['/']['('] = 1;
	priorities['/'][')'] = 2;
	priorities['^']['+'] = 2;
	priorities['^']['-'] = 2;
	priorities['^']['*'] = 2;
	priorities['^']['/'] = 2;
	priorities['^']['^'] = 2;
	priorities['^']['('] = 1;
	priorities['^'][')'] = 2;
	priorities['(']['+'] = 1;
	priorities['(']['-'] = 1;
	priorities['(']['*'] = 1;
	priorities['(']['/'] = 1;
	priorities['(']['^'] = 1;
	priorities['(']['('] = 1;
	priorities['('][')'] = 3;
	return priorities;
}

double CFormulaParser::calcFormula(std::string formula, std::map<char, double> params)
{
	std::stack<double> stack;
	plus<double> pl;
	minus<double> min;
	multiplies<double> mult;
	divides<double> div;
	power<double> pw;

	for (std::string::iterator it = formula.begin(); it != formula.end(); it++)
	{
		switch (*it)
		{
		case '+':
			stack.push(makeAction(&stack, &pl));
			break;
		case '-':
			stack.push(makeAction(&stack, &min));
			break;
		case '*':
			stack.push(makeAction(&stack, &mult));
			break;
		case '/':
			stack.push(makeAction(&stack, &div));
			break;
		case '^':
			stack.push(makeAction(&stack, &pw));
			break;
		default:
			stack.push(params[*it]);
		}
	}
	double result = stack.top();
	return result;
}

double CFormulaParser::makeAction(std::stack<double>* stack, binary_function<double, double, double>* func)
{
	if (stack->empty())
		throw "Error while calculation: not enough argument";
	double operandA, operandB;
	operandB = stack->top();
	stack->pop();
	if (stack->empty())
	{
		return (*func)(operandB);
	}
	operandA = stack->top();
	stack->pop();
	return (*func)(operandA, operandB);
}

double CFormulaParser::Calculate(std::map<char, double> params)
{
	mergeParams(params);
	return calcFormula(_preparedFormula,params);
}

void CConditionalFormulaParser::startParsing(std::string formula)
{
	std::regex exp("^\\((([A-Z]|[0-9\\-]+)([<>=!]+)([A-Z]|[0-9\\-]+))\\)\\?([^:]+):(.+)$");
	std::smatch result;
	if (!std::regex_match(formula, result, exp))
		throw "Wrong Conditional Statement";
	_preparedFormula.operandA = makeOperand(result[2].str());
	_preparedFormula.operandB = makeOperand(result[4].str());
	std::function<bool(double, double)> func;
	std::string actions[] = { ">","<","=","!=",">=","<=" };
	std::function<bool(double, double)> functions[] = { isgreater<double,double>,isless<double,double>,std::equal_to<double>(),std::not_equal_to<double>(),isgreaterequal<double,double>,islessequal<double,double> };
	for (int i = 0; i < 6; i++)
	{
		if (result[3].str()==(actions[i]))
		{
			func = functions[i];
			break;
		}
	}
	if (func == NULL)
	{
		throw "Wrong Conditional Statement";
	}
	_preparedFormula.function = func;
	_preparedFormula.trueFormula = makePolandNotation(result[5].str());
	_preparedFormula.falseFormula = makePolandNotation(result[6].str());
}

double CConditionalFormulaParser::Calculate(std::map<char, double> params)
{
	mergeParams(params);
	if (_preparedFormula.function(params[_preparedFormula.operandA], params[_preparedFormula.operandB]))
	{
		return calcFormula(_preparedFormula.trueFormula, params);
	}else {
		return calcFormula(_preparedFormula.falseFormula, params);
	}

}

CConditionalFormulaParser::~CConditionalFormulaParser()
{

}

CConditionalFormulaParser::CConditionalFormulaParser()
{

}

CFormulaParser::CFormulaParser() :last_const_index(0)
{

}
CFormulaParser::CFormulaParser(std::string formula)
{
	startParsing(formula);
}
CFormulaParser* CFormulaParser::ParserFactory(std::string formula)
{
	CFormulaParser* result;
	int qPos, dPos;
	qPos = formula.find("?");
	dPos = formula.find(":", qPos);
	if (qPos != std::string::npos && dPos != std::string::npos)
	{
		result = new CConditionalFormulaParser;
	}
	else if (qPos != std::string::npos || dPos != std::string::npos)
	{
		throw "Wrong formula";
	}
	else 
	{
		result = new CFormulaParser;
	}
	try 
	{
		result->startParsing(formula);
	}
	catch (std::string err)
	{
		delete result;
		throw err;
	}
	return result;
}

char CFormulaParser::makeOperand(std::string str)
{


	if (str.length() == 1 && *(str.begin()) >= 'A' && *(str.begin()) <= 'Z')
	{
		return *(str.begin());
	} else {
		
		_constants[++last_const_index] = std::stod(str);
		return last_const_index;
	}
}
void CFormulaParser::mergeParams(std::map<char, double> &params)
{
	for (std::map<char, double>::iterator it = _constants.begin(); it != _constants.end(); it++)
	{
		params[it->first] = it->second;
	}
}