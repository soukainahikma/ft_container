#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iostream>
#include "my_traits.hpp"
namespace ft
{
	template<class Iterator>
	class _iterator:public __iterator<std::random_access_iterator_tag,
							typename iterator_traits<Iterator>::value_type >
	{
		public:
			typedef Iterator													iterator_type;
			typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
			typedef typename iterator_traits<iterator_type>::reference			reference;
			typedef typename iterator_traits<iterator_type>::pointer			pointer;

			public:
				iterator_type base() const
				{
					return(ptr_toIter);
				}
				_iterator(){ptr_toIter = NULL};
				_iterator(iterator_type ptr)
				{
					ptr_toIter = ptr;
				};
				template<class Iter>
				_iterator(const _iterator<Iter> & rev_it):ptr_toIter(rev_it.base()){};
				reference operator*() const
				{
					return *ptr_toIter;
				}
				_iterator &operator++()
				{
					(ptr_toIter)++;
					return(*this);
				}
				_iterator operator++(int)
				{	
					_iterator result;
					result = *this;
					++(this->ptr_toIter);
					return(result);
				}
				_iterator &operator--()
				{
					(ptr_toIter)--;
					return(*this);
				}
				_iterator operator--(int)
				{	
					_iterator result;
					result = *this;
					--this->ptr_toIter;
					return(result);
				}
				_iterator operator + (difference_type a) const
				{
					_iterator<iterator_type> tmp;
					tmp = *this;
					tmp.ptr_toIter = tmp.ptr_toIter + a;
					return(tmp);
				}

				_iterator operator - (difference_type a) const
				{
					_iterator<iterator_type> tmp;
					tmp = *this;
					tmp.ptr_toIter = tmp.ptr_toIter - a;
						return(tmp);
				}
				_iterator &operator += (difference_type a)
				{
					this->ptr_toIter += a;
					return(*this);
				}

				_iterator &operator -= (difference_type a)
				{
					this->ptr_toIter -=a;
						return(*this);
				}
				
				reference operator[](difference_type i) const{
						return *(*this + i);
				}
				pointer operator->() const
				{
					return(&(operator*()));
				}
			private:
				iterator_type ptr_toIter;
	};
	template <class U,class V>
	bool operator== (const _iterator<U>& lhs,const _iterator<V>& rhs)
	{
		return(lhs.base() == rhs.base());
	};
	template <class U,class V>
	bool operator!= (const _iterator<U>& lhs,const _iterator<V>& rhs)
	{
		return(lhs.base() != rhs.base());
	};
	template <class U,class V>
	bool operator<  (const _iterator<U>& lhs,const _iterator<V>& rhs)
	{
		return(lhs.base() < rhs.base());
	};
	template <class U,class V>
	bool operator<= (const _iterator<U>& lhs,const _iterator<V>& rhs)
	{
			return(lhs.base() <= rhs.base());
	};
	template <class U,class V>
	bool operator>  (const _iterator<U>& lhs, const _iterator<V>& rhs)
	{
		return(lhs.base() > rhs.base());
	};
	template <class U,class V>
	bool operator>= (const _iterator<U>& lhs, const _iterator<V>& rhs)
	{
		return(lhs.base() >= rhs.base());
	};
	template <class Iterator>
	_iterator<Iterator> operator+ (typename _iterator<Iterator>::difference_type n, const _iterator<Iterator>& rev_it)
	{
		return(n + rev_it);
	};
	template <class Iterator>
	typename _iterator<Iterator>::difference_type operator- (const _iterator<Iterator>& lhs,const _iterator<Iterator>& rhs)
	{
		return( lhs.base() - rhs.base());
	};
	
	template<class Iterator>
	class _reverseiterator
	{
			typedef Iterator													iterator_type;
			typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
			typedef typename iterator_traits<iterator_type>::value_type			value_type;
			typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
			typedef typename iterator_traits<iterator_type>::reference			reference;
			typedef typename iterator_traits<iterator_type>::pointer			pointer;
			public:
				iterator_type base() const
				{
					return(ptr_toIter);
				}
				_reverseiterator(){ptr_toIter = NULL};
				_reverseiterator(iterator_type it) : ptr_toIter(it){};
				template<class Iter>
				_reverseiterator(const _reverseiterator<Iter>& rev_it)
				{
					*this = rev_it;
				};
				reference operator*() const
				{
					iterator_type tmp = ptr_toIter;
					return (*(--tmp));
				}
				_reverseiterator& operator++()
				{
					--(this->ptr_toIter);
					return(*this);
				}
				_reverseiterator operator++(int)
				{	
					_reverseiterator result;
					result = *this;
					--this->ptr_toIter;
					return(result);
				}
				_reverseiterator &operator--()
				{
					++(this->ptr_toIter);
					return(*this);
				}
				_reverseiterator operator--(int)
				{	
					_reverseiterator result;
					result = *this;
					++this->ptr_toIter;
					return(result);
				}
				_reverseiterator operator + (difference_type a) const
				{
					_reverseiterator<iterator_type> tmp;
					tmp = *this;
					tmp.ptr_toIter = tmp.ptr_toIter - a;
					return(tmp);
				}
				_reverseiterator operator - (difference_type a) const
				{
					_reverseiterator<iterator_type> tmp;
					tmp = *this;
					tmp.ptr_toIter = tmp.ptr_toIter + a;
					return(tmp);
				}
				_reverseiterator &operator += (difference_type a)
				{
					this->ptr_toIter -= a;
					return(*this);
				}
				_reverseiterator &operator -= (difference_type a)
				{
					this->ptr_toIter +=a;
					return(*this);
				}
				
				reference operator[](difference_type i) const
				{
					return *(*this + i);
				}
				pointer operator->() const
				{
					return&(operator*());
				}
		private:
			iterator_type ptr_toIter;
	};
	template <class Iterator>
	bool operator== (const _reverseiterator<Iterator>& lhs,const _reverseiterator<Iterator>& rhs)
	{
		return(lhs.base() == rhs.base());
	};
	template <class Iterator>
	bool operator!= (const _reverseiterator<Iterator>& lhs,const _reverseiterator<Iterator>& rhs)
	{
		return(lhs.base() != rhs.base());
	};
	template <class Iterator>
	bool operator<  (const _reverseiterator<Iterator>& lhs,const _reverseiterator<Iterator>& rhs)
	{
		return(lhs.base() > rhs.base());
	};
	template <class Iterator>
	bool operator<= (const _reverseiterator<Iterator>& lhs,const _reverseiterator<Iterator>& rhs)
	{
			return(lhs.base() >= rhs.base());
	};
	template <class Iterator>
	bool operator>  (const _reverseiterator<Iterator>& lhs, const _reverseiterator<Iterator>& rhs)
	{
		return(lhs.base() < rhs.base());
	};
	template <class Iterator>
	bool operator>= (const _reverseiterator<Iterator>& lhs, const _reverseiterator<Iterator>& rhs)
	{
		return(lhs.base() <= rhs.base());
	};
	template <class Iterator>
	_reverseiterator<Iterator> operator+ (typename _reverseiterator<Iterator>::difference_type n, const _reverseiterator<Iterator>& rev_it)
	{
		return(n - rev_it);
	};
	template <class Iterator>
	typename _reverseiterator<Iterator>::difference_type operator- (const _reverseiterator<Iterator>& lhs,const _reverseiterator<Iterator>& rhs)
	{
		return(lhs.base() -rhs.base());
	};
};
#endif
