#include <Vm.hpp>
#include <Debug.hpp>

Vm::Vm(std::istream & is, std::ostream & os) :
	_inStream(is),
	_outStream(os)
	{
		(void)this->_abstract;
		(void)this->_inStream;
		(void)this->_outStream;
	}
Vm::~Vm(void) {}

//TODO: Excpetion line too large
int Vm::start(void) {
	// Debug::Log("Start");
	char line[Vm::commandLenghtMax];
	int nbLine = 0;

	while (this->_inStream.getline(line, Vm::commandLenghtMax)) {
		nbLine++;
		// Debug::Log(line);
		try {
			this->_parser.feed(this->_lexer.getTokens(line));
		} catch (MyException const e) {
			this->_listError.push_back({nbLine, e});
		}
	}
	for (t_listError::const_iterator itErr = this->_listError.begin(); itErr != this->_listError.end(); ++itErr) {
		std::cout << "Line " << itErr->line << ": " << itErr->exception.what() << std::endl;
	}
	this->_parser.exec(this->_abstract);
	this->_outStream << this->_abstract.GetStringStream().str();
	return (0);
}
int Vm::commandLenghtMax = 256;
