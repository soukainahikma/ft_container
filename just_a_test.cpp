#include"pair.hpp"
#include "binary_tree.hpp"
#include <iostream>
#include "map.hpp"
#include <map>
int main()
{
	ft::pair <int, int> pr = ft::make_pair(10,20);
	ft::btree<ft::pair <int, int> > test;
	// test.insert(pr);

	test.insert_(ft::make_pair(50,10));
	test.insert_(ft::make_pair(40,11));
	test.insert_(ft::make_pair(30,12));
	test.insert_(ft::make_pair(20,12));
	test.insert_(ft::make_pair(61,12));
	test.insert_(ft::make_pair(70,12));
	test.insert_(ft::make_pair(55,12));
	test.insert_(ft::make_pair(41,12));
	test.insert_(ft::make_pair(10,12));
	test.insert_(ft::make_pair(5,12));
	test.print_preorder(test.getroot(), "this is first node   ");
	test.deletion_node(test.getroot(),40);
	test.deletion_node(test.getroot(),30);

	// test.printer(test);
	// ft::node<ft::pair <int, int> > *a = test.right_rotation(test.getroot());
	// ft::node<ft::pair <int, int> > *b = test.balance(test.getroot());
	// test.insert(ft::make_pair(16,15));
	// test.insert(ft::make_pair(35,18));
	// test.insert(ft::make_pair(30,19));
	// test.insert(ft::make_pair(37,77));
	// std::cout<< " this is after " << std::endl;
	// test.print_preorder(test.getroot(), "this is first node   ");
	std::cout << std::endl;
	test.print_preorder(test.getroot(), "this is first node   ");
}