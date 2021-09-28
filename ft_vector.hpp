#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP
#include <iostream>
#include <iterator>
#include <algorithm>
namespace ft
{
	template <typename T>
	class ft_vector
	{
		typedef typename std::random_access_iterator_tag iterator;
		private:
		 std::allocator<T> dataAlloc;
		 T *vec;
		public:
			ft_vector(){} // default
			ft_vector(int number_of_elements , T val)
			{
				vec = dataAlloc.allocate(number_of_elements);
				for (int i = 0; i < number_of_elements; i++)
					vec[i] = val;
				

			} // parametrized 
			/* ft_vector(iterator itb , iterator ite)
			{

				int size_ = std::distance(itb,ite)
				vec = dataAlloc.allocate(size_);
				for (int i = 0; i < number_of_elements; i++)
				{
					vec[i] = *itb;
					itb++;
				}

			} */ // range of iterators 
			// ft_vector(){} // copy constructor

	};
}
#endif
