#ifndef LEXER_HPP
# define LEXER_HPP

# include <iostream>
# include <vector>

enum eLexerType {
	LEX_NONE,
	LEX_INSTRUCTOR,
	LEX_SEPARATOR,
	LEX_ARGV,
	LEX_BRACKET,
	LEX_END_LINE
};

typedef struct	s_token
{
	std::string		value;
	eLexerType		type;
}				t_token;

class Lexer {
	private:
		std::vector<t_token>	_token;

		void _init(void);

	public:
		void none(const char c) const;
		Lexer (void);
		~Lexer (void);

		std::vector<t_token>	getToken(std::string const & line);
};

typedef void 	(Lexer::*theFn)(const char);

#endif
