#include"pair.hpp"
#include "binary_tree.hpp"
#include <iostream>
#include "map.hpp"
#include <map>
int main()
{
	ft::map<int, int> mymap;
	mymap.insert(ft::make_pair(50,60));
	mymap.insert(ft::make_pair(40,60));
	mymap.insert(ft::make_pair(100,60));
	ft::map<int,int>::reverse_iterator it = mymap.end();
	ft::map<int,int>::reverse_iterator it2 = it;
	std::cout << (*it2).first<< " ===> " << it2->second << std::endl;
	if(it != it2)
		std::cout<< "they are equal"<< std::endl;
	else
	std::cout<< "they are not equal"<< std::endl;
}