#include <IOperand.hpp>

class Operand : public IOperand {
	public:
		Operand(void);
		Operand(int value, eOperandType type); // template
		Operand(Operand const & rhs);

		virtual int						getPrecision( void ) const;
		virtual eOperandType			getType( void ) const;

		virtual IOperand const			* operator+( IOperand const & rhs ) const;
		virtual IOperand const			* operator-( IOperand const & rhs ) const;
		virtual IOperand const			* operator*( IOperand const & rhs ) const;
		virtual IOperand const			* operator/( IOperand const & rhs ) const;
		virtual IOperand const			* operator%( IOperand const & rhs ) const;

		virtual std::string const &		toString( void ) const ;

		virtual							~Operand( void ) {}


	protected:
		int				_precision;
		eOperandType	_type;

	static std::string type[5];
};

std::ostream	& operator<<( std::ostream & o, Operand const & rhs );
