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
			typedef tree_iterator<const value_type, pointer>						const_iterator;
			typedef ft::_reverseiterator<iterator>									reverse_iterator;
			typedef ft::_reverseiterator<const_iterator>							const_reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type				difference_type;
			typedef size_t											size_type;

			// template <class Key_, class T, class Compare, class Alloc>
			class value_compare:public std::binary_function<value_type,value_type,bool>
			{
				friend class map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
						{ return comp(x.first, y.first); }
			};
		private:
			typedef btree<value_type, key_compare>           				__base;
		public:
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
				// size_of_tree = 0;
			}
			template <class InputIterator>
  			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(),typename ft::enable_if<!ft::is_integral<InputIterator>::value,bool>::type = 0)
			{
				while(first != last)
				{
					my_avl_tree.insert_avl(*first);
					first++;
				}
			}
			/* assingment operator */
			map& operator= (const map& x)
			{
				// x.allocator_type_ make sure if we copy the allocator too;
				// this->size_of_tree = x.size_of_tree;
				// make sure to add the assigment operator in the btree to make a deep copy;
				this->my_avl_tree = x.my_avl_tree;
				return(*this);
			}
		/* iterators ********************************** */
			iterator begin(){return(iterator(my_avl_tree.btree_min()));};
			const_iterator begin()const {return(const_iterator(my_avl_tree.btree_min()));};
			iterator end(){
				iterator it = my_avl_tree.btree_max();
				if(it == NULL)
					return(it);
				return(++it);
			};
			const_iterator end() const{return(++const_iterator(my_avl_tree.btree_max()));};
			reverse_iterator rend() {return(reverse_iterator (begin()));};
			const_reverse_iterator rend() const{return(const_reverse_iterator (begin()));};
			reverse_iterator rbegin(){return(reverse_iterator(end()));};
			const_reverse_iterator rbegin() const {return(const_reverse_iterator(end()));};
		/* Capacity  ********************************************** */
			bool empty() const
			{
				if(my_avl_tree.empty())
					return(true);
				return(false);
			}
			size_type size() const{ return(my_avl_tree.size_btree()); }
			size_type max_size() const{return(allocator_type_.max_size());}
			/* ***********operator[]********************************************* */
			// back to understand how this operator works
			mapped_type& operator[] (const key_type& k){ return((*((this->insert(ft::make_pair(k,mapped_type()))).first)).second); }
		/* ********************modifiers***************************************** */
			ft::pair<iterator,bool> insert (const value_type& val)
			{
				ft::pair<iterator,bool> pr;
				// size_t i = size();
					my_avl_tree.insert_avl(val);
				// if(i < size())
				// {
				// 	pr.second = true;
				// 	pr.first = my_avl_tree.Search_tree(val);
				// }
				// else
				// {
				// 	pr.first = NULL;
				// 	pr.second = false;
				// }
				return(pr);

			}
			iterator insert (iterator position, const value_type& val)
			{
				static_cast<void> (position);
				return(insert(val).first);
			}
			template <class InputIterator>
  			void insert (InputIterator first, InputIterator last,typename ft::enable_if<!ft::is_integral<InputIterator>::value,bool>::type = 0)
			{
				while(first!= last)
				{
					insert(*first);
					first++;
				}
			}
			void erase (iterator position)
			{
				// if(my_avl_tree.Search_tree(*position) != NULL)
					// size_of_tree--;
				my_avl_tree.deletion_node(position->first);
			}
			size_type erase (const key_type& k)
			{
				// if(my_avl_tree.Search_tree(ft::make_pair(k,mapped_type())) != NULL)
				// {
					// size_of_tree--;
					size_t i = size();
					my_avl_tree.deletion_node(k);
					if(i< size())
						return(1);
				// }
				return(0);
			}
			void erase (iterator first, iterator last)
			{
				iterator tmp;
				std::vector<key_type> vec;
////// FIXME !!!!!!!!!!!!this is a danger zone (REMEMBER TO CHANGE THE STD OF THE VECTOR AND WORK WITH MINE)!!!!!!!!!!!!!!!!!!!
				while(first != last )
				{
					vec.push_back(first->first);
					first++;
				}
				for(size_t i = 0; i < vec.size();i++)
					erase(vec[i]);
			}
			void swap (map& x)
			{
				map y;
				y = x;
				x = *this;
				*this = y;
			}
			void clear()
			{
				erase(begin(),end());
			}
			/* ***Operations************************************** */
			iterator find (const key_type& k)
			{
				node<value_type> *node_ = my_avl_tree.Search_tree(ft::make_pair(k,mapped_type()));
				if(node_ == NULL)
					return(end());
				return(iterator(node_));
			}
			//go back to the const_iterators see if its working and fix them if not
			const_iterator find (const key_type& k) const
			{
				node<value_type> *node_ = my_avl_tree.Search_tree(ft::make_pair(k,mapped_type()));
				if(node_ == NULL)
					return(end());
				return(const_iterator(node_));

			}

			size_type count (const key_type& k) const
			{
				if(my_avl_tree.Search_tree(ft::make_pair(k,mapped_type())) != NULL)
					return(1);
				return(0);
			}
			iterator lower_bound (const key_type& k)
			{
				iterator itb = begin();
				iterator ite = end();
				while(itb != ite)
				{
					if(comp(itb->first,k))
						itb++;
					else
						return(itb);
				}
				return(ite);
			}
			const_iterator lower_bound (const key_type& k) const
			{
				const_iterator itb = begin();
				const_iterator ite = end();
				while(itb != ite)
				{
					if(comp(itb->first,k))
						itb++;
					else
						return(itb);
				}
				return(ite);
			}
			 iterator upper_bound (const key_type& k)
			 {
				iterator itb = begin();
				iterator ite = end();
				while(itb != ite)
				{
					if(!comp(k,itb->first))
						itb++;
					else
						return(itb);
				}
				return(ite);
			 }
			// const_iterator upper_bound (const key_type& k) const;
			/* ***Observers:************************************** */
			key_compare key_comp() const
			{
				return(comp);
			}
			value_compare value_comp() const
			{
				return(value_compare(comp));
			}
			void avl_printer()
			{
				my_avl_tree.print_preorder();
			}
		private:
			allocator_type allocator_type_;
			__base my_avl_tree;
			// size_type size_of_tree;
			key_compare comp;
	};
};
#endif