#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP
#include <iostream>
#include "binary_tree.hpp"
#include "iterator.hpp"
namespace ft
{
	// template <typename T>
	// struct iterator_traits {
	// 	typedef typename T::value_type				value_type;
	// 	typedef typename T::difference_type			difference_type;
	// 	typedef typename T::iterator_category		iterator_category;
	// 	typedef typename T::pointer					pointer;
	// 	typedef typename T::reference				reference;
	// };

	// template<typename T>
	// struct iterator_traits<T*>
	// {
	// 	typedef std::bidirectional_iterator_tag	iterator_category;
	// 	typedef T								value_type;
	// 	typedef T*								pointer;
	// 	typedef T&								reference;
	// 	typedef std::ptrdiff_t					difference_type;
	// };
	// template<typename T>
	// struct iterator_traits< const T*>
	// {
	// 	typedef std::bidirectional_iterator_tag	iterator_category;
	// 	typedef T								value_type;
	// 	typedef const T*						const_pointer;
	// 	typedef const T&						const_reference;
	// 	typedef std::ptrdiff_t					difference_type;
	// };
	template<class Tp,class Iter>
	class tree_iterator
	{
		public:
			typedef Iter														node_type;
			typedef typename iterator_traits<node_type>::iterator_category		iterator_category;
			typedef typename iterator_traits<node_type>::difference_type		difference_type;
			typedef typename iterator_traits<node_type>::value_type			value_type;
			typedef Tp&															reference;
			typedef Tp*															pointer;
		public:
		tree_iterator(){};
		tree_iterator(node_type node)
		{
			node_ = node;
		}
		node_type base() const
		{
			return(node_);
		}
		reference operator*() const
		{return(node_->key_value);}
		pointer operator->() const
		{
			return(&(node_->key_value));
		}
		tree_iterator &operator++()
		{
			node_ = node_successor(node_);
			return(*this);
		}
		tree_iterator operator++(int)
		{	
			tree_iterator result;
			result = *this;
			node_ = node_successor(node_);
			return(result);
		}
		tree_iterator &operator--()
		{
			node_ = node_predecessor(node_);
			return(*this);
		}
		tree_iterator operator--(int)
		{	
			tree_iterator result;
			result = *this;
			node_ = node_predecessor(node_);
			return(result);
		}			

		friend bool operator==(const tree_iterator<Tp,Iter>& __x, const tree_iterator<Tp,Iter>& __y)
		{	return __x.node_ == __y.node_;}
		friend bool operator!=(const tree_iterator<Tp,Iter>& __x, const tree_iterator<Tp,Iter>& __y)
		{	return __x.node_ != __y.node_;}
		private:
			node_type node_;
			node<Tp> *btree_min(node<Tp> *root)
			{
				while(root->left)
					return(btree_min(root->left));
				return(root);
			}
			node<Tp> *btree_max(node<Tp> *root)
			{
				while(root->right)
					return(btree_max(root->right));
				return(root);
			}
			node<Tp> *node_successor(node<Tp> *x)
			{
				if(x->right != NULL)
					return(btree_min(x->right));
				node<Tp> *y = x->parent;
				while(y !=NULL && x == y->right)
				{
					x = y;
					y = y->parent;
				}
				return(y);
			}
			node<Tp> *node_predecessor(node<Tp> *x)
			{
				if(x->left != NULL)
					return(btree_max(x->left));
				node<Tp> *y = x->parent;
				while(y !=NULL && x == y->left)
				{
					x = y;
					y = y->parent;
				}
				return(y);
			}

	};
}
#endif