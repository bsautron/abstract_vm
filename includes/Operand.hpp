#ifndef OPERAND_HPP
# define OPERAND_HPP

# include <IOperand.hpp>
# include <climits>
# include <cfloat>
# include <regex>

struct numberChecker
{
	double		value;
	double		min;
	double		max;
	std::regex	reg;
};

template <typename T>
class Operand : public IOperand
{
private:
	T 				_number;
	int				_precision;
	eOperandType	_type;

	Operand(void);
	bool _CheckOverflow(std::string const & value, numberChecker cc) {
		if (!std::regex_match(value, cc.reg))
			throw "regex_match failed";
		if (cc.value > cc.max)
			throw "overflow";
		if (cc.value < cc.min)
			throw "underflow";
		return true;
	}

public:
	Operand(std::string const & value, eOperandType type) : _type(type) {
		numberChecker cc[5] = {
			{std::stod(value), static_cast<double>(CHAR_MIN), static_cast<double>(CHAR_MAX), std::regex("\\d+")},
			{std::stod(value), static_cast<double>(SHRT_MIN), static_cast<double>(SHRT_MAX), std::regex("\\d+")},
			{std::stod(value), static_cast<double>(INT_MIN), static_cast<double>(INT_MAX), std::regex("\\d+")},
			{std::stod(value), static_cast<double>(FLT_MIN), static_cast<double>(FLT_MAX), std::regex("\\d+\\.\\d+")},
			{std::stod(value), static_cast<double>(DBL_MIN), static_cast<double>(DBL_MAX), std::regex("\\d+\\.\\d+")}
		};

		this->_CheckOverflow(value, cc[this->_type]);
		this->_precision = 0;
	}

	int				getPrecision( void ) 	const { return this->_precision; }
	eOperandType	getType( void ) 		const { return this->_type; }

	~Operand(void) {}

};

#endif /* end of include guard: OPERAND_HPP */
