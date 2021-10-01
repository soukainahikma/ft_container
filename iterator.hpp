#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <vector>
template<typename Iter>
struct iterator_traits
{
    typedef ptrdiff_t difference_type;
    typedef Iter value_type;
    typedef Iter* pointer;
    typedef Iter& reference;
    typedef std::random_access_iterator_tag iterator_category;
};
template<typename T>
class _iterator
{
	typedef typename iterator_traits<T>::value_type  value_type ;
	typedef typename iterator_traits<T>::difference_type  difference_type ;
	typedef typename iterator_traits<T>::pointer  pointer ;
	typedef typename iterator_traits<T>::reference  reference ;
	typedef typename iterator_traits<T>::iterator_category  iterator_category ;

		public:
///////////******************************************************CONSTRUCTORS********************************************************************
			_iterator(){};
			_iterator(T* ptr)// parametrized constructor
			{
				ptr_toIter = ptr;
			};
			_iterator(const _iterator<T>& rawIterator)// copy constructor
			{
				*this = rawIterator;
			};
			~_iterator(){};
///////////*************************************************OPERATORS*************************************************************************
			_iterator<T>&  operator=(const _iterator<T>& rawIterator)//see if we have to use std:: allocate or new
			{
				ptr_toIter = new T;
				this->ptr_toIter = rawIterator.ptr_toIter;
				return(*this);
			};
			T& operator*() const
			{
				return *ptr_toIter;
			}
			_iterator operator++()
			{
				(ptr_toIter)++;
				return(*this);
			}
			_iterator operator--()
			{
				(ptr_toIter)--;
				return(*this);
			}

			_iterator operator + (difference_type a)
			{
				this->ptr_toIter = this->ptr_toIter + a;
				return(*this);
			}

			_iterator operator - (difference_type a)
			{
				this->ptr_toIter = this->ptr_toIter - a;
					return(*this);
			}
			_iterator operator += (difference_type a)
			{
				this->ptr_toIter += a;
				return(*this);
			}

			_iterator operator -= (difference_type a)
			{
				this->ptr_toIter -=a;
					return(*this);
			}
			_iterator operator--(int)
			{	
				_iterator result;
				result = *this;
				this->ptr_toIter--;
				return(result);
			}
			_iterator operator++(int)
			{	
				_iterator result;
				result = *this;
				this->ptr_toIter++;
				return(result);
			}
			T &operator[](unsigned int i){
					return this->ptr_toIter[i];
			}
			T *operator->(){return(this->ptr_toIter);}
		protected:
			T* ptr_toIter;
};

template<typename T>
class _reverseiterator: public _iterator<T>
{
		typedef typename iterator_traits<T>::value_type  value_type ;
		typedef typename iterator_traits<T>::difference_type  difference_type ;
		typedef typename iterator_traits<T>::pointer  pointer ;
		typedef typename iterator_traits<T>::reference  reference ;
		typedef typename iterator_traits<T>::iterator_category  iterator_category ;

		public:
///////////******************************************************CONSTRUCTORS********************************************************************
			_reverseiterator(){};
			_reverseiterator(T* ptr)// parametrized constructor
			{
				this->ptr_toIter = ptr;
			};
			_reverseiterator(const _reverseiterator<T>& rawIterator)// copy constructor
			{
				*this = rawIterator;
			};
			~_reverseiterator(){};
///////////*************************************************OPERATORS*************************************************************************
			_reverseiterator<T>&  operator=(const _reverseiterator<T>& rawIterator)//see if we have to use std:: allocate or new
			{
				this->ptr_toIter = new T;
				this->ptr_toIter = rawIterator.ptr_toIter;
				return(*this);
			};
			T& operator*() const
			{
				return *(this->ptr_toIter);
			}
			_reverseiterator operator++()
			{
				(this->ptr_toIter)--;
				return(*this);
			}
			_reverseiterator operator--()
			{
				(this->ptr_toIter)++;
				return(*this);
			}

			_reverseiterator operator + (difference_type a)
			{
				this->ptr_toIter = this->ptr_toIter - a;
				return(*this);
			}

			_reverseiterator operator - (difference_type a)
			{
				this->ptr_toIter = this->ptr_toIter + a;
					return(*this);
			}
			_reverseiterator operator += (difference_type a)
			{
				this->ptr_toIter -= a;
				return(*this);
			}

			_reverseiterator operator -= (difference_type a)
			{
				this->ptr_toIter +=a;
					return(*this);
			}
			_reverseiterator operator--(int)
			{	
				_reverseiterator result;
				result = *this;
				this->ptr_toIter++;
				return(result);
			}
			_reverseiterator operator++(int)
			{	
				_reverseiterator result;
				result = *this;
				this->ptr_toIter--;
				return(result);
			}
			T &operator[](unsigned int i){
					return this->ptr_toIter[i];
			}
};
#endif
