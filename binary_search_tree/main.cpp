#include "btree.hpp"

int main()
{
	btree mytree;

	mytree.insert(29);
	mytree.insert(15);
	mytree.insert(13);
	mytree.insert(16);
	mytree.insert(35);
	mytree.insert(30);
	mytree.insert(37);
	mytree.printer(mytree);

}