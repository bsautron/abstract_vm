#include <Operand.hpp>

template<>
Operand<char>::Operand(std::string const & value, eOperandType type) : _type(type) {
	this->_Checker(value, "-?\\d+");
}

template<>
Operand<short>::Operand(std::string const & value, eOperandType type) : _type(type) {
	this->_Checker(value, "-?\\d+");
}

template<>
Operand<int>::Operand(std::string const & value, eOperandType type) : _type(type) {
	this->_Checker(value, "-?\\d+");
}

template<>
Operand<float>::Operand(std::string const & value, eOperandType type) : _type(type) {
	this->_Checker(value, "-?\\d+\\.\\d+");
}

template<>
Operand<double>::Operand(std::string const & value, eOperandType type) : _type(type) {
	this->_Checker(value, "-?\\d+\\.\\d+");
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
