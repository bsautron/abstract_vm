#ifndef TOKEN_HPP
# define TOKEN_HPP

# include <iostream>
# include <vector>

enum eTokenType {
	TK_NONE,
	TK_COMMAND,
	TK_OPERAND,
	TK_ARGS,
	TK_COMMENT,
	TK_EXIT,
	TK_ENDREAD
};

typedef struct	s_token
{
	std::string		value;
	eTokenType		type;
}				t_token;

typedef std::vector<t_token *>	t_tokens;

#endif
