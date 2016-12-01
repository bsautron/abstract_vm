/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 14:35:07 by bsautron          #+#    #+#             */
/*   Updated: 2016/12/01 21:06:59 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <istream>
#include <ostream>
#include <Operand.hpp>
#include <Vm.hpp>
#include <Lexer.hpp>
#include <Parser.hpp>
#include <Debug.hpp>

int main(int ac, char **av)
{
	Operand<float>::assumePrecision = false;
	Operand<double>::assumePrecision = false;
	Lexer::commandLengthMax = 256;
	Parser::abortException = false;

	std::istream	& inStream = std::cin;
	std::ostream	& outStream = std::cout;

	Vm	vm{inStream, outStream};

	try {
		for (int i = 1; i < ac; ++i) {
			std::ifstream	ifs(av[i]);
			if (!ifs.good()) {
				Debug::fatal("If you want I process your files, give me good files!!!");
				return (1);
			}
			vm.feedInStream(ifs, false);
			ifs.close();
		}
		return vm.start();
	}
	catch (std::exception const & e) {
		Debug::fatal(std::string(e.what()));
		return (1);
	}
	return (0);
}
