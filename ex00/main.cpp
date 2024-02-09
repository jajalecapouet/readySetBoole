#include "../includes/booleFunctions.hpp"

using namespace ft;

int main()
{

	unsigned int a = adderDemoVersion(4785891, 1247878);
	std::cout << "a = " << a << "\n\n";

	std::cout << "worst add possible : \n";
	unsigned int b = adderDemoVersion(-1, 1);
	std::cout << "b = " << b << "\n\n";

	unsigned int c = adderDemoVersion(1023, 511);
	std::cout << "c = " << c << "\n\n";

	unsigned int d = adderDemoVersion(1023, -1);
	std::cout << "c = " << d << "\n\n";

	std::cout << "\n128 + 64 = " << adder(128, 64) << '\n';
	std::cout << "\n75456 + 74110 = " << adder(75456, 74110) << '\n';
	std::cout << "\n-1 + 1023 = " << adder(-1, 1023) << '\n';
	std::cout << "\n1023 + -1 = " << adder(1023, -1) << '\n';

	return 0;
}