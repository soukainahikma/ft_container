#include<iterator>
template <class Iterator>
struct my_iterator_traits {
  typedef typename Iterator::iterator_category iterator_category;
  typedef typename Iterator::value_type        value_type;
  typedef typename Iterator::difference_type   difference_type;
  typedef typename Iterator::pointer           pointer;
  typedef typename Iterator::reference         reference;
};
template <class T>
struct my_iterator_traits<T*> {
  typedef random_access_iterator_tag iterator_category;
  typedef T                          value_type;
  typedef ptrdiff_t                  difference_type;
  typedef T*                         pointer;
  typedef T&                         reference;
  };
template <class _Iter>
class my__wrap_iter
{
public:
    typedef _Iter                                                      iterator_type;
    typedef typename my_iterator_traits<iterator_type>::iterator_category iterator_category;
    typedef typename my_iterator_traits<iterator_type>::value_type        value_type;
    typedef typename my_iterator_traits<iterator_type>::difference_type   difference_type;
    typedef typename my_iterator_traits<iterator_type>::pointer           pointer;
    typedef typename my_iterator_traits<iterator_type>::reference         reference;
private:
    iterator_type __i;
};