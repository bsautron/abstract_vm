#include <Lexer.hpp>

Lexer::Lexer(void) {
	this->_init();
}

Lexer::~Lexer(void) {}

void 		Lexer::_init(void) {
}

void Lexer::none(const char c) const {
	std::cout << c << std::endl;
}

// void Lexer::_(/* arguments */) {
	/* code */
// }

std::vector<t_token>	Lexer::getToken(std::string const & line) {
	theFn	caca = &Lexer::none;

	std::vector<t_token>	ret;

	caca('d');
	// for (std::string::const_iterator it = line.begin(); it!=line.end(); ++it) {
	// }
	return ret;
}
