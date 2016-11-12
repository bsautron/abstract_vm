#include <Lexer.hpp>
#include <Debug.hpp>
#include <MyException.hpp>

Lexer::Lexer(void) {}
Lexer::~Lexer(void) {}

eTokenType Lexer::_enterScope(eScopeType scopeType) {
	// std::string scopeName[] = {
	// 	"Default",
	// 	"ExitOrComment",
	// 	"Command",
	// 	"Args",
	// 	"Operand"
	// };
	eTokenType (Lexer::*scope[])(void) = {
		&Lexer::Default,
		&Lexer::ExitOrComment,
		&Lexer::Exit,
		&Lexer::Comment,
		&Lexer::Command,
		&Lexer::Args,
		&Lexer::Operand
	};

	// Debug::Log("Lexer: Enter to " + scopeName[scopeType] + " scope");
	// std::cout << "Cursor at " << *this->_currentIt << std::endl;
	this->_skipAllSpace();
	if (scopeType == LXS_DEFAULT && *this->_currentIt == ';')
		return (this->*scope[LXS_EXITORCOMMENT])();
	else if (scopeType != LXS_COMMENT && *this->_currentIt == ';')
		return (this->*scope[LXS_COMMENT])();

	return (this->*scope[scopeType])();
}

eTokenType Lexer::Default(void) {
	char c = *this->_currentIt;

	if (this->_currentIt == this->_str.end())
		return TK_NONE;
	if (c == ';')
		return this->_enterScope(LXS_EXITORCOMMENT);
	return this->_enterScope(LXS_COMMAND);
}

eTokenType Lexer::ExitOrComment(void) {
	this->_currentIt++;
	char c = *this->_currentIt;

	if (c == ';') {
		this->_currentIt++;
		return this->_enterScope(LXS_EXIT);
	}
	return this->_enterScope(LXS_COMMENT);
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
		if (*this->_currentIt == ' ')
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
	t_token * newToken;
	if (this->_currentIt != this->_str.end())
		 newToken = this->_createNewToken(TK_ARGS);

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
	throw MyException(EXC_TMP);
}

t_token *	Lexer::_createNewToken(eTokenType type) {
	t_token	* newToken = new t_token;

	newToken->type = type;
	this->_tokens.push_back(newToken);
	return newToken;
}

void 	Lexer::_skipAllSpace(void) {
	while (this->_currentIt != this->_str.end() && *this->_currentIt == ' ')
		this->_currentIt++;
}

t_tokens	Lexer::getTokens(char const * str) {
	this->_tokens.clear();

	// Debug::Info("Lexer: Start get Token to a line");
	// Debug::Info("Lexer: \"" + str + "\"");
	this->_str = std::string(str);
 	this->_currentIt = this->_str.begin();

	this->_enterScope(LXS_DEFAULT);
	this->_skipAllSpace();
	if (*this->_currentIt == ';')
		this->_enterScope(LXS_COMMENT);
	if (this->_currentIt != this->_str.end())
		throw MyException(EXC_CHAR_BEYOND);
	return this->_tokens;
}
