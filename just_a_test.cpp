#include <iostream>
// #include <vector>
// #include <stack>
#include "vector.hpp"
#include "stack.hpp"


int main ()
{
   ft::vector <int> s1, s2, s3;
    s1.push_back( 5 );
    s1.push_back( 10 );
    s2.push_back( 1 );
    s2.push_back( 2 );
    s3.push_back( 5 );
    s3.push_back( 10 );
    if ( s1 <= s2 )
        std::cout << "The stack s1 is less than or equal to "
            << "the stack s2." << std::endl;
    else
        std::cout << "The stack s1 is greater than "
            << "the stack s2." << std::endl;

    if ( s1 <= s3 )
        std::cout << "The stack s1 is less than or equal to "
            << "the stack s3." << std::endl;
    else
        std::cout << "The stack s1 is greater than "
            << "the stack s3." << std::endl;
}