#ifndef MODEL_HPP
# define MODEL_HPP

# include <iostream>

class Model {
private:
	std::string		_type;
	std::string		_type;
	std::string		_type;

	Model ( void ) ;
	Model ( Model const & src );

public:
	Model ( std::string const & format; std::string const & type, std::string const & description );
	~Model ( void );

};

#endif
