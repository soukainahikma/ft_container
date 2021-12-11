#include "../vector.hpp"
#include <vector>


int main ()
{
   std::cout << "- Relational operators for vector" << std::endl;
  {  std::vector<int> foo (1,200);   // three ints with a value of 100
    std::vector<int> bar (1,100);   // two ints with a value of 200

    if (foo==bar) std::cout << "foo and bar are equal\n";
    if (foo!=bar) std::cout << "foo and bar are not equal\n";
    if (foo< bar) std::cout << "foo is less than bar\n";
    if (foo> bar) std::cout << "foo is greater than bar\n";
    if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
    if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}
 
    
}