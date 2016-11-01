#ifndef TOKEN_HPP
# define TOKEN_HPP

# include <iostream>

enum eTokenType {
	TK_NONE,
	TK_COMMAND,
	TK_OPERAND,
	TK_ARGS,
	TK_COMMENT,
	TK_EXIT
};

typedef struct	s_token
{
	std::string		value;
	eTokenType		type;
}								t_token;

#endif
