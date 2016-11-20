#ifndef OPERAND_HPP
# define OPERAND_HPP

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
		std::stringstream	_stringStream;

		Operand(void);

		void _Checker(std::string const & value) {
			this->_CheckIsNumber(value);
			this->_CheckIsBounded(value);

			if (!Operand<T>::assumePrecision && !this->_IsEqual(value))
				throw LimitationPrecisionException();
		}

		void _CheckIsNumber(std::string const & value)	{
			std::smatch	arrayMatch;
			std::regex	numberPattern("-?\\d+(\\.\\d+)?");

			if (!std::regex_match(value, arrayMatch, numberPattern))
				throw NanException();
			if (this->_type < FLOAT) {
				this->_precision = 0;
				if (arrayMatch[1].length())
					throw NotValidNumberException();
			}
			else {
				this->_precision = arrayMatch[1].length() ? arrayMatch[1].length() - 1 : 0;
				if (!arrayMatch[1].length())
					throw NotValidNumberException();
			}
			this->_stringStream = this->_GetStream(this->_precision, std::stold(value));
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
					throw UnderflowException();
			} catch (const std::out_of_range & e) {
				throw UnderflowException();
			} catch (const std::exception & e) {
				throw e;
			}
		}

		void _CheckIsUnderMax(std::string const & value) const {
			try {
				if ( ! ((this->_IsInteger() ? std::stoi(value) : std::stod(value)) <= std::numeric_limits<T>::max() ))
					throw OverflowException();
			} catch (const std::out_of_range & e) {
				throw OverflowException();
			} catch (const std::exception & e) {
				throw e;
			}
		}

		bool _IsInteger(void) const {
			return (this->_type < FLOAT);
		}

		bool _IsEqual( std::string const & value ) const {
			return this->_stringStream.str().compare(value) == 0;
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
			return this->_builder.createOperand(
				(opSelected->getType() >= FLOAT) ? opSelected->getType() : this->_GetBiggerType( rhs.getType(), this->_type ),
				this->_GetStream( opSelected->getPrecision(), value ).str()
			);
		}

		bool _IsZero(std::string const value) const {
			return std::regex_match(value, std::regex("-?0*(\\.0+)?"));
		}

	public:


		class OverflowException : public std::overflow_error {

			public:
				OverflowException(void) throw() : std::overflow_error("") {}
				OverflowException(OverflowException const & src) throw() : std::overflow_error("") {
					*this = src;
				}
				OverflowException & operator=(OverflowException const & rhs) throw() {
					(void)rhs;
					return *this;
				}

				virtual ~OverflowException(void) throw() {}
		};

		class UnderflowException : public std::underflow_error {

			public:
				UnderflowException(void) throw() : std::underflow_error("") {}
				UnderflowException(UnderflowException const & src) throw() : std::underflow_error("") {
					*this = src;
				}
				UnderflowException & operator=(UnderflowException const & rhs) throw() {
					(void)rhs;
					return *this;
				}

				virtual ~UnderflowException(void) throw() {}
		};

		class DivideByZeroException : public std::runtime_error {

			public:
				DivideByZeroException(void) throw() : std::runtime_error("") {}
				DivideByZeroException(DivideByZeroException const & src) throw() : std::runtime_error("") {
					*this = src;
				}
				DivideByZeroException & operator=(DivideByZeroException const & rhs) throw() {
					(void)rhs;
					return *this;
				}

				virtual ~DivideByZeroException(void) throw() {}
		};

		class ModuloByZeroException : public std::runtime_error {

			public:
				ModuloByZeroException(void) throw() : std::runtime_error("") {}
				ModuloByZeroException(ModuloByZeroException const & src) throw() : std::runtime_error("") {
					*this = src;
				}
				ModuloByZeroException & operator=(ModuloByZeroException const & rhs) throw() {
					(void)rhs;
					return *this;
				}

				virtual ~ModuloByZeroException(void) throw() {}
		};

		class ModuloFloatException : public std::runtime_error {

			public:
				ModuloFloatException(void) throw() : std::runtime_error("") {}
				ModuloFloatException(ModuloFloatException const & src) throw() : std::runtime_error("") {
					*this = src;
				}
				ModuloFloatException & operator=(ModuloFloatException const & rhs) throw() {
					(void)rhs;
					return *this;
				}

				virtual ~ModuloFloatException(void) throw() {}
		};

		class LimitationPrecisionException : public std::runtime_error {

			public:
				LimitationPrecisionException(void) throw() : std::runtime_error("") {}
				LimitationPrecisionException(LimitationPrecisionException const & src) throw() : std::runtime_error("") {
					*this = src;
				}
				LimitationPrecisionException & operator=(LimitationPrecisionException const & rhs) throw() {
					(void)rhs;
					return *this;
				}

				virtual ~LimitationPrecisionException(void) throw() {}
		};
		class NanException : public std::invalid_argument {

			public:
				NanException(void) throw() : std::invalid_argument("") {}
				NanException(NanException const & src) throw() : std::invalid_argument("") {
					*this = src;
				}
				NanException & operator=(NanException const & rhs) throw() {
					(void)rhs;
					return *this;
				}

				virtual ~NanException(void) throw() {}
		};
		class NotValidNumberException : public std::invalid_argument {

			public:
				NotValidNumberException(void) throw() : std::invalid_argument("") {}
				NotValidNumberException(NotValidNumberException const & src) throw() : std::invalid_argument("") {
					*this = src;
				}
				NotValidNumberException & operator=(NotValidNumberException const & rhs) throw() {
					(void)rhs;
					return *this;
				}

				virtual ~NotValidNumberException(void) throw() {}
		};

		Operand(std::string const & value);
		// Operand(IOperand const & op);

		virtual ~Operand(void) {}

		IOperand const * operator+( IOperand const & rhs ) const {
			return this->_BuilderOperand(rhs, std::stold(this->_stringStream.str()) + std::stold(rhs.toString()));
		}

		IOperand const * operator-( IOperand const & rhs ) const {
			return this->_BuilderOperand(rhs, std::stold(this->_stringStream.str()) - std::stold(rhs.toString()));
		}

		IOperand const * operator*( IOperand const & rhs ) const {
			return this->_BuilderOperand(rhs, std::stold(this->_stringStream.str()) * std::stold(rhs.toString()));
		}

		IOperand const * operator/( IOperand const & rhs ) const {
			if (this->_IsZero(rhs.toString()))
				throw DivideByZeroException();
			return this->_BuilderOperand(rhs, std::stold(this->_stringStream.str()) / std::stold(rhs.toString()));
		}

		IOperand const * operator%( IOperand const & rhs ) const {
			if (rhs.getType() >= FLOAT || this->_type >= FLOAT)
				throw ModuloFloatException();
			if (this->_IsZero(rhs.toString()))
				throw ModuloByZeroException();
			return this->_BuilderOperand(rhs, std::stoi(this->_stringStream.str()) % std::stoi(rhs.toString()));
		}

		int						getPrecision( void ) 	const { return this->_precision; }
		eOperandType			getType( void ) 		const { return this->_type; }

		bool 	IsPositive(void) const {
			return this->_stringStream.str()[0] != '-';
		}

		virtual std::string const & toString() const {
			std::string *s = new std::string(this->_stringStream.str());
			return *s;
		}

		static bool					assumePrecision;
		static std::string			stringType[5];
		static int 					nb;

};

std::ostream & operator<<(std::ostream & os, IOperand const & rhs);


#endif
