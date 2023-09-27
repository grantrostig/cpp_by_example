// Author: Grant Rostig, adapted from cppreference.com using-declaration entry https://en.cppreference.com/w/cpp/language/using_declaration
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using std::endl, std::cout, std::cerr, std::cin;

template <typename T, typename U> class Vector_with_name_tpl2 : public std::vector<T> { // todo: why not? class Vector_with_name_tplt<T> : public std::vector<T> {};
public:
  // using std::vector::push_back;
  // using std::vector<T>;
  // using std::vector<T>::push_back;	// note this line on cppref: using B<Y>::f; // compiles, but f is not a template-name
  // using std::vector<T>::push_back();
  // using std::vector<T>::push_back(int x);
  std::string 	name{"not_set"};
  U 		template_type_data_member1{'c'};
  //U 		template_type_data_member2('c');
  Vector_with_name_tpl2()    = default;
  Vector_with_name_tpl2(std::string name) : name{name} {};
  //Vector_with_name_tpl(bool i) : name{i} {};
};

template<typename T> class Vector_with_name_tpl1 : public std::vector<T> {
// specialzation  template<typename T> class Vector_with_name_tpl1<T> : public std::vector<T> {
  public:
    //using std::vector<T>;	 		// todo: how do I pull in the initialization constructor from base?
    using std::vector<T>::push_back;		// member access rights, and names only.
    //using std::vector<T>::push_back();  	// todo: what would this mean if it compiled.

    std::string 		   name{"not_set"};
    Vector_with_name_tpl1()    	   = default; 		//Vector_with_name_tpl1<T>() = default;
    //Vector_with_name_tpl1()      = delete; 		//Vector_with_name_tpl1<T>() = default;

    Vector_with_name_tpl1(std::initializer_list<T> initlist) : std::vector<T> {initlist} {}; // todo: where does documentation state that this works?  Next line does nothing?

    //Vector_with_name_tpl1(std::initializer_list<T> initlist) {
    //  std::vector<T> { initlist };  // todo: this line does not init the vector within this class.
    //  this->_M_shrink_to_fit();
    //};
    //Vector_with_name_tpl1( T value, size_t count) : std::vector (value,count) {};
    //Vector_with_name_tpl1( T value, size_t count)  : Vector_with_name_tpl1::vector (value,count), name{name} {};
    Vector_with_name_tpl1( T value, size_t count)   : Vector_with_name_tpl1::Vector_with_name_tpl1::vector (value,count), name{name} {};
    //Vector_with_name_tpl1( T value, size_t count) : std::vector<T> (value,count) {};
    //Vector_with_name_tpl1( T value, size_t count) : std::vector<T> (value,count) {};

    Vector_with_name_tpl1(std::string name) : name{name} {};  // todo: how do we differentiate between two similar constructors?
};
class Vector_with_name : public std::vector<int> {
public:
  // using std::vector::push_back;
  // using std::vector<int>;
  // using std::vector<int>::push_back;	// note this line on cppref: using B<Y>::f; // compiles, but f is not a template-name
  // using std::vector<int>::push_back();
  // using std::vector<int>::push_back(int x);
  std::string name{"not_set"};
  Vector_with_name() = default;
  Vector_with_name(std::string name) : name{name} {};
};
void test_supplemented_vector() {
  //Vector_with_name vec_name{"my_vec2 initalized"};
  //Vector_with_name_tpl1<int> vec_name{};
  //Vector_with_name_tpl1<int> vec_name{"my_vec initalized"};
  //Vector_with_name_tpl1<std::string> vec_name{"member1"s,"member2","member3"};  // todo: how do we convert that C string to a C++ one using "s ?
  Vector_with_name_tpl1<std::string> vec_name{"member1","member2","member3"};

  for (int i = 0; i < 10; i++) {
    //vec_name.push_back(i + .1); // todo: why no narrowing warning?
    vec_name.push_back(std::to_string(i + .1)); // todo: why no narrowing warning?
  };
  cout << vec_name.name << ", "<<vec_name.size()<< endl;
  for (auto i :vec_name ) {
    cout<<", "<<i; // todo: why no narrowing warning?
  }; cout<<endl;

  //Vector_with_name_tpl1<int> vec_tpl1{"my_vec2 initalized"};
  //Vector_with_name_tpl<float, bool > vec_tpl2{"my_vec2 initalized"};

  //Vector_with_name_tpl1<float, std::string> vec_tpl1{"my_vec2 initalized"};
//  for (int i = 0; i < 10; i++) {
//    vec_tpl1.push_back(static_cast<float>(i) + .1);
//  };
//  cout << "name: "  << vec_tpl1.name << endl;
  //cout << "tname: " << vec_tpl1.template_type_data_member1 << endl;
}

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
void test_inheritance_visibility() {
  Derived_type 		derived_obj;
  int  			junk		{derived_obj.p_base_data_member_protected};

  Base_type 		&base_obj_ref	{derived_obj}; 	// todo: is this slicing? no, but why no warning?
  Base_type  		*base_obj_ptr	{&derived_obj}; // todo: is this slicing? no, but why no warning?
  Base_type 		base_obj	{derived_obj}; 	// todo: is this slicing?
  base_obj = derived_obj;  				// todo: is this slicing?
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

template <class T>
struct named_vector: private std::vector<T> {
  using iterator 	= typename std::vector<T>::iterator;
  using const_iterator 	= typename std::vector<T>::const_iterator;
  using std::vector<T>::push_back;		// brings them to public:
  //using std::vector<T>::begin;
  using std::vector<T>::end;
  using std::vector<T>::cbegin;
  using std::vector<T>::cend;

//  using std::vector<T>::operator+( std::vector );

  //operator+( named_vector );

  named_vector(std::string_view name):std::vector<T>{}, name_{name} {}
  ~named_vector() {  std::clog << "destructor, name: " << name_ << ".\n" << endl; }  // afterwards will call member data ~ and then ~self....
  //~named_vector() override = default;
  //~named_vector() override;
  //~named_vector() override {};
  //~named_vector() = delete;			// todo: does this stop the destructor for the base class from being called?

  [[nodiscard]] std::string_view name() const {return name_;};
  void name(std::string_view name) {name_ = name;};
  void name(std::string&& name) {name_ = std::move(name);};
  void problem() {
    std::clog <<  "should call ~.\n";
    dispose_of_vector( this );  // this is implicitly converted.  private, but is member.
  }
private:
  std::string name_;
};

template <class T>
struct vector_named: public std::vector<T> {
  using iterator 	= typename std::vector<T>::iterator;
  using const_iterator 	= typename std::vector<T>::const_iterator;
  using std::vector<T>::push_back;		// brings them to public:
  using std::vector<T>::end;
  using std::vector<T>::cbegin;
  using std::vector<T>::cend;
  //  using std::vector<T>::operator+( std::vector );
  //  operator+( named_vector );

  vector_named(std::string_view name):std::vector<T>{}, name_{name} {}
  ~vector_named() {  std::clog << "destructor, name: " << name_ << ".\n" << endl; }  // afterwards will call member data ~ and then ~self....
  //~named_vector() override = default;
  //~named_vector() override;
  //~named_vector() override {};
  //~named_vector() = delete;			// todo: does this stop the destructor for the base class from being called?

  [[nodiscard]] std::string_view name() const 	{return name_;};
  void name(std::string_view name) 		{name_ = name;};
  void name(std::string&& name) 		{name_ = std::move(name);};
  void problem() {
    std::clog <<  "should call ~.\n";
    dispose_of_vector( this );  // this is implicitly converted.  private, but is member.
  }
private:
  std::string name_;
};

//template <class T> void dispose_of_vector(vector_named<T>*v) {
template <class T> void dispose_of_vector(std::vector<T>*v) {
  delete v; }

template<typename T>
concept Hashable = requires(T a) {
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
/*
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
  ~concepts_vector() {  std::clog << "destructor, name: " << name_ << ".\n" << endl; }  // afterwards will call member data ~ and then ~self....
  //~named_vector() override = default;
  //~named_vector() override;
  //~named_vector() override {};
  //~named_vector() = delete;			// todo: does this stop the destructor for the base class from being called?

  [[nodiscard]] std::string_view name() const {return name_;};
  void name(std::string_view name) {name_ = name;};
  void name(std::string&& name) {name_ = std::move(name);};
  void problem() {
    std::clog <<  "should call ~.\n";
    dispose_of_vector( this );  // this is implicitly converted.  private, but is member.
  }
private:
  std::string name_;
};
*/
template <class T>
std::ostream& operator<<(std::ostream& os, named_vector<T> const&nv) {
  os << '[' << nv.name() << ": ";
  std::copy(nv.cbegin(), nv.cend(), std::ostream_iterator<T>(os, ", "));
  os << ']';
  return os;
}

int main() {
  //test_inheritance_visibility();
  //test_supplemented_vector();
  //std::vector<int> v1 {1,2,3,4};
  //std::vector<int> v2 {1,2,3,4};
  //auto r = v1 < v2;

  vector_named<int> * nvp {new vector_named<int>{"joe"}}; // decltype(nvp) == named_vector<int>*
  dispose_of_vector(nvp);
  auto junk = nvp;
  delete nvp;

  //nvp->begin();
  //begin(*nvp);

  //nvp->push_back(7);
  //std::cout << *nvp < *nvp << '\n';
  //std::cout << nvp < nvp << '\n';
  //std::cout << (*nvp < *nvp) << '\n';
  //std::cout << v1 < v2 << '\n';
  //nvp->problem();
  std::clog << "main(): post problem()\n";
  cout << "###" << endl; return 0;
}
