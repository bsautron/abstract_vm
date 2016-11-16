#ifndef MYEXCEPTION_HPP
# define MYEXCEPTION_HPP

# include <iostream>
# include <list>

enum eExceptionCode {
	EXC_TMP,
	EXC_UNKNOW,
	EXC_UNDERFLOW,
	EXC_OVERFLOW,
	EXC_NAN,
	EXC_NOT_VALID_SYNTAX_NUMBER,
	EXC_PARSER_EMPTY,
	EXC_PARSER_IDK,
	EXC_LIMITATION_PRECISION,
	EXC_DEVIDE_BZERO,
	EXC_MODULO_BZERO,
	EXC_MODULO_BFLOAT,

	EXC_STACK_EMPTY,
	EXC_ASSERT_FAILED,
	EXC_TO_SHORT,

	EXC_CHAR_BEYOND,
	EXC_LEXICAL,
	EXC_COMMAND_NOT_FOUND,
	EXC_OPERAND_NOT_FOUND,
	EXC_NOT_END_EXIT
};

class MyException : public std::exception {
	private:
		eExceptionCode	_code;

		MyException (void);

	public:
		MyException (eExceptionCode code);
		virtual ~MyException (void) throw();

		virtual const char *	what(void) const throw();

		static std::string	exceptionString[];
};

typedef struct	s_error {
	int 		line;
	MyException	exception;
}				t_error;

typedef	std::list<t_error>	t_listError;

#endif
