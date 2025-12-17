#include "easyfind.hpp"
#include <iostream>
#include <vector>

int	main(void)
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	std::cout << (easyfind(vec, 2) == vec.end() ? "Not found" : "Found") << '\n';
	std::cout << (easyfind(vec, 100) == vec.end() ? "Not found" : "Found") << '\n';
}

