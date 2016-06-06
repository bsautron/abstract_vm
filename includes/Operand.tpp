#include <IOperand.hpp>

template<typename T>
class Operand : public IOperand {
	public:
		Operand(void) {}
		Operand(int precision, eOperandType type, T value);
		Operand(Operand<T> const & rhs);

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
		T 				_value;

	// private:
	//

	static std::string type[5];
};


std::ostream	& operator<<( std::ostream & o, IOperand const & rhs );
