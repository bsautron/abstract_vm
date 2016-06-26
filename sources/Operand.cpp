#include <Operand.hpp>

template<>
Operand<char>::Operand(std::string const & value, eOperandType type) : _type(type) {
	if (!this->_IsNumber(value))
		throw std::string("Not a number");

	this->_CheckOverflow(value, Operand<char>::cheker[type]);
	this->_precision = sizeof(char);
	this->_number = static_cast<char>(std::stoi(value));
}
template<>
Operand<short>::Operand(std::string const & value, eOperandType type) : _type(type) {
	if (!this->_IsNumber(value))
		throw std::string("Not a number");

	this->_CheckOverflow(value, Operand<short>::cheker[type]);
	this->_precision = sizeof(short);
	this->_number = static_cast<short>(std::stoi(value));
}
template<>
Operand<int>::Operand(std::string const & value, eOperandType type) : _type(type) {
	if (!this->_IsNumber(value))
		throw std::string("Not a number");

	this->_CheckOverflow(value, Operand<int>::cheker[type]);
	this->_precision = sizeof(int);
	this->_number = std::stoi(value);
}
template<>
Operand<float>::Operand(std::string const & value, eOperandType type) : _type(type) {
	if (!this->_IsNumber(value))
		throw std::string("Not a number");

	this->_CheckOverflow(value, Operand<float>::cheker[type]);
	this->_precision = sizeof(float);
	this->_number = std::stof(value);
}
template<>
Operand<double>::Operand(std::string const & value, eOperandType type) : _type(type) {
	if (!this->_IsNumber(value))
		throw std::string("Not a number");

	this->_CheckOverflow(value, Operand<double>::cheker[type]);
	this->_precision = sizeof(double);
	this->_number = std::stod(value);
}

template<typename T>
t_numberChecker const Operand<T>::cheker[5] = {
   {static_cast<double>(CHAR_MIN), static_cast<double>(CHAR_MAX), std::regex("-?\\d+")},
   {static_cast<double>(SHRT_MIN), static_cast<double>(SHRT_MAX), std::regex("-?\\d+")},
   {static_cast<double>(INT_MIN), static_cast<double>(INT_MAX), std::regex("-?\\d+")},
   {static_cast<double>(FLT_MIN), static_cast<double>(FLT_MAX), std::regex("-?\\d+\\.\\d+")},
   {static_cast<double>(DBL_MIN), static_cast<double>(DBL_MAX), std::regex("-?\\d+\\.\\d+")}
};
