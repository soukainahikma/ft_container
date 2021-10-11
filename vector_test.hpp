#ifndef VECTOR_TEST_HPP
#define VECTOR_TEST_HPP
#include <iostream>
#include "iterator_test.hpp"
#include <iterator>
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
			typedef _reverseiterator<pointer>							reverse_iterator;
			typedef const _iterator<pointer>							const_iterator;
			typedef const _reverseiterator<pointer>							const_reverse_iterator;
			typedef typename iterator_traits<pointer>::difference_type	difference_type;
			typedef typename allocator_type::size_type					size_type;
			vector(){

				_number_of_elements = 0;
				vec = allocator_type_.allocate(0);
				vec = nullptr;
			}
			vector (size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type())// parametrized 
			{
				allocator_type_ = alloc;// remember to do an explicite casting
				vec = allocator_type_.allocate(n);
				_number_of_elements = n;
				for (size_type i = 0; i < n; i++)
					vec[i] = val;
			}
			//need a copy constructor here
			~vector(){}
			/* **************************iterators************************ */
			iterator begin(){return(iterator(vec));};
			iterator end(){return(iterator(&vec[_number_of_elements - 1]));};
			const_iterator begin() const {return(const_iterator(&vec[0]));};
			const_iterator end() const {return(const_iterator(&vec[_number_of_elements - 1]));};
			reverse_iterator rend(){return(reverse_iterator(&vec[0]));};
			reverse_iterator rbegin(){return(reverse_iterator(&vec[_number_of_elements - 1]));};
			const_reverse_iterator rend()const {return(const_reverse_iterator(&vec[0]));};
			const_reverse_iterator rbegin()const {return(const_reverse_iterator(&vec[_number_of_elements - 1]));};
			/* **************************capacity************************ */
			size_type size() const{return(_number_of_elements);};
			size_type max_size() const{return(allocator_type_.max_size());};
			/* **************************operators************************ */
			T &operator[](unsigned int i){
						return this->vec[i];
				}
			int distance_(iterator first, iterator last)
			{
				int i = 0;
				while(first != last)
				{
					std::cout << first[i] << std::endl;
					first++;
					i++;
				}
				if(first == last)
					i++;
				return(i);
			}
		private:
			allocator_type	allocator_type_;
			pointer vec;
			int _number_of_elements;
			int _capacity;

	};
}
#endif