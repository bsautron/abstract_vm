#ifndef PARSER_HPP
# define PARSER_HPP

# include <IOperand.hpp>
# include <Abstract.hpp>
# include <Lexer.hpp>
# include <list>
# include <OperandBuilder.hpp>

class Parser {
	private:
		std::list<t_tokens>		_listCommand;
		OperandBuilder			_builder;

		int 			_strToCommandType(std::string const str) const;
		eOperandType	_strToOperandType(std::string const str) const;

	public:
		Parser (void);
		~Parser (void);

		void 	exec(Abstract & abstract);
		void 	feed(t_tokens tk);

		void 	push(Abstract & abstract, IOperand const * op);
		void 	pop(Abstract & abstract, IOperand const * op);
		void 	dump(Abstract & abstract, IOperand const * op);
		void 	assert(Abstract & abstract, IOperand const * op);
		void 	add(Abstract & abstract, IOperand const * op);
		void 	sub(Abstract & abstract, IOperand const * op);
		void 	div(Abstract & abstract, IOperand const * op);
		void 	mod(Abstract & abstract, IOperand const * op);
		void 	mul(Abstract & abstract, IOperand const * op);
		void 	print(Abstract & abstract, IOperand const * op);
		void 	exit(Abstract & abstract, IOperand const * op);
		void 	comment(Abstract & abstract, IOperand const * op);
};

#endif
