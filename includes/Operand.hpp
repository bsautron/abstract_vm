#ifndef OPERAND_HPP
# define OPERAND_HPP

// # include <OperandBuilder.hpp>
# include <MyException.hpp>
# include <IOperand.hpp>
# include <OperandBuilder.hpp>
# include <limits>
# include <sstream>
# include <regex>

template <typename T>
class Operand : public IOperand
{
	private:
		eOperandType		_type;
		int					_precision;
		OperandBuilder		_builder;
		std::stringstream 	_stringstream;

		Operand(void);

		void _Checker(std::string const & value) {
			this->_CheckIsNumber(value);
			this->_CheckIsBounded(value);
		}

		void _CheckIsNumber(std::string const & value)	{
			std::smatch	arrayMatch;
			std::regex	numberPattern("-?\\d+(\\.\\d+)?");

			if (!std::regex_match(value, arrayMatch, numberPattern))
				throw MyException(EXC_NAN);
			this->_precision = arrayMatch[1].length() ? arrayMatch[1].length() - 1 : 0;
			this->_stringstream = this->_GetStream(this->_precision, std::stold(value));

			if (!Operand<T>::assumePrecision && value.compare(this->_stringstream.str()))
				throw MyException(EXC_LIMITATION_PRECISION);
		}

		void _CheckIsBounded(std::string const & value) {
			if (value[0] == '-')
				this->_CheckIsUpperMin(value);
			else
				this->_CheckIsUnderMax(value);
		}

		void _CheckIsUpperMin(std::string const & value) {
			try {
				if ( !((this->_IsInteger() ? std::stoi(value) : std::stod(value)) >= std::numeric_limits<T>::min() ))
					throw MyException(EXC_UNDERFLOW);
			} catch (const std::out_of_range & e) {
				throw MyException(EXC_UNDERFLOW);
			} catch (const MyException & e) {
				throw e;
			}
		}

		void _CheckIsUnderMax(std::string const & value) {
			try {
				if ( ! ((this->_IsInteger() ? std::stoi(value) : std::stod(value)) <= std::numeric_limits<T>::max() ))
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

		eOperandType _GetBiggerType(eOperandType a, eOperandType b) const {
			return a > b ? a : b;
		}

		int _GetBiggerPrecision(int a, int b) const {
			return a > b ? a : b;
		}

		std::stringstream _GetStream(int precision, long double number) const {
			std::stringstream stream;
			stream << std::fixed;
			stream.precision(precision);
			stream << number;
			return stream;
		}

	public:

		Operand(std::string const & value);

		~Operand(void) {}

		IOperand const * operator+( IOperand const & rhs ) const {
			eOperandType newType = this->_GetBiggerType(rhs.getType(), this->_type);
			int newPrecision = this->_GetBiggerPrecision(rhs.getPrecision(), this->_precision);
			std::stringstream stringstream = this->_GetStream(newPrecision, std::stold(rhs.toString()) + std::stold(this->_stringstream.str()));

			return this->_builder.createOperand(newType, stringstream.str());
		}


		int						getPrecision( void ) 	const { return this->_precision; }
		eOperandType			getType( void ) 		const { return this->_type; }

		virtual std::string const & toString() const {
			std::string *s = new std::string(this->_stringstream.str());
			return (*s);
		}

		static bool					assumePrecision;
		static std::string			stringType[5];
};

std::ostream & operator<<(std::ostream & os, IOperand const & rhs);

#endif
