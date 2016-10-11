#ifndef OPERANDBUILDER_HPP
# define OPERANDBUILDER_HPP

# include <IOperand.hpp>

class OperandBuilder {
	private:
		OperandBuilder(OperandBuilder const & src);

	public:
		OperandBuilder (void);
		~OperandBuilder (void);

		IOperand const * createInt8( std::string const & value ) const;
		IOperand const * createInt16( std::string const & value ) const;
		IOperand const * createInt32( std::string const & value ) const;
		IOperand const * createFloat( std::string const & value ) const;
		IOperand const * createDouble( std::string const & value ) const;

		IOperand const * createOperand(eOperandType type, std::string const & value) const;
};

#endif
