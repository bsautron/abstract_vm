#include <OperandBuilder.hpp>

OperandBuilder::OperandBuilder(void) {}
OperandBuilder::~OperandBuilder(void) {}

IOperand const * OperandBuilder::createInt8( std::string const & value ) const {
	return (new Operand<char>(value, INT8));
}
IOperand const * OperandBuilder::createInt16( std::string const & value ) const {
	return (new Operand<short>(value, INT16));
}
IOperand const * OperandBuilder::createInt32( std::string const & value ) const {
	return (new Operand<int>(value, INT32));
}
IOperand const * OperandBuilder::createFloat( std::string const & value ) const {
	return (new Operand<float>(value, FLOAT));
}
IOperand const * OperandBuilder::createDouble( std::string const & value ) const {
	return (new Operand<double>(value, DOUBLE));
}

IOperand const *	OperandBuilder::createOperand(eOperandType type, std::string const & value) const {
	IOperand const	* (OperandBuilder::*builder[5])(std::string const &) const = {
		&OperandBuilder::createInt8,
		&OperandBuilder::createInt16,
		&OperandBuilder::createInt32,
		&OperandBuilder::createFloat,
		&OperandBuilder::createDouble
	};

	return (this->*builder[type])(value);
}
