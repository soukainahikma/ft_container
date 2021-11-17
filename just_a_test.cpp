
#include"pair.hpp"
#include "binary_tree.hpp"
#include <iostream>
#include <map>
int main()
{
	ft::pair <int, int> pr = ft::make_pair(10,20);
	ft::btree<ft::pair <int, int> > test;
	// test.insert(pr);

	test.insert(ft::make_pair(30,10));
	test.insert(ft::make_pair(40,11));
	test.insert(ft::make_pair(33,12));
	std::cout<< " this is before " << std::endl;
	test.printer(test);
	// ft::node<ft::pair <int, int> > *a = test.right_rotation(test.getroot());
	ft::node<ft::pair <int, int> > *b = test.right_left_rotation(test.getroot());
	// test.insert(ft::make_pair(16,15));
	// test.insert(ft::make_pair(35,18));
	// test.insert(ft::make_pair(30,19));
	// test.insert(ft::make_pair(37,77));
	std::cout<< " this is after " << std::endl;
	test.print_preorder(b, "this is first node   ");
	// test.print_height();
}
