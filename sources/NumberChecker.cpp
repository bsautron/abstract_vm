#include <NumberChecker.hpp>

NumberChecker::NumberChecker(std::string const & value, eOperandType type) : _value(value), _type(type) {}

template<>
typename void NumberChecker::_isNumber<char>(std::string const & value) {
	char	val = static_cast<char>(std::stoi(value));
	this->_isBounded<char>(val, CHAR_MIN, CHAR_MAX);
}

template<typename T>
typename bool	NumberChecker::_isBounded(T value, T min, T max) {
	if (!(value >= min && value <= max))
		throw std::string("Out of bound");
	return (true);
}


template<typename T>
typename T 	NumberChecker::isValidNumber(std::string const & value) {
	std::regex	e("(-)?[\\d]+(.[\\d]+)?");
	if (!std::regex_match(value, e))
		throw std::string("Not a number");
}
