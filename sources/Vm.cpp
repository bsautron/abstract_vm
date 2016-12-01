/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vm.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:10:45 by bsautron          #+#    #+#             */
/*   Updated: 2016/12/01 21:10:46 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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


void	Vm::feedInStream(std::istream & inStream, bool stdIn) {
	std::string			line;
	std::list<t_errors>	errors;

	if (stdIn) this->_alreadyReadNativeStream = true;

	while (std::getline(inStream, line)) {
		if (stdIn && !line.compare(";;"))
			break;

		++this->_nbLine;
		if (line.size() > Lexer::commandLengthMax)
			throw BigLineException();
		try {
			this->_currentTk = this->_lexer.getTokens(line);
			this->_parser.feed(this->_currentTk);
		} catch (std::exception const & e) {
			errors.push_back({this->_nbLine, std::string(e.what())});
			this->_statusLexer = 1;
		}
	}

	for (std::list<t_errors>::const_iterator it = errors.begin(); it != errors.end(); ++it) {
		std::stringstream	s;
		s << "Line " << it->nbLine << ": " << it->message;
		Debug::error(s.str());
	}
}

int Vm::start(void) {
	int	ret = 0;

	if (!this->_alreadyReadNativeStream && (!this->_currentTk.size() || this->_currentTk[0]->value.compare("exit")))
		this->feedInStream(this->_inStream, true);

	if (!this->_currentTk.size() || this->_currentTk[0]->value.compare("exit"))
		throw NotExitTerminateException();


	this->_statusParser = this->_parser.exec(this->_abstract);
	ret = this->_statusLexer | this->_statusParser;

	this->_outStream << this->_abstract.getStringStream().str();
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
