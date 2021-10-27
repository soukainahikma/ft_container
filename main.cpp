#include "vector.hpp"
#include "iterator.hpp"
#include<iterator>
#include <vector>
#include <stdlib.h>  
int main ()
{
std::vector<int> foo (3,0);
  std::vector<int> bar (5,0);

  bar = foo;
  foo = std::vector<int>();

  std::cout << "Size of foo: " << int(foo.size()) << '\n';
  std::cout << "Size of bar: " << int(bar.size()) << '\n';
  return 0;
}
