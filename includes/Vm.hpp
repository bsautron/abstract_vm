/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vm.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:05:29 by bsautron          #+#    #+#             */
/*   Updated: 2016/12/01 21:05:30 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_HPP
# define VM_HPP

# include <Lexer.hpp>
# include <Parser.hpp>
# include <Abstract.hpp>
# include <OperandBuilder.hpp>
# include <list>

typedef struct	s_errors {
	size_t					nbLine;
	std::string	const		message;
}				t_errors;

class Vm {
	private:
		std::istream &	_inStream;
		std::ostream &	_outStream;
		Abstract		_abstract;
		Lexer			_lexer;
		Parser			_parser;
		int				_statusLexer;
		int				_statusParser;
		OperandBuilder	_builder;
		size_t			_nbLine;
		t_tokens		_currentTk;
		bool			_alreadyReadNativeStream;


		Vm(void);
		Vm(Vm const & src);
		Vm & operator=(Vm const & rhs);

	public:
		Vm(std::istream & is, std::ostream & os);
		~Vm(void);

		void	feedInStream(std::istream & inStream, bool stdIn);

		int start(void);

		class BigLineException : public std::length_error {

			public:
				BigLineException(void) throw();
				BigLineException(BigLineException const & src) throw();
				BigLineException & operator=(BigLineException const & rhs) throw();

				virtual ~BigLineException(void) throw();
		};
		class NotExitTerminateException : public std::runtime_error {

			public:
				NotExitTerminateException(void) throw();
				NotExitTerminateException(NotExitTerminateException const & src) throw();
				NotExitTerminateException & operator=(NotExitTerminateException const & rhs) throw();

				virtual ~NotExitTerminateException(void) throw();
		};
};

#endif
