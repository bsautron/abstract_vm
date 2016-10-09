#include <Operand.hpp>

template<>
Operand<char>::Operand(std::string const & value) : _value(value), _type(INT8), _precision(0) {
	this->_Checker();
}

template<>
Operand<short>::Operand(std::string const & value) : _value(value), _type(INT16), _precision(0) {
	this->_Checker();
}

template<>
Operand<int>::Operand(std::string const & value) : _value(value), _type(INT32), _precision(0) {
	this->_Checker();
}

template<>
Operand<float>::Operand(std::string const & value) : _value(value), _type(FLOAT) {
	this->_Checker();
}

template<>
Operand<double>::Operand(std::string const & value) : _value(value), _type(DOUBLE) {
	this->_Checker();
}

template<typename T>
std::string	Operand<T>::type[5] = {
	"UInt8",
	"UInt16",
	"UInt32",
	"Float",
	"Double"
};



std::ostream & operator<<(std::ostream &os, IOperand const &rhs) {
    os << rhs.toString();
    return (os);
}
