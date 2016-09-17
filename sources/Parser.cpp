#include <Parser.hpp>
#include <MyException.hpp>

Parser::Parser(std::vector<t_token> tokens) : _tokens(tokens) {}
Parser::~Parser(void) {}

void 			Parser::Verify(void) {
	eTokenType	shortInstruction[1] = { TK_ARGV };
	eTokenType	longInstruction[6] = { TK_ARGV, TK_SEPARATOR, TK_ARGV, TK_BRACKET_OPEN, TK_ARGV, TK_BRACKET_CLOSE };
	std::vector<eTokenType>	typeToIter;
	int 				i = 0;

	if (this->_tokens.size() == 0) {
		throw MyException(EXC_PARSER_EMPTY);
	}
	else if (this->_tokens.size() == 1)
		typeToIter.assign(shortInstruction, shortInstruction + 1);
	else
		typeToIter.assign(longInstruction, longInstruction + 6);

	for (std::vector<t_token>::iterator it = this->_tokens.begin(); it != this->_tokens.end(); ++it) {
		if ((*it).type != typeToIter[i])
			throw MyException(EXC_PARSER_IDK);
		i++;
	}
	if (this->_tokens.size() != 1 && this->_tokens.size() != 6)
		throw MyException(EXC_UNKNOW);
}
