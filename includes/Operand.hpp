/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:05:11 by bsautron          #+#    #+#             */
/*   Updated: 2016/12/01 21:05:12 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		Operand(IOperand const & src);
		Operand & operator=(Operand<T> const & rhs);

		void _checker(std::string const & value) {
			this->_checkIsNumber(value);
			this->_checkIsBounded(value);

			if (!Operand<T>::assumePrecision && !this->_isEqual(value))
				throw LimitationPrecisionException();
		}

		void _checkIsNumber(std::string const & value)	{
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
			this->_stringStream = this->_getStream(this->_precision, std::stold(value));
		}

		void _checkIsBounded(std::string const & value) const {

			if (value[0] == '-')
				this->_checkIsUpperMin(value);
			else
				this->_checkIsUnderMax(value);
		}

		void _checkIsUpperMin(std::string const & value) const {
			try {
				if ( !( (this->_isInteger() ? std::stoi(value) : std::stod(value)) >= std::numeric_limits<T>::lowest() ))
					throw UnderflowException();
			} catch (const std::out_of_range & e) {
				throw UnderflowException();
			}
		}

		void _checkIsUnderMax(std::string const & value) const {
			try {
				if ( ! ((this->_isInteger() ? std::stoi(value) : std::stod(value)) <= std::numeric_limits<T>::max() ))
					throw OverflowException();
			} catch (const std::out_of_range & e) {
				throw OverflowException();
			}
		}

		bool _isInteger(void) const {
			return (this->_type < FLOAT);
		}

		bool _isEqual( std::string const & value ) const {
			return this->_stringStream.str().compare(value) == 0;
		}

		eOperandType _getBiggerType(eOperandType a, eOperandType b) const {
			return a > b ? a : b;
		}

		int _getBiggerPrecision(int a, int b) const {
			return a > b ? a : b;
		}

		std::stringstream _getStream(int precision, long double number) const {
			std::stringstream stream;
			stream << std::fixed;
			stream.precision(precision);
			stream << number;
			return stream;
		}

		IOperand const *	_builderOperand( IOperand const & rhs, long double value) const {
			return this->_builder.createOperand(
				this->_getBiggerType( rhs.getType(), this->_type ),
				this->_getStream( this->_getBiggerPrecision(rhs.getPrecision(), this->_precision), value ).str()
			);
		}

		bool _isZero(std::string const value) const {
			return std::regex_match(value, std::regex("-?0*(\\.0+)?"));
		}

	public:


		class OverflowException : public std::overflow_error {

			public:
				OverflowException(void) throw() : std::overflow_error("Overflow") {}
				OverflowException(OverflowException const & src) throw() : std::overflow_error("Overflow") {
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
				UnderflowException(void) throw() : std::underflow_error("Underflow") {}
				UnderflowException(UnderflowException const & src) throw() : std::underflow_error("Underflow") {
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
				DivideByZeroException(void) throw() : std::runtime_error("Division by zero") {}
				DivideByZeroException(DivideByZeroException const & src) throw() : std::runtime_error("Division by zero") {
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
				ModuloByZeroException(void) throw() : std::runtime_error("Modulo by zero") {}
				ModuloByZeroException(ModuloByZeroException const & src) throw() : std::runtime_error("Modulo by zero") {
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
				ModuloFloatException(void) throw() : std::runtime_error("Modulo by float") {}
				ModuloFloatException(ModuloFloatException const & src) throw() : std::runtime_error("Modulo by float") {
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
				LimitationPrecisionException(void) throw() : std::runtime_error("Limiation precision") {}
				LimitationPrecisionException(LimitationPrecisionException const & src) throw() : std::runtime_error("Limiation precision") {
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
				NanException(void) throw() : std::invalid_argument("Argument is not a number") {}
				NanException(NanException const & src) throw() : std::invalid_argument("Argument is not a number") {
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
				NotValidNumberException(void) throw() : std::invalid_argument("Argument is not a valid number") {}
				NotValidNumberException(NotValidNumberException const & src) throw() : std::invalid_argument("Argument is not a valid number") {
					*this = src;
				}
				NotValidNumberException & operator=(NotValidNumberException const & rhs) throw() {
					(void)rhs;
					return *this;
				}

				virtual ~NotValidNumberException(void) throw() {}
		};

		Operand(std::string const & value);

		virtual ~Operand(void) {}

		IOperand const * operator+( IOperand const & rhs ) const {
			return this->_builderOperand(rhs, std::stold(this->_stringStream.str()) + std::stold(rhs.toString()));
		}

		IOperand const * operator-( IOperand const & rhs ) const {
			return this->_builderOperand(rhs, std::stold(this->_stringStream.str()) - std::stold(rhs.toString()));
		}

		IOperand const * operator*( IOperand const & rhs ) const {
			return this->_builderOperand(rhs, std::stold(this->_stringStream.str()) * std::stold(rhs.toString()));
		}

		IOperand const * operator/( IOperand const & rhs ) const {
			if (this->_isZero(rhs.toString()))
				throw DivideByZeroException();
			return this->_builderOperand(rhs, std::stold(this->_stringStream.str()) / std::stold(rhs.toString()));
		}

		IOperand const * operator%( IOperand const & rhs ) const {
			if (rhs.getType() >= FLOAT || this->_type >= FLOAT)
				throw ModuloFloatException();
			if (this->_isZero(rhs.toString()))
				throw ModuloByZeroException();
			return this->_builderOperand(rhs, std::stoi(this->_stringStream.str()) % std::stoi(rhs.toString()));
		}

		int						getPrecision( void ) 	const { return this->_precision; }
		eOperandType			getType( void ) 		const { return this->_type; }

		bool 	isPositive(void) const {
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
