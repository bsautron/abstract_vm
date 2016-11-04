#include <Parser.hpp>
#include <Debug.hpp>

Parser::Parser(void) {}
Parser::~Parser(void) {}

void 	Parser::push(Abstract & abstract, IOperand const * op) {
	std::cout << "push" << std::endl;
	abstract.Push(op);
}
void 	Parser::pop(Abstract & abstract, IOperand const * op) {
	std::cout << "pop" << std::endl;
	abstract.Pop();
	(void)op;
}
void 	Parser::dump(Abstract & abstract, IOperand const * op) {
	std::cout << "dump" << std::endl;
	abstract.Dump();
	(void)op;
}
void 	Parser::assert(Abstract & abstract, IOperand const * op) {
	std::cout << "assert" << std::endl;
	abstract.Assert(*op);
}
void 	Parser::add(Abstract & abstract, IOperand const * op) {
	std::cout << "add" << std::endl;
	abstract.Add();
	(void)op;
}
void 	Parser::sub(Abstract & abstract, IOperand const * op) {
	std::cout << "sub" << std::endl;
	abstract.Sub();
	(void)op;
}
void 	Parser::div(Abstract & abstract, IOperand const * op) {
	std::cout << "div" << std::endl;
	abstract.Div();
	(void)op;
}
void 	Parser::mod(Abstract & abstract, IOperand const * op) {
	std::cout << "mod" << std::endl;
	abstract.Mod();
	(void)op;
}
void 	Parser::mul(Abstract & abstract, IOperand const * op) {
	std::cout << "mul" << std::endl;
	abstract.Mul();
	(void)op;
}
void 	Parser::print(Abstract & abstract, IOperand const * op) {
	std::cout << "print" << std::endl;
	abstract.Print();
	(void)op;
}
void 	Parser::exit(Abstract & abstract, IOperand const * op) {
	std::cout << "exit" << std::endl;
	abstract.Exit();
	(void)op;
}


void Parser::Exec(Abstract & abstract, std::vector<t_token *> tk) {
	t_token * tkCommand = nullptr;
	t_token * tkOperand = nullptr;
	t_token * tkArgs = nullptr;

	void (Parser::*command[])(Abstract &, IOperand const *) = {
		&Parser::push,
		&Parser::pop,
		&Parser::dump,
		&Parser::assert,
		&Parser::add,
		&Parser::sub,
		&Parser::div,
		&Parser::mod,
		&Parser::mul,
		&Parser::print,
		&Parser::exit
	};

	Debug::Log("Command: " + tk[0]->value);
	tkCommand = tk[0];
	if (tk.size() > 1) {
		Debug::Log("Operand: " + tk[1]->value);
		tkOperand = tk[1];
	}
	if (tk.size() > 2) {
		Debug::Log("Args: " + tk[2]->value);
		tkArgs = tk[2];
	}
	IOperand const * op = (tkArgs) ? this->_builder.createOperand(this->_strToOperandType(tkOperand->value), tkArgs->value) : nullptr;
	(this->*command[this->_strToCommandType(tkCommand->value)])(abstract, op);
}

int 		Parser::_strToCommandType(std::string const str) const {
	int	i = 0;
	std::vector<std::string const> commandName;

	commandName.push_back("push");
	commandName.push_back("pop");
	commandName.push_back("dump");
	commandName.push_back("assert");
	commandName.push_back("add");
	commandName.push_back("sub");
	commandName.push_back("div");
	commandName.push_back("mod");
	commandName.push_back("mul");
	commandName.push_back("print");
	commandName.push_back("exit");

	for (std::vector<std::string const>::const_iterator it = commandName.begin(); it != commandName.end(); ++it) {
		if (!str.compare(*it))
			return i;
		i++;
	}
	return -1;
}

eOperandType Parser::_strToOperandType(std::string const str) const {
	std::map<std::string const, eOperandType> type;
	std::map<std::string const, eOperandType>::iterator it;

	type["int8"] = INT8;
	type["int16"] = INT16;
	type["int32"] = INT32;
	type["float"] = FLOAT;
	type["double"] = DOUBLE;

	it = type.find(str);
	if (it == type.end())
		throw MyException(EXC_OPERAND_NOT_FOUND);
	return type[str];
}
