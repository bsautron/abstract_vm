#ifndef MYEXCEPTION
# define MYEXCEPTION

# include <iostream>

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
	EXC_TO_SHORT
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

#endif
