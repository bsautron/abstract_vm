#include <Lexer.hpp>

Lexer::Lexer(void) {}
Lexer::~Lexer(void) {}

eTokenType Lexer::_getTokenType(const char c) const {
	if (std::isalnum(c) || c == '.')
		return (TK_ARGV);
	else if (c == ' ')
		return (TK_SEPARATOR);
	else if (c == '(')
		return (TK_BRACKET_OPEN);
	else if (c == ')')
		return (TK_BRACKET_CLOSE);
	else
		return (TK_NONE);
}

void			Lexer::_createNewToken(const char c, eTokenType type) {
	t_token	newToken;

	newToken.value.push_back(c);
	newToken.type = type;
	this->_tokens.push_back(newToken);
}

void 			Lexer::_fillToken(const char c) {
	this->_tokens.back().value.push_back(c);
}

std::vector<t_token>	Lexer::getTokens(std::string const & line) {
	char									c;
	eTokenType						type;

	for (std::string::const_iterator it = line.begin(); it!=line.end(); ++it) {
		c = *it;
		type = this->_getTokenType(c);
		if (!this->_tokens.size())
			this->_createNewToken(c, type);
		else if (type != this->_tokens.back().type)
			this->_createNewToken(c, type);
		else
			this->_fillToken(c);
	}
	return this->_tokens;
}
