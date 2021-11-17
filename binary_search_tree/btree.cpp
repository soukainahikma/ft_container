#include "btree.hpp"
#include <stack>

btree::btree()
{
	root = NULL;
}
btree::~btree(){}
void btree::insert(int key, node* leaf)
{
	node *traverse = leaf;
	node *tmp;
	// if(key < leaf->key_value)
	// 	traverse = leaf->left;
	// else
	// 	traverse = leaf->right;
	while(traverse != NULL)
	{
		tmp = traverse;
		if(key < traverse->key_value)
			traverse = traverse->left;
		else
			traverse = traverse->right;
	}
	traverse = new node;
	traverse->key_value = key;
	traverse->left=NULL;
	traverse->right= NULL;
	if(key < tmp->key_value)
			tmp->left = traverse;
		else
			tmp->right = traverse;
}
void btree::insert(int key)
{
		
	if (root != NULL)
	{
		insert(key,root);
	}
	else
	{
		root= new node;
		root->key_value = key;
		root->left = NULL;
		root->right = NULL;
	}
}


void btree::print_preorder(node *root)
{
	if (root == nullptr) {
        return;
    }
 
    // Display the data part of the root (or current node)
    std::cout << root->key_value << " ";
 
    // Traverse the left subtree
    print_preorder(root->left);
 
    // Traverse the right subtree
    print_preorder(root->right);
	
}
void btree::printer(btree tree)
{
	print_preorder(tree.root);
}