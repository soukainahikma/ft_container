#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include "iterator.hpp"
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
			typedef _reverseiterator<iterator>							reverse_iterator;
			typedef const _iterator<pointer>							const_iterator;
			typedef const _reverseiterator<const_iterator>				const_reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type	difference_type;
			typedef typename allocator_type::size_type					size_type;
			vector (const allocator_type& alloc = allocator_type())
			{
				_capacity = 0;
				allocator_type_ = alloc;
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
				_capacity = n;
			}
			// template <class InputIterator> // ImputIterator needs an enable_if to work for some cases
			vector (iterator first, iterator last, const allocator_type& alloc = allocator_type())
			{
				allocator_type_ = alloc;
				difference_type n = begin() - end();
				_capacity = _number_of_elements;
				int i = 0;
				vec = allocator_type_.allocate(_number_of_elements);
				while(first !=  last)
				{
					vec[i] = *first;
					i++;
					first++;
				}
			}
			vector (const vector& x)
			{
				_number_of_elements = x.size();
				vec = allocator_type_.allocate(_number_of_elements);
				for (int i = 0; i < _number_of_elements; i++)
				{
					vec[i] = x.vec[i];
				}
			}
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
			size_type size() const{
			difference_type n = begin() - end() + 1;
				return(n);
			};
			size_type max_size() const
			{
				// to review
				return(allocator_type_.max_size());
			};
			void resize (size_type n, value_type val = value_type())
			{
				size_type cp = _capacity;
				size_type size_ = size();

				if (n < size_)
				{
					while(size_ > n)
					{
						allocator_type_.destroy(vec + size_);
						size_--;
					}
					_number_of_elements = n;
				}
				if(n > size_)
				{
					if(n > cp)
					{
						if(n > cp *2)
							_capacity = n;
						else
							_capacity = _capacity * 2;
						vector<T> arr(_capacity);
						for(size_type i = 0; i< size(); i++ )
							arr.vec[i]= vec[i];
						allocator_type_.deallocate(vec,size());
						swap(arr);
						_number_of_elements = n;
					}
					while(_number_of_elements < n)
					{
						vec[_number_of_elements] = val;
						_number_of_elements++;
					}
				}
			}
			size_type capacity() const
			{
				return(_capacity);
			}
			bool empty() const{
				if(size() == 0)
					return(true);
				else
					return(false);
			}
			void reserve (size_type n)
			{
				if(n > _capacity)
				{
					vector<T> arr(n);
					arr._number_of_elements = size();
					for(size_type i = 0; i< size(); i++ )
						arr.vec[i]= vec[i];
					allocator_type_.deallocate(vec,size());
					swap(arr);
				}
			}
			/* **************************operators************************ */
			// vector& operator= (const vector& x)
			// {
				// 
			// }
			reference &operator[](size_type n)
			{
						return this->vec[n];
			}
			const_reference &operator[](size_type n) const
			{
				return this->vec[n];
			}
			/* **************************access functions************************ */
			
			reference at (size_type n)
			{
					 if(n < size())
				 		return(this->vec[n]);
					else
					 	throw(std::out_of_range("vector"));
					//are we allowed to use std::out_of_range
			 }
			const_reference at (size_type n) const
			{
				if(n < size())
					return(this->vec[n]);
				else
					throw(std::out_of_range("vector"));
			}
			reference front()
			{
				return(*this->begin());
			}
			const_reference front() const
			{
				return(*this->begin());
			}

			reference back()
			{
				return(*this->end());
			}
			const_reference back() const
			{
				return(*this->end());
			}
			/* ************************Modifiers********************************* */
			void swap (vector& x) // to review later
			{
				vector<T,Alloc> tmp;
				tmp = x;
				x = *this;
				*this = tmp;
			}
			void push_back (const value_type& val)
			{
				pointer arr;
				if(this->empty() && _capacity == 0)
					_capacity  = 1;
				else if(size() + 1 > _capacity)
					_capacity = _capacity * 2;
				arr = allocator_type_.allocate(_capacity);
				for(size_type i = 0 ; i< size() ; i++)
				{
					arr[i] = vec[i];
				}
				arr[size()] = val;
				allocator_type_.deallocate(vec,size());
				vec = allocator_type_.allocate(size() + 1);
				for(size_type i = 0 ; i< size() + 1 ; i++)
					vec[i] = arr[i];
				allocator_type_.deallocate(arr,_capacity);
				_number_of_elements = size() + 1;
			}
			void pop_back()
			{
				if(!this->empty())
					allocator_type_.destroy(vec + _number_of_elements);
				_number_of_elements--;
			}
			void clear()
			{
				while(!this->empty())
					this->pop_back();
			}
			iterator erase (iterator position)
			{
				pointer arr;
				size_type first_part = begin() - position;
				size_type second_part = begin() - end();
				arr = allocator_type_.allocate(_capacity);
				for(size_t i = 0; i < first_part-1 ; i++)
					arr[i] = vec[i];
				for(size_t i = first_part; i < second_part ; i++)
					arr[i] = vec[i+1];
				allocator_type_.deallocate(vec,size());
				_number_of_elements = size() - 1;
				vec = allocator_type_.allocate(size());
				for(size_type i = 0 ; i< size() ; i++)
					vec[i] = arr[i];
				allocator_type_.deallocate(arr,size());
				return(position++);
			}
			iterator erase (iterator first, iterator last)
			{
				pointer arr;
				size_type size_to_erase = first - last;
				size_type first_part = begin() - first;
				size_type second_part = begin() - end();
				arr = allocator_type_.allocate(_capacity);
				size_t i;
				for( i = 0; i < first_part ; i++)
					arr[i] = vec[i];
				for( i = i+0 ; i < second_part - size_to_erase + 1 ; i++)
					arr[i] = vec[i + size_to_erase];
				allocator_type_.deallocate(vec,size());
				_number_of_elements = size() - size_to_erase;
				vec = allocator_type_.allocate(size());
				for(size_type i = 0 ; i< size() ; i++)
					vec[i] = arr[i];
				allocator_type_.deallocate(arr,size());
				return(last++);
			}
		private:
			allocator_type	allocator_type_;
			pointer vec;
			size_type _number_of_elements;
			size_type _capacity;

	};
	template <class T, class Alloc>
	void swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		vector<T,Alloc> tmp;
		tmp = x;
		x = y;
		y = tmp;
	}
}

#endif