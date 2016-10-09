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
		std::string		_value;
		eOperandType	_type;
		int				_precision;

		Operand(void);

		void _Checker(void) {
			this->_CheckIsNumber();
			this->_CheckIsBounded();
		}

		void _CheckIsNumber(void)	{
			std::smatch	arrayMatch;
			std::regex	numberPattern("-?\\d+(\\.\\d+)?");

			if (!std::regex_match(this->_value, arrayMatch, numberPattern))
				throw MyException(EXC_NAN);
			this->_precision = arrayMatch[1].length() ? arrayMatch[1].length() - 1 : 0;
		}

		void _CheckIsBounded(void) {
			if (this->_value[0] == '-')
				this->_CheckIsUpperMin();
			else
				this->_CheckIsUnderMax();
		}

		void _CheckIsUpperMin(void) {
			try {
				if ( !((this->_IsInteger() ? std::stoi(this->_value) : std::stod(this->_value)) >= std::numeric_limits<T>::min() ))
					throw MyException(EXC_UNDERFLOW);
			} catch (const std::out_of_range & e) {
				throw MyException(EXC_UNDERFLOW);
			} catch (const MyException & e) {
				throw e;
			}
		}

		void _CheckIsUnderMax(void) {
			try {
				if ( ! ((this->_IsInteger() ? std::stoi(this->_value) : std::stod(this->_value)) <= std::numeric_limits<T>::max() ))
					throw MyException(EXC_OVERFLOW);
			} catch (const std::out_of_range & e) {
				throw MyException(EXC_OVERFLOW);
			} catch (const MyException & e) {
				throw e;
			}
		}

		bool _IsInteger(void) {
			return (this->_type < FLOAT);
		}

	public:

		Operand(std::string const & value);


			// Check if it's a good format string
			// if (!this->_IsNumber(value))
			// 	throw MyException(EXC_NAN);

			// Check if it's a integer or floating point number
			// if (!std::regex_match(value, std::regex(format)))
				// throw MyException(EXC_NOT_VALID_SYNTAX_NUMBER);

			// throw MyException((value[0] == '-') ? EXC_UNDERFLOW : EXC_OVERFLOW);
		// }


		~Operand(void) {}
		// Operand(IOperand const * op) {
		// 	this->_type = op->getType();
		// 	this->_precision = op->getPrecision();
		// 	this->_number = op->getNumber();
		// 	this->_strValue = op->getStrValue();
		// }

		int						getPrecision( void ) 	const { return this->_precision; }
		eOperandType			getType( void ) 		const { return this->_type; }

		virtual std::string const & toString() const {
			std::string *s = new std::string("[" + Operand<T>::type[this->_type] + "]: " + this->_value);
			return (*s);
		}

		static std::string			type[5];
};

std::ostream & operator<<(std::ostream &os, IOperand const &rhs);

#endif /* end of include guard: OPERAND_HPP */
