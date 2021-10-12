

#include "vector_test.hpp"
#include "iterator_test.hpp"
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
	ft::vector<int> a(4,3);
	for (size_t i = 0; i < 4; i++)
	{
		a[i] = a[i] + i;
		std::cout << a[i]<< std::endl;
	}
	ft::vector<int>::reverse_iterator itb (a.rbegin());
	ft::vector<int>::reverse_iterator ite = a.rend();
	
	
	std::cout << "|begin()|"<< *itb << std::endl;
	std::cout << "|end()  |"<< *ite << std::endl;
	ite = ite - 2;
	std::cout << ite[0] << std::endl;
	
	// std::reverse_iterator<int>::
	// std::cout << "|end() +1|"<< *ite << std::endl;
	// std::cout << "|Allocation max size|"<<test.max_size()<< std::endl;
	// std::cout << a.distance_(itb,ite) << std::endl;
	// std::cout << "|begin()|"<< *itb << std::endl;
}
