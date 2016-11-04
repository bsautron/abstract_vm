#ifndef LEXER_HPP
# define LEXER_HPP

# include <iostream>
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

		t_token *	_createNewToken(eTokenType type);
		eTokenType	_enterScope(eScopeType scopeType);

	public:
		Lexer(void);
		~Lexer(void);

		std::vector<t_token *>	getTokens(char const * str);

		eTokenType Default(void);
		eTokenType ExitOrComment(void);
		eTokenType Command(void);
		eTokenType Args(void);
		eTokenType Operand(void);
};

#endif
