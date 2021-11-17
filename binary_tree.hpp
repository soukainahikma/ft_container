#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP
#include <iostream>
namespace ft
{
	template <class T>
	struct node
	{
		T key_value;
		node<T> *left;
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
			void insert(value_type key)
			{
				if (root != NULL)
				{
					insert(key,root);
				}
				else
				{
					root= allocator_type_.allocate(1);
					root->key_value = key;
					root->left = NULL;
					root->right = NULL;
				}
			}
			void insert(value_type key, node<T> *leaf)
			{
				node<T> *traverse = leaf;
				node<T> *tmp;
				while(traverse != NULL)
				{
					tmp = traverse;
					if(compare(key.first , traverse->key_value.first))
						traverse = traverse->left;
					else
						traverse = traverse->right;
				}
				traverse = allocator_type_.allocate(1);
				traverse->key_value = key;
				traverse->left=NULL;
				traverse->right= NULL;
				if(compare(key.first , tmp->key_value.first))
						tmp->left = traverse;
				/* here i should balance tmp */
					else
						tmp->right = traverse;
				/* here i should balance tmp */
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
			void printer(btree<T> tree)
			{
				print_preorder(tree.root, "this is first node   ");
			}
			
			node<T> *right_rotation(node<T> *node_to_rotate)
			{
				node<T> *y;
				node<T> *tmp;
				y = node_to_rotate->left;
				tmp = y->right;
				y->right = node_to_rotate;
				node_to_rotate->left = tmp;
				return(y);
			}
			node<T> *left_rotation(node<T> *node_to_rotate)
			{
				node<T> *y;
				node <T> *tmp;
				y = node_to_rotate->right;
				tmp = y->left;
				y->left = node_to_rotate;
				node_to_rotate->right = tmp;
				return(y);
			}
			node<T> *left_right_rotation(node<T> *node_to_rotate)
			{
				node<T> *y = node_to_rotate->left;;
				node_to_rotate->left = left_rotation(y);
				return(right_rotation(node_to_rotate));
			}
			node<T> *right_left_rotation(node<T> *node_to_rotate)
			{
				node<T> *y = node_to_rotate->right;
				node_to_rotate->right = right_rotation(y);
				return(left_rotation(node_to_rotate));
			}
			int height_calculator(node<T> node_)
			{
				int h =0;
				if(t!= NULL)
				{
					
				}
			}
			int balance_factor(node<T> node_)
			{
				/* difference of height of the left and the right */

			}
			node<T> *balance(node<T> *node_)
			{
				/* calculate balance factor */
				/*	check on blance factor to chose rotation calculate difference to know wich rotation*/

			}
	};
			}
			

#endif
