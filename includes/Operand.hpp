#ifndef OPERAND_HPP
# define OPERAND_HPP

# include <MyException.hpp>
# include <IOperand.hpp>
# include <limits>
# include <iostream>
# include <regex>
# include <iomanip>


typedef struct	s_model {
	std::string const &	format;
	std::string const &	type;
	std::string const &	more;
}				t_model;

static t_model	models[5] {
	{"UInt8", "-?\\d+", "Integer 8 bit (1 Byte)"},
	{"UInt16", "-?\\d+", "Integer 16 bit (2 Bytes)"},
	{"UInt32", "-?\\d+", "Integer 32 bit (4 Bytes)"},
	{"Float", "-?\\d+\\.\\d+", "Float 32 bit (4 Bytes)"},
	{"Double", "-?\\d+\\.\\d+", "Integer 64 bit (8 Bytes)"},
};

template <typename T>
class Operand : public IOperand
{
	private:
		int				_precision;
		std::string		_value;
		eOperandType	_type;

		Operand(void);

		// void 	_Checker(std::string const & value, std::string const & format) {
		// 	T		tmp;
		// }

		bool _IsNumber(std::string const & value)	{ return std::regex_match(value, std::regex("-?\\d+(\\.\\d+)?")); }
		bool _IsInteger(void)						{ return (this->_type < FLOAT); }

	public:

		Operand(std::string const & value, eOperandType type) : _value(value), _type(type) {
			// Check if it's a good format string
			if (!this->_IsNumber(value))
				throw MyException(EXC_NAN);

			// Check if it's a integer or floating point number
			// if (!std::regex_match(value, std::regex(format)))
				// throw MyException(EXC_NOT_VALID_SYNTAX_NUMBER);

			// throw MyException((value[0] == '-') ? EXC_UNDERFLOW : EXC_OVERFLOW);
		}


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
			std::string *s = new std::string("[" + Operand<T>::type[this->_type] + "]: " + this->_value);
			return (*s);
		}

		static std::string			type[5];
};

std::ostream & operator<<(std::ostream &os, IOperand const &rhs);

#endif /* end of include guard: OPERAND_HPP */
