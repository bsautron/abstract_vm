#ifndef VM_HPP
# define VM_HPP

# include <iostream>

class Vm {
	private:
		int		_fd;

		void 	_Welcome(void);

	public:
		Vm (void);
		Vm (std::string const & fileName);
		~Vm (void);

};

#endif
