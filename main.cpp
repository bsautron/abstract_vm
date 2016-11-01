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
	// std::istream & i = std::cin;
	// std::ostream & o = std::cout;

	// Vm	vm(i, o);
	// Vm.start();

	Lexer	l;
	std::vector<t_token *> tk;

	std::string tkName[6] = {
		"TK_NONE",
		"TK_COMMAND",
		"TK_OPERAND",
		"TK_ARGS",
		"TK_COMMENT",
		"TK_EXIT"
	};

	try {
		tk = l.getTokens("()");
		for (std::vector<t_token *>::iterator it = tk.begin() ; it != tk.end(); ++it) {
			std::cout << tkName[(*it)->type] << ": " << (*it)->value << std::endl;
		}

	} catch (const char *e) {
		std::cout << e << std::endl;
		return (1);
	}
	return (0);
}
