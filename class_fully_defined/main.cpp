/* A Modern C++ class definition example
 * showing all required function members:
 * + constructors
 * + copy, and move
 * + operators - unary and binary
 *
 * Author: Grant Rostig 2021/10/14
 * Copyright: Boost
 * Inspired by: B. Stoustrup's books
 */

#include "../../grostig_tools/cpp_headers.h"

/* Tips from C++ in a Nutshell:
 * P:135: POD hasn't got: user-defined constructor/destructor, copy(&move??) assignment operator
 * 			   virtual, base classes(meaning no inheritance??)
 * 			   nonstatic: private or protected members, data members that are ref
 * 	   ALSO: nonstatic data members must have a POD type, which are: fundamental, enum (enum class??),
 *           POD class (&struct??) or union, ptr to (or array of POD types).

extern "C" int stat( char * filename, struct stat * st);  // elaborated type specifier example

*/
//template <typename T>
class C {
 // todo: public first just for the using statements?  opinions on better way??
    using Vvs 		= std::vector<std::vector<std::string>>;	// todo: is one ever required to do a typedef instead of using??
    using Uptr 		= std::unique_ptr<C>;
    using Uptr_v 	= std::vector<Uptr>;

public:
    int 					i_ 			{};
    int const 				i_const 	{99};  	// Must be inited here or on constructor. todo: when can we set it?? what order is respected??
    int static 				i_static 	;  			// compiler::non-const must be init out of line. todo: what if I don't??
    int const static 		i_cstatic 	{};
    int mutable 		    i_mutable 	{};		// Even in a const Class definition. For example as a data cache, or memoization.
    /*T 					t 			{};		// todo: for template doesn't compile??
    std::string 			s 			{};
    std::string static 		s_static;  		   	// non-const must be init out of line. todo: what if I don't??
    std::vector<int> 		vi 			{};
    std::vector<int> static vi_static;  		// non-const must be init out of line.
    Vvs 					vvs 		{};
    Vvs static 				vvs_static;  		// non-const must be init out of line.
    // Now for some sophisticated UML relationships - note a C++ aggregate is not the same as UML aggregation, but confusingly similar.
    https://en.cppreference.com/w/cpp/language/aggregate_initialization
    https://stackoverflow.com/questions/4178175/what-are-aggregates-and-pods-and-how-why-are-they-special
    https://softwareengineering.stackexchange.com/questions/255973/c-association-aggregation-and-composition
    https://stackoverflow.com/questions/885937/what-is-the-difference-between-association-aggregation-and-composition
    https://www.youtube.com/watch?v=B46RqPYhEys
    https://www.learncpp.com/cpp-tutorial/aggregation/
    //C * 				composed_member_this 	{nullptr};  	// todo:?? or is this an aggregate?
    //Uptr 				composed_member_this_u 	{nullptr};
    //std::vector<C *>	composed_members_this_v 	{nullptr};  // todo:?? put nulls in all members?
    //Uptr_v				composed_members_this_vu 	{nullptr};  // todo:?? put nulls in all members?
    */
public:  						// things that MUST be public in general
    // C() = 0; 						// default contructor  todo: Do constructors have an implicit/hidden this?  todo: how do statics get initialized??
    //C();								// default contructor  todo: Do constructors have an implicit/hidden this?  todo: how do statics get initialized??
    C() {};								// default contructor  todo: Do constructors have an implicit/hidden this?  todo: how do statics get initialized??
    //C() = default; 						// does this defeat other default member functions?  todo: Do constructors have an implicit/hidden this?  todo: how do statics get initialized??
    //C(int i) = default;					// todo: why is this not a special member function and why can't it be defaulted?
    C(int i)		:i_{i}, i_const{42} {}	// specialized constuctor for int using initializer list. i_const may be inited here. todo: when can we set it?? what order is respected??
    /*C(int & i_)		:i(i_) {}; 	// move constuctor
    C( C const & x ) { i = x.i; }; 	// copy constructor  // must be ref
    //C( C const volatile & x ) { i = x.i;  }; 	// copy constructor  // must be ref

    C( C const && x ) { i = x.i;  }; 	// move constructor  // must be ref
    ~C(); 						// default destructor // todo:?? are there most specific destructors generally used?

    // setters and getters
    // operators
    C& operator=( 	C & 	rhs ) 			{ i = rhs.i; s=rhs.s; vi=rhs.vi; vvs=rhs.vvs; //composed_member_this=composed_member_this;// return *this; };  // move assignment
    C  operator=( 	C 		rhs ) 			{ i = rhs.i; s=rhs.s; vi=rhs.vi; vvs=rhs.vvs; //composed_member_this=composed_member_this;// return *this; };  // copy assignment
    C  operator=( 	int 	rhs ) 			{ i = rhs; return false;};  // copy assignment - partial  // todo:?? return what, check all operators!

    C operator+=( 	C & 	rhs ) 			{ i + rhs.i; return *this; };  // copy assignment - partial  // todo:?? return what?
    C operator+=( 	int & 	rhs ) 			{ i + rhs; return *this; };  // copy assignment - partial  // todo:?? return what?
    C operator+(	C &		rhs ) 			{};
    C operator*=( 	C & 	rhs ) 			{ i + rhs.i; return *this; };  // copy assignment - partial  // todo:?? return what?

    // unary - todo:: some are there more??
    C operator!(		 )					{}; 	// todo:?? pre-fix unary
    C operator++(	int 			rhs )	{};  	// pre-fix unary??
    //C& operator++(	int 		rhs ) 			{};  // post-fix unary??
    //C operator++(	C<T>::i &		rhs ) 			{};  // pre-fix unary

    C operator&=( 	C rhs)				{};
    C operator&( 	C rhs)				{};
    C operator&&( 	C rhs)				{};  				// todo: What is this even?

    size_t size() 						{};  	// todo: add nothrow, final
    void clear() 						{};
    void reset() 						{};
    void capacity() 					{};
    void f() 							{};

    void operator<<( C rhs) 			{};  	// todo:?? bitshift
    void operator>>( C & rhs ) 		{};

    void operator<=> ( C const &) {};

    // struct stat st; 			//todo:?? elaborated type specifier example  eg: struct My_type my_var, where struct is needed.
    */
};

int C::i_static = 77;

//    void operator <=>( C const &,  C const &) {};

std::ostream & operator<<( std::ostream & os,       C & rhs) {};  	// todo:?? make this work for more that <char>, the ostream typedef.
//std::basic_ostream<char, std::char_traits<char>> & operator<<( std::basic_ostream<char, std::char_traits<char>> & os,       C & rhs) {};  	// todo:?? more template parameters?
//std::basic_ostream<char, std::char_traits<char>> & operator<<( std::basic_ostream<char, std::char_traits<char>> & os, const C & rhs) {};  	// todo:?? more template parameters?

int main() {
    //struct stat st; // todo:?? elaborated type specifier example  eg: struct My_type my_var, where struct is needed.
    C my_c_var;
    C my_c_var2 {323};
    my_c_var2.i_static = 123;



    cout << "###" << endl;
    return 0;
}

















