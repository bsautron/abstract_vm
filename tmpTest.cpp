#include <iostream>
#include <istream>
#include <ostream>
#include <vector>

int main(void)
{
	std::vector<char> v;

	v.push_back('s');

	std::cout << v[10] << std::endl;
	return (0);
}
