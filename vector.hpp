#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include "iterator.hpp"

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
			typedef _iterator<const_pointer>							const_iterator;
			typedef _reverseiterator<const_iterator>					const_reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type	difference_type;
			typedef size_t												size_type;
			explicit vector (const allocator_type& alloc = allocator_type())
			{
				_capacity = 0;
				allocator_type_ = alloc;
				_number_of_elements = 0;
				vec = nullptr;
			}
			explicit vector (size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type())// parametrized 
			{
				allocator_type_ = alloc;
				vec = allocator_type_.allocate(n);
				_number_of_elements = n;
				for (size_type i = 0; i < n; i++)
					vec[i] = val;
				_capacity = n;
			}
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value,bool>::type = 0)
			{
				allocator_type_ = alloc;
				_number_of_elements = last - first;
				_capacity = _number_of_elements;
				vec = allocator_type_.allocate(_capacity);
				for (size_t i = 0; i < _number_of_elements; i++)
					vec[i] = *(first++);
			}
			vector (const vector& x)
			{
				_number_of_elements = x.size();
				vec = allocator_type_.allocate(_number_of_elements);
				
				for (size_type i = 0; i < _number_of_elements; i++)
				{
					vec[i] = x.vec[i];
				}
			}
			~vector(){allocator_type_.deallocate(vec,_capacity);}
			iterator begin(){return(iterator(&vec[0]));};
			const_iterator begin() const {return(const_iterator(&vec[0]));};
			iterator end(){return(iterator(&vec[_number_of_elements]));};
			const_iterator end() const {return(const_iterator(&vec[_number_of_elements]));};
			reverse_iterator rend(){return(reverse_iterator(&vec[0]));};
			reverse_iterator rbegin(){return(reverse_iterator(&vec[_number_of_elements]));};
			const_reverse_iterator rend()const {return(const_reverse_iterator(&vec[0]));};
			const_reverse_iterator rbegin()const {return(const_reverse_iterator(&vec[_number_of_elements]));};
			size_type size() const{
			difference_type n =end()- begin();
				return(n);
			};
			size_type max_size() const{return(allocator_type_.max_size());};
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
				else if(n > size_)
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
						swap(arr);
						_number_of_elements = arr.size();
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
					if(n< _capacity * 2)
						n = _capacity *2;
					vector<T> arr(n);
					arr._number_of_elements = size();
					for(size_type i = 0; i< size(); i++ )
						arr.vec[i]= vec[i];
					swap(arr);
				}
			}
			vector& operator= (const vector& x)
			{
				allocator_type_.deallocate(vec,size());
				_capacity = x._capacity;
				_number_of_elements = x._number_of_elements;
				vec = allocator_type_.allocate(_capacity);
				_number_of_elements = x._number_of_elements;
				for(size_t i =0 ; i < size() ;i++)
				{
					vec[i] = x.vec[i];
				}
				return(*this);
			}
			reference &operator[](size_type n)
			{
						return this->vec[n];
			}
			const_reference &operator[](size_type n) const
			{
				return this->vec[n];
			}
			reference at (size_type n)
			{
					 if(n < size())
				 		return(this->vec[n]);
					else
					 	throw(std::out_of_range("vector"));
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
				return(*(this->end() - 1));
			}
			const_reference back() const
			{
				return(*this->end());
			}
			void swap (vector& x)
			{
				vector<T,Alloc> tmp;
				tmp = x;
				x = *this;
				*this = tmp;
			}
			void push_back (const value_type& val)
			{
				if( _capacity == 0)
					_capacity  = 1;
				else if(size() + 1 > _capacity)
					_capacity = _capacity * 2;
				
				vector<T,Alloc> new_vec(_capacity);
				for(size_type i = 0 ; i< size() ; i++)
				{
					new_vec[i] = vec[i];
				}
				new_vec[size()] = val;
				new_vec._number_of_elements = size() +1;
				swap(new_vec);
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
				iterator it = position;
				while(it != end())
				{
					*it = *(it+1);
					it++;
				}
				pop_back();
				return(position++);
			}
			iterator erase (iterator first, iterator last)
			{
				size_t size_ = last - first;
				iterator it = first ;
				for(size_t i = 0; i< size_; i++)
				{
					it = erase(it);
				}
				return(it);
			}
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value,bool>::type = 0)
			{
				size_type sizeOfVec = size();
				vector<T, Alloc> tmp(first,last);
				size_type sizeOfAssigne = tmp.size();
				swap(tmp);
				if(sizeOfAssigne > sizeOfVec)
					reserve(sizeOfAssigne);
				else
					reserve(sizeOfVec);
			}
			void assign (size_type n, const value_type& val)
			{
				size_type sizeOfAssigne = n;
				size_type sizeOfVec = size();
				vector<T, Alloc> tmp(n,val);
				swap(tmp);
				if(sizeOfAssigne > sizeOfVec)
					reserve(sizeOfAssigne);
				else
					reserve(sizeOfVec);
			}
			allocator_type get_allocator() const
			{
				return(allocator_type_);
			}
			iterator insert (iterator position, const value_type& val)
			{
				iterator first = begin();
				vector<T, Alloc> tmp;
				tmp.reserve(_capacity);
				while(first < position)
				{
					tmp.push_back(*first);
					first++;
				}
				size_type to_add = tmp.size();
				tmp.push_back(val);
				while(first < end())
				{
			
					tmp.push_back(*first);
					first++;
				}
				swap(tmp);
				return(begin() + to_add);
			}
			 void insert (iterator position, size_type n, const value_type& val)
			 {
				 size_type i = 0;
				 while(i < n)
				 {
					position = insert(position,val) + 1;
					 i++;
				 }
			 }
			 template <class InputIterator>
				void insert (iterator position, InputIterator first, InputIterator last,
						typename ft::enable_if<!ft::is_integral<InputIterator>::value,bool>::type = 0)
				{
					difference_type diff = last - first;
					difference_type diff1 = position - begin();
					reserve(size() + diff);
					position = begin() + diff1; 
					while(first != last)
					{
						position = insert(position, *first) +1;
						first++;
					}
				}
		private:
			allocator_type	allocator_type_;
			pointer vec;
			size_type _number_of_elements;
			size_type _capacity;

	};
template <class T, class Alloc >
void swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
{
	vector<T,Alloc> tmp;
	tmp = x;
	x = y;
	y = tmp;
}
template <class InputIterator1, class InputIterator2>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
							InputIterator2 first2, InputIterator2 last2)
{
	while (first1!=last1)
	{
		if (first2==last2 || *first2<*first1)
			return false;
		else if (*first1<*first2)
			return true;
		++first1; ++first2;
	}
	return (first2!=last2);
}
template <class InputIterator1, class InputIterator2>
bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
{
while (first1!=last1) 
{
	if (!(*first1 == *first2))
		return false;
	++first1; ++first2;
}
return true;
}
template <class T, class Alloc>
bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return(lhs.size() == rhs.size() && equal(lhs.begin(),lhs.end(),rhs.begin()));
}
template <class T, class Alloc>
bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return(!(lhs == rhs));
}
template <class T, class Alloc>
bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return(lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end()));
}
template <class T, class Alloc>
bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return(!(rhs < lhs));
}
template <class T, class Alloc>
bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return(rhs<lhs);
}
template <class T, class Alloc>
bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return(!(lhs < rhs));
}
}

#endif