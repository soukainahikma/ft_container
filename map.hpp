#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include "binary_tree.hpp"
#include "pair.hpp"
#include "tree_iterator.hpp"
#include"iterator.hpp"
#include"my_traits.hpp"
#include <map>
#include <vector>
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
			typedef const tree_iterator<value_type, pointer>						const_iterator;
			typedef ft::_reverseiterator<iterator>									reverse_iterator;
			typedef ft::_reverseiterator<const_iterator>							const_reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type				difference_type;
			typedef size_t											size_type;
		private:
			typedef btree<value_type, key_compare>           				__base;
		public:
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){}
			template <class InputIterator>
  			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(),typename ft::enable_if<!ft::is_integral<InputIterator>::value,bool>::type = 0)
			{
				// last++;
				while(first != last)
				{
					my_avl_tree.insert_(*first);
					first++;
				}
				my_avl_tree.print_preorder(my_avl_tree.getroot(), "first node   ");
			}
		/* iterators ********************************** */
			iterator begin(){return(iterator(my_avl_tree.btree_min(my_avl_tree.getroot())));};
			const_iterator begin()const {return(const_iterator(my_avl_tree.btree_min(my_avl_tree.getroot())));};
			iterator end(){return(iterator(my_avl_tree.get_end_node()));};
		/* ********************************************** */
			ft::pair<iterator,bool> insert (const value_type& val)
			{
				ft::pair<iterator,bool> pr;
				node<value_type> *node_ = my_avl_tree.Search_tree(my_avl_tree.getroot(),val);
				if(node_ == NULL)
				{
					pr.second = true;
					my_avl_tree.insert_(val);
					pr.first = my_avl_tree.Search_tree(my_avl_tree.getroot(),val);
				}
				else
				{
					pr.first = node_;
					pr.second = false;
				}
				return(pr);

			}
			void avl_printer()
			{
				my_avl_tree.print_preorder(my_avl_tree.getroot(),"this is first node   ");
			}
		private:
			allocator_type allocator_type_;
			__base my_avl_tree;
	};
};
#endif