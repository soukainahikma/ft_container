#include"pair.hpp"
#include "binary_tree.hpp"
#include <iostream>
#include "map.hpp"
#include <map>
#include<vector>
int main ()
{
  ft::map<int,int> mymap;

  mymap[1]=10;
  mymap[2]=20;
  mymap[3]=30;

  ft::pair<ft::map<int,int>::iterator,ft::map<int,int>::iterator> ret;
  ret = mymap.equal_range(-1);

  std::cout << "lower bound points to: ";
  std::cout << ret.first->first << " => " << ret.first->second << '\n';

  std::cout << "upper bound points to: ";
  std::cout << ret.second->first << " => " << ret.second->second << '\n';

  return 0;
}