#ifndef ABSTRACT_HPP
# define ABSTRACT_HPP

# include <sstream>
# include <string>
# include <deque>
# include <MyException.hpp>
# include <IOperand.hpp>
# include <cstdlib>
# include <OperandBuilder.hpp>
# include <map>
# include <token.hpp>
# include <vector>

# define DELETE_CPTR(X)		{delete X; X = nullptr;}

class Abstract : public std::deque<IOperand const *> {
	private:
		std::stringstream	_stringStream;

		void 	_DeleteOperand(IOperand const * operand);
		std::stringstream	_ConcatStream(char const c) const;
		std::stringstream	_ConcatStream(std::string const str) const;

	public:
		Abstract(void);
		~Abstract(void);

		void 	Push(IOperand const * op);
		void 	Pop(void);
		void 	Dump(void) const;
		void 	Assert(IOperand const & value) const;
		void 	Add(void);
		void 	Sub(void);
		void 	Div(void);
		void 	Mod(void);
		void 	Mul(void);
		void 	Print(void) const;
		void 	Exit(void) const;

		std::stringstream & GetStringStream(void);


};

#endif
