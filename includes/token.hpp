#ifndef TOKEN_HPP
# define TOKEN_HPP

# include <iostream>

enum eTokenType {
	TK_NONE,
	TK_SEPARATOR,
	TK_ARGV,
	TK_BRACKET_OPEN,
	TK_BRACKET_CLOSE
};

typedef struct	s_token
{
	std::string		value;
	eTokenType		type;
}								t_token;

#endif
