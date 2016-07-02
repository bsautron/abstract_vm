#ifndef OPERAND_HPP
# define OPERAND_HPP

# include <MyException.hpp>
# include <IOperand.hpp>
# include <iostream>
// # include <climits>
// # include <cfloat>
# include <regex>

typedef struct	s_numberChecker
{
	double			min;
	double			max;
	std::regex		reg;
}				t_numberChecker;

template <typename T>
class Operand : public IOperand
{
private:
	T 				_number;
	int				_precision;
	eOperandType	_type;

	Operand(void);
	// bool _CheckOverflow(std::string const & value, t_numberChecker cc) {
	// 	// TODO: Find an expection for regec failed
	// 	// if (!std::regex_match(value, cc.reg))
	// 	// 	throw std::string("regex_match failed");
	// 	(void)value;
	// 	if (this->_number > cc.max)
	// 		throw MyException(EXC_OVERFLOW);
	// 	if (this->_number < cc.min)
	// 		throw MyException(EXC_UNDERFLOW);
	// 	return true;
	// }

	bool _IsNumber(std::string const & value)	{ return std::regex_match(value, std::regex("-?\\d+(\\.\\d+)?")); }
	bool _IsInteger(void)						{ return (this->_type < FLOAT); }

public:
	Operand(std::string const & value, eOperandType type);

	int				getPrecision( void ) 	const { return this->_precision; }
	eOperandType	getType( void ) 		const { return this->_type; }

	~Operand(void) {}

	// static t_numberChecker const cheker[5];
};

#endif /* end of include guard: OPERAND_HPP */
