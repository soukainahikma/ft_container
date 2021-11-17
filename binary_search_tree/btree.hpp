#ifndef BTREE_HPP
#define BTREE_HPP
#include <iostream>
struct node
{
	int key_value;
	node *left;
	node *right;
};
class btree
{
	private:
		node *root;
		void insert(int key, node *leaf);
	public:
		btree();
		~btree();
		void insert(int key);
		void print_preorder(node *root);
		void printer(btree tree);
};
#endif