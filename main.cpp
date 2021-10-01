
#include "vector.hpp"
#include "iterator.hpp"
#include<iterator>
#include <vector>

int main ()
{
	using namespace ft;
	std::vector<int> test;
	for (size_t i = 0; i < 3; i++)
	{
		test.push_back(i);
	}
	ft::vector<int> a(3,3);
	for (size_t i = 0; i < 3; i++)
	{
		a[i] = a[i] + i;
	}
	ft::vector<int>::iterator itb = a.rbegin();
	ft::vector<int>::iterator ite = a.rend();
	std::cout << "|begin()|"<< *itb << std::endl;
	std::cout << "|end()  |"<< *ite << std::endl;
	std::cout << "|Allocation max size|"<<test.max_size();

	
}
