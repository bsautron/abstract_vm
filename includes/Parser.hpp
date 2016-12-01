/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:05:24 by bsautron          #+#    #+#             */
/*   Updated: 2016/12/01 21:05:25 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
# define PARSER_HPP

# include <IOperand.hpp>
# include <Abstract.hpp>
# include <Lexer.hpp>
# include <list>
# include <OperandBuilder.hpp>

class Parser {
	private:
		std::list<t_tokens>		_listCommand;
		OperandBuilder			_builder;
		bool					_end;

		Parser(Parser const * src);
		Parser & operator=(Parser const & rhs);

		int				_strToCommandType(std::string const str) const;
		eOperandType	_strToOperandType(std::string const str) const;
		std::string		_tokensToStr(t_tokens tk) const;


	public:
		Parser (void);
		~Parser (void);

		int			exec(Abstract & abstract);
		void		feed(t_tokens tk);

		void		push(Abstract & abstract, IOperand const * op);
		void		pop(Abstract & abstract, IOperand const * op);
		void		dump(Abstract & abstract, IOperand const * op);
		void		assert(Abstract & abstract, IOperand const * op);
		void		add(Abstract & abstract, IOperand const * op);
		void		sub(Abstract & abstract, IOperand const * op);
		void		div(Abstract & abstract, IOperand const * op);
		void		mod(Abstract & abstract, IOperand const * op);
		void		mul(Abstract & abstract, IOperand const * op);
		void		print(Abstract & abstract, IOperand const * op);
		void		exit(Abstract & abstract, IOperand const * op);
		void		comment(Abstract & abstract, IOperand const * op);
		void		verbose(Abstract & abstract, IOperand const * op);
		void		min(Abstract & abstract, IOperand const * op);
		void		max(Abstract & abstract, IOperand const * op);
		void		swap(Abstract & abstract, IOperand const * op);
		void		help(Abstract & abstract, IOperand const * op);
		void		fuckedup(Abstract & abstract, IOperand const * op);

		static	bool		abortException;

		class Command404Exception : public std::invalid_argument {

			public:
				Command404Exception(void) throw();
				Command404Exception(Command404Exception const & src) throw();
				Command404Exception & operator=(Command404Exception const & rhs) throw();

				virtual ~Command404Exception(void) throw();
		};

		class Operand404Exception : public std::invalid_argument {

			public:
				Operand404Exception(void) throw();
				Operand404Exception(Operand404Exception const & src) throw();
				Operand404Exception & operator=(Operand404Exception const & rhs) throw();

				virtual ~Operand404Exception(void) throw();
		};

		class ArgumentNotValidException : public std::invalid_argument {

			public:
				ArgumentNotValidException(void) throw();
				ArgumentNotValidException(ArgumentNotValidException const & src) throw();
				ArgumentNotValidException & operator=(ArgumentNotValidException const & rhs) throw();

				virtual ~ArgumentNotValidException(void) throw();
		};

};

#endif
