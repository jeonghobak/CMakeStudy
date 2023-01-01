#include "../module1/feature1.hpp"
#include "feature2.hpp"
#include <iostream>

void func2()
{
	func1();
	std::cout << "void func2()" << '\n';
}
