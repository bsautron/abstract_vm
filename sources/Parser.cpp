#include <Parser.hpp>
#include <Debug.hpp>

Parser::Parser(void) : _end(false) {}
Parser::~Parser(void) {}

void 	Parser::push(Abstract & abstract, IOperand const * op) {
	abstract.Push(op);
}
void 	Parser::pop(Abstract & abstract, IOperand const * op) {
	if (op) {
		throw MyException(EXC_CHAR_BEYOND);
	}
	abstract.Pop();

}
void 	Parser::dump(Abstract & abstract, IOperand const * op) {
	if (op) {
		throw MyException(EXC_CHAR_BEYOND);
	}
	abstract.Dump();
}
void 	Parser::assert(Abstract & abstract, IOperand const * op) {
	abstract.Assert(*op);
}
void 	Parser::add(Abstract & abstract, IOperand const * op) {
	if (op) {
		throw MyException(EXC_CHAR_BEYOND);
	}
	abstract.Add();

}
void 	Parser::sub(Abstract & abstract, IOperand const * op) {
	if (op) {
		throw MyException(EXC_CHAR_BEYOND);
	}
	abstract.Sub();

}
void 	Parser::div(Abstract & abstract, IOperand const * op) {
	if (op) {
		throw MyException(EXC_CHAR_BEYOND);
	}
	abstract.Div();

}
void 	Parser::mod(Abstract & abstract, IOperand const * op) {
	if (op) {
		throw MyException(EXC_CHAR_BEYOND);
	}
	abstract.Mod();

}
void 	Parser::mul(Abstract & abstract, IOperand const * op) {
	if (op) {
		throw MyException(EXC_CHAR_BEYOND);
	}
	abstract.Mul();

}
void 	Parser::print(Abstract & abstract, IOperand const * op) {
	if (op) {
		throw MyException(EXC_CHAR_BEYOND);
	}
	abstract.Print();

}
void 	Parser::exit(Abstract & abstract, IOperand const * op) {
	(void)abstract;
	if (op) {
		throw MyException(EXC_CHAR_BEYOND);
	}
	this->_end = true;
}
void 	Parser::comment(Abstract & abstract, IOperand const * op) {
	(void)abstract;
	(void)op;
}

std::string Parser::_tokensToStr(t_tokens tk) const {
	std::stringstream s;

	s << tk[0]->value;
	for (t_tokens::const_iterator it = tk.begin(); it != tk.end(); ++it) {
		if (it == tk.begin())
			continue;
		s << " " << (*it)->value;
	}
	return s.str();
}

int Parser::exec(Abstract & abstract, std::ostream & outStream) {
	int ret = 0;
	this->_listCommand.reverse();

	for (std::list<t_tokens>::const_iterator it = this->_listCommand.begin(); it != this->_listCommand.end(); ++it) {
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
			&Parser::exit,
			&Parser::comment
		};

		// Debug::Info("Exec");
		if (it->size() > 0) {
			// Debug::Log(tkName[it[0]->type] + ": " + it[0]->value);
			tkCommand = (*it)[0];
		}
		if (it->size() > 1) {
			// Debug::Log("Operand: " + it[1]->value);
			tkOperand = (*it)[1];
		}
		if (it->size() > 2) {
			// Debug::Log("Args: " + it[2]->value);
			tkArgs = (*it)[2];
		}

		try {
			if (it->size() && (*it->begin())->type == TK_EXIT)
				(this->*command[this->_strToCommandType("exit")])(abstract, nullptr);
			else if (it->size() && (*it->begin())->type == TK_COMMENT)
				(this->*command[this->_strToCommandType("comment")])(abstract, nullptr);
			else if (it->size()) {
				if (tkOperand && !tkArgs && tkOperand->type != TK_COMMENT)
					throw MyException(EXC_CHAR_BEYOND);
				IOperand const * op = tkArgs ? this->_builder.createOperand(this->_strToOperandType(tkOperand->value), tkArgs->value) : nullptr;
				int index = this->_strToCommandType(tkCommand->value);
				if (index == -1)
					throw MyException(EXC_COMMAND_NOT_FOUND);
				(this->*command[index])(abstract, op);
			}
		} catch (MyException const & e) {
			ret = 1;
			outStream << "Fail to exec \"" << this->_tokensToStr(*it) << "\": " << e.what() << std::endl;
			if (Parser::abortException)
				break;
		}
		if (this->_end)
			break;
	}
	return ret;
}

void 	Parser::feed(t_tokens tk) {
	this->_listCommand.push_front(tk);
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
	commandName.push_back("comment");

	for (std::vector<std::string const>::const_iterator it = commandName.begin(); it != commandName.end(); ++it) {
		if (!str.compare(*it)) {
			return i;
		}
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

bool 	Parser::abortException = false;
