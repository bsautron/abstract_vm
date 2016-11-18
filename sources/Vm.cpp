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

int Vm::start(void) {
	std::string	line;
	int nbLine = 0;
	int retLexer = 0;
	int retParser = 0;
	int	ret = 0;
	t_tokens currentTk;

	while (std::getline(this->_inStream, line) && line.compare(";;")) {
		if (line.size() > Lexer::commandLengthMax) {
			throw MyException(EXC_LINE_TOO_LONG);
		}
		nbLine++;
		try {
			currentTk = this->_lexer.getTokens(line);
			this->_parser.feed(currentTk);
		} catch (MyException const & e) {
			this->_listError.push_back({nbLine, e});
		}
	}
	for (t_listError::const_iterator itErr = this->_listError.begin(); itErr != this->_listError.end(); ++itErr) {
		std::stringstream	s;
		s << "Line " << itErr->line << ": " << itErr->exception.what();
		Debug::Error(s.str());
	}
	if (!currentTk.size() || currentTk[0]->value.compare("exit")) {
		throw MyException(EXC_NOT_END_EXIT);
	}
	retLexer = this->_listError.size();
	retParser = this->_parser.exec(this->_abstract);
	ret = retLexer | retParser;
	if (!ret) {
		this->_outStream << this->_abstract.GetStringStream().str();
	}
	return (ret);
}
int Vm::commandLenghtMax = 256;
