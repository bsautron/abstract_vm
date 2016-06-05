/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 19:08:46 by bsautron          #+#    #+#             */
/*   Updated: 2016/06/04 20:13:13 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Test {
	public:
		Test( void );
		Test( int nb );
		Test( Test const & src );
		~Test( void );

		Test & operator=( Test const & rhs );

		int		getNb( void ) const;


	private:
		int		_nb;
};

std::ostream	& operator<<( std::ostream & o, Test const & rhs );
