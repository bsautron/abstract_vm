#ifndef ABSTRACTVM_HPP
# define ABSTRACTVM_HPP

# include <iostream>

class AbstractVm {
	public:
		AbstractVm(void);
		~AbstractVm(void);

	private:
		AbstractVm(AbstractVm const & src);
};

#endif
