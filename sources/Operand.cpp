#include <Operand.hpp>

template<>
Operand<char>::Operand(std::string const & value) : _type(INT8) {
	this->_Checker(value);
}

template<>
Operand<short>::Operand(std::string const & value) : _type(INT16) {
	this->_Checker(value);
}

template<>
Operand<int>::Operand(std::string const & value) : _type(INT32) {
	this->_Checker(value);
}

template<>
Operand<float>::Operand(std::string const & value) : _type(FLOAT) {
	this->_Checker(value);
}

template<>
Operand<double>::Operand(std::string const & value) : _type(DOUBLE) {
	this->_Checker(value);
}

template<>
std::string	Operand<void>::stringType[] = {
	"Int8",
	"Int16",
	"Int32",
	"Float",
	"Double"
};

std::ostream & operator<<(std::ostream & os, IOperand const & rhs) {
	os << rhs.toString();
	return (os);
}

template<typename T>
bool Operand<T>::assumePrecision = false;

// 
//
// OverflowException::OverflowException(void) throw() : std::overflow_error("Overflow") {}
// OverflowException::~OverflowException(void) throw() {}
// OverflowException::OverflowException(OverflowException const & src) throw() : std::overflow_error("Overflow") {
// 	*this = src;
// }
// OverflowException & OverflowException::operator=(OverflowException const & rhs) throw() {
// 	(void)rhs;
// 	return *this;
// }
//
// UnderflowException::UnderflowException(void) throw() : std::underflow_error("Underflow") {}
// UnderflowException::~UnderflowException(void) throw() {}
// UnderflowException::UnderflowException(UnderflowException const & src) throw() : std::underflow_error("Underflow") {
// 	*this = src;
// }
// UnderflowException & UnderflowException::operator=(UnderflowException const & rhs) throw() {
// 	(void)rhs;
// 	return *this;
// }
//
// DivideByZeroException::DivideByZeroException(void) throw() : std::runtime_error("Divide by zero") {}
// DivideByZeroException::~DivideByZeroException(void) throw() {}
// DivideByZeroException::DivideByZeroException(DivideByZeroException const & src) throw() : std::runtime_error("Divide by zero") {
// 	*this = src;
// }
// DivideByZeroException & DivideByZeroException::operator=(DivideByZeroException const & rhs) throw() {
// 	(void)rhs;
// 	return *this;
// }
//
// ModuloByZeroException::ModuloByZeroException(void) throw() : std::runtime_error("Modulo by zero") {}
// ModuloByZeroException::~ModuloByZeroException(void) throw() {}
// ModuloByZeroException::ModuloByZeroException(ModuloByZeroException const & src) throw() : std::runtime_error("Modulo by zero") {
// 	*this = src;
// }
// ModuloByZeroException & ModuloByZeroException::operator=(ModuloByZeroException const & rhs) throw() {
// 	(void)rhs;
// 	return *this;
// }
//
// ModuloFloatException::ModuloFloatException(void) throw() : std::runtime_error("Modulo by floating number") {}
// ModuloFloatException::~ModuloFloatException(void) throw() {}
// ModuloFloatException::ModuloFloatException(ModuloFloatException const & src) throw() : std::runtime_error("Modulo by floating number") {
// 	*this = src;
// }
// ModuloFloatException & ModuloFloatException::operator=(ModuloFloatException const & rhs) throw() {
// 	(void)rhs;
// 	return *this;
// }
//
// LimitationPrecisionException::LimitationPrecisionException(void) throw() : std::runtime_error("Limitation of precision") {}
// LimitationPrecisionException::~LimitationPrecisionException(void) throw() {}
// LimitationPrecisionException::LimitationPrecisionException(LimitationPrecisionException const & src) throw() : std::runtime_error("Limitation of precision") {
// 	*this = src;
// }
// LimitationPrecisionException & LimitationPrecisionException::operator=(LimitationPrecisionException const & rhs) throw() {
// 	(void)rhs;
// 	return *this;
// }
//
// NanException::NanException(void) throw() : std::invalid_argument("Argument is not a number") {}
// NanException::~NanException(void) throw() {}
// NanException::NanException(NanException const & src) throw() : std::invalid_argument("Argument is not a number") {
// 	*this = src;
// }
// NanException & NanException::operator=(NanException const & rhs) throw() {
// 	(void)rhs;
// 	return *this;
// }
//
// NotValidNumberException::NotValidNumberException(void) throw() : std::invalid_argument("Argument is not a valid number") {}
// NotValidNumberException::~NotValidNumberException(void) throw() {}
// NotValidNumberException::NotValidNumberException(NotValidNumberException const & src) throw() : std::invalid_argument("Argument is not a valid number") {
// 	*this = src;
// }
// NotValidNumberException & NotValidNumberException::operator=(NotValidNumberException const & rhs) throw() {
// 	(void)rhs;
// 	return *this;
// }
