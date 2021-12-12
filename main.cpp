#include "vector.hpp"
#include "map.hpp"
#include<map>
#include<vector>

#ifndef NS
#define NS  ft
#endif
template <typename T, typename U>
void print_map(NS::map<T, U> &mp, char const *label)
{
	std::cout << "\nmap Size: " << mp.size();
	std::cout << "\nmap [" << label << "] contains: ";
	if (!mp.size())
		std::cout << "nothing";
	else
		std::cout << "\n\n";
	for (typename NS::map<T, U>::iterator it = mp.begin(); it != mp.end(); ++it)
	{
		std::cout << "[" << it->first << "]"
				  << " = " << it->second << std::endl;
	}
	std::cout << std::endl;
}
template <typename T>
void print_vector(NS::vector<T> &vect, char const *label)
{
	std::cout << "\nvector Size: " << vect.size();
	std::cout << "\nvector [" << label << "] contains:";
	if (!vect.size())
		std::cout << "\tnothing";
	for (typename NS::vector<T>::iterator it = vect.begin(); it != vect.end(); ++it)
	{
		std::cout << "  [ " << *it << " ]";
	}
	std::cout << std::endl;
}
int main()
{
	std::cout << "- Erase elements" << std::endl;
    {NS::vector<int> myvector1;
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
    std::cout << std::endl;
    }
}