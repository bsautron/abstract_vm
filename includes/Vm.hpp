#ifndef VM_HPP
# define VM_HPP

# include <istream>
# include <ostream>
# include <string>
# include <deque>
# include <MyException.hpp>
# include <IOperand.hpp>

# define DELETE_CPTR(X)		{delete X; X = nullptr;}

class Vm : public std::deque<IOperand const *> {
	private:
		void 	_Start(void);
		void 	_DeleteOperand(IOperand const * operand);

	public:
		Vm (void);
		~Vm (void);

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
