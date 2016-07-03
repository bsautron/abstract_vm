#include <Vm.hpp>

Vm::Vm(void) : _fd(0) {
	this->_welcome();
}

Vm::Vm(std::string const & fileName) : _fileName(fileName) {
	this->_welcome();
}

Vm::~Vm(void) {}

void 		Vm::_Welcome(void) {
	std::cout << "Welcome to ABSTRACT_VM :)" << std::endl;
	std::cout << "\tFROM: ";
	if (this->_fileName)
		std::cout << this->_fileName;
	else
		std::cout << "stdin";
	std::cout << std::endl;
}
