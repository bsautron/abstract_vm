#include <Operand.tpp>

template<typename T>
Operand::Operand( int precision, eOperandType type, T value ) :
	_precision(precision),
	_type(type),
	_value(value){
	std::cout << "[Operand]: constructor type: " << Operand::type[this->_type] << " precision: " << precision <<  std::endl;
}

Operand::Operand( Operand const & rhs ) {
	std::cout << "[Operand]: constructor COPY" << std::endl;
	*this = rhs;
}




int				Operand::getPrecision(void) const { return this->_precision; }
eOperandType	Operand::getType(void) const { return this->_type; }


std::string const	& Operand::toString(void) const {
	std::string *s = new std::string("");

	*s = "This is teh operand (type: " + Operand::type[this->_type] + " / precision: " + std::to_string(this->_precision) + ")\n";
	return (*s);
}


IOperand const		* Operand::operator+( IOperand const & rhs ) const {
	std::cout << "THE +" << std::endl;
	(void)rhs;
	return nullptr;
}
IOperand const		* Operand::operator-( IOperand const & rhs ) const {
	std::cout << "THE -" << std::endl;
	(void)rhs;
	return nullptr;
}
IOperand const		* Operand::operator*( IOperand const & rhs ) const {
	std::cout << "THE *" << std::endl;
	(void)rhs;
	return nullptr;
}
IOperand const		* Operand::operator/( IOperand const & rhs ) const {
	std::cout << "THE /" << std::endl;
	(void)rhs;
	return nullptr;
}
IOperand const		* Operand::operator%( IOperand const & rhs ) const {
	std::cout << "THE modulo" << std::endl;
	(void)rhs;
	return nullptr;
}

std::ostream		& operator<<( std::ostream & o, Operand const & rhs )
{
	o << rhs.toString();
	return (o);
}


std::string	Operand::type[5] = {
	"UInt8",
	"UInt16",
	"UInt32",
	"Float",
	"Double"
};
