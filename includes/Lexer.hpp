#ifndef LEXER_HPP
# define LEXER_HPP

# include <iostream>
# include <token.hpp>

enum eScopeType {
	LXS_DEFAULT,
	LXS_EXIT,
	LXS_COMMENT,
	LXS_COMMAND,
	LXS_ARGS,
	LXS_OPERAND
};

class Lexer {

	public:
		class LexicalException : public std::logic_error {

			public:
				LexicalException(void) throw();
				LexicalException(LexicalException const & src) throw();
				LexicalException & operator=(LexicalException const & rhs) throw();

				virtual ~LexicalException(void) throw();
		};

		Lexer(void);
		~Lexer(void);

		t_tokens	getTokens(std::string const str);

		eTokenType scopeDefault(void);
		eTokenType scopeExit(void);
		eTokenType scopeComment(void);
		eTokenType scopeCommand(void);
		eTokenType scopeArgs(void);
		eTokenType scopeOperand(void);

		static size_t commandLengthMax;

	private:
		t_tokens					_tokens;
		std::string					_str;
		std::string::const_iterator _currentIt;

		Lexer(Lexer const & src);
		Lexer & operator=(Lexer const & rhs);

		t_token *	_createNewToken(eTokenType type);
		eTokenType	_enterScope(eScopeType scopeType);
		eTokenType	_enterScope(eScopeType scopeType, bool skipSpace);
		void 		_skipAllSpace(void);
		bool		_isSpace(char const c) const;

};

#endif
