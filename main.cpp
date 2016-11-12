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
#include <fstream>

// TODO: Lowercase first letter of members function
// TODO: Add static variable to enable multi error - Can't you parse en command to set this?
int main(int ac, char **av)
{
	std::ifstream	ifs (av[1]);
	std::istream	& inStream = (ac > 1 && ifs.good()) ? ifs : std::cin;
	std::ostream	& outStream = std::cout;
	int				ret;

	Vm	vm{inStream, outStream};

	ret = vm.start();
	if (ifs.good())
		ifs.close();
	return (ret);
}
