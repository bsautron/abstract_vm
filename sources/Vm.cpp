#include <Vm.hpp>
#include <Operand.hpp>
#include <iostream>

Vm::Vm(void) {}
Vm::~Vm(void) {}

void Vm::Push(IOperand const * op) {
	this->push_front(op);
}
void Vm::Pop(void) {
	if (this->empty())
		throw MyException(EXC_STACK_EMPTY);
	this->pop_front();
}
void Vm::Assert(IOperand const & value) const {
	if ( value.toString().compare(this->front()->toString()) || value.getType() != this->front()->getType())
		throw MyException(EXC_ASSERT_FAILED);
}
void Vm::Add(void) {

	if (this->size() < 2)
		throw MyException(EXC_TO_SHORT);

	IOperand const * op1 = this->front();
	this->Pop();
	IOperand const * op2 = this->front();
	this->Pop();

	this->Push((*op1) + (*op2));
	this->_DeleteOperand(op1);
	this->_DeleteOperand(op2);
}
void Vm::Sub(void) {

	if (this->size() < 2)
		throw MyException(EXC_TO_SHORT);

	IOperand const * op1 = this->front();
	this->Pop();
	IOperand const * op2 = this->front();
	this->Pop();

	this->Push((*op1) - (*op2));
	this->_DeleteOperand(op1);
	this->_DeleteOperand(op2);
}
void Vm::Div(void) {

	if (this->size() < 2)
		throw MyException(EXC_TO_SHORT);

	IOperand const * op1 = this->front();
	this->Pop();
	IOperand const * op2 = this->front();
	this->Pop();

	this->Push((*op1) / (*op2));
	this->_DeleteOperand(op1);
	this->_DeleteOperand(op2);
}
void Vm::Mul(void) {

	if (this->size() < 2)
		throw MyException(EXC_TO_SHORT);

	IOperand const * op1 = this->front();
	this->Pop();
	IOperand const * op2 = this->front();
	this->Pop();

	this->Push((*op1) * (*op2));
	this->_DeleteOperand(op1);
	this->_DeleteOperand(op2);
}
void Vm::Mod(void) {

	if (this->size() < 2)
		throw MyException(EXC_TO_SHORT);

	IOperand const * op1 = this->front();
	this->Pop();
	IOperand const * op2 = this->front();
	this->Pop();

	this->Push((*op1) % (*op2));
	this->_DeleteOperand(op1);
	this->_DeleteOperand(op2);
}

void Vm::Print(void) const {
	if (this->empty())
		throw MyException(EXC_STACK_EMPTY);

	IOperand const * operand = this->front();
	if (operand->getType() != INT8)
		throw MyException(EXC_ASSERT_FAILED);
	std::cout << static_cast<char>(std::stoi(operand->toString()));
}
void Vm::Dump(void) const {
	std::cout << "----- DUMP -----" << std::endl;
	std::deque<IOperand const *>::const_iterator operand = this->begin();

	while (operand != this->end()) {
		std::cout << (*operand++)->toString() << std::endl;
	}
	std::cout << "--- End DUMP ---" << std::endl;
}

void Vm::_DeleteOperand(IOperand const * operand) {
	if (operand) {
		delete operand;
		operand = nullptr;
	}
	else
		throw MyException(EXC_TMP);
}
