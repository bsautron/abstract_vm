#ifndef MYEXCEPTION
# define MYEXCEPTION

#include <iostream>

enum eExceptionCode {
	EXC_UNKNOW,
	EXC_UNDERFLOW,
	EXC_OVERFLOW,
	EXC_NAN
};

class MyException : public std::exception {
	private:
		eExceptionCode	_code;

		MyException (void);

	public:
		MyException (eExceptionCode code);
		virtual ~MyException (void) throw();

		virtual const char *	what(void) const throw();

		static std::string	exceptionString[4];
};

#endif
