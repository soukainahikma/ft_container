#include"pair.hpp"
#include "binary_tree.hpp"
#include <iostream>
#include "map.hpp"
#include <map>
int main()
{
	
	{std::cout<< "this result is for my_map "<<std::endl;
	ft::map<int ,int> mymap;
	mymap.insert(ft::make_pair(50,10));
	mymap.insert(ft::make_pair(40,11));
	mymap.insert(ft::make_pair(30,12));
	mymap.insert(ft::make_pair(20,12));
	mymap.insert(ft::make_pair(61,12));
	mymap.insert(ft::make_pair(70,12));
	mymap.insert(ft::make_pair(55,12));
	mymap.insert(ft::make_pair(41,12));
	mymap.insert(ft::make_pair(10,12));
	mymap.insert(ft::make_pair(5,12));
	mymap.insert(ft::make_pair(2,12));
	ft::map<int,int>::iterator it= mymap.end();
	mymap.avl_printer();
	it--;
	std::cout<< it->first << std::endl;}
	{std::cout<< "this result is for the other map "<<std::endl;
	std::map<int ,int> mymap;
	mymap.insert(std::make_pair(50,10));
	mymap.insert(std::make_pair(40,11));
	mymap.insert(std::make_pair(30,12));
	mymap.insert(std::make_pair(20,12));
	mymap.insert(std::make_pair(61,12));
	mymap.insert(std::make_pair(70,12));
	mymap.insert(std::make_pair(55,12));
	mymap.insert(std::make_pair(41,12));
	mymap.insert(std::make_pair(10,12));
	mymap.insert(std::make_pair(5,12));
	mymap.insert(std::make_pair(2,12));
	std::map<int,int>::iterator it= mymap.end();
	it--;
	std::cout<< it->first << std::endl;}
	// std::map<int,int> range_map(mymap.begin(),mymap.end());

	
	//std::btree<std::pair<int, int> > = std::btree<std::pair<const int, int>>

	

}