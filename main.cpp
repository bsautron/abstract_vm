/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 14:35:07 by bsautron          #+#    #+#             */
/*   Updated: 2016/11/19 22:04:19 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <abstract_vm.hpp>
#include <fstream>
#include <Debug.hpp>

// TODO: Lowercase first letter of members function
// TODO: Add static variable to enable multi error - Can't you parse en command to set this?
// TODO: Attention pour la precision, prend la plus grand precision pour la virgule et pour le type
int main(int ac, char **av)
{
	Operand<float>::assumePrecision = false;
	Operand<double>::assumePrecision = false;
	Lexer::commandLengthMax = 256;
	Parser::abortException = true;

	std::ifstream	ifs (av[1]);
	std::istream	& inStream = (ac > 1 && ifs.good()) ? ifs : std::cin;
	std::ostream	& outStream = std::cout;

	Vm	vm{inStream, outStream};
	int				ret = 0;

	try {
		ret = vm.start();
	}
	catch (std::exception const & e) {
		Debug::Fatal(std::string(e.what()));
		ret = 1;
	}

	if (ifs.good())
		ifs.close();
	
	return (ret);
}
