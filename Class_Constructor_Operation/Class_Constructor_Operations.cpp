/* Copyright (c) 2016 Grant Rostig
 * all rights reserved
 *
 * We demonstrate:
 * - the most basic constructors and operators.
 * - the use of boost::operators to "complete" the other operators needed for a normal 'int like' class.
 * - to show the basics and make the concepts easier to understand, templates are not used.
 *
 * inspired by arne-mertz.de
 */
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <utility>
#include <boost/operators.hpp>
using std::cout, std::cin, std::cerr, std::clog, std::endl, std::istream, std::ostream, std::left, std::right, std::setw, std::string;

// =================== use https://github.com/worthy-os/operators to get other operations or use boost::operators

//class T : boost::ordered_field_operators< T
class T : boost::euclidean_ring_operators< T  // includes modulo.
        , boost::unit_steppable< T
        , boost::equivalent< T
        >
        >
        >
{
    // invariants:
    int my_val1 {998};  // the {} here is an 'in class initializer'
    int my_val2 {999};
    static       int  class_wide_val;              // no init here, must be done outside of class. TCPLv2 P506
    static const int  cclass_wide_val {888};
    static constexpr int cx_class_wide_val {887};  // a literal type TCPLv2 P265

public:             // all member methods have an implict this pointer passed to them.
    class Bad_t {}; // exception class

    T() noexcept  {                        // ===== default constructor =====
        // existence implies removal of implicit default constructor. TCPLv2
        LOG_UDT( R"(
                 Just Prior to: T() body
                 )"
                 , my_val1, my_val2 );                                                   // todo:  when using explict it breaks several assignment statements, what conversion can I write to allow them?

        my_val1 = 0;
        my_val2 = 0;
        LOG_UDT( R"(
                 T()
                 )"
                 , my_val1, my_val2 );
    }

    T( const T& rhs ) noexcept {  // =====  copy constructor =====
        // is the only constructor (~, copy, move, assignment) this is not implictly created.
        // existence  implies removal of implicit default constructor. TCPLv2 P491
        // existence !implies removal of implicit copy    constructor. TCPLv2 P491
        // T( const T& rhs )=delete;
        // T( const T& rhs )=default;
    // T( T& rhs ) noexcept {         // NOTE it is not const!!  apparently this is legal. why? // todo: how would ADL differentiate the two?  Would it prefer this one?
        my_val1 = rhs.my_val1;
        my_val2 = rhs.my_val2;
        LOG_UDT( R"(
                 T( const T& rhs )
                 )"
                 , my_val1, my_val2 );
    }

    T( int rhs1, int rhs2 ) noexcept {  // ===== two ints 'conversion' copy constructor =====
        my_val1 = rhs1;
        my_val2 = rhs2;
        LOG_UDT( R"(
                 T( int rhs1, int rhs2 )
                 )"
                 , my_val1, my_val2 );
    }

//    T( const int& rhs1, const int& rhs2 ) noexcept {  // ===== two ints 'conversion' copy constructor =====
//    // T( const int& rhs1 = {}, const int& rhs2 = {}) noexcept {  // todo: why does this break explicit initialization T{2} ?
//        my_val1 = rhs1;
//        my_val2 = rhs2;
//        LOG_UDT( R"(
//                 T( const int& rhs1, const int& rhs2 )
//                 )"
//                 , my_val1, my_val2 );
//    }

    explicit T( const int& rhs ) noexcept {  // ===== single int 'conversion' constructor =====
        // if not explicit then this also acts as a conversion from the arg class type to the class type (which is different).
        // don't need to make 2+ arg constructors explicit but can for some uses.  TCPLv2
        // todo:  how to make a conversion which is disabled by making the above explicit.
        my_val1 = rhs;
        my_val2 = rhs;
        LOG_UDT( R"(
                 T( const int& rhs )
                 )"
                 , my_val1, my_val2 );
    }


    T( T&& rhs) noexcept {          // ===== move constructor ===== optional =====  // todo:  when optional exactly? For example: deep copy? return value elison?
        // todo:  when using explict it breaks several assignment statements, what conversion can I write to allow them?
        //    todo:  *** Will this be generated if using boost::operator? ***
        //  T( T&& rhs)=default;
        my_val1 = std::move(rhs.my_val1);            // todo: is this correct?
        my_val2 = std::move(rhs.my_val2);            // todo: is this correct?
        LOG_UDT( R"(
                T( T&& rhs) noexcept
                 )"
                 , my_val1, my_val2 );
    }

    // ==================== Operator Overloading for: Operators ========================  https://en.cppreference.com/w/cpp/language/operator_arithmetic


    //    todo:  *** Will this be generated if using boost::operator? ***
    //     double          operator()(const T& rhs) const; // function object.  todo: are these two equivalent
    //     explicit operator double()(const T& rhs) const // function object.  todo:
    //         {
    //             log_UDT_activity("T& operator=( T const & ref_in_t )", my_val1, my_val2);
    //             return std::static_cast<double> my_val1;
    //         }

    T& operator=( const T& rhs) noexcept {       // ===== copy assignment ===== - accepting a pointer or reference to class being copied
        // only need be defined if deep copy is required.  memberwise or shallow copy? is default generated by compiler.
        // T& to allow chaining, must return *this.
        // ===== has implicit meaning if not deleted!!
        my_val1 = rhs.my_val1;
        my_val2 = rhs.my_val2;
        // if (this != &rhs) noexcept { // mertz.de, 2015 todo: problem with std::swap
        //     T tmp(rhs);
        //     swap(tmp, rhs);
        // }
        LOG_UDT( R"(
                 T& operator=( const T& rhs) noexcept
                 )"
                 , my_val1, my_val2 );
        return *this;                   // return a "self-reference"
    }

    // T& clone( const T& rhs) noexcept;  can be used instead of copy assignment, expecially in a base class where copy operations are deleted. TCPLv2 P514

    T& operator=( T&& rhs) noexcept {            // ===== move assignment ===== optional =====  // todo:  when optional? - accepting a pointer or reference to class being copied
        // T& to allow chaining, must return *this.
        // ===== has implicit meaning if not deleted!!
        my_val1 = std::move(rhs.my_val1);            // todo: is this correct?
        my_val2 = std::move(rhs.my_val2);            // todo: is this correct?
        LOG_UDT( R"(
                 T& operator=( T&& rhs) noexcept
                 )"
                 , my_val1, my_val2 );
        return *this;                   // why * and not & ???
    }

    //  ~T()=default;
    ~T() noexcept {                                     // ===== destructor ===== used to give back resources: memory (pointers), files, locks, thread handles, sockets.  PPP 641.  But not iostreams?  What about new std::filesystem?
        // for a base class to have one, the base must have a virtual destructor.
        LOG_UDT( R"(
                 ~T()
                 )"
                 , my_val1, my_val2 );
    }

    // ===== new ===== delete =====
    // void* operator new     ( size_t sz )=delete;  // TCPLv2 P282 // todo: how does this relate to a class that doesn't have any pointers or doesn't use any heap memory? it disallows using new in even those cases.
    // void* operator new[]   ( size_t sz )=delete;
    // void* operator new     ( size_t sz, void* p ) noexcept;  // placement new.  TCPLv2 P284 P377 P487 P566  // todo:  can these be deleted and should they ever be?
    // void* operator new[]   ( size_t sz, void* p ) noexcept;
    // void* operator new     ( size_t sz, const nothrow_t& ) noexcept;  // nothrow new TCPLv2 P285
    // void* operator new[]   ( size_t sz, const nothrow_t& ) noexcept;
    // void  operator delete  ( void* p)=delete;
    // void  operator delete[]( void* p)=delete;
    // void  operator delete  ( void* p, void* ) noexcept;         // placement delete.
    // void  operator delete[]( void* p, void* ) noexcept;
    // void  operator delete  ( void* p, const nothrow_t& ) noexcept;  // nothrow delete
    // void  operator delete[]( void* p, const nothrow_t& ) noexcept;

    //  todo:  need a library to generate these for me.
    int  val1() const      { return my_val1; }
    int  val2() const      { return my_val2; }
    void val1(int const v) { my_val1 = v; }
    void val2(int const v) { my_val2 = v; }

    T operator-() const noexcept {       // ===== unary minus =====
        T tmp = *this;
        tmp.my_val1 *= -1;
        tmp.my_val2 *= -1;
        LOG_UDT( R"(
                 T& operator-()
                 )"
                 , my_val1, my_val2 );
        return tmp;
    }

    T operator+() const noexcept {       // ===== unary plus =====  todo:  need const here? compile error.
        LOG_UDT( R"(
                 T& operator+()
                 )"
                 , my_val1, my_val2 );
        return *this;
    }

    // bool operator! () const;

    T operator+=( const T& rhs ) noexcept { // ===== addition of another T
        this->my_val1 += rhs.my_val1;
        this->my_val2 += rhs.my_val2;
        LOG_UDT( R"(
                 T& operator+=( const T& rhs)
                 )"
                 , my_val1, my_val2 );
        return *this;
    }

    T operator+=( const int& rhs ) noexcept { // ===== addition of int ===== todo:  what if anything does this offer?  doesn't seem to fix my + compile error of types.  can boost::operator help with this?
        this->my_val1 += rhs;
        this->my_val2 += rhs;
        LOG_UDT( R"(
                T& operator+=( const int& rhs ) noexcept
                 )"
                 , my_val1, my_val2 );
        return *this;
    }

    //    todo:  *** Will these be generated if using boost::operator? ***
    //    T& operator+=( const T&& rhs ) noexcept {              // ===== addition of another T ===== optional =====  // todo:  when optional?
    //        // todo:
    //        log_UDT_activity("T& operator+=( const T && ref_in_t )",my_val1, my_val2);
    //    }

    T operator-=( const T& rhs ) noexcept { // ===== addition of another T
        this->my_val1 -= rhs.my_val1;
        this->my_val2 -= rhs.my_val2;
        LOG_UDT( R"(
                 T& operator-=( const T& rhs)
                 )"
                 , my_val1, my_val2 );
        return *this;
    }

    T operator*=( const T& rhs ) noexcept {           // =====
        this->my_val1 *= rhs.my_val1;
        this->my_val2 *= rhs.my_val2;
        LOG_UDT( R"(
                 T& operator*=( const T& rhs )
                 )"
                 , my_val1, my_val2 );
        return *this;
    }

    T operator*=( const int rhs ) noexcept {           // =====
        this->my_val1 *= rhs;
        this->my_val2 *= rhs;
        LOG_UDT( R"(
                 T& operator*=( const int rhs )
                 )"
                 , my_val1, my_val2 );
        return *this;
    }

    T operator/=( const T& rhs ) noexcept {           // =====
        this->my_val1 /= rhs.my_val1;
        this->my_val2 /= rhs.my_val2;
        LOG_UDT( R"(
                 T& operator/=( const T& rhs )
                 )"
                 , my_val1, my_val2 );
        return *this;
    }

    T operator%=( const T& rhs ) noexcept {           // =====
        this->my_val1 %= rhs.my_val1;
        this->my_val2 %= rhs.my_val2;
        LOG_UDT( R"(
                 T& operator%=( const T& rhs )
                 )"
                 , my_val1, my_val2 );
        return *this;
    }

    T operator|=( const T& rhs ) noexcept {           // =====
        // todo:
        LOG_UDT( R"(
                 T& operator|=( const T& rhs )
                 )"
                 , my_val1, my_val2 );
    }

    T operator&=( const T& rhs ) noexcept {           // =====
        // todo:
        LOG_UDT( R"(
                 T& operator&=( const T& rhs )
                 )"
                 , my_val1, my_val2 );
    }

    T operator^=( const T& rhs ) noexcept {           // =====
        // todo:
        LOG_UDT( R"(
                 T& operator^=( const T& rhs )
                 )"
                 , my_val1, my_val2 );
    }

    T& operator++() noexcept {           // ===== prefix increment =====
        my_val1 += 1;
        my_val2 += 1;
        LOG_UDT( R"(
                 T operator++()
                 )"
                 , my_val1, my_val2 );
        return *this;
    }

    T& operator--() noexcept {           // ===== prefix decrement =====
        my_val1 -= 1;
        my_val2 -= 1;
        LOG_UDT( R"(
                 T& operator--()
                 )"
                 , my_val1, my_val2 );
        return *this;
    }

//    T operator++( const int ) noexcept {
//        T tmp {*this};
//        my_val1 += 1;
//        my_val2 += 1;
//        LOG_UDT( R"(
//                 T operator++( const int ) noexcept {
//                 )"
//                 , my_val1, my_val2 );
//        return tmp;
//    }

//    T operator--( const int ) noexcept {
//        T tmp {*this};
//        my_val1 -= 1;
//        my_val2 -= 1;
//        LOG_UDT( R"(
//                 T operator--( const int ) noexcept {
//                 )"
//                 , my_val1, my_val2 );
//        return tmp;
//    }

    //                                         todo:  *** Will these be generated if using boost::operator? ***
    //    T operator++( const T& rhs, const int ) noexcept;           // ===== non-member function,outside class: ===== postfix increment =====
    //    T operator--( const T& rhs, const int ) noexcept;           // ===== non-member function,outside class: ===== postfix decrement =====
    //    T operator+ ( const T  rhs )            noexcept;           // ===== non-member function,outside class: ===== prefix unary plus ====
    //    T operator- ( const T  rhs )            noexcept;           // ===== non-member function,outside class: ===== prefix unary minus ====
    //    T operator+ ( const T  rhs, const T )   noexcept;           // ===== non-member function,outside class: ===== binary plus ====
    //    T operator- ( const T  rhs, const T )   noexcept;           // ===== non-member function,outside class: ===== binary minus ====

    bool operator< (const T& rhs) const {
        LOG_UDT( R"(
                 bool operator< (const T& rhs)
                 )"
                 , my_val1, my_val2 );
        return ( my_val1 + my_val2 ) < ( rhs.my_val1 + rhs.my_val2 );
    }

    //                                         todo:  *** Will these be generated if using boost::operator? ***  I think so yes.
    // bool operator> (const T& rhs) const;
    // bool operator<=(const T& rhs) const;
    // bool operator>=(const T& rhs) const;
    // bool operator==(const T& rhs) const;
    // bool operator!=(const T& rhs) const;

    // T*     operator&() const? noexcept;                  // ===== prefix unary ===== address of
    // T*     operator&()=delete;                           // ===== prefix unary ===== address of ===== has implicit meaning if not deleted!!
    // void   operator,( const T&) const? noexcept;         // ===== comma =====  sequence operator
    // void   operator,( const T&)=delete;                  // ===== comma =====  sequence operator ===== has implicit meaning if not deleted!!

    //    todo:  *** Will these be generated if using boost::operator, having defined some other operation? ***  I think not no.
    // T&?  operator-> const T& rhs) const; // todo:
    // T&?  operator->*const T& rhs) const; // todo:
    // T&?  operator[] const T& rhs) const; // todo:

    // todo: mertz.de, 2015: implement unary and binary of the T= family as class methods, all other binary operators as free functions, if possible

private:

    std::string string_rep() const;  // these could be cached TCPL 16.2.9
    std::string cstring_rep( char char_array[], int max_size) const;

    bool is_valid() {
        // some additional check on invariants beyond just is_a_correct_t().
        return true;
    }

    void LOG_UDT (string const & message, int const my_val1, int const my_val2) const {
        cout << "Class-this: " << setw(15) << right << this << ", action: " << left << message;
        cout << "my_val: " << setw(6) << right << my_val1 << setw(6) << right << my_val2 << endl;
    }

    //    friend // function is NOT USED.  Called with: log_UDT_activity2(this, "~T(): ",this->my_val);
    //    void log_UDT_activity2 (T * my_this, const string& message, int const my_val1, int const my_val2) const {  // shows the 'implicit this parameter' which is hidden in the above member functions
    //        cout << "Class2this: " << setw(15) << right << my_this << ", action: " << left << message;
    //        cout << "my_val: " << setw(6) << right << my_val1 << setw(6) << right << my_val2 << endl;
    //    }

    //    friend // function is NOT USED.  Called with: log_UDT_activity2(this, "~T(): ",this->my_val);
    //    void log_UDT_activity3 (T *, const string & , int const1, int const my_val2 ) const;
};

//// function is NOT USED
//void log_UDT_activity3 (T * my_this, const string & message, int const my_val1, int const my_val2) const {  // shows the 'implicit this parameter' which is hidden in the above member functions
//    cout << "Class3this: " << setw(15) << right << my_this << ", action: " << setw(35) << left << message;
//    cout << "my_val: " << setw(6) << right << my_val1 << setw(6) << right << my_val2 << endl;
//}

//  ===== T class Helper Functions ===== // they don't need access to private members.

bool is_a_correct_t(T& t);  // simple example property
const T& default_t();
ostream& operator<<( ostream& os, const T& t);
istream& operator>>( istream& is,       T& t);

// ===== End of Class =====

// ===== Functions used by main =====

T call_by_value(T t_obj_in) noexcept {
    return t_obj_in;
}

T call_by_value_temp(T t_obj_in) noexcept { 	// how can this function with temp, do same Class operations as above???
    T temp = t_obj_in;
    return temp;
}

T& call_by_ref(T& t_ref_in) noexcept {  // why return T&??? what is it???  I guess it is like the original reference declaration, doesn't do much except say we have an alias???
    return t_ref_in;
}

T* make_new_obj(int int1_in, int int2_in) noexcept {
    T temp { int1_in, int2_in };
    return new T(temp);  // todo: editor compile error, but will it compile after boost::operators does its magic?
}

void  LOG(string message_in) noexcept {
    cout << endl << message_in << endl;
}

T global_obj1 {};         // created before main starts running, destroyed after main has finished'

struct Two_Ts {
    T t1;
    T t2;
};

int main()
{
    cout << "*** MAIN START ***" << endl;

    { LOG(R"(
            T local0;
            )");
        T local0;  }

    { LOG(R"(
            Two_Ts local1;
            )");
        Two_Ts local1; }

    {  LOG(R"(
            T local2 (2,22);
            )");
        T local2 (2,22); }

    {  LOG(R"(
            T local3 {3,33};
            )");
        T local3 {3,33}; }

    {  LOG(R"(
            T local4 = {4,44}
            )");
        T local4 = {4,44};

        LOG(R"(
            T local7 {local4};
            )");
        T local7 {local4}; // same result with ()

        LOG(R"(
            local7 = T{55,55};
            )");
        local7 = T{55,55};

        //        local7 = 555;  // no viable overloaded '='
        LOG("# end of block.");
    }
    { LOG("T* local6p = new T; // copy constructor of explicit new default constructed object");
        LOG(R"(
            T local0;
            )");
        T* local6p  = new T;

        LOG("local6p = new T(6); // copy constructor of explicit new object");
        LOG(R"(
            local6p = new T(3,33);
            )");
        local6p = new T(3,33);

        LOG(R"(
            local6p = new T{4,44};
            )");
        local6p = new T{4,44};

        // local6p = new T = {4};  // todo:  compile error, why if above works???
        LOG("# end of block.");
    }
    {  LOG(R"(
            T local7 {7,77};
            )");
        T local7 {7,77};

        LOG(R"(
            T local8 {8,88};
            )");
        T local8 {8,88};

        LOG(R"(
            local8 = call_by_value( local7);
            )");
        local8 = call_by_value( local7);

        LOG(R"(
            local8 = call_by_value_temp( local7);
            )");
        local8 = call_by_value_temp( local7);

        LOG(R"(
            T& local9 = call_by_ref(local7);
            )");
        T& local9 = call_by_ref(local7);
        cout << "*** & local8: " << &local8 << endl;

        LOG(R"(
            local8 = local7;
            )");
        local8 = local7;
        LOG("# end of block.");
    }

    {  LOG(R"(
           delete make_new_obj(46,47); }
           )");
        delete make_new_obj(46,47); }

//    { LOG(R"(
//            std::vector<T> unused_v {1,2}; } // todo: no matching constructor
//            )");
//        std::vector<T> unused_v {1,2}; } // todo: no matching constructor

//    { LOG(R"(
//            std::vector<T> unused_v2 (3,333); } // todo: no matching constructor
//            )");
//        std::vector<T> unused_v2 (3,333); } // todo: no matching constructor

    {  LOG(R"(
            )");
        T* unused_p = new T{8,88};

        LOG(R"(
            delete unused_p;
            )");
        delete unused_p;
        LOG("# end of block.");
    }

    {  LOG(R"(
            T* local9 = new T[3];
            )");
        T* local9 = new T[3];

        LOG(R"(
            delete[] local9;
            )");
        delete[] local9;
        LOG("# end of block.");
    }

        LOG(R"(
    T my_t_1     (1,1);
            )");
    T my_t_1     (1,1);

        LOG(R"(
    T my_t_2     (2,2);
            )");
    T my_t_2     (2,2);

        LOG(R"(
    T my_t_3     {3,3};
            )");
    T my_t_3     {3,3};

        LOG(R"(
    T my_t_4   = {4,4};
            )");
    T my_t_4   = {4,4};

        LOG(R"(
    T my_t_5   = {5,5};
            )");
    T my_t_5   = {5,5};

        LOG(R"(
    T restore_2 {my_t_2} ;
            )");
    T restore_2 {my_t_2} ;

        LOG(R"(
    assert( T{2} + my_t_2  == my_t_4);  // explicit initialization. AKA direct initialization.
            )");
    assert( T{2} + my_t_2  == my_t_4);  // explicit initialization. AKA direct initialization.

        LOG(R"(
    assert( my_t_2 + T {2} == my_t_4);
            )");
    assert( my_t_2 + T {2} == my_t_4);

    // assert( 2 + my_t_2  == my_t_4);     // error, todo: how can I declare an implicit conversion while also having the explicit keyword in the conversion constructor, a special conversion member function?
    // assert( my_t_2 + 2 == my_t_4);

        LOG(R"(
    my_t_2++;
            )");
    my_t_2++;

        LOG(R"(
    assert( my_t_2 == my_t_3);
            )");
    assert( my_t_2 == my_t_3);

        LOG(R"(
    my_t_2 = restore_2;
            )");
    my_t_2 = restore_2;

        LOG(R"(
    ++my_t_2;
            )");
    ++my_t_2;

        LOG(R"(
    assert( my_t_2 == my_t_3);
            )");
    assert( my_t_2 == my_t_3);

        LOG(R"(
    my_t_2 = restore_2;
            )");
    my_t_2 = restore_2;

        LOG(R"(
    assert( -my_t_1 == my_t_2 - my_t_3);
            )");
    assert( -my_t_1 == my_t_2 - my_t_3);

        LOG(R"(
    T tmp2 {};
            )");
    T tmp2 {};

        LOG(R"(
    tmp2 = --my_t_2;
            )");
    tmp2 = --my_t_2;

        LOG(R"(
    assert( tmp2 == my_t_3 - restore_2);
            )");
    assert( tmp2 == my_t_3 - restore_2);

        LOG(R"(
    my_t_2 = restore_2;
            )");
    my_t_2 = restore_2;

        LOG(R"(
    assert( my_t_2-- == my_t_3 - my_t_2);
            )");
    assert( my_t_2-- == my_t_3 - my_t_2);

        LOG(R"(
    my_t_2 = restore_2;
            )");
    my_t_2 = restore_2;

        LOG(R"(
    assert( my_t_2 + my_t_2 == my_t_4);
            )");
    assert( my_t_2 + my_t_2 == my_t_4);

        LOG(R"(
    assert( my_t_2 * my_t_2 == my_t_4);
            )");
    assert( my_t_2 * my_t_2 == my_t_4);

        LOG(R"(
    assert( my_t_4 / my_t_2 == my_t_2);
            )");
    assert( my_t_4 / my_t_2 == my_t_2);

        LOG(R"(
    assert( my_t_5 % my_t_2 == my_t_1);
            )");
    assert( my_t_5 % my_t_2 == my_t_1);

    // assert( my_t_5 |= my_t_5 == my_t_1 &= my_t_1); // fake/false comparison.

    struct {int a; int b;} anon_initializer1 = {42,43};  // TCPLv2 460  ad-hoc data structure
    struct {int a; int b;} anon_initializer2 {42,43};

    cout << "###" << endl; return 0;
}
