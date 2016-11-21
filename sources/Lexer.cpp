#include <Lexer.hpp>
#include <Debug.hpp>

Lexer::Lexer(void) {}
Lexer::~Lexer(void) {}

eTokenType Lexer::_enterScope(eScopeType scopeType) {
	return this->_enterScope(scopeType, true);
}

eTokenType Lexer::_enterScope(eScopeType scopeType, bool skipSpace) {
	eTokenType (Lexer::*scope[])(void) = {
		&Lexer::scopeDefault,
		&Lexer::scopeExit,
		&Lexer::scopeComment,
		&Lexer::scopeCommand,
		&Lexer::scopeArgs,
		&Lexer::scopeOperand
	};

	if (skipSpace)
		this->_skipAllSpace();
	if (scopeType != LXS_COMMENT && *this->_currentIt == ';')
		return (this->*scope[LXS_COMMENT])();

	return (this->*scope[scopeType])();
}

eTokenType Lexer::scopeDefault(void) {
	if (this->_currentIt == this->_str.end())
		return TK_NONE;
	return this->_enterScope(LXS_COMMAND);
}

eTokenType Lexer::scopeExit(void) {
	this->_createNewToken(TK_EXIT);
	return TK_NONE;
}
eTokenType Lexer::scopeComment(void) {
	this->_currentIt = this->_str.end();
	this->_createNewToken(TK_COMMENT);
	return TK_NONE;
}

eTokenType Lexer::scopeCommand(void) {
	t_token * newToken = this->_createNewToken(TK_COMMAND);
	while (this->_currentIt != this->_str.end()) {
		if (*this->_currentIt == ';')
			return this->_enterScope(LXS_COMMENT);
		if (this->_isSpace(*this->_currentIt))
			return this->_enterScope(LXS_OPERAND);
		newToken->value.push_back(*this->_currentIt);
		this->_currentIt++;
	}
	return TK_NONE;
}

eTokenType Lexer::scopeOperand(void) {
	t_token * newToken;
	if (this->_currentIt != this->_str.end())
		 newToken = this->_createNewToken(TK_OPERAND);

	if (*this->_currentIt == '(')
		throw LexicalException();

	while (this->_currentIt != this->_str.end()) {
		if (this->_isSpace(*this->_currentIt))
			throw LexicalException();
		if (*this->_currentIt == ';')
			throw LexicalException();
		if (*this->_currentIt == '(') {
			this->_currentIt++;
			if (*this->_currentIt == ';')
				throw LexicalException();
			return this->_enterScope(LXS_ARGS, false);
		}
		newToken->value.push_back(*this->_currentIt);
		this->_currentIt++;
	}
	throw LexicalException();
	return TK_NONE;
}

eTokenType Lexer::scopeArgs(void) {
	t_token * newToken;
	if (this->_currentIt != this->_str.end())
		 newToken = this->_createNewToken(TK_ARGS);

	while (this->_currentIt != this->_str.end()) {
		if (this->_isSpace(*this->_currentIt))
			throw LexicalException();
		if (*this->_currentIt == ';')
			throw LexicalException();
		if (*this->_currentIt == ')') {
			this->_currentIt++;
			return TK_ARGS;
		}
		newToken->value.push_back(*this->_currentIt);
		this->_currentIt++;
	}
	throw LexicalException();
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
		throw LexicalException();
	return this->_tokens;
}

size_t	Lexer::commandLengthMax = 255;

Lexer::LexicalException::LexicalException(void) throw() : std::logic_error("Lexical error") {}
Lexer::LexicalException::~LexicalException(void) throw() {}
Lexer::LexicalException::LexicalException(LexicalException const & src) throw() : std::logic_error("Lexical error") {
	*this = src;
}
Lexer::LexicalException & Lexer::LexicalException::operator=(Lexer::LexicalException const & rhs) throw() {
	(void)rhs;
	return *this;
}
