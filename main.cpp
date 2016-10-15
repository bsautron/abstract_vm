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

int main(void)
{
	Vm	vm;
	try {
		// TODO: Add static variable to enable multi error - Can't you parse en command to set this?
		Operand<double>::assumePrecision = true;
		vm.Push(new Operand<char>{"112"});
		vm.Print();
		vm.Push(new Operand<char>{"100"});
		vm.Print();

	} catch (std::exception const & e) {
		std::cout << "VM error: " << e.what() << std::endl;
		std::cout << "Stack trace:" << std::endl;

		vm.Dump();

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
