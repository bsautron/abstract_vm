#include <iostream>

class A : public std::logic_error {
	public:
		A(void) : std::logic_error("Lexical Error") {}
		virtual ~A(void) throw() {}
		A(A const & src) : std::logic_error("Lexical Error") {
			*this = src;
		}
		A & operator=(A const & rhs) {
			(void)rhs;
			return *this;
		}

};

int main(void)
{
	try {
		throw A();
	} catch (std::exception const & e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
