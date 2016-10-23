#ifndef VM_HPP
# define VM_HPP

# include <ostream>
# include <istream>
# include <string>
# include <deque>
# include <MyException.hpp>
# include <IOperand.hpp>

# define DELETE_CPTR(X)		{delete X; X = nullptr;}

class Vm : public std::deque<IOperand const *> {
	private:
		std::ostream &	_outstream;
		std::istream &	_instream;
		Lexer			_lexer;
		Parser			_parser;

		void 	_DeleteOperand(IOperand const * operand);

	public:
		Vm(std::ostream & os);
		~Vm(void);

		void 	start(void);

		void 	Push(IOperand const * op);
		void 	Pop(void);
		void 	Dump(void) const;
		void 	Assert(IOperand const & value) const;
		void 	Add(void);
		void 	Sub(void);
		void 	Div(void);
		void 	Mod(void);
		void 	Mul(void);
		void 	Print(void) const;
};

#endif
