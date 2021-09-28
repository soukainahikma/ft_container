
#include "ft_vector.hpp"
#include "iterator.hpp"
#include <vector>

int main ()
{
	using namespace ft;
	std::vector<int> test;
	for (size_t i = 0; i < 5; i++)
	{
		test.push_back(i);
	}
	ft::ft_vector<int> a(3,100);
	ft::ft_vector<int> b;
	my__wrap_iter<int *> it;
	// std::__wrap_iter<int*> it;
	// it = test.begin();
	// std::cout << *it << std::endl;
}
