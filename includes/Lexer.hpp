#ifndef LEXER_HPP
# define LEXER_HPP

# include <iostream>
# include <vector>
# include <token.hpp>

class Lexer {
	private:
		std::vector<t_token>		_tokens;

		eTokenType	_getTokenType(const char c) const;
		void				_createNewToken(const char c, eTokenType type);
		void 				_fillToken(const char c);

	public:
		Lexer (void);
		~Lexer (void);
		void none(const char c) const;

		std::vector<t_token>	getTokens(std::string const & line);
};

typedef void 	(Lexer::*fnLexer)(const char) const;

#endif
