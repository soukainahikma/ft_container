#ifndef ITERATOR_TEST_HPP
#define ITERATOR_TEST_HPP

template <typename T>
struct iterator_traits {
    typedef typename T::value_type            value_type;
    typedef typename T::difference_type       difference_type;
    typedef typename T::iterator_category     iterator_category;
    typedef typename T::pointer               pointer;
    typedef typename T::reference             reference;
};

template<typename T>
struct iterator_traits<T*>
{
	typedef std::random_access_iterator_tag	iterator_category;
	typedef T								value_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef std::ptrdiff_t					difference_type;
};

template<typename T>
struct iterator_traits< const T*>
{
	typedef std::random_access_iterator_tag	iterator_category;
	typedef T								value_type;
	typedef const T*						const_pointer;
	typedef const T&						const_reference;
	typedef std::ptrdiff_t					difference_type;
};

template<class Category, class T, class Distance = ptrdiff_t,
         class Pointer = T*, class Reference = T&>
struct __iterator
{
    typedef T         value_type;
    typedef Distance  difference_type;
    typedef Pointer   pointer;
    typedef Reference reference;
    typedef Category  iterator_category;
};

// template<class Iterator>
// class _iterator :public __iterator<typename iterator_traits<Iterator>::iterator_category,
//                       typename iterator_traits<Iterator>::value_type,
//                       typename iterator_traits<Iterator>::difference_type,
//                       typename iterator_traits<Iterator>::pointer,
//                       typename iterator_traits<Iterator>::reference>
// {
template<class Iterator>
class _iterator
{
	// typedef typename iterator_traits<Iterator>::value_type  value_type ;
	// typedef typename iterator_traits<Iterator>::difference_type  difference_type ;
	// typedef typename iterator_traits<Iterator>::pointer  pointer ;
	// typedef typename iterator_traits<Iterator>::reference  reference ;
	// typedef typename iterator_traits<Iterator>::iterator_category  iterator_category ;


	typedef Iterator                                            iterator_type;
    typedef typename iterator_traits<Iterator>::difference_type difference_type;
    typedef typename iterator_traits<Iterator>::reference       reference;
    typedef typename iterator_traits<Iterator>::pointer         pointer;

		public:
///////////******************************************************CONSTRUCTORS********************************************************************
			_iterator(){};
			_iterator(pointer ptr)// parametrized constructor
			{
				ptr_toIter = ptr;
			};
			_iterator(const _iterator<Iterator> & rawIterator)// copy constructor
			{
				*this = rawIterator;
			};
			~_iterator(){};
///////////*************************************************OPERATORS*************************************************************************
			_iterator<Iterator>&  operator=(const _iterator<Iterator>& rawIterator)//see if we have to use std:: allocate or new
			{
				this->ptr_toIter = rawIterator.ptr_toIter;
				return(*this);
			};
			reference operator*() const
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
			Iterator &operator[](unsigned int i){
					return this->ptr_toIter[i];
			}
			Iterator *operator->(){return(this->ptr_toIter);}
		protected:
			pointer ptr_toIter;
};

// template<typename T>
// class _reverseiterator: public _iterator<T>
// {
// 		typedef typename iterator_traits<T>::value_type  value_type ;
// 		typedef typename iterator_traits<T>::difference_type  difference_type ;
// 		typedef typename iterator_traits<T>::pointer  pointer ;
// 		typedef typename iterator_traits<T>::reference  reference ;
// 		typedef typename iterator_traits<T>::iterator_category  iterator_category ;

// 		public:
// ///////////******************************************************CONSTRUCTORS********************************************************************
// 			_reverseiterator(){};
// 			_reverseiterator(T* ptr)// parametrized constructor
// 			{
// 				this->ptr_toIter = ptr;
// 			};
// 			_reverseiterator(const _reverseiterator<T>& rawIterator)// copy constructor
// 			{
// 				*this = rawIterator;
// 			};
// 			~_reverseiterator(){};
// ///////////*************************************************OPERATORS*************************************************************************
// 			_reverseiterator<T>&  operator=(const _reverseiterator<T>& rawIterator)//see if we have to use std:: allocate or new
// 			{
// 				this->ptr_toIter = new T;
// 				this->ptr_toIter = rawIterator.ptr_toIter;
// 				return(*this);
// 			};
// 			T& operator*() const
// 			{
// 				return *(this->ptr_toIter);
// 			}
// 			_reverseiterator operator++()
// 			{
// 				(this->ptr_toIter)--;
// 				return(*this);
// 			}
// 			_reverseiterator operator--()
// 			{
// 				(this->ptr_toIter)++;
// 				return(*this);
// 			}

// 			_reverseiterator operator + (difference_type a)
// 			{
// 				this->ptr_toIter = this->ptr_toIter - a;
// 				return(*this);
// 			}

// 			_reverseiterator operator - (difference_type a)
// 			{
// 				this->ptr_toIter = this->ptr_toIter + a;
// 					return(*this);
// 			}
// 			_reverseiterator operator += (difference_type a)
// 			{
// 				this->ptr_toIter -= a;
// 				return(*this);
// 			}

// 			_reverseiterator operator -= (difference_type a)
// 			{
// 				this->ptr_toIter +=a;
// 					return(*this);
// 			}
// 			_reverseiterator operator--(int)
// 			{	
// 				_reverseiterator result;
// 				result = *this;
// 				this->ptr_toIter++;
// 				return(result);
// 			}
// 			_reverseiterator operator++(int)
// 			{	
// 				_reverseiterator result;
// 				result = *this;
// 				this->ptr_toIter--;
// 				return(result);
// 			}
// 			T &operator[](unsigned int i){
// 					return this->ptr_toIter[i];
// 			}
// };
#endif
