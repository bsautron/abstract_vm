#include <MyException.hpp>

MyException::MyException(eExceptionCode code) : _code(code) {}
MyException::~MyException(void) throw() {}

const char *		MyException::what(void) const throw() {
	return MyException::exceptionString[this->_code].c_str();
}

std::string	MyException::exceptionString[] = {
	"TMP EXCPETION",
	"UnKnow",
	"Underflow",
	"Overflow",
	"Not a Number",
	"Not valid syntax number",
	"Argv empty",
	"Must treat each case",
	"Abstract limitation precision",
	"Divide by zero",
	"Modulo by zero",
	"Modulo by none integer numbers",
	"The stack is empty",
	"Assert failed",
	"The stack is too short"

};
