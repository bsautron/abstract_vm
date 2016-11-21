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
	size_t nbLine = 0;
	int retLexer = 0;
	int retParser = 0;
	int	ret = 0;
	t_tokens currentTk;
	std::list<t_errors> errors;

	while (std::getline(this->_inStream, line) && line.compare(";;")) {
		++nbLine;
		if (line.size() > Lexer::commandLengthMax) {
			throw BigLineException();
		}
		try {
			currentTk = this->_lexer.getTokens(line);
			this->_parser.feed(currentTk);
		} catch (std::exception const & e) {
			errors.push_back({nbLine, std::string(e.what())});
			retLexer = 1;
		}
	}
	for (std::list<t_errors>::const_iterator it = errors.begin(); it != errors.end(); ++it) {
		std::stringstream	s;
		s << "Line " << it->nbLine << ": " << it->message;
		Debug::error(s.str());
	}
	if (!currentTk.size() || currentTk[0]->value.compare("exit")) {
		throw NotExitTerminateException();
	}
	retParser = this->_parser.exec(this->_abstract);
	ret = retLexer | retParser;
	if (!ret) {
		this->_outStream << this->_abstract.getStringStream().str();
	}
	return (ret);
}

Vm::BigLineException::BigLineException(void) throw() : std::length_error("Line too long") {}
Vm::BigLineException::~BigLineException(void) throw() {}
Vm::BigLineException::BigLineException(BigLineException const & src) throw() : std::length_error("Line too long") {
	*this = src;
}
Vm::BigLineException & Vm::BigLineException::operator=(Vm::BigLineException const & rhs) throw() {
	(void)rhs;
	return *this;
}

Vm::NotExitTerminateException::NotExitTerminateException(void) throw() : std::runtime_error("Missing exit command in the end") {}
Vm::NotExitTerminateException::~NotExitTerminateException(void) throw() {}
Vm::NotExitTerminateException::NotExitTerminateException(NotExitTerminateException const & src) throw() : std::runtime_error("Missing exit command in the end") {
	*this = src;
}
Vm::NotExitTerminateException & Vm::NotExitTerminateException::operator=(Vm::NotExitTerminateException const & rhs) throw() {
	(void)rhs;
	return *this;
}
