#include "Operand.hpp"

std::ostream		& operator<<( std::ostream & o, const IOperand & rhs ){
	o << rhs.toString();
	return (o);
}

// void name(void) {
//
// }
