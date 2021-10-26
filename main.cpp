#include "vector.hpp"
#include "iterator.hpp"
#include<iterator>
#include <vector>
#include <stdlib.h>  
int main ()
{
std::vector<int> foo (3,0);
  std::vector<int> bar (5,0);

std::cout << "before assignment\n";
	for(size_t i = 0; i < foo.size(); i++)
		std::cout << foo[i]<< " ";
	std::cout << "\n";
	for(size_t i = 0; i < bar.size(); i++)
		std::cout << bar[i]<< " ";
	std::cout << "\n";

std::cout << "Size of foo: " << int(foo.size())<< " Capacity of foo: "<< foo.capacity() << '\n';
std::cout << "Size of bar: " << int(bar.size())<< " Capacity of bar: "<< bar.capacity() << '\n';
std::cout << "after assignment\n";
  bar = foo;
  foo = std::vector<int>();

	std::cout << "Size of foo: " << int(foo.size())<< " Capacity of foo: "<< foo.capacity() << '\n';
	std::cout << "Size of bar: " << int(bar.size())<< " Capacity of bar: "<< foo.capacity() << '\n';
	for(size_t i = 0; i < foo.size(); i++)
		std::cout << foo[i]<< " ";
	std::cout << "\n";
	for(size_t i = 0; i < bar.size(); i++)
		std::cout << bar[i]<< " ";
	std::cout << "\n";

  return 0;
}
