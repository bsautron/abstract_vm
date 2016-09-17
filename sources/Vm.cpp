#include <Vm.hpp>

Vm::Vm(void) : _fd(0) {}
Vm::~Vm(void) {}

void 			Vm::Push(IOperand const * op) {
	this->push_front(op);
}
void 			Vm::Pop(void) {
	this->pop_front();
}
void 			Vm::Add(void) {

	if (this->size() >= 2) {
		// IOperand 		* op1 = this[0];
		// IOperand 		* op2 = this[1];
		std::cout << (*this)[0]->toString() << std::endl;
		std::cout << (*this)[0]->toString() << std::endl;
		std::cout << (*this)[0]->toString() << std::endl;
		std::cout << (*this)[0]->toString() << std::endl;
	}
}
void 			Vm::Dump(void) {
	for (auto & op : *this)
			std::cout << op->toString() << std::endl;
}
