// #include "../iterator.hpp"
// #include "../reverse_iterator.hpp"
#include "../vector.hpp"
// #include "../stack.hpp"

typedef struct data
{
    int a;
    int b;
    // data() {std::cout << "Constructor Default\n";}
    data(int a = 1337, int b = 42) : a(a), b(b)
    {
        std::cout << "a: " << a << ", b: " << b << std::endl;
        std::cout << "Constructor parametrse\n";
    }
    data(const data& dt) {*this = dt;}
    data& operator= (const data& dt)
    {
        if (this != &dt)
        {
            this->a = dt.a;
            this->b = dt.b;
        }
        return (*this);
    }
} t_data;

int main()
{
    // *************************************************************************
                                //NOTE - Vector
    // *************************************************************************

    std::cout << "- Constructor" << std::endl;
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

    std::cout << "- Assign content (operator=)" << std::endl;
   { ft::vector<int> foo (3,0);
    ft::vector<int> bar (5,0);
    bar = foo;
    foo = ft::vector<int>();
    std::cout << "Size of foo: " << int(foo.size()) << '\n';
    std::cout << "Size of bar: " << int(bar.size()) << '\n';}

    std::cout << "- Return iterator to beginning" << std::endl;
   { ft::vector<int> myvector;
    for (int i=1; i<=5; i++) myvector.push_back(i);
    std::cout << "myvector contains:";
    for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';}
    
    std::cout << "- Return iterator to end" << std::endl;
    {ft::vector<int> myvector;
    for (int i=1; i<=5; i++) myvector.push_back(i);
    std::cout << "myvector contains:";
    for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';}
    
    std::cout << "- Return reverse iterator to reverse beginning" << std::endl;
   { ft::vector<int> myvector (5);  // 5 default-constructed ints
    int i=0;
    ft::vector<int>::reverse_iterator rit = myvector.rbegin();
    for (; rit!= myvector.rend(); ++rit)
        *rit = ++i;
    std::cout << "myvector contains:";
    for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';}
    
    std::cout << "- Return reverse iterator to reverse end" << std::endl;
    {ft::vector<int> myvector (5); 
    ft::vector<int>::reverse_iterator rit = myvector.rbegin();
    int i=0;
    for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
        *rit = ++i;
    std::cout << "myvector contains:";
    for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';}
    
    std::cout << "- Return size" << std::endl;
    // ft::vector<int> myints;
    // std::cout << "0. size: " << myints.size() << '\n';
    // for (int i=0; i<10; i++) myints.push_back(i);
    // std::cout << "1. size: " << myints.size() << '\n';
    // myints.insert (myints.end(),10,100);
    // std::cout << "2. size: " << myints.size() << '\n';
    // myints.pop_back();
    // std::cout << "3. size: " << myints.size() << '\n';
    
    std::cout << "- Return maximum size" << std::endl;
   { ft::vector<int> myvector;
    for (int i=0; i<100; i++) myvector.push_back(i);
    std::cout << "size: " << myvector.size() << "\n";
    std::cout << "capacity: " << myvector.capacity() << "\n";
    std::cout << "max_size: " << myvector.max_size() << "\n"; }
    
    std::cout << "- Change size" << std::endl;
  {  ft::vector<int> myvector;
    for (size_t i=1;i<10;i++) myvector.push_back(i);
    myvector.resize(5);
    myvector.resize(8,100);
    myvector.resize(12);
    myvector.resize(30, 60);
    myvector.resize(15, 60);
    std::cout << "myvector contains:";
    for (size_t i=0;i<myvector.size();i++)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';}
    
    std::cout << "- Return size of allocated storage capacity" << std::endl;
   { ft::vector<int> myvector;
    for (int i=0; i<100; i++) myvector.push_back(i);
    std::cout << "size: " << (int) myvector.size() << '\n';
    std::cout << "capacity: " << (int) myvector.capacity() << '\n';
    std::cout << "max_size: " << (int) myvector.max_size() << '\n';}
    
    std::cout << "- Test whether vector is empty" << std::endl;
    {ft::vector<int> myvector;
    int sum (0);
    for (int i=1;i<=10;i++) myvector.push_back(i);
    while (!myvector.empty())
    {
        sum += myvector.back();
        myvector.pop_back();
    }
    std::cout << "total: " << sum << '\n';}
    
    std::cout << "- Request a change in capacity" << std::endl;
    {ft::vector<int>::size_type sz;
    ft::vector<int> foo;
    sz = foo.capacity();
    std::cout << "making foo grow:\n";
    for (int i=0; i<100; ++i) {
        foo.push_back(i);
        if (sz!=foo.capacity()) {
        sz = foo.capacity();
        std::cout << "capacity changed: " << sz << '\n';
        }
    }
    ft::vector<int> bar;
    sz = bar.capacity();
    bar.reserve(100);   // this is the only difference with foo above
    std::cout << "making bar grow:\n";
    for (int i=0; i<100; ++i) {
        bar.push_back(i);
        if (sz!=bar.capacity()) {
        sz = bar.capacity();
        std::cout << "capacity changed: " << sz << '\n';
        }
    }}
    
    std::cout << "- Access element" << std::endl;
  {  ft::vector<int> myvector (10);
    ft::vector<int>::size_type sz = myvector.size();
    for (unsigned i=0; i<sz; i++) myvector[i]=i;
    for (unsigned i=0; i<sz/2; i++)
    {
        int temp;
        temp = myvector[sz-1-i];
        myvector[sz-1-i]=myvector[i];
        myvector[i]=temp;
    }
    std::cout << "myvector contains:";
    for (unsigned i=0; i<sz; i++)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';}
    
    std::cout << "- Access element" << std::endl;
    {ft::vector<int> myvector (10);
    for (unsigned i=0; i<myvector.size(); i++)
        myvector.at(i)=i;
    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size(); i++)
        std::cout << ' ' << myvector.at(i);
    std::cout << '\n';}

    std::cout << "- Access first element" << std::endl;
   { ft::vector<int> myvector;
    myvector.push_back(78);
    myvector.push_back(16);
    myvector.front() -= myvector.back();
    std::cout << "myvector.front() is now " << myvector.front() << '\n';}
    
    std::cout << "- Access last element" << std::endl;
   { ft::vector<int> myvector;
    myvector.push_back(10);
    while (myvector.back() != 0)
    {
        myvector.push_back ( myvector.back() -1 );
    }
    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size() ; i++)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';}
    
    std::cout << "- Assign vector content" << std::endl;
    {ft::vector<int> first;
    ft::vector<int> second;
    ft::vector<int> third;
    first.assign (7,100);          
    ft::vector<int>::iterator it;
    it=first.begin()+1;
    second.assign (it,first.end()-1);
    int myints[] = {1776,7,4};
    third.assign (myints,myints+3);
    std::cout << "Size of first: " << int (first.size()) << '\n';
    std::cout << "Size of second: " << int (second.size()) << '\n';
    std::cout << "Size of third: " << int (third.size()) << '\n';}
    
    std::cout << "- Add element at the end" << std::endl;
    // ft::vector<int> myvector;
    // int myint;
    // std::cout << "Please enter some integers (enter 0 to end):\n";
    // do {
    //     std::cin >> myint;
    //     myvector.push_back (myint);
    // } while (myint);
    // std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
    
    std::cout << "- Delete last element" << std::endl;
   { ft::vector<int> myvector;
    int sum (0);
    myvector.push_back (100);
    myvector.push_back (200);
    myvector.push_back (300);
    while (!myvector.empty())
    {
        sum+=myvector.back();
        myvector.pop_back();
    }
    std::cout << "The elements of myvector add up to " << sum << '\n';}
    
    std::cout << "- Clear content" << std::endl;
    {ft::vector<int> myvector;
    myvector.push_back (100);
    myvector.push_back (200);
    myvector.push_back (300);
    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size(); i++)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';
    std::cout << myvector.size() << std::endl;
    std::cout << myvector.capacity() << std::endl;
    myvector.clear();
    std::cout << myvector.size() << std::endl;
    std::cout << myvector.capacity() << std::endl;
    myvector.push_back (1101);
    myvector.push_back (2202);
    std::cout << myvector.size() << std::endl;
    std::cout << myvector.capacity() << std::endl;
    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size(); i++)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';}
    
    std::cout << "- Insert elements" << std::endl;
    // ft::vector<int> myvector(3, 100);
    // std::cout << myvector.size() << std::endl;
    // std::cout << myvector.capacity() << std::endl;
    // ft::vector<int>::iterator it;
    // it = myvector.begin();
    // it = myvector.insert ( it , 200 );
    // myvector.insert (it,2,300);
    // it = myvector.begin();
    // ft::vector<int> anothervector (2,400);
    // std::cout << myvector.size() << std::endl;
    // std::cout << myvector.capacity() << std::endl;
    // myvector.insert (it+2,anothervector.begin(),anothervector.end());
    // std::cout << myvector.size() << std::endl;
    // std::cout << myvector.capacity() << std::endl;
    // int myarray [] = { 501,502,503 };
    // myvector.insert (myvector.begin(), myarray, myarray+3);
    // std::cout << "myvector contains:";
    // for (it=myvector.begin(); it<myvector.end(); it++)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';

    // ft::vector<int> vec;
    // vec.push_back(10);
    // vec.push_back(20);
    // vec.push_back(30);
    // vec.push_back(40);
    // ft::vector<int>::iterator it = vec.insert(vec.begin(), 3);
    // vec.insert(it, 2);
    // int i = 2;
    // it = vec.insert(vec.begin() + i, 7);
    // std::cout << "The vector elements are: ";
    // for (ft::vector<int>::iterator it1 = vec.begin(); it1 != vec.end(); ++it1)
    //     std::cout << *it1 << " ";
    // std::cout << '\n';
    
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

    std::cout << "- Swap content" << std::endl;
{    ft::vector<int> foo(3, 100);   // three ints with a value of 100
    ft::vector<int> bar(5, 200);   // five ints with a value of 200
    std::cout << "Size foo before " << foo.size() << std::endl;
    std::cout << "Capa foo before " << foo.capacity() << std::endl;
    std::cout << "Size bar before " << bar.size() << std::endl;
    std::cout << "Capa bar before " << bar.capacity() << std::endl;
    foo.swap(bar);
    std::cout << "Size foo after " << foo.size() << std::endl;
    std::cout << "Capa foo after " << foo.capacity() << std::endl;
    std::cout << "Size bar after " << bar.size() << std::endl;
    std::cout << "Capa bar after " << bar.capacity() << std::endl;
    std::cout << "foo contains:";
    for (unsigned i=0; i<foo.size(); i++)
        std::cout << ' ' << foo[i];
    std::cout << '\n';
    std::cout << "bar contains:";
    for (unsigned i=0; i<bar.size(); i++)
        std::cout << ' ' << bar[i];
    std::cout << '\n';}

    std::cout << "- Get allocator" << std::endl;
    {ft::vector<int> myvector;
    int * p;
    unsigned int i;
    p = myvector.get_allocator().allocate(5);
    for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);
    std::cout << "The allocated array contains:";
    for (i=0; i<5; i++) std::cout << ' ' << p[i];
    std::cout << '\n';
    for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
    myvector.get_allocator().deallocate(p,5);}
    
    std::cout << "- Relational operators for vector" << std::endl;
  {  ft::vector<int> foo (1,200);   // three ints with a value of 100
    ft::vector<int> bar (1,100);   // two ints with a value of 200

    if (foo==bar) std::cout << "foo and bar are equal\n";
    if (foo!=bar) std::cout << "foo and bar are not equal\n";
    if (foo< bar) std::cout << "foo is less than bar\n";
    if (foo> bar) std::cout << "foo is greater than bar\n";
    if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
    if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";}
 
    std::cout << "- Exchange contents of vectors" << std::endl;
    {ft::vector<int> foo(3,100);   // three ints with a value of 100
    ft::vector<int> bar(5,200);   // five ints with a value of 200
    ft::swap(foo, bar);
    std::cout << "foo contains:";
    for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << "bar contains:";
    for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';}

    // *************************************************************************
                                //NOTE - Stack
    // *************************************************************************

    //NOTE - ft::stack::stack
    // ft::vector<int> myvector (2,200);        // vector with 2 elements
    // ft::stack<int> first;                    // empty stack
    // ft::stack<int,ft::vector<int> > third;  // empty stack using vector
    // ft::stack<int,ft::vector<int> > fourth (myvector);
    // std::cout << "size of first: " << first.size() << '\n';
    // std::cout << "size of third: " << third.size() << '\n';
    // std::cout << "size of fourth: " << fourth.size() << '\n';

    //NOTE - ft::stack::empty
    // ft::stack<int> mystack;
    // int sum (0);
    // for (int i=1;i<=10;i++) mystack.push(i);
    // while (!mystack.empty())
    // {
    //     sum += mystack.top();
    //     mystack.pop();
    // }
    // std::cout << "total: " << sum << '\n';

    //NOTE - ft::stack::size
    // ft::stack<int> myints;
    // std::cout << "0. size: " << myints.size() << '\n';
    // for (int i=0; i<5; i++) myints.push(i);
    // std::cout << "1. size: " << myints.size() << '\n';
    // myints.pop();
    // std::cout << "2. size: " << myints.size() << '\n';

    //NOTE - ft::stack::top
    // ft::stack<int> mystack;
    // mystack.push(10);
    // mystack.push(20);
    // mystack.top() -= 5;
    // std::cout << "mystack.top() is now " << mystack.top() << '\n';

    //NOTE - ft::stack::push
    // ft::stack<int> mystack;
    // for (int i=0; i<5; ++i) mystack.push(i);
    // std::cout << "Popping out elements...";
    // while (!mystack.empty())
    // {
    //     std::cout << ' ' << mystack.top();
    //     mystack.pop();
    // }
    // std::cout << '\n';

    //NOTE - ft::stack::pop
    // ft::stack<int> mystack;
    // for (int i=0; i<5; ++i) mystack.push(i);
    // std::cout << "Popping out elements...";
    // while (!mystack.empty())
    // {
    //     std::cout << ' ' << mystack.top();
    //     mystack.pop();
    // }
    // std::cout << '\n';

    //NOTE - operator==
    // ft::stack <int, ft::vector<int> > s1, s2, s3;
    // s1.push( 1 );
    // s2.push( 2 );
    // s3.push( 1 );
    // if ( s1 == s2 )
    //     std::cout << "The stacks s1 and s2 are equal." << std::endl;
    // else
    //     std::cout << "The stacks s1 and s2 are not equal." << std::endl;

    // if ( s1 == s3 )
    //     std::cout << "The stacks s1 and s3 are equal." << std::endl;
    // else
    //     std::cout << "The stacks s1 and s3 are not equal." << std::endl;

    //NOTE - operator!=
    // ft::stack <int, ft::vector<int> > s1, s2, s3;
    // s1.push( 1 );
    // s2.push( 2 );
    // s3.push( 1 );
    // if ( s1 != s2 )
    //     std::cout << "The stacks s1 and s2 are not equal." << std::endl;
    // else
    //     std::cout << "The stacks s1 and s2 are equal." << std::endl;
    // if ( s1 != s3 )
    //     std::cout << "The stacks s1 and s3 are not equal." << std::endl;
    // else
    //     std::cout << "The stacks s1 and s3 are equal." << std::endl;

    //NOTE - operator<
    // ft::stack <int, ft::vector<int> > s1, s2, s3;
    // s1.push( 2 );
    // s1.push( 4 );
    // s1.push( 6 );
    // s1.push( 8 );
    // s2.push( 5 );
    // s2.push( 10 );
    // s3.push( 2 );
    // s3.push( 4 );
    // s3.push( 6 );
    // s3.push( 8 );
    // if ( s1 < s2 )
    //     std::cout << "The stack s1 is less than "
    //         << "the stack s2." << std::endl;
    // else
    //     std::cout << "The stack s1 is greater than or equal to "
    //         << "the stack s2." << std::endl;

    // if ( s1 < s3 )
    //     std::cout << "The stack s1 is less than "
    //         << "the stack s3." << std::endl;
    // else
    //     std::cout << "The stack s1 is greater than to "
    //         << "the stack s3." << std::endl;
    // ft::stack <int>::size_type i_size_s1 = s1.size( );
    // std::cout << "The stack s1 from the top down is: ( ";
    // unsigned int i;
    // for ( i = 1 ; i <= i_size_s1 ; i++ )
    // {
    //     std::cout << s1.top( ) << " ";
    //     s1.pop( );
    // }
    // std::cout << ")." << std::endl;

    //NOTE - operator<=
    // ft::stack <int> s1, s2, s3;
    // s1.push( 5 );
    // s1.push( 10 );
    // s2.push( 1 );
    // s2.push( 2 );
    // s3.push( 5 );
    // s3.push( 10 );
    // if ( s1 <= s2 )
    //     std::cout << "The stack s1 is less than or equal to "
    //         << "the stack s2." << std::endl;
    // else
    //     std::cout << "The stack s1 is greater than "
    //         << "the stack s2." << std::endl;

    // if ( s1 <= s3 )
    //     std::cout << "The stack s1 is less than or equal to "
    //         << "the stack s3." << std::endl;
    // else
    //     std::cout << "The stack s1 is greater than "
    //         << "the stack s3." << std::endl;

    //NOTE - operator>
    // ft::stack <int, ft::vector<int> > s1, s2, s3;
    // s1.push( 1 );
    // s1.push( 2 );
    // s1.push( 3 );
    // s2.push( 5 );
    // s2.push( 10 );
    // s3.push( 1 );
    // s3.push( 2 );
    // if ( s1 > s2 )
    //     std::cout << "The stack s1 is greater than "
    //         << "the stack s2." << std::endl;
    // else
    //     std::cout << "The stack s1 is not greater than "
    //         << "the stack s2." << std::endl;

    // if ( s1 > s3 )
    //     std::cout << "The stack s1 is greater than "
    //         << "the stack s3." << std::endl;
    // else
    //     std::cout << "The stack s1 is not greater than "
    //         << "the stack s3." << std::endl;

    //NOTE - operator>=
    // ft::stack <int, ft::vector<int> > s1, s2, s3;
    // s1.push( 1 );
    // s1.push( 2 );
    // s2.push( 5 );
    // s2.push( 10 );
    // s3.push( 1 );
    // s3.push( 2 );
    // if ( s1 >= s2 )
    //     std::cout << "The stack s1 is greater than or equal to "
    //         << "the stack s2." << std::endl;
    // else
    //     std::cout << "The stack s1 is less than "
    //         << "the stack s2." << std::endl;

    // if ( s1>= s3 )
    //     std::cout << "The stack s1 is greater than or equal to "
    //         << "the stack s3." << std::endl;
    // else
    //     std::cout << "The stack s1 is less than "
    //         << "the stack s3." << std::endl;

}