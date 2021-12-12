#include "../vector.hpp"
#include <vector>


int main ()
{
 std::cout << "- Erase elements" << std::endl;
    {ft::vector<int> myvector1;
    for (int i=1; i<=10; i++) myvector1.push_back(i);
    std::cout << myvector1.size() << std::endl;
    std::cout << myvector1.capacity() << std::endl;
    myvector1.erase (myvector1.begin() - 1);
    myvector1.erase (myvector1.begin(),myvector1.begin()+3);
    std::cout << myvector1.size() << std::endl;
    std::cout << myvector1.capacity() << std::endl;
    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector1.size(); ++i)
        std::cout << ' ' << myvector1[i];
    std::cout << std::endl;}
 
    
}