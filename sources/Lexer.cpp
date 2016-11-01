#include <Lexer.hpp>
#include <Debug.hpp>
#include <MyException.hpp>

Lexer::Lexer(void) {}
Lexer::~Lexer(void) {}

eTokenType Lexer::_getTokenType(const char c) const {
	std::cout << c << std::endl;
	// if (std::isalnum(c) || c == '.')
	// 	return (TK_ARGV);
	// else if (c == ' ')
	// 	return (TK_SEPARATOR);
	// else if (c == '(')
	// 	return (TK_BRACKET_OPEN);
	// else if (c == ')')
	// 	return (TK_BRACKET_CLOSE);
	// else
		return (TK_NONE);
}

eTokenType Lexer::_enterScope(eScopeType scopeType) {
	// std::string scopeName[LXS_TOTAL_SCOPE] = {
	// 	"Default",
	// 	"ExitOrComment",
	// 	"Command",
	// 	"Args",
	// 	"Operand"
	// };
	eTokenType (Lexer::*scope[LXS_TOTAL_SCOPE])(void) = {
		&Lexer::Default,
		&Lexer::ExitOrComment,
		&Lexer::Command,
		&Lexer::Args,
		&Lexer::Operand
	};

	// Debug::Log("Lexer: Enter to " + scopeName[scopeType] + " scope");
	// std::cout << "Cursor at " << *this->_currentIt << std::endl;
	return (this->*scope[scopeType])();
}

eTokenType Lexer::Default(void) {
	char c = this->_getCurrentChar();

	if (this->_currentIt == this->_str.end())
		return TK_NONE;
	if (c == ';')
		return this->_enterScope(LXS_EXITORCOMMENT);
	return this->_enterScope(LXS_COMMAND);
}

eTokenType Lexer::ExitOrComment(void) {
	this->_currentIt++;
	char c = this->_getCurrentChar();

	if (c == ';') {
		this->_currentIt++;
		this->_createNewToken(TK_EXIT);
	}
	else {
		this->_currentIt = this->_str.end();
		this->_createNewToken(TK_COMMENT);
	}
	return TK_NONE;
}

eTokenType Lexer::Command(void) {
	t_token * newToken = this->_createNewToken(TK_COMMAND);
	while (this->_currentIt != this->_str.end()) {
		if (*this->_currentIt == ' ') {
			this->_currentIt++;
			return this->_enterScope(LXS_OPERAND);
		}
		newToken->value.push_back(*this->_currentIt);
		this->_currentIt++;
	}
	return TK_NONE;
}

eTokenType Lexer::Operand(void) {
	t_token * newToken = this->_createNewToken(TK_OPERAND);
	while (this->_currentIt != this->_str.end()) {
		if (*this->_currentIt == ' ')
			throw MyException(EXC_LEXICAL);
		if (*this->_currentIt == '(') {
			this->_currentIt++;
			return this->_enterScope(LXS_ARGS);
		}
		newToken->value.push_back(*this->_currentIt);
		this->_currentIt++;
	}
	return TK_NONE;
}

eTokenType Lexer::Args(void) {
	t_token * newToken = this->_createNewToken(TK_ARGS);
	while (this->_currentIt != this->_str.end()) {
		if (*this->_currentIt == ' ')
			throw MyException(EXC_LEXICAL);
		if (*this->_currentIt == ')') {
			this->_currentIt++;
			return TK_ARGS;
		}
		newToken->value.push_back(*this->_currentIt);
		this->_currentIt++;
	}
	return TK_NONE;
}

void 	Lexer::_skipNextSpace(void) {
	while (this->_currentIt != this->_str.end() && *this->_currentIt == ' ') {
		this->_currentIt++;
	}
}


t_token *	Lexer::_createNewToken(eTokenType type) {
	t_token	* newToken = new t_token;

	newToken->type = type;
	this->_tokens.push_back(newToken);
	return newToken;
}

void 			Lexer::_fillToken(const char c) {
	this->_tokens.back()->value.push_back(c);
}

std::vector<t_token *>	Lexer::getTokens(std::string const & str) {
	this->_tokens.clear();

	// Debug::Info("Lexer: Start get Token to a line");
	// Debug::Info("Lexer: \"" + str + "\"");
	this->_str = str;
 	this->_currentIt = this->_str.begin();

	if (*this->_currentIt == ' ')
		throw MyException(EXC_LEXICAL);
	this->_enterScope(LXS_DEFAULT);
	if (this->_currentIt != this->_str.end())
		throw MyException(EXC_CHAR_BEYOND);
	return this->_tokens;
}

char		Lexer::_getCurrentChar(void) const {
	return *this->_currentIt;
}
