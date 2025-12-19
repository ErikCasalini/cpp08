#include "Span.hpp"
#include <stdexcept>
#include <iostream>
#include <vector>

int main()
{
	try
	{
		{std::cout << "TESTING DEFAULT CONSTRUCTION\n";
		Span	sp;
		std::cout << "Elements list: " << sp << " | Max elements: " << sp.getMax() << " | Current elements: " << sp.getNelem() << '\n';
		try {
			sp.addNumber(3);
		} catch (const std::exception &e) {
			std::cout << "Add number do default constructed span: " << e.what() << "\n\n"; }}


		{std::cout << "TESTING COPY\n";
		std::cout << "Creating a span...\n";
		Span	sp(3);
		sp.addNumber(1);
		sp.addNumber(5);
		sp.addNumber(9);
		std::cout << "Elements list: " << sp << " | Max elements: " << sp.getMax() << " | Current elements: " << sp.getNelem() << '\n';
		std::cout << "Constructing by copy another span...\n";
		Span	cpy(sp);
		std::cout << "Elements list: " << cpy << " | Max elements: " << cpy.getMax() << " | Current elements: " << cpy.getNelem() << '\n';
		std::cout << "Constructing another span and coping the first one inside of it...\n";
		Span	cpy2(5);
		cpy2 = sp;
		std::cout << "Elements list: " << cpy2 << " | Max elements: " << cpy2.getMax() << " | Current elements: " << cpy2.getNelem() << "\n\n";}


		{std::cout << "TESTING MAX SIZE\n";
		Span	sp(3);
		std::cout << "Elements list: " << sp << " | Max elements: " << sp.getMax() << " | Current elements: " << sp.getNelem() << '\n';
		std::cout << "Adding one element...\n";
		sp.addNumber(5);
		try {
			sp.shortestSpan();
		} catch (const std::exception &e) {
			std::cout << "Span calculation with less than 2 elements: " << e.what() << '\n'; }
		std::cout << "Adding another element...\n";
		sp.addNumber(1);
		std::cout << "Elements list: " << sp << " | Max elements: " << sp.getMax() << " | Current elements: " << sp.getNelem() << '\n';
		std::cout << "Adding another element...\n";
		sp.addNumber(8);
		std::cout << "Elements list: " << sp << " | Max elements: " << sp.getMax() << " | Current elements: " << sp.getNelem() << '\n';
		std::cout << "Shortest span: " << sp.shortestSpan() << " | Longest span: " << sp.longestSpan() << '\n';
		try {
			sp.addNumber(3);
		} catch (const std::exception &e) {
			std::cout << "Adding number when max size is reached: " << e.what() << "\n\n"; }}


		{std::cout << "TESTING ADD RANGE\n";
		int	size = 10000;
		Span				sp(size + 1);
		std::vector<int>	vec(size);
		int y = -5000;
		for (unsigned int i = 0; i < vec.size(); ++i, y += 3)
			vec[i] = y;
		std::cout << "Coping vector inside span from iterators begin and end...\n";
		sp.addRange(vec.begin(), vec.end());
		// std::cout << "Elements list: " << sp << " | Max elements: " << sp.getMax() << " | Current elements: " << sp.getNelem() << '\n';
		std::cout << "Shortest span: " << sp.shortestSpan() << " | Longest span: " << sp.longestSpan() << '\n';
		try {
			sp.addRange(vec.begin(), vec.end());
		} catch (const std::exception &e) {
			std::cout << "Trying to add more than max: " << e.what() << '\n';}
		std::cout << "Adding a new number to change shortest span...\n";
		sp.addNumber(y - 3);
		// std::cout << "Elements list: " << sp << " | Max elements: " << sp.getMax() << " | Current elements: " << sp.getNelem() << '\n';
		std::cout << "Shortest span: " << sp.shortestSpan() << " | Longest span: " << sp.longestSpan() << '\n';}
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
		return (1);
	}
	return (0);
}
