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

#include "abstract_vm.hpp"

int main(void)
{
	// Operand<float>	a("0.23", FLOAT);
	Lexer				a;
	std::string	b = "push  int4(234.3)";

	a.getTokens(b);
	return (0);
}
