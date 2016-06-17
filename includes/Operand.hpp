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

# include <IOperand.hpp>
# include <NumberChecker.hpp>
# include <regex>

template<typename T>
class Operand : public IOperand {
	public:
		Operand(int precision, eOperandType type, std::string const & value) : _precision(precision), _type(type) {
			this->checkValue(value);
			this->_value = 0;
			std::string s = "Create operand (type: " + Operand<T>::type[this->_type] + " / precision: " + std::to_string(this->_precision) + ")";
			std::cout << s << std::endl;
			std::cout << value << std::endl;
		}
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

		void checkValue(std::string const & value) {
			std::regex	e("[\\d]+(.[\\d]+)?");

			if (!std::regex_match(value, e))
				throw std::string("Not a number");
		}

		virtual std::string const &		toString( void ) const {
			std::string *s = new std::string("");

			*s = "This is teh operand (type: " + Operand<T>::type[this->_type] + " / precision: " + std::to_string(this->_precision) + ")\n";
			return (*s);
		}

		Operand(void);
		virtual							~Operand( void ) {}


	private:
		int				_precision;
		eOperandType	_type;
		T 				_value;

	static std::string type[5];
};

std::ostream		& operator<<( std::ostream & o, const IOperand & rhs );


#endif
