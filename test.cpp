/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 14:35:07 by bsautron          #+#    #+#             */
/*   Updated: 2016/11/18 19:20:04 by bsautron         ###   ########.fr       */
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
	std::string tkName[6] = {
		"TK_NONE",
		"TK_COMMAND",
		"TK_OPERAND",
		"TK_ARGS",
		"TK_COMMENT",
		"TK_EXIT"
	};

	Lexer	lex;
	t_tokens		tokens;
	int							i;

	{
		value = "push int3(23.2)";
		i = 0;
		bool	fail = false;
		std::cout << "Get token [" << value << "]: ";
		eTokenType types[] = {
			TK_COMMAND,
			TK_OPERAND,
			TK_ARGS
		};

		try {
			tokens = lex.getTokens(value);
			for (t_tokens::iterator it = tokens.begin() ; it != tokens.end(); ++it) {
				if ((*it)->type != types[i]) {
					fail = true;
					std::cout << std::endl << "\t";
					test_fail("\"" + (*it)->value + "\" ['" + tkName[(*it)->type] + "'] must be '" + tkName[types[i]] + "'");
				}
				i++;
			}
			if (tokens.size() != 3) {
				fail = true;
				std::cout << std::endl << "\t";
				test_fail("no");
			}
			if (!fail) {
				test_success("Good");
			}
		} catch (std::exception const & e) {
			test_fail(e.what());
		}
		std::cout << std::endl;
	}

	{
		value = "; auwfrw aiuwefpauwef aiwuf aiwuef a";
		i = 0;
		bool	fail = false;
		std::cout << "Get token [" << value << "]: ";
		eTokenType types[] = {
			TK_COMMENT
		};

		try {
			tokens = lex.getTokens(value);
			for (t_tokens::iterator it = tokens.begin() ; it != tokens.end(); ++it) {
				if ((*it)->type != types[i]) {
					fail = true;
					std::cout << std::endl << "\t";
					test_fail("\"" + (*it)->value + "\" ['" + tkName[(*it)->type] + "'] must be '" + tkName[types[i]] + "'");
				}
				i++;
			}
			if (tokens.size() != 1) {
				fail = true;
				std::cout << std::endl << "\t";
				test_fail("no");
			}
			if (!fail) {
				test_success("Good");
			}
		} catch (std::exception const & e) {
			test_fail(e.what());
		}

		std::cout << std::endl;
	}

	{
		value = ";;";
		i = 0;
		bool	fail = false;
		std::cout << "Get token [" << value << "]: ";
		eTokenType types[] = {
			TK_EXIT
		};

		try {
			tokens = lex.getTokens(value);
			for (t_tokens::iterator it = tokens.begin() ; it != tokens.end(); ++it) {
				if ((*it)->type != types[i]) {
					fail = true;
					std::cout << std::endl << "\t";
					test_fail("\"" + (*it)->value + "\" ['" + tkName[(*it)->type] + "'] must be '" + tkName[types[i]] + "'");
				}
				i++;
			}
			if (tokens.size() != 1) {
				fail = true;
				std::cout << std::endl << "\t";
				test_fail("no");
			}
			if (!fail) {
				test_success("Good");
			}
		} catch (std::exception const & e) {
			test_fail(e.what());
		}
		std::cout << std::endl;
	}

	{
		value = "aopgho";
		i = 0;
		bool	fail = false;
		std::cout << "Get token [" << value << "]: ";
		eTokenType types[] = {
			TK_COMMAND
		};

		try {
			tokens = lex.getTokens(value);
			for (t_tokens::iterator it = tokens.begin() ; it != tokens.end(); ++it) {
				if ((*it)->type != types[i]) {
					fail = true;
					std::cout << std::endl << "\t";
					test_fail("\"" + (*it)->value + "\" ['" + tkName[(*it)->type] + "'] must be '" + tkName[types[i]] + "'");
				}
				i++;
			}
			if (tokens.size() != 1) {
				fail = true;
				std::cout << std::endl << "\t";
				test_fail("no");
			}
			if (!fail) {
				test_success("Good");
			}
		} catch (std::exception const & e) {
			test_fail(e.what());
		}
		std::cout << std::endl;
	}

	{
		value = "aopgho awuihf";
		i = 0;
		std::cout << "Get token [" << value << "]: ";

		try {
			tokens = lex.getTokens(value);
			test_fail("Must be syntax error");
		} catch (std::exception const & e) {
			test_success(e.what());
		}
		std::cout << std::endl;
	}
	{
		value = "aopgho awuihf awefu";
		i = 0;
		std::cout << "Get token [" << value << "]: ";

		try {
			tokens = lex.getTokens(value);
			test_fail("Must be syntax error");
		} catch (std::exception const & e) {
			test_success(e.what());
		}
		std::cout << std::endl;
	}

	{
		value = "aopgho aiuwehf()";
		i = 0;
		bool	fail = false;
		std::cout << "Get token [" << value << "]: ";
		eTokenType types[] = {
			TK_COMMAND,
			TK_OPERAND,
			TK_ARGS
		};

		try {
			tokens = lex.getTokens(value);
			for (t_tokens::iterator it = tokens.begin() ; it != tokens.end(); ++it) {
				if ((*it)->type != types[i]) {
					fail = true;
					std::cout << std::endl << "\t";
					test_fail("\"" + (*it)->value + "\" ['" + tkName[(*it)->type] + "'] must be '" + tkName[types[i]] + "'");
				}
				i++;
			}
			if (tokens.size() != 3) {
				fail = true;
				std::cout << std::endl << "\t";
				test_fail("no");
			}
			if (!fail) {
				test_success("Good");
			}
		} catch (std::exception const & e) {
			test_fail(e.what());
		}
		std::cout << std::endl;
	}

	{
		value = "aopgho ()";
		i = 0;
		std::cout << "Get token [" << value << "]: ";

		try {
			tokens = lex.getTokens(value);
			test_fail("Must be syntax error");
		} catch (std::exception const & e) {
			test_success(e.what());
		}
		std::cout << std::endl;
	}

	{
		value = "aopgho sdfg(esiru serihu)";
		i = 0;
		std::cout << "Get token [" << value << "]: ";

		try {
			tokens = lex.getTokens(value);
			test_fail("Must be syntax error");
		} catch (std::exception const & e) {
			test_success(e.what());
		}
		std::cout << std::endl;
	}

	{
		value = "aopgho sdfg( opsi)";
		i = 0;
		std::cout << "Get token [" << value << "]: ";

		try {
			tokens = lex.getTokens(value);
			test_fail("Must be syntax error");
		} catch (std::exception const & e) {
			test_success(e.what());
		}
		std::cout << std::endl;
	}

	{
		value = "      push			  int5(sdfg)";
		i = 0;
		bool	fail = false;
		std::cout << "Get token [" << value << "]: ";
		eTokenType types[] = {
			TK_COMMAND,
			TK_OPERAND,
			TK_ARGS
		};


		try {
			tokens = lex.getTokens(value);
			for (t_tokens::iterator it = tokens.begin() ; it != tokens.end(); ++it) {
				if ((*it)->type != types[i]) {
					fail = true;
					std::cout << std::endl << "\t";
					test_fail("\"" + (*it)->value + "\" ['" + tkName[(*it)->type] + "'] must be '" + tkName[types[i]] + "'");
				}
				i++;
			}
			if (tokens.size() != 3) {
				fail = true;
				std::cout << std::endl << "\t";
				test_fail("no");
			}
			if (!fail) {
				test_success("Good");
			}
		} catch (std::exception const & e) {
			test_fail(e.what());
		}
		std::cout << std::endl;
	}

	{
		value = "()";
		i = 0;
		bool	fail = false;
		std::cout << "Get token [" << value << "]: ";
		eTokenType types[] = {
			TK_COMMAND
		};

		try {
			tokens = lex.getTokens(value);
			for (t_tokens::iterator it = tokens.begin() ; it != tokens.end(); ++it) {
				if ((*it)->type != types[i]) {
					fail = true;
					std::cout << std::endl << "\t";
					test_fail("\"" + (*it)->value + "\" ['" + tkName[(*it)->type] + "'] must be '" + tkName[types[i]] + "'");
				}
				i++;
			}
			if (tokens.size() != 1) {
				fail = true;
				std::cout << std::endl << "\t";
				test_fail("no");
			}
			if (!fail) {
				test_success("Good");
			}
		} catch (std::exception const & e) {
			test_fail(e.what());
		}
		std::cout << std::endl;
	}

	{
		value = "    awuihf awefu";
		i = 0;
		std::cout << "Get token [" << value << "]: ";

		try {
			tokens = lex.getTokens(value);
			test_fail("Must be syntax error");
		} catch (std::exception const & e) {
			test_success(e.what());
		}
		std::cout << std::endl;
	}

	{
		value = "push int8(dff_";
		i = 0;
		std::cout << "Get token [" << value << "]: ";

		try {
			tokens = lex.getTokens(value);
			test_fail("Must be syntax error");
		} catch (std::exception const & e) {
			test_success(e.what());
		}
		std::cout << std::endl;
	}


	{
		value = "";
		i = 0;
		std::cout << "Get token [" << value << "]: ";

		try {
			tokens = lex.getTokens(value);
			if (tokens.size() != 0)
				test_fail("Must be have 0 tokens");
			else
				test_success("Good");
		} catch (std::exception const & e) {
			test_fail(e.what());
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
