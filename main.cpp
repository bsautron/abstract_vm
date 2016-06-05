#include <abstract_vm.hpp>

int main(void)
{
	Operand		a = Operand(3, ETYPE_INT8);
	std::cout << a << std::endl;
	return (0);
}
