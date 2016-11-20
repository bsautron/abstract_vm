#ifndef VM_HPP
# define VM_HPP

# include <Lexer.hpp>
# include <Parser.hpp>
# include <Abstract.hpp>
# include <OperandBuilder.hpp>

class Vm {
	private:
		std::istream &	_inStream;
		std::ostream &	_outStream;
		Abstract		_abstract;
		Lexer			_lexer;
		Parser			_parser;
		OperandBuilder	_builder;

	public:
		Vm (std::istream & is, std::ostream & os);
		~Vm (void);

		int start(void);

		class BigLineException : public std::length_error {

			public:
				BigLineException(void) throw();
				BigLineException(BigLineException const & src) throw();
				BigLineException & operator=(BigLineException const & rhs) throw();

				virtual ~BigLineException(void) throw();
		};
		class NotExitTerminateException : public std::runtime_error {

			public:
				NotExitTerminateException(void) throw();
				NotExitTerminateException(NotExitTerminateException const & src) throw();
				NotExitTerminateException & operator=(NotExitTerminateException const & rhs) throw();

				virtual ~NotExitTerminateException(void) throw();
		};
};

#endif
