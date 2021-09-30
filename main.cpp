
#include "ft_vector.hpp"
#include "iterator.hpp"
#include<iterator>
#include <vector>

int main ()
{
	using namespace ft;
	std::vector<int> test;
	for (size_t i = 0; i < 3; i++)
	{
		test.push_back(100);
	}
	ft::ft_vector<int> a(3,100);
	ft::ft_vector<int>::_iterator it = a.begin();
	++it;
	--it;
	a[2] = 10;
	std::cout << a[2] << std::endl;

	
}
