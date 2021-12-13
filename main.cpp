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
	{
		std::cout<<"this the first test "<< std::endl;
	NS::vector<int> myvector(3, 100);
	std::cout << myvector.size() << std::endl;
	std::cout << myvector.capacity() << std::endl;
	NS::vector<int>::iterator it;
	it = myvector.begin();
	it = myvector.insert ( it , 200 );
	myvector.insert (it,2,300);
	it = myvector.begin();
	NS::vector<int> anothervector (2,400);
	std::cout << "THIS IS SIZE  " << myvector.size() << std::endl;
	std::cout << "THIS IS CAPACITY " << myvector.capacity() << std::endl;
	myvector.insert (it+2,anothervector.begin(),anothervector.end());
	std::cout << "THIS IS SIZE  " << myvector.size() << std::endl;
	std::cout << "THIS IS CAPACITY " << myvector.capacity() << std::endl;
	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);
	std::cout << "THIS IS SIZE  " << myvector.size() << std::endl;
	std::cout << "THIS IS CAPACITY " << myvector.capacity() << std::endl;
	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
	std::cout << ' ' << *it;
	std::cout << '\n';
	}
	{
		std::cout << "\ncapacity()" << std::endl;
		std::cout << "=======================================" << std::endl;
		NS::vector<size_t> vec(50, 500);
		NS::vector<size_t> myvect(4, 100);
		std::cout<< "here ----------------------------" <<std::endl;
		std::cout << "myvect.capacity() is: " << myvect.capacity() << '\n';
		std::cout << "myvect.size() is: " << myvect.size() << '\n';

		myvect.push_back(200);
		std::cout << "myvect.capacity() is: " << myvect.capacity() << '\n';
		std::cout << "myvect.size() is: " << myvect.size() << '\n';
		
		myvect.insert(myvect.begin(), vec.begin(), vec.end());

		std::cout << "myvect.capacity() is: " << myvect.capacity() << '\n';
		std::cout << "myvect.size() is: " << myvect.size() << '\n';

		myvect.push_back(200);
		std::cout << "myvect.capacity() is: " << myvect.capacity() << '\n';
		std::cout << "myvect.size() is: " << myvect.size() << '\n';
		std::cout << "=======================================" << std::endl;
	}
}