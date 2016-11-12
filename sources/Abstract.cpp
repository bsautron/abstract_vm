#include <Abstract.hpp>
#include <Operand.hpp>
#include <iostream>

Abstract::Abstract(void) {}
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
	char const c = static_cast<char const>(std::stoi(operand->toString()));
	this->_stringStream = this->_ConcatStream(c);
}
void Abstract::Dump(void) const {
	std::deque<IOperand const *>::const_iterator operand = this->begin();

	while (operand != this->end()) {
		this->_stringStream = this->_ConcatStream((*operand++)->toString() + '\n');
	}
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

std::stringstream	Abstract::_ConcatStream(char const c) const {
	std::stringstream newStringString;

	newStringString << this->_stringStream << c;
	return newStringString;
}
std::stringstream	Abstract::_ConcatStream(std::string const str) const {
	std::stringstream newStringString;

	newStringString << this->_stringStream << str;
	return newStringString;
}


std::stringstream & Abstract::GetStringStream(void) {
	return this->_stringStream;
}
