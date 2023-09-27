/* NOT PRODUCTION QUALITY CODE, just shows learning/teaching example, not real programming, don't copy this style, just playing around

// Copyright Grant Rostig 2015 - 2021. Distributed under the Boost Software License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)

Author: 		Grant Rostig
Inspired by:
-Generated as part of Grant's password manager effort to show how the Overloaded pattern is used by std::visit.
Shows how to:
-Overloaded could be applied to a menu system.
-The menu system allows for various function signatures
and various configurations of return values.

Reminder of usefull resources:
https://coliru.stacked-crooked.com/
https://godbolt.org/
https://cppinsights.io/
https://Wandbox.org
https://arnemertz.github.io/online-compilers/

Note: UDTs have initial capitalization.
*/
// #include <bits/stdc++.h>
#include <string>
#include <vector>
#include <iostream>
#include <functional>
using std::cout, std::cin, std::cerr, std::endl;
// template<class... Ts> struct Overloaded : Ts... {	using Ts::operator()...; };
// template<class... Ts> Overloaded(Ts...) -> Overloaded<Ts...>;  // deduction guide.  -> = returns.  todo: explain: what returns what to whom?

struct Application_State { // status state of the menu system, this would show the stack of menus and submenus, to the current context.  The details are ommitted here to focus my questions.
  int 	        a 	{980};
  std::string 	b 	{"init value"};
};
// An Action is the function that the menu system "runs"/invokes/calls/executes??.  This enum informs the menu system what to do after the "action" has been completed.

enum class  Return_value_t1 : int {
    retain_menu,
    prior_menu,
    main_menu,
    quit_save,
    terminate,
    NA
};
using       Return_value_t2 = std::string;

#ifdef MULTIPLE_RET_TYPES
std::function< Action_post_return_value_variant () > action_fn_void_param;
#else
using Action_fn  =  std::function< Return_value_t1 ( ) >;
#endif

class Menu_option {
  std::string name_           { "init'ed option name." };

#ifdef MULTIPLE_RET_TYPES
  std::function< Action_post_return_value_variant () > action_fn_void_param;
#else
  Action_fn action_fn_;
#endif

  public:
    //Menu_option() = default;
    Menu_option( std::string name, Action_fn fn) : name_(name), action_fn_(fn) {};
    Return_value_t1 process( Application_State as) {
      return action_fn_();
    }
    void print_name() const {
        cout << name_;
    }
};

class Menu {
  std::string                   name_           { "init'ed menu name."};
  std::vector< Menu_option > 	options_        {{"Close Menu", [this] () { this->close(); return Return_value_t1::NA ;} }};
  Menu *                        parent_menu_    {nullptr};
  bool                          is_menu_closing_{false};
  bool                          is_shutdowning_ {false};
 public:
    //Menu( std::vector<Menu_option> options ) : options_(options) {}  // todo: make this an initializer list
    Menu( std::string name, Menu * menu ) : name_(name),parent_menu_(menu) {
      this->add_menu_option( Menu_option {"Shutdown", [this] () { this->shutdown(); return Return_value_t1::NA ;} });
    };

    void add_menu_option( Menu_option mo) { options_.emplace_back( mo ); }

    Return_value_t1 run(   Application_State application_state) {
      Return_value_t1 ret {};
      while ( !   is_menu_closing_ && ! is_shutdowning_ ) {         // while ( not ( is_menu_closing_ ||     is_shutdowning_)) {
        this->print();
        cout << "\nselect #: "; int selection {0}; cin  >> selection;
        Menu_option & menu_option = options_.at(selection);
        ret = menu_option.process( application_state );
      }
      // return ( is_shutdowning_ ) ? Return_value_t1::terminate : Return_value_t1::retain_menu;
      /* switch (ret) {
      case Return_value_t1::prior_menu:
        return Return_value_t1::prior_menu;
        break;
      case Return_value_t1::main_menu:
        return Return_value_t1::main_menu;
        break;
      case Return_value_t1::terminate:
        return Return_value_t1::terminate;
        break;
      default:
        break;
      } */


      //if (main_menu)        return  Return_value_t1::main_menu;
      if (is_shutdowning_)  return  Return_value_t1::terminate;
      return  Return_value_t1::prior_menu;
    }
    void print()    { cout << " Menu-"<< this->name_ << "::"; for (auto & i: options_) { i.print_name() ; cout << ", "; }; }
    void close()    { is_menu_closing_  = true; };
    void shutdown() { is_shutdowning_   = true; };
};

// The various actions taken on running a Menu action. The return values are also varied for testing purposes.
Return_value_t1 action_save( int &  i, Menu * menu_current) {
  bool   user_wants_retain_menu {true};
  cout << "action save."<<endl;
  if (!user_wants_retain_menu) { menu_current->close();}
  return Return_value_t1::NA;
}
Return_value_t1 action1_1( int & i) {
    cout << "action_int              :"<<++i<<endl;
    return Return_value_t1::prior_menu;
}
Return_value_t1 action1_2( double&  i) {
  cout << "action double			 :"<<++i<<endl;
  return Return_value_t1::terminate;
}
Return_value_t1 action1_3( int&  i, std::string&  sval) {
    sval+="@";
    cout << "action_int_string		 :"<<++i<<", "<<sval<<endl;
    return Return_value_t1::retain_menu;
}
Return_value_t1 action1_4(Application_State & s, int&  i) {
    cout << "action_state_int		 :"<<++s.a<<i<<endl;
    return Return_value_t1::prior_menu;
}
Return_value_t1 action1_5(Application_State & s, double&  i) {
    cout << "action_state_double	 :"<<++s.a<<", "<<++i<<endl;
    return Return_value_t1::terminate;
}
Return_value_t1 action1_6(Application_State & s, int &  i, std::string&  sval) {
    sval+="@";
    cout << "action_state_int_string :"<<++s.a<<", "<<++i<<", "<<sval<<endl;
    return Return_value_t1::retain_menu;
}
Return_value_t1 action1_7(Application_State & s, int &  i, int & i2, std::string&  sval) {
    sval+="@";
    cout << "action_state_int2_string:"<<++s.a<<", "<<++i<<", "<<++i2<<", "<<sval<<endl;
    return Return_value_t1::retain_menu;
}
Return_value_t2 action2_1( int&  i) {
    cout << "action_int2			 :"<<++i<<endl;
    return "1";
}
Return_value_t2 action2_2( double&  i) {
    cout << "action double2			 :"<<++i<<endl;
    return "2";
}
Return_value_t2 action2_3( int&  i, std::string& sval) {
    sval+="@";
    cout << "action_int_string2		 :"<<++i<<", "<<sval<<endl;
    return "3";
}
Return_value_t2 action2_4(Application_State & s, int& i) {
    cout << "action_state_int2		 :"<<++s.a<<", "<<++i<<endl;
    return "4";
}
Return_value_t2 action2_5(Application_State & s, double& i) {
    cout << "action_state_double2    :"<<++s.a<<", "<<++i<<endl;
    return "5";
}
Return_value_t2 action2_6(Application_State & s, int & i, std::string& sval) {
    sval+="@";
    cout << "action_state_int_string2:"<<++s.a<<", "<<++i<<", "<<sval<<endl;
    return "6";
}

/*void menu_file(Application_State & s, int & i, std::string& sval, Menu * current_menu) {
  int ival {1}, ival2 {20}; double dval {12};
  Menu my_menu1 {"my_menu1", current_menu};
  my_menu1.add_menu_option( Menu_option  {"Save                 ", std::bind( action_save, std::reference_wrapper{ival}, std::reference_wrapper{current_menu} ) } );
  my_menu1.add_menu_option( Menu_option  {"bind:Int, String     "s, std::bind( action1_3,   std::reference_wrapper{ival}, std::reference_wrapper{sval}) });
  my_menu1.run(s);
  cout << "menu_file:"<<endl;
  //return "6";
}*/

/*int process_menu_selection( Menu_option const & menu_option ) {  // some of these are const because they will not change.
//    int error {0};
//    menu_option.print_name();                          //cout << "Menu option name:" << menu_option.name_ << endl;
//    //Action_post_return_value_variant action_result = menu_option.action_fn_void_param ("junk");
//    //Action_post_return_value_variant action_result = menu_option.action_fn_void_param {"junk"};
//    Action_post_return_value1 action_result = menu_option.action_fn();

//    // Now comes the part of seeing what I got back. todo: There is probably a better way to do this?
//        switch ( action_result ) {
//        case Action_post_return_value1::terminate:
//            cout << "return:terminate.\n";
//            break;
//        case Action_post_return_value1::prior_menu:
//            cout << "return:prior_menu.\n";
//            break;
//        case Action_post_return_value1::retain_menu:
//            cout << "return:retain_menu.\n";
//            break;
//        default:
//            assert(false);
//            error = 1;
//            break;
//        }
//        return error;
//}
*/

int main() {
  int ival {1}, ival2 {20}; double dval {12}; std::string sval {"sval_"};
  Application_State   application_state {};

  /*using namespace std::literals;
  Menu 	        menu_main 	  {"main_menu"s};                      // todo: note how the menu_option does bind the menu_state and application state variables at this stage.
  Menu 	        menu_main 	  {"main_menu", Menu_option  { "bind:Int             ", std::bind( action1_1, std::reference_wrapper{ival} ) }};
  */
  Menu 	        menu_main 	  {"Main Menu", nullptr};
  /* lambdas provided better type safety, so what is std::bind good for? here: https://stackoverflow.com/questions/6610046/stdfunction-and-stdbind-what-are-they-and-when-should-they-be-used
  menu_main.add_menu_option( Menu_option  {"bind:Int             ", std::bind( action1_1, std::reference_wrapper{ival} ) } );
  menu_main.add_menu_option( Menu_option  {"bind:Int, String     ", std::bind( action1_3, std::reference_wrapper{ival}, std::reference_wrapper{sval}) });
  */
  menu_main.add_menu_option( Menu_option    {"Lambda:Int",          [&ival]       (){ return action1_1(ival);}       });  // todo: can we call this bind'ing also?
  menu_main.add_menu_option( Menu_option    {"Lambda:Int&String",   [&ival, &sval](){ return action1_3(ival, sval);} });

  Menu          menu_file         {"File Menu", &menu_main };
  menu_file.add_menu_option( Menu_option    {"Bind:Int&String",     std::bind( action1_3,   std::reference_wrapper{ival}, std::reference_wrapper{sval}) });
  menu_file.add_menu_option( Menu_option    {"Save",                std::bind( action_save, std::reference_wrapper{ival}, & menu_file ) } );
  menu_main.add_menu_option( Menu_option    {"File",                [&menu_file, application_state](){ auto ret = menu_file.run(application_state); return ret;} });

              ++ival; ++ival2; ++dval; application_state.a++; sval += "#";
              cout << "pre menu  >> ival: "<<ival<<", ival2: "<<ival2<<", dval: "<<dval<<", sval: "<<sval<< ",  state_menu_widget.a:"<<application_state.a<< endl;
  menu_main.run( application_state );
              cout << "post menu >> ival: "<<ival<<", ival2: "<<ival2<<", dval: "<<dval<<", sval: "<<sval<< ",  state_menu_widget.a:"<<application_state.a<< endl;

  cout << "###" << endl;
  return 0;
}
