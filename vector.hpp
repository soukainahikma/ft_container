#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include "iterator_test.hpp"
#include <algorithm>
// #include<iterator>
#include<vector>
namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{private:
			typedef T			value_type;
			std::allocator<value_type>	allocator_type_;
			value_type* vec;
			int _number_of_elements; //remember to remove it
		public:
		// typedef T                                        value_type;
		typedef Allocator                                allocator_type;
		typedef typename allocator_type::reference       reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::size_type       size_type;
		typedef typename allocator_type::difference_type difference_type;
		typedef typename allocator_type::pointer         pointer;
		typedef typename allocator_type::const_pointer   const_pointer;
		
		
		
		public:
			typedef _iterator<pointer> iterator;
			// typedef const _iterator<value_type> const_iterator;
			// typedef const _reverseiterator<value_type> reverse_iterator; 
			// typedef const _reverseiterator<value_type> const_reverse_iterator;
			// typedef typename std::allocator<value_type>::size_type size_type;



			vector(){} // default
			vector(int number_of_elements , T val)// parametrized 
			{
				std::cout << "|allocation max size|" << allocator_type_.max_size() <<std::endl;
				_number_of_elements = number_of_elements;
				for (int i = 0; i < number_of_elements; i++)
					vec[i] = val;
			}
			// vector() {} // range of iterators
			// vector(){} // copy constructor
			~vector(){
			}
			
			iterator begin(){return(iterator(&vec[0]));};
			iterator end(){return(iterator(&vec[_number_of_elements - 1]));};
			// const_iterator begin() const {return(const_iterator(&vec[0]));};
			// const_iterator end() const {return(const_iterator(&vec[_number_of_elements - 1]));};
			// reverse_iterator rend(){return(reverse_iterator(&vec[0]));};
			// reverse_iterator rbegin(){return(reverse_iterator(&vec[_number_of_elements - 1]));};
			// const_reverse_iterator rend()const {return(const_reverse_iterator(&vec[0]));};
			// const_reverse_iterator rbegin()const {return(const_reverse_iterator(&vec[_number_of_elements - 1]));};
			size_type size() const{return(_number_of_elements);};
			size_type max_size() const{return(allocator_type_.max_size());};
			//operators
			T &operator[](unsigned int i){
					return this->vec[i];
			}
			
	};
}
#endif
