/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 19:12:14 by bsautron          #+#    #+#             */
/*   Updated: 2016/06/04 20:27:02 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Test.hpp>

Test::Test( void )
{
	this->_nb = 0;
	std::cout << "[Test]: constructor default " << std::endl;
}

Test::Test( int nb ) : _nb(nb)
{
	std::cout << "[Test]: constructor normal" << std::endl;
}

Test::Test( Test const & src )
{
	std::cout << "[Test]: constructor copy" << std::endl;
	*this = src;
}

Test	& Test::operator=( Test const & rhs )
{
	std::cout << "[Test]: assignement " <<std::endl;
	this->_nb = rhs.getNb();

	return (*this);
}

Test::~Test( void )
{
	std::cout << "[Test]: destructor" << std::endl;
}




int		Test::getNb( void ) const
{
	return (this->_nb);
}

std::ostream	& operator<<( std::ostream & o, Test const & rhs )
{
	o << rhs.getNb();
	return (o);
}
