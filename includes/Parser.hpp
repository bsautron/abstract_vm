#ifndef PARSER_HPP
# define PARSER_HPP

# include <IOperand.hpp>
# include <Abstract.hpp>
# include <OperandBuilder.hpp>

class Parser {
	private:
		OperandBuilder	_builder;
		int 			_strToCommandType(std::string const str) const;
		eOperandType	_strToOperandType(std::string const str) const;

	public:
		Parser (void);
		~Parser (void);

		void Exec(Abstract & abstract, std::vector<t_token *> tk);

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
};

#endif
