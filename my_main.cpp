#include "vector.hpp"
#include "iterator.hpp" 

int main () {
   std::cout << "NOTE - Constructor"<< std::endl;
   { ft::vector<int> first;                                
    ft::vector<int> second (4,100);                      
    ft::vector<int> third (second.begin(),second.end()); 
    ft::vector<int> fourth (third);                       
    int myints[] = {16,2,77,29};
    ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
    std::cout << "The contents of fifth are:";
    for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';}
}