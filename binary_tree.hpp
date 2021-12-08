#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP
#include <iostream>
#include <map>

#define ZERO_CHILD 0
#define ONE_RIGHT_CHILD 1
#define ONE_LEFT_CHILD -1
#define TWO_CHILDREN 2

namespace ft
{
	template <class T>
	struct node
	{
		T key_value;
		node<T> *left;
		node<T> *parent;
		node<T> *right;
		int height;
		node(const T& src) : key_value(src){};
	};
	template <class T, class Compare= std::less<typename T::first_type>, class Allocator = std::allocator<node<T> > >
	class btree
	{
		public:
			typedef T				value_type;
			typedef Compare		value_compare;
			typedef Allocator		allocator_type;
		private:
			node<T>				*end_node;
			node<T>				*root;
			allocator_type		allocator_type_;
			value_compare		compare;
			size_t				bsize;
			
		public:
			btree(){
			// end_node = allocator_type_.allocate(1);
			// root->parent = end_node;
			// end_node->left = root;
			 root = NULL;
			 bsize = 0;
			//  root->height = 0;
			};
			~btree(){};//fix me
			size_t size_btree()const { return(bsize); }
			void print_preorder(){ print_preorder(root,"this is first node   "); }
			void print_inorder(){ print_inorder(root,"this is first node   "); }
			node<T> *btree_min(){ return(btree_min(root));}
			node<T> *btree_max(){ return(btree_max(root));}
			//bach to this deletion to replace the int in the key
			node<T> *deletion_node(int key){ 
				root = deletion_node(root,key);
				return(root); 
				}
			node<T> *Search_tree(T key_value)const { return(Search_tree(root,key_value)); }
			bool empty()
			{
				if(root == NULL)
					return(true);
				return(false);
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
			void print_inorder(node<T> *root,std::string str)
			{
				if (root == nullptr) {
					return;
				}
				print_inorder(root->left,"this is left         ");
				std::cout << str<<"|" <<root->key_value.first << " "<< root->key_value.second << "|"<<std::endl;
				print_inorder(root->right,"this is right        ");
			}
			node<T> *left_rotation(node<T> *node_to_rotate)
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
				y->height = std::max(height(y->left), height(y->right)) +1;
				node_to_rotate->height = std::max(height(node_to_rotate->left), height(node_to_rotate->right)) + 1;
				return(y);
			}
			node<T> *right_rotation(node<T> *node_to_rotate)
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
				y->height = std::max(height(y->left), height(y->right)) + 1;
				node_to_rotate->height = std::max(height(node_to_rotate->left), height(node_to_rotate->right)) + 1;
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
			int height(node<T> *node_)
			{
				if(node_== NULL)
					return(0);
				return(node_->height);
			}
			int get_balance(node<T> *node_)
			{
				if(node_ == NULL)
					return(0);
				return(height(node_->left) - height(node_->right));
			}
			node<T> *balance(node<T> *node_)
			{
				int balance_factor_ = get_balance(node_);
				// std::cout<< "balance_factor  " << balance_factor_ << std::endl;
				if(balance_factor_ > 1)
				{ 
					if(get_balance(node_->left) >= 0)
						node_ = right_rotation(node_);
					else
						node_ = left_right_rotation(node_);
				}
				else if(balance_factor_ < -1)
				{
					if(get_balance(node_->right) > 0)
						node_ = right_left_rotation(node_);
					else
						node_ = left_rotation(node_);
				}
				return(node_);
			}
			void insert_avl(value_type const &key)
			{
					// std::cout<< "here"<<std::endl;
				if(root == NULL)
				{
					root= allocator_type_.allocate(1);
					allocator_type_.construct(root, key);
					root->left = NULL;
					root->right = NULL;
					root->height = 1;
					bsize++;
					return;
				}
				root = insert(key,root);
				end_node = allocator_type_.allocate(1);
				root->parent = end_node;
				end_node->left = root;
			}
			node<T> *insert(value_type const &key, node<T> *root_)
			{
				if(root_ == NULL)
				{	
					root_= allocator_type_.allocate(1);
					allocator_type_.construct(root_, key);
					root_->left = NULL;
					root_->right = NULL;
					root_->height = 1;
					bsize++;
					return(root_);
				}
				if(compare(key.first , root_->key_value.first))
				{
					node<T> *child = insert(key,root_->left);
					root_->left = child;
					child->parent = root_;

				}
				else if(key.first == root_->key_value.first)
					return(root_);
				else
				{
					node<T> *child = insert(key,root_->right);
					root_->right = child;
					child->parent = root_;
				}
				root_->height = 1 + std::max(height(root_->left),height(root_->right));
				root_ = balance(root_);
				return(root_);
			}
			node<T> *btree_min(node<T> *root)
			{
				if(!root)
					return(root);
				while(root->left)
					return(btree_min(root->left));
				return(root);
			}
			node<T> *btree_max(node<T> *root)
			{
				if(!root)
					return(root);
				while(root->right)
					return(btree_max(root->right));
				return(root);
			}
			node<T> *btree_successor(node<T> *x)
			{
				if(x->right != NULL)
					return(btree_min(x->right));
				node<T> *y = x->parent;
				while(y !=NULL && x == y->right)
				{
					x = y;
					y = y->parent;
				}
				return(y);
			}
			node<T> *btree_predecessor(node<T> *x)
			{
				if(x->left != NULL)
					return(btree_max(x->left));
				node<T> *y = x->parent;
				while(y !=NULL && x == y->left)
				{
					x = y;
					y = y->parent;
				}
				return(y);
			}
			int n_children_(node<T> *node)
			{
				if(node->right && node->left == NULL)
					return(ONE_RIGHT_CHILD);
				if(node->left && node->right == NULL)
					return(ONE_LEFT_CHILD);
				if(node->left && node->right)
					return(TWO_CHILDREN);
				return(ZERO_CHILD);
			}
			node<T> *deletion_node(node<T>* root_,int key)
			{
				if(root_ == NULL)
					return(root_);
					/* come back here for compare */
				if(key < root_->key_value.first)
				{
					root_->left = deletion_node(root_->left,key);
				}
				else if(key > root_->key_value.first)
				{
					root_->right = deletion_node(root_->right,key);
				}
				else
				{
					int n_children = n_children_(root_);
					if(n_children == ZERO_CHILD)
					{
						node<T> *tmp = root_;
						root_ = NULL;
						allocator_type_.deallocate(root_,1);
					}
					else if(n_children == ONE_RIGHT_CHILD || n_children == ONE_LEFT_CHILD)
					{
						node<T> *tmp = root_->left? root_->left:root_->right;
						allocator_type_.construct(root_, tmp->key_value);
						// root_->key_value = tmp->key_value;
						if(n_children == ONE_RIGHT_CHILD )
							root_->right = NULL;
						else
							root_->left = NULL;
						allocator_type_.deallocate(tmp,1);
					}
					else if(n_children == TWO_CHILDREN)
					{
						node<T> *tmp = btree_min(root_->right);
						allocator_type_.construct(root_, tmp->key_value);
						// root_->key_value = tmp->key_value;
						root_->right = deletion_node(root_->right,tmp->key_value.first);
					}
					bsize--;
				}
				if(root_ == NULL)
					return(root_);
				root_ = balance(root_);
				return(root_);
			}
			node<T> *Search_tree(node<T> *root_ , T key_value) const
			{
				if(root_ != NULL)
				{
					if(root_->key_value.first == key_value.first)
						return(root_);
					if(compare(key_value.first,root_->key_value.first))
						return(Search_tree(root_->left,key_value));
					else
						return(Search_tree(root_->right,key_value));
				}
				return(root_);
			}
	};
}
			
#endif