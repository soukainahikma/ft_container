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
			typedef _iterator<T> iterator;
			typedef const _iterator<T> const_iterator;
			typedef const _reverseiterator<T> reverse_iterator; 
			typedef const _reverseiterator<T> const_reverse_iterator;
			typedef typename std::allocator<T>::size_type size_type;
			vector(){} // default
			vector(int number_of_elements , T val)// parametrized 
			{
				std::cout << "|allocation max size|" << dataAlloc.max_size() <<std::endl;
				_number_of_elements = number_of_elements;
				for (int i = 0; i < number_of_elements; i++)
					vec[i] = val;
			}
			// vector() {} // range of iterators 
			// vector(){} // copy constructor
			~vector(){
				/* This destroys all container elements, and deallocates all the storage capacity allocated by the vector using its allocator. */
			}
			
			iterator begin(){return(iterator(&vec[0]));};
			iterator end(){return(iterator(&vec[_number_of_elements - 1]));};
			const_iterator begin() const {return(const_iterator(&vec[0]));};
			const_iterator end() const {return(const_iterator(&vec[_number_of_elements - 1]));};
			reverse_iterator rend(){return(reverse_iterator(&vec[0]));};
			reverse_iterator rbegin(){return(reverse_iterator(&vec[_number_of_elements - 1]));};
			const_reverse_iterator rend()const {return(const_reverse_iterator(&vec[0]));};
			const_reverse_iterator rbegin()const {return(const_reverse_iterator(&vec[_number_of_elements - 1]));};
			size_type size() const{return(_number_of_elements);};
			size_type max_size() const{return(dataAlloc.max_size());};
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
