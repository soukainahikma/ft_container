
#include "vector_test.hpp"
#include "iterator_test.hpp"
#include <vector>

int main ()
{
	// using namespace ft;
	// std::vector<int> a;
	// a.begin();
	ft::vector<int> a(3,3);
	a.begin();
	for (size_t i = 0; i < 3; i++)
	{
		a[i] = a[i] + i;
		std::cout << a[i] << std::endl;
	}
	ft::vector<int>::iterator itb = a.begin();
	// ft::vector<int>::iterator ite = a.end();
	std::cout << "|begin()|"<< *itb << std::endl;
	// std::cout << "|end()  |"<< *ite << std::endl;


}
