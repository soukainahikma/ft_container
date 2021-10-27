#include "vector.hpp"
#include "iterator.hpp"
#include<iterator>
#include <vector>
#include <stdlib.h>  
int main ()
{
ft::vector<int> foo (3,2);
  ft::vector<int> bar (5,4);
std::cout << "before     Size of foo: " << int(foo.size()) << " capacity " << foo.capacity() << '\n';
std::cout << "before     Size of bar: " << int(bar.size()) << " capacity " << bar.capacity() << '\n';
std::cout << "before   foo elements" << std::endl;
	for (size_t i = 0 ; i < foo.size() ; i++)
	{
		std::cout << foo[i] << " " ;
	}
	std::cout << std::endl;
	std::cout << "before   bar elements" << std::endl;
	for (size_t i = 0 ; i < bar.size() ; i++)
	{
		std::cout << bar[i] << " " ;
	}
	std::cout << std::endl;
  bar = foo;
  foo = std::vector<int>();

  std::cout << "after    Size of foo: " << int(foo.size()) << " capacity " << foo.capacity() << '\n';
  std::cout << "after    Size of bar: " << int(bar.size()) << " capacity " << bar.capacity() << '\n';
	std::cout << "before   foo elements" << std::endl;
	for (size_t i = 0 ; i < foo.size() ; i++)
	{
		std::cout << foo[i] << " " ;
	}
	std::cout << std::endl;
	std::cout << "before   bar elements" << std::endl;
	for (size_t i = 0 ; i < bar.size()+5 ; i++)
	{
		std::cout << bar[i] << " " ;
	}
	std::cout << std::endl;
  return 0;
}
