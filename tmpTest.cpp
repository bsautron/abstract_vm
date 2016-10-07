#include <iostream>

struct s_sst {
	int a;
	double b;
};

int main(void)
{
	struct s_sst a = {2, 9.3};

	std::cout << a.b << std::endl;
	return 0;
}
