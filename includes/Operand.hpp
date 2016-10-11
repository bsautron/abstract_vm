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
			this->_stringstream.precision(this->_precision);
			this->_stringstream << std::fixed;
			this->_stringstream << std::stold(value);
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

	public:

		Operand(std::string const & value);

		~Operand(void) {}

		IOperand const * operator+( IOperand const & rhs ) const {
			eOperandType rhsType = rhs.getType();
			eOperandType newType = (rhsType > this->_type) ? rhsType : this->_type;
			int rshPrecision = rhs.getPrecision();
			int newPrecision = (rshPrecision > this->_precision) ? rshPrecision : this->_precision;

			std::stringstream stringstream;
			stringstream << std::fixed;
			stringstream.precision(newPrecision);

			if (newType < FLOAT)
				stringstream << (std::stoi(rhs.toString()) + std::stoi(this->_stringstream.str()));
			else
				stringstream << (std::stold(rhs.toString()) + std::stold(this->_stringstream.str()));

			return this->_builder.createOperand(newType, stringstream.str());
		}


		int						getPrecision( void ) 	const { return this->_precision; }
		eOperandType			getType( void ) 		const { return this->_type; }

		virtual std::string const & toString() const {
			std::string *s = new std::string(this->_stringstream.str());
			return (*s);
		}

		static std::string			stringType[5];
};

std::ostream & operator<<(std::ostream & os, IOperand const & rhs);

#endif
