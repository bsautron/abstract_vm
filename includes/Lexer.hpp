#ifndef LEXER_HPP
# define LEXER_HPP

# include <iostream>
# include <istream>
# include <vector>
# include <token.hpp>

class Lexer {
	private:
		std::vector<t_token>		_tokens;
		std::istream &				_instream;

		eTokenType	_getTokenType(const char c) const;
		void		_createNewToken(const char c, eTokenType type);
		void 		_fillToken(const char c);

	public:
		Lexer(void);
		~Lexer(void);

		std::vector<t_token>	getTokens(std::string const & str) const;
};

#endif
