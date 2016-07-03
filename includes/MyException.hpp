#ifndef MYEXCEPTION
# define MYEXCEPTION

# include <iostream>

# define NB_EXC		5

enum eExceptionCode {
	EXC_UNKNOW,
	EXC_UNDERFLOW,
	EXC_OVERFLOW,
	EXC_NAN,
	EXC_NOT_VALID_SYNTAX_NUMBER
};

class MyException : public std::exception {
	private:
		eExceptionCode	_code;

		MyException (void);

	public:
		MyException (eExceptionCode code);
		virtual ~MyException (void) throw();

		virtual const char *	what(void) const throw();

		static std::string	exceptionString[NB_EXC];
};

#endif
