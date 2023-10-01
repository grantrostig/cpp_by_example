// Author: Grant Rostig, adapted from cppreference.com using-declaration entry https://en.cppreference.com/w/cpp/language/using_declaration
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using std::endl, std::cout, std::cerr, std::cin;
// Not all the ideas here have been implemented:  https://www.sandordargo.com/blog/2020/10/14/strong-types-for-containers

template <class T>
struct Vector_named: private std::vector<T> {
    using iterator 	    = typename std::vector<T>::iterator;
    using const_iterator 	= typename std::vector<T>::const_iterator;
    using std::vector<T>::begin;
    using std::vector<T>::end;
    using std::vector<T>::cbegin;
    using std::vector<T>::cend;
    using std::vector<T>::push_back;		// brings them to public:
    //using std::vector<T>::operator+;
    Vector_named(std::string_view name):std::vector<T>{}, name_{name} {}

    Vector_named(std::initializer_list<T> initlist): std::vector<T> {initlist} {}; // TODO??: where does documentation state that this works?  Next line does nothing?
    // OR
    //  Vector_named(std::initializer_list<T> initlist) {
    //    std::vector<T> { initlist };  // TODO??: this line does not init the vector within this class.
    //    this->_M_shrink_to_fit();
    //  };


    ~Vector_named() { cerr << "Vector_named.destructor object name:`" << name_ << "`.\n" << endl; }  // afterwards will call member data ~ and then ~self....
    //TODO: explain what following destructors would do:
    //~named_vector() override = default;
    //~named_vector() override;
    //~named_vector() override {};
    //~named_vector() = delete;			// TODO??: does this stop the destructor for the base class from being called?

    [[nodiscard]] std::string_view name() const {return name_;};
    void set_name( std::string_view    name) {name_ = name;};
    void name(     std::string      && name) {name_ = std::move(name);};
    void problem() {
        cerr <<  "Should call ~.\n";
        dispose_of_vector( this );  // this is implicitly converted.  private, but is member.
    }
private:
    std::string name_;
};

template <class T>
std::ostream& operator<<(std::ostream& os, Vector_named<T> const&nv) {
    os << '[' ;
    std::copy(nv.cbegin(), nv.cend(), std::ostream_iterator<T>(os, ", "));
    os << ']';
    return os;
}

template <class T>
//void dispose_of_vector(std::vector<T> * v) {
// OR
void dispose_of_vector(Vector_named<T>*v) {
    delete v;
};


void test_vector_named() { {
        std::vector<double> normal_vec {1.1,1.2,1.3};
        //Vector_named<int> nv_int {"nv_int_name"};
        // OR
        Vector_named<int> nv_int {3,4,5};
        nv_int.name("nv_int");

        nv_int.push_back(2);
        nv_int.push_back(22);
        cout << "Vector_named_int.name:" << nv_int.name() << endl;
        cout << "Vector_named_int:" << nv_int << endl;

        Vector_named<std::string> nv_string {"nv_string_name","two","three"};
        nv_string.set_name("nv_string_name");
        cout << "Vector_named_string.name:" << nv_string.name() << endl;
        cout << "Vector_named_string:" << nv_string << endl;
    }
    cout << "Two nv's should have destructed just above." << endl;
    Vector_named<int> * nv_int_ptr {new Vector_named<int>{"nv_int_ptr_name"}}; // decltype(nvp) == named_vector<int>*
    // TODO??: try this: auto junk = nvp; delete nvp;  // TODO: causes crash.
    dispose_of_vector( nv_int_ptr );
    cout << "One nv's should have destructed just above." << endl;

  //nvp->begin();
  //begin(*nvp);
  //nvp->push_back(7);
  //std::cout << *nvp < *nvp << '\n';
  //std::cout << nvp < nvp << '\n';
  //std::cout << (*nvp < *nvp) << '\n';
  //std::cout << v1 < v2 << '\n';
  //nvp->problem();
  //cerr << "main(): post problem()\n";

}

//----------------------------------------------------------------------------------------------------

template <typename T, typename U>
class Vector_named_with_2 : public std::vector<T> { // TODO??: why not? class Vector_with_name_tplt<T> : public std::vector<T> {};
public:
    //using std::vector<T,U>::push_back;
    std::string 	        name                            {"not_set"};
    U 		                templated_data_member      {};
    Vector_named_with_2()    = default;
    Vector_named_with_2(std::string name) : name{name} {};
    //Vector_named_with_2(bool i) : name{i} {};
    //Vector_named_with_2()       = delete;
    Vector_named_with_2(std::initializer_list<T> initlist): std::vector<T> {initlist} {}; // TODO??: where does documentation state that this works?  Next line does nothing?
    Vector_named_with_2( T value, size_t count): Vector_named_with_2::vector (value,count), name{name} {};
};

void test_vector_with_2() {
  //Vector_named_with_2<std::string>      vec_name    {"member1","member2","member3"};
  // TODO??: how to make this template with a "parameter pack" of internal members, for example this has only one: Vector_named_with_2<int>                vec_tpl2{"my_vec2 initalized"};
  Vector_named_with_2<float, bool >       vec_fb {"my_vec2_fb initalized"};
  Vector_named_with_2<float, std::string> vec_fs {"my_vec2_fs initalized"};

  // We lost the meaning of these loops, but there are clues...
  for (int i = 0; i < 10; i++) {
      // vec_fs.push_back(std::to_string(i + .1)); // TODO??: why no narrowing warning?
  };
  cout << "vec_name:" << vec_fs.name << ", "<<vec_fs.size()<< endl;
  for (auto i :vec_fs ) {
      cout<<", "<<i; // TODO??: why no narrowing warning?
  }; cout<<endl;
  for (int i = 0; i < 10; i++) {
      //vec_fs.push_back( static_cast<float>(i) + .1);
  };

  cout << "name: "  << vec_fs.name << endl;
  cout << "tname: " << vec_fs.templated_data_member << endl;
}
//----------------------------------------------------------------------------------------------------

struct Base_type {
  virtual void 	f_virtual(int i) { std::cout << "B::f " << i << "\n"; }
  void 		g(char i) { std::cout << "B::g " << i << "\n"; }
  void 		h(int i) { std::cout << "B::h " << i << "\n"; }
protected:
  using 	Value_type = int; // typedef int Value_type;
  int 		p_base_data_member_protected{};                // B::p_base_data_member_protected is protected
};

struct Derived_type : public Base_type {
  // using B;
  using Base_type::Value_type;                                 // D::value_type is public
  using Base_type::p_base_data_member_protected;                                          // D::p_base_data_member_protected is now public
  int 		d_derived_data_member;

  using Base_type::f_virtual;
  void f_virtual(int i) { std::cout << "D::f " << i << "\n"; } // D::f(int) overrides B::f(int)
  using Base_type::g;
  void g(int i) { std::cout << "D::g " << i << "\n"; } // both g(int) and g(char) are visible
  using Base_type::h;
  void h(int i) { std::cout << "D::h " << i << "\n"; } // D::h(int) hides B::h(int)
};

void test_inheritance_visibility_Derived_type() {
  Derived_type 		derived_obj;
  int  			    junk		{derived_obj.p_base_data_member_protected};

  Base_type 		&base_obj_ref	{derived_obj}; 	// TODO??: is this slicing? no, but why no warning?
  Base_type  		*base_obj_ptr	{&derived_obj}; // TODO??: is this slicing? no, but why no warning?
  Base_type 		base_obj	{derived_obj}; 	// TODO??: is this slicing?
  base_obj = derived_obj;  				// TODO??: is this slicing?
  //base_obj_ref.p_base_data_member_protected = 2; 		// compile error, B::p_base_data_member_protected is protected
  derived_obj.p_base_data_member_protected = 1; // protected B::p_base_data_member_protected is accessible as public D::p_base_data_member_protected

  base_obj_ref.f_virtual(1); 	// calls derived f()
  derived_obj.f_virtual(1);     // calls derived f()
  derived_obj.g(1);     	// calls derived g(int)
  derived_obj.g('a');   	// calls base g(char)
  base_obj_ref.h(1); 		// calls base h()
  derived_obj.h(1);     	// calls derived h()
  //derived_obj.B::g(9);
}
//----------------------------------------------------------------------------------------------------

/*  template<typename T> concept Hashable = requires(T a) {
  { std::hash<T>{}(a) } -> std::convertible_to<std::size_t>;
};

//concept Derived = std::is_base_of<U, T>::value;
template <class T>
concept Is_concepts_named_vector = requires( T my_t_variable )
{
  std::vector<T>::iterator;  			{push_back(my_t_variable)};
  std::vector<T>::iterator;  			{push_back(my_t_variable)};
    //decltype(std::vector<T>::push_back) 		{push_back(my_t_variable)};
    //std::vector<T>::iterator  push_back {my_t_variable};
    //decltype(std::vector<T>::push_back) {};
    //decltype(std::vector<T>::push_back2);

};
//
template <typename T>
Concepts_vector
{
  using iterator 	= typename std::vector<T>::iterator;
  using const_iterator 	= typename std::vector<T>::const_iterator;
  using std::vector<T>::push_back;		// brings them to public:
  //using std::vector<T>::begin;
  using std::vector<T>::end;
  using std::vector<T>::cbegin;
  using std::vector<T>::cend;

  //  using std::vector<T>::operator+( std::vector );

     //operator+( named_vector );

  concepts_vector(std::string_view name):std::vector<T>{}, name_{name} {}
  ~concepts_vector() {  cerr << "destructor, name: " << name_ << ".\n" << endl; }  // afterwards will call member data ~ and then ~self....
  //~named_vector() override = default;
  //~named_vector() override;
  //~named_vector() override {};
  //~named_vector() = delete;			// TODO??: does this stop the destructor for the base class from being called?

  [[nodiscard]] std::string_view name() const {return name_;};
  void name(std::string_view name) {name_ = name;};
  void name(std::string&& name) {name_ = std::move(name);};
  void problem() {
    cerr <<  "should call ~.\n";
    dispose_of_vector( this );  // this is implicitly converted.  private, but is member.
  }
private:
  std::string name_;
};
//test_concept();
//----------------------------------------------------------------------------------------------------
*/

int main() {
  test_vector_named();

  //test_vector_with_2();

  //test_inheritance_visibility_Derived_type();

  //test_concept();

  cout << "###" << endl; return 0;
}
