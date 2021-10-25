

#include "vector.hpp"
#include "iterator.hpp"
#include<iterator>
#include <vector>
#include <stdlib.h>  
int main ()
{
	{
		std::vector<int> myvector (10,3);   // 10 zero-initialized ints

		// assign some values:
		std::cout << myvector.back()  << std::endl;

	}
	std::cout << "here testing" << std::endl;
	{
		ft::vector<int> myvector (10,3);   // 10 zero-initialized ints

		// assign some values:
		std::cout << myvector.back()  << std::endl;
		return 0;
	}

}
