#pragma once
#include <FormulaParser.h>
#include <gtest/gtest.h>


TEST(FormulaParserTest, TestBasicOperations)
{
	CFormulaParser parser_plus("A+B"), parser_minus("A-B"),parser_multiply("A*B"),parser_division("A/B");
	
	std::map<char, double> arguments;
	arguments['A'] = 3;
	arguments['B'] = 2;
	EXPECT_EQ(5, parser_plus.Calculate(arguments));
	EXPECT_EQ(1, parser_minus.Calculate(arguments));
	
	EXPECT_EQ(6, parser_multiply.Calculate(arguments));
	
	EXPECT_EQ(1.5, parser_division.Calculate(arguments));
}

TEST(FormulaParserTest, TestOrderOperation)
{
	CFormulaParser parser_first("A+A*A"), parser_second("(A+A)*A");
	std::map<char, double> arguments;
	arguments['A'] = 2;
	EXPECT_EQ(6, parser_first.Calculate(arguments));
	EXPECT_EQ(8, parser_second.Calculate(arguments));
}

TEST(FormulaParserTest, TestFactorySimple)
{
	std::unique_ptr<CFormulaParser> parser(CFormulaParser::ParserFactory("A+A"));
	std::map<char, double> arguments;
	arguments['A'] = 2;
	EXPECT_EQ(4, parser->Calculate(arguments));
}

TEST(FormulaParserTest, TestFactoryLogicSimple)
{
	std::unique_ptr<CFormulaParser> parser(CFormulaParser::ParserFactory("(A>1)?B+A:B+A"));
	std::map<char, double> arguments;
	arguments['A'] = 2;
	arguments['B'] = 3;
	EXPECT_EQ(5, parser->Calculate(arguments));
}

TEST(FormulaParserTest, TestLogic)
{
	std::unique_ptr<CFormulaParser> parser(CFormulaParser::ParserFactory("(A>3)?B+A:B-A"));
	std::map<char, double> arguments;
	arguments['A'] = 5;
	arguments['B'] = 3;
	EXPECT_EQ(8, parser->Calculate(arguments));
	arguments['A'] = 2;
	EXPECT_EQ(1, parser->Calculate(arguments));

}


TEST(FormulaParserTest, TestNumericConstants)
{
	std::unique_ptr<CFormulaParser> parser1(CFormulaParser::ParserFactory("A+2")), parser2(CFormulaParser::ParserFactory("-2*A")), parser3(CFormulaParser::ParserFactory("A+5425"));
	std::map<char, double> arguments;
	arguments['A'] = 5;
	EXPECT_EQ(7, parser1->Calculate(arguments));
	EXPECT_EQ(-10, parser2->Calculate(arguments));
	EXPECT_EQ(5430, parser3->Calculate(arguments));
}

TEST(FormulaParserTest, TestNumericConstants2)
{
	std::unique_ptr<CFormulaParser> parser1(CFormulaParser::ParserFactory("A*-2")), parser2(CFormulaParser::ParserFactory("-2*A+B/-4"));
	std::map<char, double> arguments;
	arguments['A'] = 5;
	arguments['B'] = 16;
	EXPECT_EQ(-10, parser1->Calculate(arguments));
	EXPECT_EQ(-14, parser2->Calculate(arguments));
	
}


TEST(FormulaParserTest, DecimalTest)
{
	std::unique_ptr<CFormulaParser> parser1(CFormulaParser::ParserFactory("A*0.5")), parser2(CFormulaParser::ParserFactory("A+1.254"));
	std::map<char, double> arguments;
	arguments['A'] = 5;
	EXPECT_EQ(2.5, parser1->Calculate(arguments));
	EXPECT_EQ(6.254, parser2->Calculate(arguments));
}
int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}