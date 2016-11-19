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
	private:
		t_tokens					_tokens;
		std::string					_str;
		std::string::const_iterator _currentIt;

		t_token *	_createNewToken(eTokenType type);
		eTokenType	_enterScope(eScopeType scopeType);
		eTokenType	_enterScope(eScopeType scopeType, bool skipSpace);
		void 		_skipAllSpace(void);
		bool		_isSpace(char const c) const;

	public:
		class LexicalError : public std::logic_error {

			public:
				LexicalError(void);
				virtual ~LexicalError(void) throw();

				virtual const char *	what(void) const throw();

			private:
				LexicalError(LexicalError const & src);
				LexicalError & operator=(LexicalError const & rhs);
		};

		Lexer(void);
		~Lexer(void);

		t_tokens	getTokens(std::string const str);

		eTokenType Default(void);
		eTokenType Exit(void);
		eTokenType Comment(void);
		eTokenType Command(void);
		eTokenType Args(void);
		eTokenType Operand(void);

		static size_t commandLengthMax;

};

#endif
