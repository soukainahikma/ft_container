#include"pair.hpp"
#include "binary_tree.hpp"
#include <iostream>
#include "map.hpp"
#include <map>
int main()
{
	std::map<int, int> mymap;
	mymap.insert(std::make_pair(50,60));
	mymap.insert(std::make_pair(40,60));
	mymap.insert(std::make_pair(100,60));
	std::map<int,int>::iterator it = --mymap.end();
	std::cout << it->first<< " ===> " << it->second << std::endl;
	it--;
	std::cout << it->first<< " ===> " << it->second << std::endl;
	it--;
	std::cout << it->first<< " ===> " << it->second << std::endl;

	
	
}