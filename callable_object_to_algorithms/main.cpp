/* code from:
 * The C++ Standard Library - A Tutorial and Reference
 * by Nicolai M. Josuttis, Addison-Wesley, 1999
 * © Copyright Nicolai M. Josuttis 1999
 * page 303-305.
 * and some GCC stuff.
 * modfied by Grant
 */
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

template <class T>
inline void PRINT_ELEMENTS (const T& coll, string optcstr="") {
    typename T::const_iterator pos;
    std::cout << optcstr;
    for (pos=coll.begin(); pos!=coll.end(); ++pos)
        std::cout << *pos << ' ';
    std::cout << std::endl;
}

class Nth_fo {    // function object that returns true for the nth call
    int nth;       // call for which to return true
    int count;     // call counter
  public:
    Nth_fo(int n) : nth(n), count(0) { cout << "I'm in Nth_fo() constructor now.\n"; }
    bool operator() (int not_used) {
        return ++count == nth;
    }
};

bool Nth_fn(int junk) {    // function only
    static int nth   {3};       // call for which to return true
    static int count {0};     // call counter
    return ++count == nth;
};

/** GCC
   *  @brief Remove elements from a sequence using a predicate.
   *  @ingroup mutating_algorithms
   *  @param  __first  A forward iterator.
   *  @param  __last   A forward iterator.
   *  @param  __pred   A predicate.
   *  @return   An iterator designating the end of the resulting sequence.
   *
   *  All elements for which @p __pred returns true are removed from the range
   *  @p [__first,__last).
   *
   *  remove_if() is stable, so the relative order of elements that are
   *  not removed is unchanged.
   *
   *  Elements between the end of the resulting sequence and @p __last
   *  are still present, but their value is unspecified.
  */
template<typename _ForwardIterator, typename _Predicate>
_ForwardIterator remove_if1(_ForwardIterator __first, _ForwardIterator __last, _Predicate __pred) {
    __first = std::find_if(__first, __last, __pred);
    if (__first == __last)
        return __first;
    _ForwardIterator next = __first;
    return remove_copy_if( ++next, __last, __first, __pred);
};

template<typename _ForwardIterator, typename _Predicate>
// &__pred not allowed in parameter list?  Can't pass function object by reference? Compiles, but can't be called!??
_ForwardIterator remove_if5(_ForwardIterator __first, _ForwardIterator __last, _Predicate __pred) {
    _Predicate my_pred = __pred; 		// would this help?
    __first = std::find_if(__first, __last,  __pred);  // note the &
    if (__first == __last)
        return __first;
    _ForwardIterator next = __first;
    return remove_copy_if( ++next, __last, __first,  __pred);  // note the &
};

template<typename _ForwardIterator, typename _Predicate>
_ForwardIterator remove_if2(_ForwardIterator __first, _ForwardIterator __last, _Predicate __pred) {
    while ( __first != __last && !__pred( *__first )) // replaces std::find_if() and fixes unexpected behaviour.
        ++__first;
    if (__first == __last)
        return __first;
    _ForwardIterator next = __first;
    return remove_copy_if( ++next, __last, __first, __pred);
};

template<typename _ForwardIterator, typename _Predicate>
_ForwardIterator remove_if3(_ForwardIterator __first, _ForwardIterator __last, _Predicate __pred) {
    while ( __first != __last && !__pred( *__first )) // replaces std::find_if() and fixes unexpected behaviour.
        ++__first;
    if (__first == __last)
        return __first;
    _ForwardIterator next = __first;
    return remove_copy_if( ++next, __last, __first, __pred);
};

int main() {
    list<int> coll1 { 0,1,2,3,4,5,6,7,8,9 }, coll2 {coll1}, coll3 {coll1}, coll4 {coll1};
    PRINT_ELEMENTS( coll1, "orig        : "); cout << "Remove third element, not also the 6th!\n";
    auto pos1 = remove_if1( coll1.begin(), coll1.end(), Nth_fo(3) ); 		// remove third element
    auto pos2 = remove_if2( coll2.begin(), coll2.end(), Nth_fo(3) ); 		// remove third element, try again!
    auto pos3 = remove_if3( coll3.begin(), coll3.end(), Nth_fo(3) ); 		// remove third element, try again!
    //auto pos4 = remove_if4( coll3.begin(), coll3.end(), Nth_fn(0) ); 		// remove third element, try again!
    coll1.erase( pos1, coll1.end() );	// why is this needed? what does remove_if do? why? strange name?
    coll2.erase( pos2, coll2.end() );
    coll2.erase( pos3, coll3.end() );
    //coll2.erase( pos4, coll4.end() );
    PRINT_ELEMENTS( coll1, "nth removed1: "); PRINT_ELEMENTS( coll2, "nth removed2: "); PRINT_ELEMENTS( coll3, "nth removed3: "); //PRINT_ELEMENTS( coll4, "nth removed4: ");
}
