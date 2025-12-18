#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int	main(void)
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	std::cout << "VECOR TEST\n" << (easyfind(vec, 2) == vec.end() ? "Not found" : "Found") << '\n'
			  << (easyfind(vec, 100) == vec.end() ? "Not found" : "Found") << "\n\n";

	std::list<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	std::cout << "LIST TEST\n" << (easyfind(list, 5) == list.end() ? "Not found" : "Found") << '\n'
			  << (easyfind(list, 0) == list.end() ? "Not found" : "Found") << '\n'
			  << (easyfind(list, 12) == list.end() ? "Not found" : "Found") << '\n'
			  << (easyfind(list, 6) == list.end() ? "Not found" : "Found") << "\n\n";

	std::deque<int> deque;
	deque.push_back(1);
	deque.push_back(2);
	deque.push_back(3);
	deque.push_back(4);
	deque.push_back(5);
	std::cout << "DEQUE TEST\n" << (easyfind(deque, 112) == deque.end() ? "Not found" : "Found") << '\n'
			  << (easyfind(deque, 99) == deque.end() ? "Not found" : "Found") << '\n'
			  << (easyfind(deque, 4) == deque.end() ? "Not found" : "Found") << '\n'
			  << (easyfind(deque, 3) == deque.end() ? "Not found" : "Found") << '\n';
}

