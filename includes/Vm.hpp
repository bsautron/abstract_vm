#ifndef VM_HPP
# define VM_HPP

# include <iostream>
# include <string>
# include <deque>
# include <MyException.hpp>
# include <IOperand.hpp>

class Vm : public std::deque<IOperand const *> {
	private:
		int		_fd;

		void 	_Start(void);

	public:
		Vm (void);
		~Vm (void);

		void 	Push(IOperand const * op);
		void 	Pop(void);
		void 	Dump(void) const;
		// void 	Assert(IOperand const * op);
		// void 	Add(void);

	static void 	DeleteOperand(IOperand const * operand) {
		if (operand)
			delete operand;
		else
			throw MyException(EXV_TMP);
	}

};

#endif
