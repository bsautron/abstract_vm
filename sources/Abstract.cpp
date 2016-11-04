#include <Abstract.hpp>
#include <Operand.hpp>
#include <iostream>

Abstract::Abstract(std::ostream & os) : _outStream(os) {}
Abstract::~Abstract(void) {}

void Abstract::Push(IOperand const * op) {
	this->push_front(op);
}
void Abstract::Pop(void) {
	if (this->empty())
		throw MyException(EXC_STACK_EMPTY);
	this->pop_front();
}
void Abstract::Assert(IOperand const & value) const {
	IOperand const * operand = this->front();
	if ( value.toString().compare(operand->toString()) || value.getType() != operand->getType())
		throw MyException(EXC_ASSERT_FAILED);
}
void Abstract::Add(void) {

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
void Abstract::Sub(void) {

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
void Abstract::Div(void) {

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
void Abstract::Mul(void) {

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
void Abstract::Mod(void) {

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

void Abstract::Print(void) const {
	if (this->empty())
		throw MyException(EXC_STACK_EMPTY);

	IOperand const * operand = this->front();
	if (operand->getType() != INT8)
		throw MyException(EXC_ASSERT_FAILED);
	this->_outStream << static_cast<char>(std::stoi(operand->toString()));
}
void Abstract::Dump(void) const {
	this->_outStream << "----- DUMP -----" << std::endl;
	std::deque<IOperand const *>::const_iterator operand = this->begin();

	while (operand != this->end()) {
		this->_outStream << (*operand++)->toString() << std::endl;
	}
	this->_outStream << "--- End DUMP ---" << std::endl;
}

void Abstract::Exit(void) const {
	_Exit(0);
}

void Abstract::_DeleteOperand(IOperand const * operand) {
	if (operand) {
		delete operand;
		operand = nullptr;
	}
	else
		throw MyException(EXC_TMP);
}
