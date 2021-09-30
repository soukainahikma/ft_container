#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include "iterator.hpp"
#include <algorithm>
namespace ft
{
	template <typename T>
	class vector
	{	

		private:
		 std::allocator<T> dataAlloc;
		 T *vec;
		 int _number_of_elements;
		public:
			vector(){} // default
			vector(int number_of_elements , T val)// parametrized 
			{
				_number_of_elements = number_of_elements;
				for (int i = 0; i < number_of_elements; i++)
					vec[i] = val;
			}
			// vector() {} // range of iterators 
			// vector(){} // copy constructor
			~vector(){
				/* This destroys all container elements, and deallocates all the storage capacity allocated by the vector using its allocator. */
			}
			typedef _iterator<T> iterator;
		typedef const _iterator<T> const_iterator;
			iterator begin(){return(iterator(&vec[0]));};
			iterator end(){return(iterator(&vec[_number_of_elements - 1]));};
			const_iterator begin() const {return(const_iterator(&vec[0]));};
			const_iterator end() const {return(const_iterator(&vec[_number_of_elements - 1]));};

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
