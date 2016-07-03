#ifndef LEXER_HPP
#define LEXER_HPP

enum eLexerType {
	LEX_NONE,
	LEX_INSTRUCTOR,
	LEX_SEPARATOR,
	LEX_ARGV,
	LEX_BRACKET,
	LEX_END_LINE
};

class Lexer {
	private:
		/* data */

	public:
		Lexer (void);
		~Lexer (void);

		static getToken(std::string const & line);

};

#endif
