#ifndef VM_HPP
# define VM_HPP

# include <iostream>
# include <string>
# include <deque>
# include <IOperand.hpp>

class Vm : public std::deque<IOperand const *> {
	private:
		int											_fd;

		void 	_Start(void);

	public:
		Vm (void);
		~Vm (void);

		void 		Dump(void);
		void 		Push(IOperand const * op);
		void 		Pop(void);
		void 		Add(void);

};

#endif
