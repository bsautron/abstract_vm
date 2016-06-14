#include "OperandBuilder.hpp"

OperandBuilder::OperandBuilder(void) {}
OperandBuilder::~OperandBuilder(void) {}

IOperand const * OperandBuilder::createInt8( std::string const & value ) const {
	return new Operand<char>(sizeof(char), ETYPE_INT8, static_cast<char>(std::stoi(value)));
}
IOperand const * OperandBuilder::createInt16( std::string const & value ) const {
	return new Operand<short>(sizeof(short), ETYPE_INT16, static_cast<short>(std::stoi(value)));
}
IOperand const * OperandBuilder::createInt32( std::string const & value ) const {
	return new Operand<int>(sizeof(int), ETYPE_INT32, std::stoi(value));
}
IOperand const * OperandBuilder::createFloat( std::string const & value ) const {
	return new Operand<float>(sizeof(float), ETYPE_FLOAT, std::stof(value));
}
IOperand const * OperandBuilder::createDouble( std::string const & value ) const {
	return new Operand<double>(sizeof(double), ETYPE_DOUBLE, std::stod(value));
}

IOperand const *	OperandBuilder::createOperand(eOperandType type, std::string const & value) const {
	IOperand const	* (OperandBuilder::*builder[5])(std::string const &) const = {
		&OperandBuilder::createInt8,
		&OperandBuilder::createInt16,
		&OperandBuilder::createInt32,
		&OperandBuilder::createFloat,
		&OperandBuilder::createDouble
	};

	// IOperand const	* (OperandBuilder::*builder)(std::string const &) const;

	// builder = &OperandBuilder::createInt8;
	return (this->*builder[type])(value);
}
