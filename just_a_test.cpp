#include <iostream>
// #include <type_traits>
// #include <vector>

// #include "my_traits.hpp"
// // 1. the return type (bool) is only valid if T is an integral type:
// template <class T>
// typename ft::enable_if<ft::is_integral<T>::value,bool>::type is_odd (T i) {return bool(i%2);}

// // 2. the second template argument is only valid if T is an integral type:
// // template < class T,
// //            class = typename std::enable_if<std::is_integral<T>::value>::type>
// // bool is_even (T i) {return !bool(i%2);}

// int main() {

//   short int i = 1;    // code does not compile if type of i is not integral
//   std::string s = "hah";    // code does not compile if type of i is not integral
//   std::string s2 ="alkdfj";
//   std::cout << std::boolalpha;
//   std::cout << "i is odd: " << is_odd(s) << std::endl;
//   // std::cout << "i is odd: " << is_odd(s) << std::endl;
//   // std::cout << "i is even: " << is_even(i) << std::endl;

//   return 0;
// }