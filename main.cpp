/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 14:35:07 by bsautron          #+#    #+#             */
/*   Updated: 2016/06/08 16:28:51 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "abstract_vm.hpp"

int main(void)
{
	OperandBuilder	op;
	IOperand	const *a = op.createOperand(ETYPE_INT8, "5.3");

	(void)a;
	return (0);
}
