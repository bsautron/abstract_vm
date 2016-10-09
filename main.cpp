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

	try {
		Operand<float>	a("34.2349857");
		Operand<int>	b("12");
		Operand<char>	c("-1000");
		std::cout << "/* message */" << std::endl;
	} catch (std::exception const & e) {
		std::cout << e.what() << std::endl;
	}
	// Vm		vm;

	// try {
	// 	OperandBuilder	bob;
	//
	// 	IOperand const * op1 = bob.createOperand(INT8, "1");
	// 	(void)op1;
	// 	// IOperand const * op2 = bob.createOperand(FLOAT, "2.44");
	// 	// IOperand const * op3 = bob.createOperand(INT8, "4");
	// 	// vm.Push(op1);
	// 	// vm.Push(op2);
	// 	// vm.Push(op3);
	// 	// vm.Add();
	// 	// vm.Dump();
	// } catch (std::exception const & e) {
	// 	std::cout << "ERROR: " << e.what() << std::endl;
	// };
	return (0);
}
