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
		OperandBuilder *	_builder;
		std::stringstream *	_stringstream;

		Operand(void);

		void _Checker(std::string const & value) {
			this->_Init();
			this->_CheckIsNumber(value);
			this->_CheckIsBounded(value);
		}

		void _Init(void) {
			this->_builder = new OperandBuilder();
			this->_stringstream = new std::stringstream();
		}

		void _CheckIsNumber(std::string const & value)	{
			std::smatch	arrayMatch;
			std::regex	numberPattern("-?\\d+(\\.\\d+)?");

			if (!std::regex_match(value, arrayMatch, numberPattern))
				throw MyException(EXC_NAN);
			if (this->_type < FLOAT) {
				this->_precision = 0;
				if (arrayMatch[1].length())
					throw MyException(EXC_NOT_VALID_SYNTAX_NUMBER);
			}
			else {
				this->_precision = arrayMatch[1].length() ? arrayMatch[1].length() - 1 : 0;
				if (!arrayMatch[1].length())
					throw MyException(EXC_NOT_VALID_SYNTAX_NUMBER);

			}
			*this->_stringstream = this->_GetStream(this->_precision, std::stold(value));

			if (!Operand<T>::assumePrecision && !this->_IsEqual(value))
				throw MyException(EXC_LIMITATION_PRECISION);
		}

		void _CheckIsBounded(std::string const & value) const {
			if (value[0] == '-')
				this->_CheckIsUpperMin(value);
			else
				this->_CheckIsUnderMax(value);
		}

		void _CheckIsUpperMin(std::string const & value) const {
			try {
				if ( !( (this->_IsInteger() ? std::stoi(value) : std::stod(value)) >= std::numeric_limits<T>::lowest() ))
					throw MyException(EXC_UNDERFLOW);
			} catch (const std::out_of_range & e) {
				throw MyException(EXC_UNDERFLOW);
			} catch (const MyException & e) {
				throw e;
			}
		}

		void _CheckIsUnderMax(std::string const & value) const {
			try {
				if ( ! ((this->_IsInteger() ? std::stoi(value) : std::stod(value)) <= std::numeric_limits<T>::max() ))
					throw MyException(EXC_OVERFLOW);
			} catch (const std::out_of_range & e) {
				throw MyException(EXC_OVERFLOW);
			} catch (const MyException & e) {
				throw e;
			}
		}

		bool _IsInteger(void) const {
			return (this->_type < FLOAT);
		}

		bool _IsEqual( std::string const & value ) const {
			return this->_stringstream->str().compare(value) == 0;
		}

		eOperandType _GetBiggerType(eOperandType a, eOperandType b) const {
			return a > b ? a : b;
		}

		int _GetBiggerPrecision(int a, int b) const {
			return a > b ? a : b;
		}

		IOperand const * _GetBiggerOperandPrecision(IOperand const * a, IOperand const * b) const {
			return (a->getPrecision() > b->getPrecision()) ? a : b;
		}

		std::stringstream _GetStream(int precision, long double number) const {
			std::stringstream stream;
			stream << std::fixed;
			stream.precision(precision);
			stream << number;
			return stream;
		}

		IOperand const *	_BuilderOperand( IOperand const & rhs, long double value) const {
			IOperand const * opSelected = this->_GetBiggerOperandPrecision(&rhs, this);
			return this->_builder->createOperand(
				(opSelected->getType() >= FLOAT) ? opSelected->getType() : this->_GetBiggerType( rhs.getType(), this->_type ),
				this->_GetStream( opSelected->getPrecision(), value ).str()
			);
		}

		bool _IsZero(std::string const value) const {
			return std::regex_match(value, std::regex("-?0*(\\.0+)?"));
		}

	public:

		Operand(std::string const & value);
		// Operand(IOperand const & op);

		virtual ~Operand(void) {
			delete this->_builder;
			delete this->_stringstream;
		}

		IOperand const * operator+( IOperand const & rhs ) const {
			return this->_BuilderOperand(rhs, std::stold(this->_stringstream->str()) + std::stold(rhs.toString()));
		}

		IOperand const * operator-( IOperand const & rhs ) const {
			return this->_BuilderOperand(rhs, std::stold(this->_stringstream->str()) - std::stold(rhs.toString()));
		}

		IOperand const * operator*( IOperand const & rhs ) const {
			return this->_BuilderOperand(rhs, std::stold(this->_stringstream->str()) * std::stold(rhs.toString()));
		}

		IOperand const * operator/( IOperand const & rhs ) const {
			if (this->_IsZero(rhs.toString()))
				throw MyException(EXC_DEVIDE_BZERO);
			return this->_BuilderOperand(rhs, std::stold(this->_stringstream->str()) / std::stold(rhs.toString()));
		}

		IOperand const * operator%( IOperand const & rhs ) const {
			if (rhs.getType() >= FLOAT || this->_type >= FLOAT)
				throw MyException(EXC_MODULO_BFLOAT);
			if (this->_IsZero(rhs.toString()))
				throw MyException(EXC_MODULO_BZERO);
			return this->_BuilderOperand(rhs, std::stoi(this->_stringstream->str()) % std::stoi(rhs.toString()));
		}
		//
		// IOperand const & operator=( IOperand const & rhs ) {
		// 	this->_Checker(rhs.toString());
		// 	return *this;
		// }

		int						getPrecision( void ) 	const { return this->_precision; }
		eOperandType			getType( void ) 		const { return this->_type; }

		bool 	IsPositive(void) const {
			return this->_stringstream->str()[0] != '-';
		}

		virtual std::string const & toString() const {
			std::string *s = new std::string(this->_stringstream->str());
			return *s;
		}

		static bool					assumePrecision;
		static std::string			stringType[5];
		static int 					nb;
};

std::ostream & operator<<(std::ostream & os, IOperand const & rhs);

#endif
