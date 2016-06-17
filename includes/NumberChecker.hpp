#ifndef NUMBERCHECKER_HPP
# define NUMBERCHECKER_HPP

# include <climits>
# include <regex>
# include <IOperand.hpp>

class NumberChecker {
	public:
		NumberChecker(std::string const & value, eOperandType type);

		template<typename T>
		T isValidNumber(std::string const & value);

	private:
		NumberChecker(NumberChecker const & src);
 		~NumberChecker(void);

		template<typename T> void	_isNumber(std::string const & value);
		template<typename T> bool	_isBounded(T value, T min, T max);

		std::string		_value;
		eOperandType	_type;
};

#endif
