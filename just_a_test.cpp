#include <iostream>
#include <vector>
#include "vector.hpp"
template <typename T>
void printer(bool test,std::string str , T value1, T value2)
{
	if(test == false)
		std::cout << str<< "  this is value1  " << value1 << "  this is value2  "<<  value2<< std::endl;
}
template <typename T>
void testIterator(std::vector<T> std_vector,ft::vector<T> ft_vector)
{
	std::vector<int>::reverse_iterator rit = std_vector.rbegin();
	ft::vector<int>::reverse_iterator srit = ft_vector.rbegin();
	printer(rit[10]== srit[10],"error 1",rit[10], srit[10]);
	// printer(*(rit - 5) == *(srit - 5),"error 2",*(rit - 5) , *(srit - 5));
	printer(*(rit + 205)== *(srit + 205),"error 3",(*(rit + 205)), *(srit + 205));
	printer(*srit++ == *rit++,"error 4",*srit++ , *rit++);
	printer(rit[-10]== srit[-10],"error 5",rit[-10],srit[-10]);
	printer(*(rit -= 5)== *(srit -= 5),"error 6",*(rit -= 5), *(srit -= 5));
	printer(*rit-- == *srit--,"error 7",*rit-- , *srit--);
	printer(*--rit == *--srit,"error 8",*--rit , *--srit);
	// printer(rit== rit,"error 9",rit,rit);

	// printer(rit.base(), vector.begin(),"error");


	// EXPECT_FALSE(rit < rit);
	// EXPECT_TRUE(rit <= ++rit);
	// EXPECT_TRUE(rit < (rit + 1));
	// EXPECT_TRUE(rit > (rit - 1));
	// EXPECT_FALSE(rit != rit);
	// EXPECT_TRUE(rit != (rit + 1));
}
int main()
{
	std::vector<int> std_vector;
	ft::vector<int> ft_vector;
for (int i = 0; i < 1000; ++i)
	{
		std_vector.push_back(i);
		ft_vector.push_back(i);
		// std::cout << std_vector[i] << "  " << ft_vector[i] << std::endl;
	}
	testIterator(std_vector,ft_vector);
}