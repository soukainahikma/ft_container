#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include<iterator>
/* template <class Category,  class T,class Distance = ptrdiff_t,class Pointer = T*,class Reference = T& >
struct struct_Iterator_traits
{
	typedef T         value_type;
	typedef Distance  difference_type;
	typedef Pointer   pointer;
	typedef Reference reference;
	typedef Category  iterator_category;
	
}; */

template<class _Category, class _Tp, class _Distance = ptrdiff_t, class _Pointer = _Tp*, class _Reference = _Tp&>
struct my_iterator
{
    typedef _Tp        value_type;
    typedef _Distance  difference_type;
    typedef _Pointer   pointer;
    typedef _Reference reference;
    typedef _Category  iterator_category;
};
template<typename T>
class iter_container:my_iterator<std::random_access_iterator_tag,T,std::ptrdiff_t, T*,T&>
{
		public:
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