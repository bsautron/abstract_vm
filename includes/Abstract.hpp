/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Abstract.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:04:49 by bsautron          #+#    #+#             */
/*   Updated: 2016/12/01 21:04:50 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACT_HPP
# define ABSTRACT_HPP

# include <sstream>
# include <string>
# include <deque>
# include <IOperand.hpp>
# include <cstdlib>
# include <OperandBuilder.hpp>
# include <map>
# include <token.hpp>
# include <vector>

# define DELETE_CPTR(X)		{delete X; X = nullptr;}

class Abstract : public std::deque<IOperand const *> {
	private:
		void				_deleteOperand(IOperand const * operand);
		std::stringstream	_stringStream;
		bool				_verbose;

		Abstract(Abstract const & src);
		Abstract & operator=(Abstract const & rhs);

		void	_printVerboseOperand(std::string const & prefix, IOperand const * op);

	public:
		Abstract(void);
		~Abstract(void);

		class StackEmptyException : public std::runtime_error {

			public:
				StackEmptyException(void) throw();
				StackEmptyException(StackEmptyException const & src) throw();
				StackEmptyException & operator=(StackEmptyException const & rhs) throw();

				virtual ~StackEmptyException(void) throw();

		};

		class StackTooShortException : public std::runtime_error {

			public:
				StackTooShortException(void) throw();
				StackTooShortException(StackTooShortException const & src) throw();
				StackTooShortException & operator=(StackTooShortException const & rhs) throw();

				virtual ~StackTooShortException(void) throw();

		};

		class AssertException : public std::runtime_error {

			public:
				AssertException(void) throw();
				AssertException(AssertException const & src) throw();
				AssertException & operator=(AssertException const & rhs) throw();

				virtual ~AssertException(void) throw();

		};

		void		push(IOperand const * op);
		void		pop(void);
		void		dump(void);
		void		assert(IOperand const & value) const;
		void		add(void);
		void		sub(void);
		void		div(void);
		void		mod(void);
		void		mul(void);
		void		print(void);
		void		min(void);
		void		max(void);
		void		swap(void);
		void		help(void) const;
		void		fuckedup(void);

		void		enableVerbose(void);
		void		disableVerbose(void);

		bool		isVerbose(void) const;


		std::stringstream & getStringStream(void);

		static std::string stringType[5];
};

#endif
