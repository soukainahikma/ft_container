#ifndef ITERATOR_HPP
#define ITERATOR_HPP

template<class _Category, class _Tp, class _Distance = ptrdiff_t, class _Pointer = _Tp*, class _Reference = _Tp&>
struct my_iterator_traits
{
    typedef _Tp        value_type;
    typedef _Distance  difference_type;
    typedef _Pointer   pointer;
    typedef _Reference reference;
    typedef _Category  iterator_category;
};
template<typename T>
class my__wrap_iter // :my_iterator_traits<std::random_access_iterator_tag,T,std::ptrdiff_t, T*,T&>
{
		public:
			// typedef T* pointer;
			my__wrap_iter(){};// default constructor
			my__wrap_iter(T* ptr){
				ptr_toIter = ptr;
			};// parametrized constructor
			// my__wrap_iter(const my__wrap_iter<T>& rawIterator){};// copy constructor
			~my__wrap_iter(){};
			// my__wrap_iter<T>&  operator=(const my__wrap_iter<T>& rawIterator){};
			T& operator*() const{
				return *ptr_toIter;
			}
			my__wrap_iter operator++()
			{
				(ptr_toIter)++;
				return(*this);
			}
			my__wrap_iter operator--()
			{
				(ptr_toIter)--;
				return(*this);
			}
		protected:
			T* ptr_toIter;
};
#endif

/* 
Construct a class template iterator that has:

member atributes:
		iterator_category
		velue_type
		difference_type
		pointer
		reference
constructors:
		parameterized with value_type
		copy constructor
		deconstructor
operators:
		=
		bool (we ll see about this one)
		+=
		-=
		++
		--
		+
		-
		(and other operators)
		*
		geters(for the ptr and const ptr)
private attribute:
	the pointer of the chosen data

 */

// and another class for the reverse iterator