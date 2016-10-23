/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 14:35:07 by bsautron          #+#    #+#             */
/*   Updated: 2016/06/08 16:28:51 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "abstract_vm.hpp"
#include <cstring>

# define TEST_GOOD_THINGS
# define TEST_OVERFLOW
# define TEST_LEXICAL_NUMBER
# define TEST_LEXER
# define TEST_BOUND
# define TEST_OTHER

// TODO: test the Parser

void test_success(const char * str) { std::cout << "\033[32m" << str << "\033[0m"; }
void test_fail(const char * str) { std::cout << "\033[30;41;1m" << str << "\033[0m"; }

void test_success(std::string const str) { std::cout << "\033[32m" << str << "\033[0m"; }
void test_fail(std::string const str) { std::cout << "\033[30;41;1m" << str << "\033[0m"; }


int main(void)
{
	std::string		value;

#ifdef TEST_GOOD_THINGS
	std::cout << "== TEST ZERO ==" << std::endl;
	try {
		value = "0";
		std::cout << "Constructor Operand: [char] " << value << ": ";
		Operand<char>	a(value);
		test_success("Good");
	} catch (std::exception const & e) {
		test_fail(e.what());
	} std::cout << std::endl;
	try {
		value = "-0";
		std::cout << "Constructor Operand: [char] " << value << ": ";
		Operand<char>	a(value);
		test_success("Good");
	} catch (std::exception const & e) {
		std::cout << e.what();
	} std::cout << std::endl;
	try {
		value = "0";
		std::cout << "Constructor Operand: [short] " << value << ": ";
		Operand<short>	a(value);
		test_success("Good");
	} catch (std::exception const & e) {
		test_fail(e.what());
	} std::cout << std::endl;
	try {
		value = "-0";
		std::cout << "Constructor Operand: [short] " << value << ": ";
		Operand<short>	a(value);
		test_success("Good");
	} catch (std::exception const & e) {
		test_fail(e.what());
	} std::cout << std::endl;
	try {
		value = "0";
		std::cout << "Constructor Operand: [int] " << value << ": ";
		Operand<int>	a(value);
		test_success("Good");
	} catch (std::exception const & e) {
		test_fail(e.what());
	} std::cout << std::endl;
	try {
		value = "-0";
		std::cout << "Constructor Operand: [int] " << value << ": ";
		Operand<int>	a(value);
		test_success("Good");
	} catch (std::exception const & e) {
		test_fail(e.what());
	} std::cout << std::endl;
	try {
		value = "0.00";
		std::cout << "Constructor Operand: [float] " << value << ": ";
		Operand<float>	a(value);
		test_success("Good");
	} catch (std::exception const & e) {
		test_fail(e.what());
	} std::cout << std::endl;
	try {
		value = "-0.00";
		std::cout << "Constructor Operand: [float] " << value << ": ";
		Operand<float>	a(value);
		test_success("Good");
	} catch (std::exception const & e) {
		test_fail(e.what());
	} std::cout << std::endl;
	try {
		value = "0.00";
		std::cout << "Constructor Operand: [double] " << value << ": ";
		Operand<double>	a(value);
		test_success("Good");
	} catch (std::exception const & e) {
		test_fail(e.what());
	} std::cout << std::endl;
	try {
		value = "-0.00";
		std::cout << "Constructor Operand: [double] " << value << ": ";
		Operand<double>	a(value);
		test_success("Good");
	} catch (std::exception const & e) {
		test_fail(e.what());
	} std::cout << std::endl;
#endif

#ifdef TEST_BOUND
	std::cout << "== TEST BOUND ==" << std::endl;
	try {
		value = "-128";
		std::cout << "Constructor Operand: [char] " << value << ": ";
		Operand<char>	a(value);
		test_success("Good");
	} catch (std::exception const & e) {
		test_fail(e.what());
	} std::cout << std::endl;
	try {
		value = "127";
		std::cout << "Constructor Operand: [char] " << value << ": ";
		Operand<char>	a(value);
		test_success("Good");
	} catch (std::exception const & e) {
		std::cout << e.what();
	} std::cout << std::endl;
	try {
		value = "-32768";
		std::cout << "Constructor Operand: [short] " << value << ": ";
		Operand<short>	a(value);
		test_success("Good");
	} catch (std::exception const & e) {
		test_fail(e.what());
	} std::cout << std::endl;
	try {
		value = "32767";
		std::cout << "Constructor Operand: [short] " << value << ": ";
		Operand<short>	a(value);
		test_success("Good");
	} catch (std::exception const & e) {
		test_fail(e.what());
	} std::cout << std::endl;
	try {
		value = "-2147483648";
		std::cout << "Constructor Operand: [int] " << value << ": ";
		Operand<int>	a(value);
		test_success("Good");
	} catch (std::exception const & e) {
		test_fail(e.what());
	} std::cout << std::endl;
	try {
		value = "2147483647";
		std::cout << "Constructor Operand: [int] " << value << ": ";
		Operand<int>	a(value);
		test_success("Good");
	} catch (std::exception const & e) {
		test_fail(e.what());
	} std::cout << std::endl;
#endif

#ifdef OTHER_TEST
	std::cout << "== OTHER TEST ==" << std::endl;
	try {
		value = "2.44";
		std::cout << "Constructor Operand: [float] " << value << ": ";
		Operand<float>	a(value);
		test_success("Good");
	} catch (std::exception const & e) {
		test_fail(e.what());
	} std::cout << std::endl;
	try {
		value = "11198470.12";
		std::cout << "Constructor Operand: [double] " << value << ": ";
		Operand<double>	a(value);
		test_success("Good");
	} catch (std::exception const & e) {
		test_fail(e.what());
	} std::cout << std::endl;
#endif

#ifdef TEST_OVERFLOW
	std::cout << "== TEST OVERFLOW" << std::endl;
	try {
		value = "-129";
		std::cout << "Constructor Operand: [char] " << value << ": ";
		Operand<char>	a(value);
		test_fail("TEST FAILED");
	} catch (std::exception const & e) {
		test_success(e.what());
	} std::cout << std::endl;
	try {
		value = "128";
		std::cout << "Constructor Operand: [char] " << value << ": ";
		Operand<char>	a(value);
		test_fail("TEST FAILED");
	} catch (std::exception const & e) {
		test_success(e.what());
	} std::cout << std::endl;

	try {
		value = "-32769";
		std::cout << "Constructor Operand: [short] " << value << ": ";
		Operand<short>	a(value);
		test_fail("TEST FAILED");
	} catch (std::exception const & e) {
		test_success(e.what());
	} std::cout << std::endl;
	try {
		value = "32768";
		std::cout << "Constructor Operand: [short] " << value << ": ";
		Operand<short>	a(value);
		test_fail("TEST FAILED");
	} catch (std::exception const & e) {
		test_success(e.what());
	} std::cout << std::endl;
	try {
		value = "-2147483649";
		std::cout << "Constructor Operand: [int] " << value << ": ";
		Operand<int>	a(value);
		test_fail("TEST FAILED");
	} catch (std::exception const & e) {
		test_success(e.what());
	} std::cout << std::endl;
	try {
		value = "2147483648";
		std::cout << "Constructor Operand: [int] " << value << ": ";
		Operand<int>	a(value);
		test_fail("TEST FAILED");
	} catch (std::exception const & e) {
		test_success(e.what());
	} std::cout << std::endl;

	try {
		value = "13249719764023984.0234285900993805923905209385";
		std::cout << "Constructor Operand: [float] " << value << ": ";
		Operand<float>	a(value);
		test_fail("TEST FAILED");
	} catch (std::exception const & e) {
		test_success(e.what());
	} std::cout << std::endl;
	try {
		value = "-111191890234985209348572093845729304857230498579028347590827760884780.013495871098470938457209384759028374590823759082340134958710984709384572093847590283745908237590823401349587109847093845720938475902837459082375908234";
		std::cout << "Constructor Operand: [double] " << value << ": ";
		Operand<double>	a(value);
		test_fail("TEST FAILED");
	} catch (std::exception const & e) {
		test_success(e.what());
	} std::cout << std::endl;
#endif

#ifdef TEST_LEXICAL_NUMBER
	std::cout << "== TEST LEXICAL NUMBER ==" << std::endl;
	try {
		value = "23.45";
		std::cout << "Constructor Operand: [char] " << value << ": ";
		Operand<char>	a(value);
		test_fail("TEST FAILED");
	} catch (std::exception const & e) {
		test_success(e.what());
	} std::cout << std::endl;
	try {
		value = "23.45";
		std::cout << "Constructor Operand: [short] " << value << ": ";
		Operand<short>	a(value);
		test_fail("TEST FAILED");
	} catch (std::exception const & e) {
		test_success(e.what());
	} std::cout << std::endl;
	try {
		value = "23.45";
		std::cout << "Constructor Operand: [int] " << value << ": ";
		Operand<int>	a(value);
		test_fail("TEST FAILED");
	} catch (std::exception const & e) {
		test_success(e.what());
	} std::cout << std::endl;
	try {
		value = "2345";
		std::cout << "Constructor Operand: [float] " << value << ": ";
		Operand<float>	a(value);
		test_fail("TEST FAILED");
	} catch (std::exception const & e) {
		test_success(e.what());
	} std::cout << std::endl;
	try {
		value = "-12";
		std::cout << "Constructor Operand: [double] " << value << ": ";
		Operand<double>	a(value);
		test_fail("TEST FAILED");
	} catch (std::exception const & e) {
		test_success(e.what());
	} std::cout << std::endl;
	try {
		value = "94";
		std::cout << "Constructor Operand: [double] " << value << ": ";
		Operand<double>	a(value);
		test_fail("TEST FAILED");
	} catch (std::exception const & e) {
		test_success(e.what());
	} std::cout << std::endl;
#endif

#ifdef TEST_LEXER
	std::cout << "== TEST LEXER ==" << std::endl;
	std::string						tokenStr[5] = {
		"TK_NONE",
		"TK_SEPARATOR",
		"TK_ARGV",
		"TK_BRACKET_OPEN",
		"TK_BRACKET_CLOSE"
	};
	std::vector<t_token>		tokens;
	int											i;

	{
		value = "push int3(23.2)";
		Lexer	lex(value);
		i = 0;
		bool	fail = false;
		std::cout << "Get token [" << value << "]: ";
		eTokenType types[] = {
			TK_ARGV,
			TK_SEPARATOR,
			TK_ARGV,
			TK_BRACKET_OPEN,
			TK_ARGV,
			TK_BRACKET_CLOSE
		};

		tokens = lex.getTokens();
		for (std::vector<t_token>::iterator it = tokens.begin() ; it != tokens.end(); ++it) {
			if ((*it).type != types[i]) {
				fail = true;
				std::cout << std::endl << "\t";
				test_fail("\"" + (*it).value + "\" ['" + tokenStr[(*it).type] + "'] must be '" + tokenStr[types[i]] + "'");
			}
			i++;
		}
		if (!fail) {
			test_success("Good");
		}
		std::cout << std::endl;
	}

	{
		value = "dump floate(casoos)";
		Lexer lex(value);
		i = 0;
		bool	fail = false;
		std::cout << "Get token [" << value << "]: ";
		eTokenType types[] = {
			TK_ARGV,
			TK_SEPARATOR,
			TK_ARGV,
			TK_BRACKET_OPEN,
			TK_ARGV,
			TK_BRACKET_CLOSE
		};

		tokens = lex.getTokens();
		for (std::vector<t_token>::iterator it = tokens.begin() ; it != tokens.end(); ++it) {
			if ((*it).type != types[i]) {
				fail = true;
				std::cout << std::endl << "\t";
				test_fail("\"" + (*it).value + "\" ['" + tokenStr[(*it).type] + "'] must be '" + tokenStr[types[i]] + "'");
			}
			i++;
		}
		if (!fail) {
			test_success("Good");
		}
		std::cout << std::endl;
	}

	{
		value = "498f.234 in)t 3(23 ((2)(";
		Lexer lex(value);
		i = 0;
		bool	fail = false;
		std::cout << "Get token [" << value << "]: ";
		eTokenType types[] = {
			TK_ARGV,
			TK_SEPARATOR,
			TK_ARGV,
			TK_BRACKET_CLOSE,
			TK_ARGV,
			TK_SEPARATOR,
			TK_ARGV,
			TK_BRACKET_OPEN,
			TK_ARGV,
			TK_SEPARATOR,
			TK_BRACKET_OPEN,
			TK_BRACKET_OPEN,
			TK_ARGV,
			TK_BRACKET_CLOSE,
			TK_BRACKET_OPEN
		};

		tokens = lex.getTokens();
		for (std::vector<t_token>::iterator it = tokens.begin() ; it != tokens.end(); ++it) {
			if ((*it).type != types[i]) {
				fail = true;
				std::cout << std::endl;
				std::cout << "[";
				std::cout << i;
				std::cout << "]\t";
				test_fail("\"" + (*it).value + "\" ['" + tokenStr[(*it).type] + "'] must be '" + tokenStr[types[i]] + "'");
			}
			i++;
		}
		if (!fail) {
			test_success("Good");
		}
		std::cout << std::endl;
	}

#endif

#ifdef TEST_OTHER
	std::cout << "== OTHER TEST ==" << std::endl;
	try {
		value = "19";
		std::cout << "Constructor Operand: [int] " << value << ": ";
		Operand<int>	a(value);
		value = "1";
		std::cout << "Constructor Operand: [char] " << value << ": ";
		Operand<char>	b(value);
		IOperand const *op = a + b;
		std::cout << "op " << Operand<void>::stringType[op->getType()] << " -> ";
		test_success(op->toString());
	} catch (std::exception const & e) {
		test_fail(e.what());
	} std::cout << std::endl;
	try {
		value = "1.9";
		std::cout << "Constructor Operand: [double] " << value << ": ";
		Operand<double>	a(value);
		value = "1.234";
		std::cout << "Constructor Operand: [float] " << value << ": ";
		Operand<float>	b(value);
		IOperand const *op = a + b;
		std::cout << "op " << Operand<void>::stringType[op->getType()] << " -> ";
		test_success(op->toString());
	} catch (std::exception const & e) {
		test_fail(e.what());
	} std::cout << std::endl;
	try {
		value = "1";
		std::cout << "Constructor Operand: [int] " << value << ": ";
		Operand<int>	a(value);
		value = "1.234";
		std::cout << "Constructor Operand: [float] " << value << ": ";
		Operand<float>	b(value);
		IOperand const *op = a + b;
		std::cout << "op " << Operand<void>::stringType[op->getType()] << " -> ";
		test_success(op->toString());
	} catch (std::exception const & e) {
		test_fail(e.what());
	} std::cout << std::endl;
#endif
	return (0);
}
