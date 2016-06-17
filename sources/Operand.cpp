#include <Operand.hpp>

std::ostream		& operator<<( std::ostream & o, const IOperand & rhs ){
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
