#include <Lexer.hpp>
#include <Debug.hpp>
#include <MyException.hpp>

Lexer::Lexer(void) {}
Lexer::~Lexer(void) {}

eTokenType Lexer::_enterScope(eScopeType scopeType) {
	return this->_enterScope(scopeType, true);
}

eTokenType Lexer::_enterScope(eScopeType scopeType, bool skipSpace) {
	eTokenType (Lexer::*scope[])(void) = {
		&Lexer::Default,
		&Lexer::Exit,
		&Lexer::Comment,
		&Lexer::Command,
		&Lexer::Args,
		&Lexer::Operand
	};

	if (skipSpace)
		this->_skipAllSpace();
	if (scopeType != LXS_COMMENT && *this->_currentIt == ';')
		return (this->*scope[LXS_COMMENT])();

	return (this->*scope[scopeType])();
}

eTokenType Lexer::Default(void) {
	if (this->_currentIt == this->_str.end())
		return TK_NONE;
	return this->_enterScope(LXS_COMMAND);
}

eTokenType Lexer::Exit(void) {
	this->_createNewToken(TK_EXIT);
	return TK_NONE;
}
eTokenType Lexer::Comment(void) {
	this->_currentIt = this->_str.end();
	this->_createNewToken(TK_COMMENT);
	return TK_NONE;
}

eTokenType Lexer::Command(void) {
	t_token * newToken = this->_createNewToken(TK_COMMAND);
	while (this->_currentIt != this->_str.end()) {
		if (this->_isSpace(*this->_currentIt))
			return this->_enterScope(LXS_OPERAND);
		newToken->value.push_back(*this->_currentIt);
		this->_currentIt++;
	}
	return TK_NONE;
}

eTokenType Lexer::Operand(void) {
	t_token * newToken;
	if (this->_currentIt != this->_str.end())
		 newToken = this->_createNewToken(TK_OPERAND);

	if (*this->_currentIt == '(')
		throw MyException(EXC_LEXICAL);

	while (this->_currentIt != this->_str.end()) {
		if (this->_isSpace(*this->_currentIt))
			throw MyException(EXC_LEXICAL);
		if (*this->_currentIt == '(') {
			this->_currentIt++;
			return this->_enterScope(LXS_ARGS, false);
		}
		newToken->value.push_back(*this->_currentIt);
		this->_currentIt++;
	}
	throw MyException(EXC_LEXICAL);
	return TK_NONE;
}

eTokenType Lexer::Args(void) {
	t_token * newToken;
	if (this->_currentIt != this->_str.end())
		 newToken = this->_createNewToken(TK_ARGS);

	while (this->_currentIt != this->_str.end()) {
		if (this->_isSpace(*this->_currentIt))
			throw MyException(EXC_LEXICAL);
		if (*this->_currentIt == ')') {
			this->_currentIt++;
			return TK_ARGS;
		}
		newToken->value.push_back(*this->_currentIt);
		this->_currentIt++;
	}
	throw MyException(EXC_LEXICAL);
	return TK_NONE;
}

t_token *	Lexer::_createNewToken(eTokenType type) {
	t_token	* newToken = new t_token;

	newToken->type = type;
	this->_tokens.push_back(newToken);
	return newToken;
}

void 	Lexer::_skipAllSpace(void) {
	while (this->_currentIt != this->_str.end() && this->_isSpace(*this->_currentIt))
		this->_currentIt++;
}

bool	Lexer::_isSpace(char const c) const {
	return c == ' ' || c == '\t';
}

t_tokens	Lexer::getTokens(std::string const str) {
	this->_tokens.clear();

	this->_str = str;
 	this->_currentIt = this->_str.begin();

	this->_enterScope(LXS_DEFAULT);
	this->_skipAllSpace();
	if (*this->_currentIt == ';')
		this->_enterScope(LXS_COMMENT);
	if (this->_currentIt != this->_str.end())
		throw MyException(EXC_CHAR_BEYOND);
	return this->_tokens;
}
