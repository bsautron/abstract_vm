#include <Vm.hpp>
#include <Debug.hpp>

Vm::Vm(std::istream & is, std::ostream & os) :
	_inStream(is),
	_outStream(os),
	_abstract(Abstract(os))
	{
		(void)this->_abstract;
		(void)this->_inStream;
		(void)this->_outStream;
	}
Vm::~Vm(void) {}

//TODO: Excpetion line too large
void Vm::start(void) {
	Debug::Log("Start");
	char line[Vm::commandLenghtMax];

	while (this->_inStream.getline(line, Vm::commandLenghtMax)) {
		Debug::Log(line);
		std::vector<t_token *> tk = this->_lexer.getTokens(line);
		this->_parser.Exec(this->_abstract, tk);
		// this->Exec(this->_lexer.getTokens(line));
	}
}
int Vm::commandLenghtMax = 256;
