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
	this->_Checker(value, "-?\\d+\\.\\d{2}");
}

template<>
Operand<double>::Operand(std::string const & value, eOperandType type) : _type(type) {
	this->_Checker(value, "-?\\d+\\.\\d{2}");
}
//
// template<typename T>
// t_numberChecker const Operand<T>::cheker[5] = {
//    {static_cast<double>(CHAR_MIN), static_cast<double>(CHAR_MAX), std::regex("-?\\d+")},
//    {static_cast<double>(SHRT_MIN), static_cast<double>(SHRT_MAX), std::regex("-?\\d+")},
//    {static_cast<double>(INT_MIN), static_cast<double>(INT_MAX), std::regex("-?\\d+")},
//    {static_cast<double>(FLT_MIN), static_cast<double>(FLT_MAX), std::regex("-?\\d+\\.\\d+")},
//    {static_cast<double>(DBL_MIN), static_cast<double>(DBL_MAX), std::regex("-?\\d+\\.\\d+")}
// };
