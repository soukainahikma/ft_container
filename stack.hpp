#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>
#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef Container			container_type;
			typedef T					value_type;
			typedef size_t				size_type;
			stack():c(){};
			stack (const container_type& ctnr):c(ctnr){};
			bool empty() const{return(c.empty());};
			size_type size() const {return(c.size());};
			value_type& top(){return(c.back());};
			const value_type& top() const{return(c.back());};
			void push (const value_type& val){ c.push_back(val);};
			void pop(){c.pop_back();};
			template <class T1, class CT>
				friend bool operator== (const stack<T1,CT>& lhs, const stack<T1,CT>& rhs);
			template <class T1, class CT>
				friend bool operator< (const stack<T1,CT>& lhs, const stack<T1,CT>& rhs);
			template <class T1, class CT>
				friend bool operator!= (const stack<T1,CT>& lhs, const stack<T1,CT>& rhs);
			template <class T1, class CT>
				friend bool operator<= (const stack<T1,CT>& lhs, const stack<T1,CT>& rhs);
			template <class T1, class CT>
				friend bool operator>  (const stack<T1,CT>& lhs, const stack<T1,CT>& rhs);
			template <class T1, class CT>
				friend bool operator>= (const stack<T1,CT>& lhs, const stack<T1,CT>& rhs);
		protected:
    		container_type c;
	};
	template <class T, class Container>
		bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{
			return(lhs.c == rhs.c);
		}
	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return(!(lhs.c == rhs.c));
	}
	template <class T, class Container>
		bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{
			return(lhs.c < rhs.c);
		}
	template <class T, class Container>
		bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{
			return(!(rhs.c < lhs.c));
		}
	template <class T, class Container>
		bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{
			return(rhs.c<lhs.c);
		}
	template <class T, class Container>
		bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{
			return(!(lhs.c < rhs.c));
		}

}

#endif