#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP
#include <iostream>
#include <map>
namespace ft
{
	template <class T>
	struct node
	{
		T key_value;
		node<T> *left;
		node<T> *parent;
		node<T> *right;
	};
	template <class T, class Compare= std::less<typename T::first_type>, class Allocator = std::allocator<node<T> > >
	class btree
	{
		public:
			typedef T				value_type;
			typedef Compare		value_compare;
			typedef Allocator		allocator_type;

		private:
			node<T> *root;
			allocator_type allocator_type_;
			value_compare compare;
		public:
			btree(){ root = NULL;};
			~btree(){};
			node<T> *getroot()
			{
				return(root);
			}
			void print_preorder(node<T> *root,std::string str)
			{
				if (root == nullptr) {
					return;
				}
				std::cout << str<<"|" <<root->key_value.first << " "<< root->key_value.second << "|"<<std::endl;
				print_preorder(root->left,"this is left         ");
				print_preorder(root->right,"this is right        ");
			}
			node<T> *right_rotation(node<T> *node_to_rotate)
			{
				node<T> *y;
				node <T> *tmp;
				y = node_to_rotate->right;
				y->parent = node_to_rotate->parent;
				tmp = y->left;
				y->left = node_to_rotate;
				node_to_rotate->parent = y;
				node_to_rotate->right = tmp;
				if(tmp != NULL)
					tmp->parent  = node_to_rotate;
				return(y);
			}
			node<T> *left_rotation(node<T> *node_to_rotate)
			{
				node<T> *y;
				node<T> *tmp;
				y = node_to_rotate->left;
				y->parent = node_to_rotate->parent;
				tmp = y->right;
				y->right = node_to_rotate;
				node_to_rotate->parent = y;
				node_to_rotate->left = tmp;
				if(tmp != NULL)
					tmp->parent  = node_to_rotate;
				return(y);
			}
			node<T> *left_right_rotation(node<T> *node_to_rotate)
			{
				node<T> *y = node_to_rotate->left;;
				node_to_rotate->left = right_rotation(y);
				return(left_rotation(node_to_rotate));
			}
			node<T> *right_left_rotation(node<T> *node_to_rotate)
			{
				node<T> *y = node_to_rotate->right;
				node_to_rotate->right = left_rotation(y);
				return(right_rotation(node_to_rotate));
			}
			int height_calculator(node<T> *node_)
			{
				int h =0;
				if(node_!= NULL)
				{
					int l_height = height_calculator(node_->left);
					int r_height = height_calculator(node_->right);
					int max_height= std::max(l_height,r_height);
					h = max_height + 1;
				}
				return(h);
			}
			int balance_factor(node<T> *node_)
			{
				int l_height = height_calculator(node_->left);
				int r_height = height_calculator(node_->right);
				int balance_factor_ = l_height - r_height ;
				return(balance_factor_);
			}
			node<T> *balance(node<T> *node_)
			{
				int balance_factor_ = balance_factor(node_);
				if(balance_factor_ > 1)
				{
					if(balance_factor(node_->left)> 0)
						node_ = left_rotation(node_);
					else
						node_ = left_right_rotation(node_);
				}
				else if(balance_factor_ < -1)
				{
					if(balance_factor(node_->right)> 0)
						node_ = right_left_rotation(node_);
					else
						node_ = right_rotation(node_);
				}
				return(node_);
			}
			void insert_(value_type key)
			{
					root = insert(key,root);
			}
			node<T> *insert(value_type key, node<T> *root_)
			{
				if(root_ == NULL)
				{	
					root_= allocator_type_.allocate(1);
					root_->key_value = key;
					root_->left = NULL;
					root_->right = NULL;
					root_->parent = NULL;
					return(root_);
				}
				if(compare(key.first , root_->key_value.first))
				{
					node<T> *child = insert(key,root_->left);
					root_->left = child;
					child->parent = root_;
					root_ = balance(root_);
				}
				else
				{
					node<T> *child = insert(key,root_->right);
					root_->right = child;
					child->parent = root_;
					root_ = balance(root_);
				}
				return(root_);
			}
	};
}
			
#endif
