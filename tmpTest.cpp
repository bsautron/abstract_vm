#include <iostream>
#include <istream>
#include <ostream>

int main(void)
{
	char	buf[100];

	std::cout << "Enter n: "; // no flush needed
	while (std::cin.getline(buf, 100)) {
		std::cout << "Enter n: "; // no flush needed
	}
	return (0);
}
