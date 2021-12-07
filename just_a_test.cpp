#include"pair.hpp"
#include "binary_tree.hpp"
#include <iostream>
#include "map.hpp"
#include <map>
int main ()
{
  std::map<char,int> mymap;
  std::map<char,int>::iterator it;

  // insert some values:
  mymap['a']=10;
  // mymap['b']=20;
  // mymap['c']=30;
  // mymap['d']=40;
  // mymap['e']=50;
  // mymap['f']=60;
  // mymap.avl_printer();
  mymap.erase('a');
    it = mymap.end();
it++;
  std::cout << it->first << std::endl;
  // it = mymap.begin();
// for (it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';
  // it=mymap.find('b');
  // mymap.erase (mymap.begin());                   // erasing by iterator

  // mymap.erase ('c');                  // erasing by key

  // it=mymap.find ('e');
  // mymap.erase ( mymap.begin(), mymap.end() );    // erasing by range
// mymap.avl_printer();
  // show content:
  

  return 0;
}