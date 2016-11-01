#ifndef LEXER_HPP
# define LEXER_HPP

# include <iostream>
# include <istream>
# include <vector>
# include <token.hpp>

# define LXS_TOTAL_SCOPE	5

enum eScopeType {
	LXS_DEFAULT,
	LXS_EXITORCOMMENT,
	LXS_COMMAND,
	LXS_ARGS,
	LXS_OPERAND
};

class Lexer {
	private:
		std::vector<t_token *>		_tokens;
		std::string					_str;
		std::string::const_iterator _currentIt;

		eTokenType	_getTokenType(const char c) const;
		t_token *	_createNewToken(eTokenType type);
		void 		_fillToken(const char c);

		eTokenType	_enterScope(eScopeType scopeType);
		char		_getCurrentChar(void) const;
		void 		_skipNextSpace(void);


	public:
		Lexer(void);
		~Lexer(void);

		std::vector<t_token *>	getTokens(std::string const & str);

		eTokenType Default(void);
		eTokenType ExitOrComment(void);
		eTokenType Command(void);
		eTokenType Args(void);
		eTokenType Operand(void);

};

#endif
