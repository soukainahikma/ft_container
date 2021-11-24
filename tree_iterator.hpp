#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP
#include <iostream>
namespace ft
{
	template <typename T>
	struct iterator_traits {
		typedef typename T::value_type				value_type;
		typedef typename T::difference_type			difference_type;
		typedef typename T::iterator_category		iterator_category;
		typedef typename T::pointer					pointer;
		typedef typename T::reference				reference;
	};

	template<typename T>
	struct iterator_traits<T*>
	{
		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::ptrdiff_t					difference_type;
	};
	template<typename T>
	struct iterator_traits< const T*>
	{
		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef const T*						const_pointer;
		typedef const T&						const_reference;
		typedef std::ptrdiff_t					difference_type;
	};
	template<class Iter>
	class tree_iterator
	{
		public:
			typedef Iter											iter_type;
			typedef iterator_traits<iter_type>::iterator_category	iterator_category;
			typedef iterator_traits<iter_type>::difference_type		difference_type;
			typedef iterator_traits<iter_type>::reference			reference;
			typedef iterator_traits<iter_type>::pointer				pointer;
			typedef tree<Iter>
		public:
		iter_type base() const;
		{
			return(_tree)
		}
		private;
			iter_type __tree;
	};
}
#endif