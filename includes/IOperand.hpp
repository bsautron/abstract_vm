/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 19:01:34 by bsautron          #+#    #+#             */
/*   Updated: 2016/06/08 17:36:00 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

typedef enum {
	ETYPE_NONE,
	ETYPE_INT8,
	ETYPE_INT16,
	ETYPE_INT32,
	ETYPE_FLOAT,
	ETYPE_DOUBLE,
} eOperandType;

class IOperand {
	public:
		virtual int						getPrecision( void ) const = 0;
		virtual eOperandType			getType( void ) const = 0;

		virtual IOperand const			* operator+( IOperand const & rhs ) const = 0;
//		virtual IOperand const			* operator-( IOperand const & rhs ) const = 0;
//		virtual IOperand const			* operator*( IOperand const & rhs ) const = 0;
//		virtual IOperand const			* operator/( IOperand const & rhs ) const = 0;
//		virtual IOperand const			* operator%( IOperand const & rhs ) const = 0;

		virtual std::string const &		toString( void ) const = 0;

		virtual							~IOperand( void ) {}
};
