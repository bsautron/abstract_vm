#ifndef PARSER_HPP
# define PARSER_HPP

# include <token.hpp>
# include <vector>

class Parser {
	private:
		std::vector<t_token> _tokens;

	public:
		Parser (std::vector<t_token> tokens);
		~Parser (void);

		void 		Verify(void);
};

#endif
