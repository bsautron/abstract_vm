#include <Abstract.hpp>
#include <Operand.hpp>
#include <iostream>

Abstract::Abstract(void) { }
Abstract::~Abstract(void) {}

void Abstract::Push(IOperand const * op) {
	this->push_front(op);
}
void Abstract::Pop(void) {
	if (this->empty())
		throw StackEmptyException();
	this->pop_front();
}
void Abstract::Assert(IOperand const & value) const {
	IOperand const * operand = this->front();
	if ( value.toString().compare(operand->toString()) || value.getType() != operand->getType())
		throw AssertException();
}
void Abstract::Add(void) {

	if (this->size() < 2)
		throw StackTooShortException();

	IOperand const * op1 = this->front();
	this->Pop();
	IOperand const * op2 = this->front();
	this->Pop();

	this->Push((*op2) + (*op1));
	this->_DeleteOperand(op1);
	this->_DeleteOperand(op2);
}
void Abstract::Sub(void) {

	if (this->size() < 2)
		throw StackTooShortException();

	IOperand const * op1 = this->front();
	this->Pop();
	IOperand const * op2 = this->front();
	this->Pop();

	this->Push((*op2) - (*op1));
	this->_DeleteOperand(op1);
	this->_DeleteOperand(op2);
}
void Abstract::Div(void) {

	if (this->size() < 2)
		throw StackTooShortException();

	IOperand const * op1 = this->front();
	this->Pop();
	IOperand const * op2 = this->front();
	this->Pop();

	this->Push((*op2) / (*op1));
	this->_DeleteOperand(op1);
	this->_DeleteOperand(op2);
}
void Abstract::Mul(void) {

	if (this->size() < 2)
		throw StackTooShortException();

	IOperand const * op1 = this->front();
	this->Pop();
	IOperand const * op2 = this->front();
	this->Pop();

	this->Push((*op2) * (*op1));
	this->_DeleteOperand(op1);
	this->_DeleteOperand(op2);
}
void Abstract::Mod(void) {

	if (this->size() < 2)
		throw StackTooShortException();

	IOperand const * op1 = this->front();
	this->Pop();
	IOperand const * op2 = this->front();
	this->Pop();

	this->Push((*op2) % (*op1));
	this->_DeleteOperand(op1);
	this->_DeleteOperand(op2);
}

void Abstract::Print(void) {
	if (this->empty())
		throw StackEmptyException();

	IOperand const * operand = this->front();
	if (operand->getType() != INT8)
		throw AssertException();
	this->_stringStream << static_cast<char const>(std::stoi(operand->toString()));
}
void Abstract::Dump() {
	std::deque<IOperand const *>::const_iterator operand = this->begin();

	while (operand != this->end()) {
		this->_stringStream << (*operand++)->toString() << std::endl;
	}
}

void Abstract::_DeleteOperand(IOperand const * operand) {
	if (operand) {
		delete operand;
		operand = nullptr;
	}
}

std::stringstream & Abstract::GetStringStream(void) {
	return this->_stringStream;
}

/* Exceptions */

Abstract::StackEmptyException::StackEmptyException(void) throw() : std::runtime_error("Stack empty") {}
Abstract::StackEmptyException::StackEmptyException(StackEmptyException const & src) throw() : std::runtime_error("Stack empty") {
	*this = src;
}
Abstract::StackEmptyException::~StackEmptyException(void) throw() {}

Abstract::StackEmptyException & Abstract::StackEmptyException::operator=(Abstract::StackEmptyException const & rhs) throw() {
	(void)rhs;
	return *this;
}

Abstract::StackTooShortException::StackTooShortException(void) throw() : std::runtime_error("Stack too short") {}
Abstract::StackTooShortException::StackTooShortException(StackTooShortException const & src) throw() : std::runtime_error("Stack too short") {
	*this = src;
}
Abstract::StackTooShortException::~StackTooShortException(void) throw() {}

Abstract::StackTooShortException & Abstract::StackTooShortException::operator=(Abstract::StackTooShortException const & rhs) throw() {
	(void)rhs;
	return *this;
}

Abstract::AssertException::AssertException(void) throw() : std::runtime_error("Assert failed") {}
Abstract::AssertException::AssertException(AssertException const & src) throw() : std::runtime_error("Assert failed") {
	*this = src;
}
Abstract::AssertException::~AssertException(void) throw() {}

Abstract::AssertException & Abstract::AssertException::operator=(Abstract::AssertException const & rhs) throw() {
	(void)rhs;
	return *this;
}
