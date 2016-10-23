/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 14:35:07 by bsautron          #+#    #+#             */
/*   Updated: 2016/07/08 12:39:57 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <abstract_vm.hpp>

// TODO: Lowercase first letter of members function
// TODO: Add static variable to enable multi error - Can't you parse en command to set this?
int main(void)
{
	std::istream & i = std::cin;
	std::ostream & o = std::cout;

	Vm	vm(i, o);
	Vm.start();

	return (0);
}
