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
#include <sstream>

int main(void)
{
	try {
		// Operand<char>	a("44");
		// Operand<short>	b("12");
		// Operand<int>	c("-1000");
		// Operand<float>	d("345.257");
		// Operand<double>	e("3049582093.123");
		//
		// IOperand const * op = a + b;
		// std::cout << "op: " << *op << std::endl;

		Operand<float>	f("123.19384759371938475937193847593719384759371938475937193847593719384759371938475937193847593719384759371938475937193847593719384759371938475937193847593719384759371938475937193847593719384759371938475937");

		std::cout << f << std::endl;

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
