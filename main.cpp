/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 14:35:07 by bsautron          #+#    #+#             */
/*   Updated: 2016/11/19 13:37:01 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <abstract_vm.hpp>
#include <fstream>
#include <Debug.hpp>

// TODO: Lowercase first letter of members function
// TODO: Add static variable to enable multi error - Can't you parse en command to set this?
int main(int ac, char **av)
{
	std::ifstream	ifs (av[1]);
	std::istream	& inStream = (ac > 1 && ifs.good()) ? ifs : std::cin;
	std::ostream	& outStream = std::cout;
	int				ret = 0;

	Vm	vm{inStream, outStream};

	try {
//		ret = vm.start();
		throw Lexer::LexicalError();
	}
	catch (std::exception const & e) {
		Debug::Fatal(std::string(e.what()));
		ret = 1;
	}
	if (ifs.good())
		ifs.close();
	return (ret);
}
