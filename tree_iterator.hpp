#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP
#include <iostream>
#include "avl_tree.hpp"
#include "iterator.hpp"
namespace ft
{
	template<class Tp,class Iter>
	class tree_iterator:public __iterator<std::bidirectional_iterator_tag,
							typename iterator_traits<Tp*>::value_type >
	{
		public:
			typedef Iter														node_type;
			typedef std::bidirectional_iterator_tag								iterator_category;
			typedef typename iterator_traits<Tp*>::reference					reference;
			typedef typename iterator_traits<Tp*>::pointer						pointer;
		public:
		tree_iterator(){};
		tree_iterator(node_type node)
		{
			node_ = node;
		}
		node_type base()
		{
			return(node_);
		}
		template<class T>
		tree_iterator(const tree_iterator<T,Iter> &treeIter):node_(treeIter.base()){}
		tree_iterator<Tp,Iter> &operator=(const tree_iterator& treeIter)
		{
			node_ = treeIter.node_;
			return(*this);
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
			node_type btree_min(node_type root)
			{
				while(root->left)
					return(btree_min(root->left));
				return(root);
			}
			node_type btree_max(node_type root)
			{
				while(root->right)
					return(btree_max(root->right));
				return(root);
			}
			node_type node_successor(node_type x)
			{
				if(x->right != NULL)
					return(btree_min(x->right));
				node_type y = x->parent;
				while(y !=NULL && x == y->right)
				{
					x = y;
					y = y->parent;
				}
				return(y);
			}
			node_type node_predecessor(node_type x)
			{
				if(x->left != NULL)
					return(btree_max(x->left));
				node_type y = x->parent;
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