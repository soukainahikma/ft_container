#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP
#include <iostream>

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
	template <class T, class Compare, class Allocator>
	class avl_tree
	{
		public:
			typedef T																	value_type;
			typedef Compare																value_compare;
			typedef typename Allocator::template rebind<node<value_type> >::other		allocator_type;
		private:
			node<value_type>					*end_node;
			node<value_type>					*root;
			allocator_type						allocator_type_;
			value_compare						compare;
			size_t								bsize;
		public:
			avl_tree()
			{
				root = NULL;
				end_node = allocator_type_.allocate(1);
				bsize = 0;
			};
			void clear()
			{
				clear(root);
				root= NULL;
			}
			void clear(node<value_type> *root_)
			{
				if (root_ == nullptr)
					return;
				allocator_type_.deallocate(root_,1);
				bsize--;
				clear(root_->left);
				clear(root_->right);
			}
			~avl_tree()
			{
				clear(root);
				allocator_type_.deallocate(end_node,1);
				
			};
			size_t max_size() const{return(allocator_type_.max_size());}
			size_t size_avl_tree()const { return(bsize); }
			void print_preorder(){ print_preorder(root,"this is first node   "); }
			void print_inorder(){ print_inorder(root,"this is first node   "); }
			node<value_type> *avl_tree_min()const{ return(avl_tree_min(root));}
			node<value_type> *avl_tree_max()const { return(avl_tree_max(root));}
			node<value_type> *Search_tree(value_type key_value)const { return(Search_tree(root,key_value)); }
			node<value_type> *deletion_node(value_type key)
			{
				root = deletion_node(root,key);
				return(root);
			}
			bool empty() const
			{
				if(root == NULL)
					return(true);
				return(false);
			}
			void print_preorder(node<value_type> *root,std::string str)
			{
				if (root == nullptr) {
					return;
				}
				std::cout << str<<"|" <<root->key_value.first << " "<< root->key_value.second << "|"<<std::endl;
				print_preorder(root->left,"this is left         ");
				print_preorder(root->right,"this is right        ");
			}
			void print_inorder(node<value_type> *root,std::string str)
			{
				if (root == nullptr) {
					return;
				}
				print_inorder(root->left,"this is left         ");
				std::cout << str<<"|" <<root->key_value.first << " "<< root->key_value.second << "|"<<std::endl;
				print_inorder(root->right,"this is right        ");
			}
			node<value_type> *left_rotation(node<value_type> *node_to_rotate)
			{
				node<value_type> *y;
				node<value_type> *tmp;
				y = node_to_rotate->right;
				y->parent = node_to_rotate->parent;
				tmp = y->left;
				y->left = node_to_rotate;
				node_to_rotate->parent = y;
				node_to_rotate->right = tmp;
				if(tmp != NULL)
					tmp->parent  = node_to_rotate;
				y->height = std::max(height(y->left), height(y->right)) + 1;
				node_to_rotate->height = std::max(height(node_to_rotate->left), height(node_to_rotate->right)) + 1;
				return(y);
			}
			node<value_type> *right_rotation(node<value_type> *node_to_rotate)
			{
				node<value_type> *y;
				node<value_type> *tmp;
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
			node<value_type> *left_right_rotation(node<value_type> *node_to_rotate)
			{
				node<value_type> *y = node_to_rotate->left;;
				node_to_rotate->left = left_rotation(y);
				return(right_rotation(node_to_rotate));
			}
			node<value_type> *right_left_rotation(node<value_type> *node_to_rotate)
			{
				node<value_type> *y = node_to_rotate->right;
				node_to_rotate->right = right_rotation(y);
				return(left_rotation(node_to_rotate));
			}
			int height(node<value_type> *node_)
			{
				if(node_== NULL)
					return(0);
				return(node_->height);
			}
			int get_balance(node<value_type> *node_)
			{
				if(node_ == NULL)
					return(0);
				return(height(node_->left) - height(node_->right));
			}
			node<value_type> *balance(node<value_type> *node_)
			{
				int balance_factor_ = get_balance(node_);
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
				if(root == NULL)
				{
					root= allocator_type_.allocate(1);
					allocator_type_.construct(root, key);
					root->left = NULL;
					root->right = NULL;
					root->height = 1;
					// end_node = allocator_type_.allocate(1);
					bsize++;
				}
				//FIXME end node
				else
					root = insert(key,root);
				root->parent = end_node;
				end_node->left = root;
				return;
			}
			node<value_type> *insert(value_type const &key, node<value_type> *root_)
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
					node<value_type> *child = insert(key,root_->left);
					root_->left = child;
					child->parent = root_;

				}
				else if(key.first == root_->key_value.first)
					return(root_);
				else
				{
					node<value_type> *child = insert(key,root_->right);
					root_->right = child;
					child->parent = root_;
				}
				root_->height = 1 + std::max(height(root_->left),height(root_->right));
				root_ = balance(root_);
				return(root_);
			}
			node<value_type> *avl_tree_min(node<value_type> *root)const
			{
				if(!root)
					return(root);
				while(root->left)
					return(avl_tree_min(root->left));
				return(root);
			}
			node<value_type> *avl_tree_max(node<value_type> *root)const 
			{
				if(!root)
					return(root);
				while(root->right)
					return(avl_tree_max(root->right));
				return(root);
			}
			node<value_type> *avl_tree_successor(node<value_type> *x)
			{
				if(x->right != NULL)
					return(avl_tree_min(x->right));
				node<value_type> *y = x->parent;
				while(y !=NULL && x == y->right)
				{
					x = y;
					y = y->parent;
				}
				return(y);
			}
			node<value_type> *avl_tree_predecessor(node<value_type> *x)
			{
				if(x->left != NULL)
					return(avl_tree_max(x->left));
				node<value_type> *y = x->parent;
				while(y !=NULL && x == y->left)
				{
					x = y;
					y = y->parent;
				}
				return(y);
			}
			int n_children_(node<value_type> *node)
			{
				if(node->right && node->left == NULL)
					return(ONE_RIGHT_CHILD);
				if(node->left && node->right == NULL)
					return(ONE_LEFT_CHILD);
				if(node->left && node->right)
					return(TWO_CHILDREN);
				return(ZERO_CHILD);
			}
			node<value_type> *deletion_node(node<value_type>* root_,value_type key)
			{
				if(root_ == NULL)
					return(root_);
				if(compare(key.first, root_->key_value.first))
				{
					root_->left = deletion_node(root_->left,key);
				}
				else if(!compare(key.first , root_->key_value.first) && key.first != root_->key_value.first)
				{
					root_->right = deletion_node(root_->right,key);
				}
				else
				{
					int n_children = n_children_(root_);
					if(n_children == ZERO_CHILD)
					{
						node<value_type> *tmp = root_;
						root_ = NULL;
						allocator_type_.deallocate(tmp,1);
					}
					else if(n_children == ONE_RIGHT_CHILD || n_children == ONE_LEFT_CHILD)
					{
						node<value_type> *tmp = root_->left? root_->left:root_->right;
						allocator_type_.construct(root_, tmp->key_value);
						if(n_children == ONE_RIGHT_CHILD )
							root_->right = NULL;
						else
							root_->left = NULL;
						allocator_type_.deallocate(tmp,1);
					}
					else if(n_children == TWO_CHILDREN)
					{
						node<value_type> *tmp = avl_tree_min(root_->right);
						allocator_type_.construct(root_, tmp->key_value);
						root_->right = deletion_node(root_->right,tmp->key_value);
					}
					bsize--;
				}
				if(root_ == NULL)
					return(root_);
				root_ = balance(root_);
				return(root_);
			}
			node<value_type> *Search_tree(node<value_type> *root_ ,value_type key_value) const
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