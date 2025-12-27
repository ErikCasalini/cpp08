#include "MutantStack.hpp"
#include <list>
#include <string>
#include <vector>
#include <iostream>

int	main(void)
{
	std::list<std::string>	lst;
	std::vector<int>		vctr;
	for (int i = 1; i <= 4; i++) {
		vctr.push_back(i);
	}
	lst.push_back("One");
	lst.push_back("Two");
	lst.push_back("Three");
	std::vector<int>::iterator			vctr_it = vctr.begin();
	std::list<std::string>::iterator	lst_it = lst.begin();
	std::cout << "PRINTING CONTENT OF VECTOR\n";
	while (vctr_it != vctr.end()) {
		std::cout << *vctr_it << ' ';
		vctr_it++; }
	std::cout << "\nPRINTING CONTENT OF LIST\n";
	while (lst_it != lst.end()) {
		std::cout << *lst_it << ' ';
		lst_it++; }
	std::cout << '\n';

	MutantStack<int>									mutant_int;
	MutantStack< std::string, std::list<std::string> >	mutant_str;
	for (int i = 1; i <= 4; i++) {
		mutant_int.push(i);
	}
	mutant_str.push("One");
	mutant_str.push("Two");
	mutant_str.push("Three");
	MutantStack<int>::iterator										mutant_int_it = mutant_int.begin();
	MutantStack< std::string, std::list<std::string> >::iterator	mutant_str_it = mutant_str.begin();
	std::cout << "\nPRINTING CONTENT OF MUTANT STACK INT\n";
	while (mutant_int_it != mutant_int.end()) {
		std::cout << *mutant_int_it << ' ';
		mutant_int_it++; }
	std::cout << "\nPRINTING CONTENT OF MUTANT STACK STRING\n";
	while (mutant_str_it != mutant_str.end()) {
		std::cout << *mutant_str_it << ' ';
		mutant_str_it++; }
	std::cout << '\n';

	std::cout << "\nTESTING ALL KINDS OF ITERATORS\n";
	MutantStack<int>::const_iterator			mutant_const_it = mutant_int.begin();
	MutantStack<int>::reverse_iterator			mutant_rev_it = mutant_int.rbegin();
	MutantStack<int>::const_reverse_iterator	mutant_const_rev_it = mutant_int.rbegin();
	std::cout << "Const iterator: " << *mutant_const_it << '\n';
	// *mutant_rev_it = 999;
	std::cout << "Reverse iterator: " << *mutant_rev_it++ << ' ' << *mutant_rev_it++ << ' ' << *mutant_rev_it++ << ' ' << *mutant_rev_it << '\n';
	// *mutant_const_rev_it = 999; //IMPOSSIBLE --> CONST VALUE
	std::cout << "Const reverse iterator: " << *mutant_const_rev_it << '\n';
}
