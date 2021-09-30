#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP
#include <iostream>
#include "iterator.hpp"
#include <algorithm>
namespace ft
{
	template <typename T>
	class ft_vector
	{
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
			}

			// parametrized 
			// ft_vector() {} // range of iterators 
			// ft_vector(){} // copy constructor
			~ft_vector(){
				/* This destroys all container elements, and deallocates all the storage capacity allocated by the vector using its allocator. */
			}
			typedef my__wrap_iter<T> _iterator;
			typedef const my__wrap_iter<T> const_iterator;
			_iterator begin(){return(_iterator(&vec[0]));};
			const_iterator begin() const {return(const_iterator(&vec[0]));};

			//operators
			T &operator[](unsigned int i){
				// if (i >= ve || i < 0)
					// throw std::exception();
				// else
					return this->vec[i];
			}

	};
}
#endif
