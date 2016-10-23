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

// template<>
// Operand<char>::Operand(IOperand const & src) : _type(INT8) {
// 	// this->_Checker(src.toString());
// 	std::cout << "/* message */" << std::endl;
// 	std::cout << src << std::endl;
// }
//
// template<>
// Operand<short>::Operand(IOperand const & src) : _type(INT16) {
// 	// this->_Checker(src.toString());
// 	std::cout << "/* message */" << std::endl;
// 	std::cout << src << std::endl;
// }
//
// template<>
// Operand<int>::Operand(IOperand const & src) : _type(INT32) {
// 	// this->_Checker(src.toString());
// 	std::cout << "/* message */" << std::endl;
// 	std::cout << src << std::endl;
// }
//
// template<>
// Operand<float>::Operand(IOperand const & src) : _type(FLOAT) {
// 	// this->_Checker(src.toString());
// 	std::cout << "/* message */" << std::endl;
// 	std::cout << src << std::endl;
// }
//
// template<>
// Operand<double>::Operand(IOperand const & src) : _type(DOUBLE) {
// 	// this->_Checker(src.toString());
// 	std::cout << "/* message */" << std::endl;
// 	std::cout << src << std::endl;
// }

template<>
std::string	Operand<void>::stringType[5] = {
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
