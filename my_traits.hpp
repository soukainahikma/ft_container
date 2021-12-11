#include <iostream>

namespace ft
{
	template <typename T>
	struct iterator_traits
	{
		typedef typename T::value_type				value_type;
		typedef typename T::difference_type			difference_type;
		typedef typename T::iterator_category		iterator_category;
		typedef typename T::pointer					pointer;
		typedef typename T::reference				reference;
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
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef std::ptrdiff_t					difference_type;
	};
	template<class Category, class T, class Distance = std::ptrdiff_t,
			 class Pointer = T*, class Reference = T&>
	struct __iterator
	{
		typedef T								value_type;
		typedef Distance						difference_type;
		typedef Pointer							pointer;
		typedef Reference						reference;
		typedef Category						iterator_category;
	};

	template<bool Cond, class T = void>
		struct enable_if {};
	template<class T>
		struct enable_if<true, T> { typedef T type; };	

	template <class T> struct is_integral					: public std::false_type{};
	template <> struct is_integral<bool>					: public std::true_type {};
	template <> struct is_integral<char>					: public std::true_type {};
	template <> struct is_integral<char16_t>				: public std::true_type {};
	template <> struct is_integral<char32_t>				: public std::true_type {};
	template <> struct is_integral<wchar_t>					: public std::true_type {};
	template <> struct is_integral<signed char>				: public std::true_type {};
	template <> struct is_integral<short int>				: public std::true_type {};
	template <> struct is_integral<int>						: public std::true_type {};
	template <> struct is_integral<long int> 				: public std::true_type {};
	template <> struct is_integral<long long int>			: public std::true_type {};
	template <> struct is_integral<unsigned char>			: public std::true_type {};
	template <> struct is_integral<unsigned short int>		: public std::true_type {};
	template <> struct is_integral<unsigned int>			: public std::true_type {};
	template <> struct is_integral<unsigned long int>		: public std::true_type {};
	template <> struct is_integral<unsigned long long int>	: public std::true_type {};


}