#include <iostream>
#include <sstream>
#include <istream>
#include <ostream>
#include <vector>

int main(void)
{
	std::stringstream	s;


	s << static_cast<char>(90);

	std::cout << s.str();
	return (0);
}
