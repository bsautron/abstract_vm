#ifndef OPERAND_HPP
# define OPERAND_HPP

# include <MyException.hpp>
# include <IOperand.hpp>
# include <iostream>
# include <regex>
# include <iomanip>

template <typename T>
class Operand : public IOperand
{
private:
	int						_precision;
	std::string		_value;
	eOperandType	_type;

	Operand(void);
	void 	_Checker(std::string const & value, std::string const & format) {
		T		tmp;

		// Check if it's a good format string
		if (!this->_IsNumber(value))
			throw MyException(EXC_NAN);

		// Check if it's a integer or floating point number
		if (!std::regex_match(value, std::regex(format)))
			throw MyException(EXC_NOT_VALID_SYNTAX_NUMBER);

		// Try to convert
		try {
			if (this->_type < FLOAT)
				tmp = std::stoi(value);
			else if (this->_type == FLOAT)
				tmp = std::stof(value);
			else
				tmp = std::stod(value);
		} catch(const std::out_of_range &) {
			throw MyException((value[0] == '-') ? EXC_UNDERFLOW : EXC_OVERFLOW);
		}

		// Check Bound
		if (this->_type < FLOAT) {
			if (std::to_string(this->_number) != value && std::to_string(this->_number) != value.substr(1)) {
				throw MyException((value[0] == '-') ? EXC_UNDERFLOW : EXC_OVERFLOW);
			}
		}
		else {
			std::string numberString = std::to_string(this->_number);
			if (numberString.substr(0, numberString.length() - 4) != value.substr(0) && numberString.substr(0, numberString.length() - 4) != value.substr(1)) {
				throw MyException((value[0] == '-') ? EXC_UNDERFLOW : EXC_OVERFLOW);
			}
		}

		this->_precision = sizeof(T);
		this->_strValue = value;
	}

	bool _IsNumber(std::string const & value)	{ return std::regex_match(value, std::regex("-?\\d+(\\.\\d+)?")); }
	bool _IsInteger(void)											{ return (this->_type < FLOAT); }

public:
	Operand(std::string const & value, eOperandType type);
	~Operand(void) {}
	// Operand(IOperand const * op) {
	// 	this->_type = op->getType();
	// 	this->_precision = op->getPrecision();
	// 	this->_number = op->getNumber();
	// 	this->_strValue = op->getStrValue();
	// }

	int						getPrecision( void ) 	const { return this->_precision; }
	eOperandType			getType( void ) 		const { return this->_type; }
	T						getNumber( void ) 		const { return this->_number; }
	std::string const		getStrValue( void ) 	const { return this->_strValue; }

	virtual std::string const & toString() const {
		std::string *s = new std::string("[" + Operand<T>::type[this->_type] + "]: " + this->_strValue);
		return (*s);
	}



	static std::string	type[5];

};

std::ostream & operator<<(std::ostream &os, IOperand const &rhs);

#endif /* end of include guard: OPERAND_HPP */
