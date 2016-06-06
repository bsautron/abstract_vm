#include <Operand.tpp>

template<typename T>
Operand<T>::Operand( int precision, eOperandType type, T value ) :
	_precision(precision),
	_type(type),
	_value(value) {
	std::cout << "[Operand]: constructor type: " << Operand<T>::type[this->_type] << " precision: " << precision <<  std::endl;
}

template<typename T>
Operand<T>::Operand( Operand const & rhs ) {
	std::cout << "[Operand]: constructor COPY" << std::endl;
	*this = rhs;
}


template<typename T> int			Operand<T>::getPrecision(void) const { return this->_precision; }
template<typename T> eOperandType	Operand<T>::getType(void) const { return this->_type; }

template <typename T>
std::string const	& Operand<T>::toString(void) const {
	std::string *s = new std::string("");

	*s = "This is teh operand (type: " + Operand<T>::type[this->_type] + " / precision: " + std::to_string(this->_precision) + ")\n";
	return (*s);
}

template<typename T>
IOperand const		* Operand<T>::operator+( IOperand const & rhs ) const {
	std::cout << "THE +" << std::endl;
	(void)rhs;
	return nullptr;
}
template<typename T>
IOperand const		* Operand<T>::operator-( IOperand const & rhs ) const {
	std::cout << "THE -" << std::endl;
	(void)rhs;
	return nullptr;
}
template<typename T>
IOperand const		* Operand<T>::operator*( IOperand const & rhs ) const {
	std::cout << "THE *" << std::endl;
	(void)rhs;
	return nullptr;
}
template<typename T>
IOperand const		* Operand<T>::operator/( IOperand const & rhs ) const {
	std::cout << "THE /" << std::endl;
	(void)rhs;
	return nullptr;
}
template<typename T>
IOperand const		* Operand<T>::operator%( IOperand const & rhs ) const {
	std::cout << "THE modulo" << std::endl;
	(void)rhs;
	return nullptr;
}

std::ostream		& operator<<( std::ostream & o, IOperand const & rhs )
{
	o << rhs.toString();
	return (o);
}


template<typename T>
std::string	Operand<T>::type[5] = {
	"UInt8",
	"UInt16",
	"UInt32",
	"Float",
	"Double"
};
