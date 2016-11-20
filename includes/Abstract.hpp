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
		void 				_DeleteOperand(IOperand const * operand);
		std::stringstream	_stringStream;

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

		void 	Push(IOperand const * op);
		void 	Pop(void);
		void 	Dump(void);
		void 	Assert(IOperand const & value) const;
		void 	Add(void);
		void 	Sub(void);
		void 	Div(void);
		void 	Mod(void);
		void 	Mul(void);
		void 	Print(void);

		//		void	Min(void);
		//		void	Max(void);
		//		void	Swap(void);
		//		void	Inverse(void);

		std::stringstream & GetStringStream(void);
};

#endif
