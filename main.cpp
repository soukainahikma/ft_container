

#include "vector.hpp"
#include "iterator.hpp"
#include<iterator>
#include <vector>

int main ()
{
	// using namespace ft;
	std::vector<int> test;
	for (size_t i = 0; i < 3; i++)
	{
		test.push_back(i);
	}
	ft::vector<int> a(4,3);
	for (size_t i = 0; i < a.size(); i++)
	{
		a[i] = a[i] + i;
		std::cout << "this "<< a[i]<< std::endl;
	}
	a.resize(6, 55);
	for (size_t i = 0; i < a.size(); i++)
	{
		std::cout << "after resize    "<< a[i]<< std::endl;
	}
}
