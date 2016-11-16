#ifndef VM_HPP
# define VM_HPP

# include <Lexer.hpp>
# include <Parser.hpp>
# include <Abstract.hpp>
# include <OperandBuilder.hpp>
# include <MyException.hpp>

class Vm {
	private:
		std::istream &	_inStream;
		std::ostream &	_outStream;
		Abstract		_abstract;
		Lexer			_lexer;
		Parser			_parser;
		t_listError		_listError;
		OperandBuilder	_builder;

	public:
		Vm (std::istream & is, std::ostream & os);
		~Vm (void);

		int start(void);

		static int commandLenghtMax;
};

#endif
