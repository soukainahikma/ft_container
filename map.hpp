#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include "binary_tree.hpp"
#include "pair.hpp"
#include "tree_iterator.hpp"
#include <map>
namespace ft
{
	template < class Key, class T,class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair< const Key,T> > > 
	class map
	{
		
		public:
			typedef Key																key_type;
			typedef T																mapped_type;
			typedef ft::pair< const key_type, mapped_type>								value_type;
			typedef Compare															key_compare;
			typedef Alloc															allocator_type;
			typedef typename allocator_type::reference								reference;
			typedef typename allocator_type::const_reference						const_reference;
			typedef typename ft::node<value_type>*									pointer;
			typedef typename allocator_type::const_pointer							const_pointer;

			typedef tree_iterator<value_type, pointer>								iterator;
			// typedef _iterator<pointer>											const_iterator;
			// typedef std::reverse_iterator<iterator>								reverse_iterator;
			// typedef std::reverse_iterator<const_iterator>						const_reverse_iterator;
			// typedef typename iterator_traits<iterator>::difference_type			difference_type;
			typedef size_t											size_type;
		private:
			typedef btree<value_type, key_compare>           				__base;
		public:
			iterator begin(){return(iterator(my_avl_tree.btree_min(my_avl_tree.getroot())));};
			iterator end(){return(iterator(my_avl_tree.btree_max(my_avl_tree.getroot())));};
			__base insert(value_type key)
			{
				my_avl_tree.insert_(key);
				return(my_avl_tree);
			}
		
		private:
			allocator_type allocator_type_;
			__base my_avl_tree;
			
	};
};
#endif