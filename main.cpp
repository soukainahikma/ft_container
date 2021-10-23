

#include "vector.hpp"
#include "iterator.hpp"
#include<iterator>
#include <vector>

int main ()
{
	// using namespace ft;
	// std::vector<int> test;
	// for (size_t i = 0; i < 3; i++)
	// {
	// 	test.push_back(i);
	// }
	ft::vector<int> a(10,3);
	for (size_t i = 0; i < a.size(); i++)
	{
		a[i] = a[i] + i;
		std::cout << "this "<< a[i]<< std::endl;
	}
	a.resize(5);
	a.resize(8,100);
	a.resize(12);
  std::cout << "a contains:";
  for (size_t i=0;i<a.size();i++)
    std::cout << ' ' << a[i];
  std::cout << '\n';

  return 0;
	
}
