#ifndef LEXER_HPP
# define LEXER_HPP

# include <iostream>
# include <vector>
# include <token.hpp>

class Lexer {
	private:
		std::vector<t_token>		_tokens;
		std::string							_str;

		Lexer (void);

		eTokenType	_getTokenType(const char c) const;
		void				_createNewToken(const char c, eTokenType type);
		void 				_fillToken(const char c);

	public:
		Lexer (std::string const & line);
		~Lexer (void);

		std::string		getStr(void) const;
		std::vector<t_token>	getTokens(void);
};

#endif
