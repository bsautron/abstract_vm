/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 15:34:50 by bsautron          #+#    #+#             */
/*   Updated: 2016/06/08 17:35:59 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
# define OPERAND_HPP

# include "IOperand.hpp"

template<typename T>
class Operand : public IOperand {
	public:
		Operand( void ) : _precision(0), _type(ETYPE_NONE), _value(0) {}
		Operand(int precision, eOperandType type, T value) : _precision(precision), _type(type), _value(value) {}
		Operand(Operand<T> const & rhs) { *this = rhs; }

		virtual int						getPrecision( void ) const { return this->_precision; }
		virtual eOperandType			getType( void ) const { return this->_type; }

		virtual	IOperand	const			* operator+( IOperand const & rhs ) const {
			std::cout << "THE +" << std::endl;
			(void)rhs;
			return nullptr;
		}
//		virtual Operand<T>	const			* operator-( IOperand const & rhs ) const;
//		virtual Operand<T>	const			* operator*( IOperand const & rhs ) const;
//		virtual Operand<T>	const			* operator/( IOperand const & rhs ) const;
//		virtual Operand<T>	const			* operator%( IOperand const & rhs ) const;

		virtual std::string const &		toString( void ) const {
			std::string *s = new std::string("");

			*s = "This is teh operand (type: " + Operand<T>::type[this->_type] + " / precision: " + std::to_string(this->_precision) + ")\n";
			return (*s);
		}

		virtual							~Operand( void ) {}


	private:
		int				_precision;
		eOperandType	_type;
		T 				_value;

	static std::string type[5];
};

std::ostream		& operator<<( std::ostream & o, const IOperand & rhs );

template<typename T>
std::string	Operand<T>::type[5] = {
	"UInt8",
	"UInt16",
	"UInt32",
	"Float",
	"Double"
};
#endif
