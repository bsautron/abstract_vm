#include <Abstract.hpp>
#include <Operand.hpp>
#include <iostream>
#include <Debug.hpp>

Abstract::Abstract(void) { }
Abstract::~Abstract(void) {}

bool Abstract::isVerbose(void) const {
	return this->_verbose;
}

void Abstract::push(IOperand const * op) {
	this->push_front(op);
}
void Abstract::pop(void) {
	if (this->empty())
		throw StackEmptyException();
	this->pop_front();
}
void Abstract::assert(IOperand const & value) const {
	IOperand const * operand = this->front();
	if ( value.toString().compare(operand->toString()) || value.getType() != operand->getType())
		throw AssertException();
}
void Abstract::add(void) {

	if (this->size() < 2)
		throw StackTooShortException();

	IOperand const * op1 = this->front();
	this->pop();
	IOperand const * op2 = this->front();
	this->pop();

	this->push((*op2) + (*op1));
	this->_deleteOperand(op1);
	this->_deleteOperand(op2);
}
void Abstract::sub(void) {

	if (this->size() < 2)
		throw StackTooShortException();

	IOperand const * op1 = this->front();
	this->pop();
	IOperand const * op2 = this->front();
	this->pop();

	this->push((*op2) - (*op1));
	this->_deleteOperand(op1);
	this->_deleteOperand(op2);
}
void Abstract::div(void) {

	if (this->size() < 2)
		throw StackTooShortException();

	IOperand const * op1 = this->front();
	this->pop();
	IOperand const * op2 = this->front();
	this->pop();

	this->push((*op2) / (*op1));
	this->_deleteOperand(op1);
	this->_deleteOperand(op2);
}
void Abstract::mul(void) {

	if (this->size() < 2)
		throw StackTooShortException();

	IOperand const * op1 = this->front();
	this->pop();
	IOperand const * op2 = this->front();
	this->pop();

	this->push((*op2) * (*op1));
	this->_deleteOperand(op1);
	this->_deleteOperand(op2);
}
void Abstract::mod(void) {

	if (this->size() < 2)
		throw StackTooShortException();

	IOperand const * op1 = this->front();
	this->pop();
	IOperand const * op2 = this->front();
	this->pop();

	this->push((*op2) % (*op1));
	this->_deleteOperand(op1);
	this->_deleteOperand(op2);
}

void Abstract::print(void) {
	if (this->empty())
		throw StackEmptyException();

	IOperand const * operand = this->front();
	if (operand->getType() != INT8)
		throw AssertException();
	this->_stringStream << static_cast<char const>(std::stoi(operand->toString()));
}
void Abstract::dump() {
	std::deque<IOperand const *>::const_iterator operand = this->begin();

	while (operand != this->end()) {

		if (this->_verbose)
			this->_printVerboseOperand("dump", *operand);

		this->_stringStream << (*operand++)->toString() << std::endl;
	}
}

void Abstract::enableVerbose() {
	Debug::info("Enable verbse mode");
	this->_verbose = true;
}

void Abstract::disableVerbose() {
	Debug::info("Disable verbse mode");
	this->_verbose = false;
}

void Abstract::min() {
	if (this->empty())
		throw StackEmptyException();

	size_t posMin = 0;
	size_t pos = 0;
	long double minValue = std::stold(this->at(posMin)->toString());

	for (std::deque<IOperand const *>::const_iterator it = this->begin(); it != this->end(); ++it) {
		long double const current = std::stold((*it)->toString());

		if (current < minValue) {
			minValue = current;
			posMin = pos;
		}
		++pos;
	}

	if (this->_verbose)
		this->_printVerboseOperand("min", this->at(posMin));

	this->_stringStream << this->at(posMin)->toString() << std::endl;
}

void Abstract::max() {
	if (this->empty())
		throw StackEmptyException();

	size_t posMax = 0;
	size_t pos = 0;
	long double maxValue = std::stold(this->at(posMax)->toString());

	for (std::deque<IOperand const *>::const_iterator it = this->begin(); it != this->end(); ++it) {
		long double const current = std::stold((*it)->toString());

		if (current > maxValue) {
			maxValue = current;
			posMax = pos;
		}
		++pos;
	}

	if (this->_verbose)
		this->_printVerboseOperand("max", this->at(posMax));

	this->_stringStream << this->at(posMax)->toString() << std::endl;
}

void Abstract::swap() {

	if (this->size() < 2)
		throw StackTooShortException();

	IOperand const * op1 = this->front();
	this->pop();
	IOperand const * op2 = this->front();
	this->pop();

	this->push(op1);
	this->push(op2);
}

void Abstract::help(void) const {
	Debug::info("Helper");
}

void Abstract::fuckedup(void) {
	this->clear();
}

void Abstract::_deleteOperand(IOperand const * operand) {
	if (operand) {
		delete operand;
		operand = nullptr;
	}
}

void Abstract::_printVerboseOperand(std::string const & prefix, IOperand const * op) {
	this->_stringStream
		<< "[" << prefix << "]"
		<< " Type "
		<< Abstract::stringType[op->getType()]
		<< " - Precision: "
		<< op->getPrecision()
		<< " - Value: ";
}

std::stringstream & Abstract::getStringStream(void) {
	return this->_stringStream;
}

std::string		Abstract::stringType[5] = {
	"INT8",
	"INT16",
	"INT32",
	"FLOAT",
	"DOUBLE"
};

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
