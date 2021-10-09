#ifndef VECTOR_TEST_HPP
#define VECTOR_TEST_HPP
#include <iostream>
#include "iterator_test.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T													value_type;
			typedef Alloc												allocator_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;  
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;

			typedef _iterator<pointer>									iterator;
			typedef const _iterator<pointer>							const_iterator;
			typedef typename iterator_traits<pointer>::difference_type	difference_type;
			typedef typename allocator_type::size_type					size_type;
			vector(){
				vec = allocator_type_.allocate(0);
				vec = nullptr;
			}
			vector (size_type n, const value_type& val = value_type())// parametrized 
			{
				vec = allocator_type_.allocate(n);
				_number_of_elements = n;
				for (size_type i = 0; i < n; i++)
					vec[i] = val;
			}
			~vector(){}
			T &operator[](unsigned int i){
						return this->vec[i];
				}
			iterator begin(){return(iterator(vec));};
			iterator end(){return(iterator(&vec[_number_of_elements - 1]));};
		private:
			allocator_type	allocator_type_;
			pointer vec;
			int _number_of_elements;
	};
}
#endif