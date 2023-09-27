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
#include <bits/stdc++.h>
using std::cout, std::cin, std::cerr, std::endl;

template<class... Ts> struct Overloaded : Ts... {	using Ts::operator()...; };
template<class... Ts> Overloaded(Ts...) -> Overloaded<Ts...>;  // deduction guide.  -> = returns.  todo: explain: what returns what to whom?

struct State_menu { // status state of the menu system, this would show the stack of menus and submenus, to the current context.  The details are ommitted here to focus my questions.
    int 	a 	{980};
    double 	b 	{990};
};

// An Action is the function that the menu system "runs"/invokes/calls/executes??.  This enum informs the menu system what to do after the "action" has been completed.
enum class Action_post_return_value1 {  //  todo: int by default??
    retain_menu,
    prior_menu,
    terminate
};
using      Action_post_return_value2 = std::string;

//#define ONE_RETURN_TYPE // Two example cases, 1) a variant with one return type, or 2) a variant with two types.

using Action_post_return_value_variant =
        std::variant <
            //std::monostate,  						// todo: good idea?
            Action_post_return_value1
#ifndef ONE_RETURN_TYPE
            , Action_post_return_value2
#endif
        >;
// vary the signature between a variety useful for testing, while keeping the return type the same, it being type_1
// note: I'm here I'm considering the signature to include the return type, which is not how C++ defines it? todo?:
using Menu_action_signature1_1 = Action_post_return_value1( int& );  // Note: the use of the meaning of the term 'signature' is expanded to includes the return type.
using Menu_action_signature1_2 = Action_post_return_value1( double& );
using Menu_action_signature1_3 = Action_post_return_value1( int&, std::string &);
using Menu_action_signature1_4 = Action_post_return_value1( State_menu &, int& );
using Menu_action_signature1_5 = Action_post_return_value1( State_menu &, double& );
using Menu_action_signature1_6 = Action_post_return_value1( State_menu &, int&, std::string &);
using Menu_action_signature1_7 = Action_post_return_value1( State_menu &, int&, int&, std::string &);
// vary the signature between a variety useful for testing, while keeping the return type the same, it being type_2
using Menu_action_signature2_1 = Action_post_return_value2( int& );
using Menu_action_signature2_2 = Action_post_return_value2( double& );
using Menu_action_signature2_3 = Action_post_return_value2( int&, std::string &);
using Menu_action_signature2_4 = Action_post_return_value2( State_menu &, int&);
using Menu_action_signature2_5 = Action_post_return_value2( State_menu &, double&);
using Menu_action_signature2_6 = Action_post_return_value2( State_menu &, int&, std::string &);

// specify the std::functions to hold the above variations of signature&return.
using Menu_action_function1_1 = std::function< Menu_action_signature1_1>;
using Menu_action_function1_2 = std::function< Menu_action_signature1_2>;
using Menu_action_function1_3 = std::function< Menu_action_signature1_3>;
using Menu_action_function1_4 = std::function< Menu_action_signature1_4>;
using Menu_action_function1_5 = std::function< Menu_action_signature1_5>;
using Menu_action_function1_6 = std::function< Menu_action_signature1_6>;
using Menu_action_function1_7 = std::function< Menu_action_signature1_7>;
using Menu_action_function2_1 = std::function< Menu_action_signature2_1>;
using Menu_action_function2_2 = std::function< Menu_action_signature2_2>;
using Menu_action_function2_3 = std::function< Menu_action_signature2_3>;
using Menu_action_function2_4 = std::function< Menu_action_signature2_4>;
using Menu_action_function2_5 = std::function< Menu_action_signature2_5>;
using Menu_action_function2_6 = std::function< Menu_action_signature2_6>;

// Menu actions can have all of the above combinations of signature&returns.
struct Menu_option {
    std::string name { "init'ed option name." };
    std::variant< Menu_action_function1_1,
                  Menu_action_function1_2,
                  Menu_action_function1_3,
                  Menu_action_function1_4,
                  Menu_action_function1_5,
                  Menu_action_function1_6,
                  Menu_action_function1_7
#ifndef ONE_RETURN_TYPE
                  , Menu_action_function2_1,
                  Menu_action_function2_2,
                  Menu_action_function2_3,
                  Menu_action_function2_4,
                  Menu_action_function2_5,
                  Menu_action_function2_6
#endif
    > action_fn_variant;
};

struct Menu {
    std::string 				name { "init'ed menu name."};
    std::vector< Menu_option > 	options {};
};

// The various actions taken on running a Menu action. The return values are also varied for testing purposes.
Action_post_return_value1 action1_1( int & i) {
    cout << "action_int				 :"<<i<<endl; i++;
    return Action_post_return_value1::prior_menu;
}
Action_post_return_value1 action1_2( double&  i) {
    cout << "action double			 :"<<i<<endl; i++;
    return Action_post_return_value1::terminate;
}
Action_post_return_value1 action1_3( int&  i, std::string&  sval) {
    cout << "action_int_string		 :"<<i<<", "<<sval<<endl; i++;
    return Action_post_return_value1::retain_menu;
}
Action_post_return_value1 action1_4(State_menu & s, int&  i) {
    cout << "action_state_int		 :"<<s.a<<i<<endl; i++;
    return Action_post_return_value1::prior_menu;
}
Action_post_return_value1 action1_5(State_menu & s, double&  i) {
    cout << "action_state_double	 :"<<s.a<<", "<<i<<endl; i++;
    return Action_post_return_value1::terminate;
}
Action_post_return_value1 action1_6(State_menu & s, int &  i, std::string&  sval) {
    cout << "action_state_int_string :"<<s.a<<", "<<i<<", "<<sval<<endl; i++;
    return Action_post_return_value1::retain_menu;
}
Action_post_return_value1 action1_7(State_menu & s, int &  i, int & i2, std::string&  sval) {
    cout << "action_state_int2_string:"<<s.a<<", "<<i<<", "<<i2<<", "<<sval<<endl; i++;
    return Action_post_return_value1::retain_menu;
}
Action_post_return_value2 action2_1( int&  i) {
    cout << "action_int2			 :"<<i<<endl; i++;
    return "1";
}
Action_post_return_value2 action2_2( double&  i) {
    cout << "action double2			 :"<<i<<endl; i++;
    return "2";
}
Action_post_return_value2 action2_3( int&  i, std::string& sval) {
    cout << "action_int_string2		 :"<<i<<", "<<sval<<endl; i++;
    return "3";
}
Action_post_return_value2 action2_4(State_menu & s, int& i) {
    cout << "action_state_int2		 :"<<s.a<<", "<<i<<endl; i++;
    return "4";
}
Action_post_return_value2 action2_5(State_menu & s, double& i) {
    cout << "action_state_double2    :"<<s.a<<", "<<i<<endl; i++;
    return "5";
}
Action_post_return_value2 action2_6(State_menu & s, int & i, std::string& sval) {
    cout << "action_state_int_string2:"<<s.a<<", "<<i<<", "<<sval<<endl; i++;
    return "6";
}

Action_post_return_value_variant call_menu_option_ifs( Menu_option const & menu_option, State_menu & state_menu_var, int & ival, int & ival2, double &  dval, std::string &  sval ) {  // some of these are const because they will not change.
    if (       std::holds_alternative< Menu_action_function1_1 >( menu_option.action_fn_variant)) {  // NOTE: should have used std::get_if<> !!
        auto af = std::get< Menu_action_function1_1 >( menu_option.action_fn_variant);
        //auto af = constexpr if can be used here ....< Menu_action_function1 >( m_opt.action_fn_variant);
        return af( ival );
    } else if (std::holds_alternative< Menu_action_function1_2 >( menu_option.action_fn_variant)) {
        auto af = std::get< Menu_action_function1_2 >( menu_option.action_fn_variant);
        return af( dval );
    } else if (std::holds_alternative< Menu_action_function1_3 >( menu_option.action_fn_variant)) {
        auto af = std::get< Menu_action_function1_3 >( menu_option.action_fn_variant);
        return af( ival, sval );
    } else if (std::holds_alternative< Menu_action_function1_4 >( menu_option.action_fn_variant)) {
        auto af = std::get< Menu_action_function1_4 >( menu_option.action_fn_variant);
        return af( state_menu_var, ival );
    } else if (std::holds_alternative< Menu_action_function1_5 >( menu_option.action_fn_variant)) {
        auto af = std::get< Menu_action_function1_5 >( menu_option.action_fn_variant);
        return af( state_menu_var, dval );
    } else if (std::holds_alternative< Menu_action_function1_6 >( menu_option.action_fn_variant)) {
        auto af = std::get< Menu_action_function1_6 >( menu_option.action_fn_variant);
        return af( state_menu_var, ival, sval );
    } else if (std::holds_alternative< Menu_action_function1_7 >( menu_option.action_fn_variant)) {
        auto af = std::get< Menu_action_function1_7 >( menu_option.action_fn_variant);
        return af( state_menu_var, ival, ival2, sval );
    }
#ifndef ONE_RETURN_TYPE
      else if (  std::holds_alternative< Menu_action_function2_1 >( menu_option.action_fn_variant)) {
        auto af = std::get< Menu_action_function2_1 >( menu_option.action_fn_variant);
        return af( ival );
    } else if (std::holds_alternative< Menu_action_function2_2 >( menu_option.action_fn_variant)) {
        auto af = std::get< Menu_action_function2_2 >( menu_option.action_fn_variant);
        return af( dval );
    } else if (std::holds_alternative< Menu_action_function2_3 >( menu_option.action_fn_variant)) {
        auto af = std::get< Menu_action_function2_3 >( menu_option.action_fn_variant);
        return af( ival, sval );
    } else if (std::holds_alternative< Menu_action_function2_4 >( menu_option.action_fn_variant)) {
        auto af = std::get< Menu_action_function2_4 >( menu_option.action_fn_variant);
        return af( state_menu_var, ival );
    } else if (std::holds_alternative< Menu_action_function2_5 >( menu_option.action_fn_variant)) {
        auto af = std::get< Menu_action_function2_5 >( menu_option.action_fn_variant);
        return af( state_menu_var, dval );
    } else if (std::holds_alternative< Menu_action_function2_6 >( menu_option.action_fn_variant)) {
        auto af = std::get< Menu_action_function2_6 >( menu_option.action_fn_variant);
        return af( state_menu_var, ival, sval );
    }
#endif
    else assert(("didn't check all alternatives",false));
}

Action_post_return_value_variant call_menu_option_no_visit( Menu_option const & menu_option, State_menu & state_menu_var, int & ival, int & ival2, double &  dval, std::string &  sval ) {  // some of these are const because they will not change.
    auto function_object_overload_set = Overloaded { // Note: Notice that the ival and dval are captured by reference even though the signatures of the functions are capture by value.
            //       This requirement is inconsistent with the above example/ugly code. todo: TODO does this cause indefined behavior?
            // duplicates make it ambigious [&ival]            (Menu_action_function1 &af)  { Action_return_1 r = af(ival); return r; }, // to be invoked via operator() on the function object (AKA lambda) or any callable object.
            [&ival]            		(Menu_action_function1_1 const &af) ->Action_post_return_value1 { Action_post_return_value1 r = af(ival); return r; }, // to be invoked via operator() on the function object (AKA lambda) or any callable object.
            [&dval]            		(Menu_action_function1_2 const &af) ->Action_post_return_value1 { Action_post_return_value1 r = af(dval); return r; },
            [&ival,&sval]      		(Menu_action_function1_3 const &af) ->Action_post_return_value1 { Action_post_return_value1 r = af(ival,sval); return r; },
            [&state_menu_var,&ival]     (Menu_action_function1_4 const &af) ->Action_post_return_value1 { Action_post_return_value1 r = af(state_menu_var,ival); return r; },
            [&state_menu_var,&dval]     (Menu_action_function1_5 const &af) ->Action_post_return_value1 { Action_post_return_value1 r = af(state_menu_var,dval); return r; },
            //[&state_menu_var,&ival,&sval](Menu_action_function1_6 const &af)->Action_post_return_value1{ Action_post_return_value1 r = af(state_menu_var,ival,sval); return r; }
            [&]                         (Menu_action_function1_6 const &af) 							{                      auto r = af(state_menu_var,ival,sval); return r; },  // todo: does using "&" waste resources?
            [&]                         (Menu_action_function1_7 const &af) 							{                      auto r = af(state_menu_var,ival,ival2,sval); return r; },  // todo: does using "&" waste resources?
            //[&]                         (Menu_action_function1_6 const &af) 								{                      auto r = af(state_menu_var,ival,sval); return r; },  // todo: does using "&" waste resources?
            //[&]                         (Menu_action_function1_6 const &af)     ->Action_post_return_value1 {                      auto r = af(state_menu_var,ival,sval); return r; },  // todo: does using "&" waste resources?
            //[&]                         (Menu_action_function1_6 const &af)->Action_post_return_value1{                      auto r = af(state_menu_var,ival,sval); return r; },  // todo: does using "&" waste resources?
#ifndef ONE_RETURN_TYPE
            [&ival]            		(Menu_action_function2_1 const &af) { Action_post_return_value2 r = af(ival); return r; },
            //[&ival]            			(Menu_action_function2_1 const &af) { return std::move( af(ival) ); },
            [&dval]            		(Menu_action_function2_2 const &af) { Action_post_return_value2 r = af(dval); return r; },
            [&ival,&sval]      		(Menu_action_function2_3 const &af) { Action_post_return_value2 r = af(ival,sval); return r; },
            [&state_menu_var,&ival]     (Menu_action_function2_4 const &af) { Action_post_return_value2 r = af(state_menu_var,ival); return r; },
            [&state_menu_var,&dval]     (Menu_action_function2_5 const &af) { Action_post_return_value2 r = af(state_menu_var,dval); return r; },
            //[&state_menu_var,&ival,&sval](Menu_action_function2_6 const &af){ Action_post_return_value2 r = af(state_menu_var,ival,sval); return r; }
            [&state_menu_var,&ival,&sval](Menu_action_function2_6 const &af){                      	 return af(state_menu_var,ival,sval);}
#endif
    };

#ifndef ONE_RETURN_TYPE
    Action_post_return_value_variant action_result {};
    // https://cpplang.slack.com/archives/C21PKDHSL/p1569203158330600
    // Required to avoid ambiguity when calling the function we must wrap the overload_set with another lambda that allows for the return value's type being of more than one type.  // todo: TODO does this additional wrapping lambda cause another level of pointer indirection?
    auto fo_return_type_overload_set = [&](auto ... args) -> Action_post_return_value_variant { return function_object_overload_set( args...); }; // todo: TODO is there a better way to do this?  Also I think I want to pass by reference?
    // Back to the pattern from the book.
    action_result = std::visit( fo_return_type_overload_set, menu_option.action_fn_variant );

    // Now comes the part of seeing what I got back. todo: There is probably a better way to do this?
    if      (std::holds_alternative< Action_post_return_value2 >( action_result )) {
        cout << "return: int "<< std::get< Action_post_return_value2 >( action_result )<<"."<<endl;
    }
    else if (std::holds_alternative< Action_post_return_value1 >( action_result )) {
        switch (std::get< Action_post_return_value1 >( action_result )) {
        case Action_post_return_value1::terminate:
            cout << "return: terminate.\n";
            break;
        case Action_post_return_value1::prior_menu:
            cout << "return: prior_menu.\n";
            break;
        case Action_post_return_value1::retain_menu:
            cout << "return: retain_menu.\n";
            break;
        default:
            assert(false);
            break;
        }
    }
    else assert(false);
#else  // only ONE_RETURN_TYPE
    Action_post_return_value1 	action_result {};
    //action_result = std::visit( function_object_overload_set, 																		current_menu_option.action_fn_variant );  // todo: why must lambda funtion argument be const for only this line, not the others?
    action_result = std::visit( [&](auto... args) -> Action_post_return_value1 { return function_object_overload_set( args...); }, menu_option.action_fn_variant );
    // Now comes the part of seeing what I got back.
    switch ( action_result ) {
    case Action_post_return_value1::terminate:
        cout << "return: terminate.\n";
        break;
    case Action_post_return_value1::prior_menu:
        cout << "return: prior_menu.\n";
        break;
    case Action_post_return_value1::retain_menu:
        cout << "return: retain_menu.\n";
        break;
    default:
        assert(false);
        break;
    }
#endif
    return action_result;
}

int main() {
    State_menu 	state_menu_var 	{};  // state value
    cout << state_menu_var.a << endl;
    Menu 		menu_main 		{};
    menu_main.name = "main_menu";  // todo: note how the menu does not bind the menu_state and application state variables it will need when running.
    menu_main.options.emplace_back(Menu_option {"Int             ", Menu_action_function1_1 {action1_1}});
    menu_main.options.emplace_back(Menu_option {"Double          ", Menu_action_function1_2 {action1_2}});
    menu_main.options.emplace_back(Menu_option {"String          ", Menu_action_function1_3 {action1_3}});
    menu_main.options.emplace_back(Menu_option {"State_int       ", Menu_action_function1_4 {action1_4}});
    menu_main.options.emplace_back(Menu_option {"State_double    ", Menu_action_function1_5 {action1_5}});
    menu_main.options.emplace_back(Menu_option {"State_int_string", Menu_action_function1_6 {action1_6}});
    menu_main.options.emplace_back(Menu_option {"State_int2_string", Menu_action_function1_7 {action1_7}});
#ifndef ONE_RETURN_TYPE
    menu_main.options.emplace_back(Menu_option {"Int            2", Menu_action_function2_1 {action2_1}});
    menu_main.options.emplace_back(Menu_option {"Double         2", Menu_action_function2_2 {action2_2}});
    menu_main.options.emplace_back(Menu_option {"String         2", Menu_action_function2_3 {action2_3}});
    menu_main.options.emplace_back(Menu_option {"State_int      2", Menu_action_function2_4 {action2_4}});
    menu_main.options.emplace_back(Menu_option {"State_double   2", Menu_action_function2_5 {action2_5}});
    menu_main.options.emplace_back(Menu_option {"State_int_strin2", Menu_action_function2_6 {action2_6}});
#endif
    // The long and ugly way to call these the menu_option action_functions using if statements. Shown for comparision to a better way below.
    cout << "\n***  The long and ugly way to call these the menu_option action_functions using if statements. ***\n";
    int ival {1}, ival2 {20}; double dval {12}; std::string sval {"an_sval_"};
    for (auto & menu_option : menu_main.options) {  // test with all the various possibilities.
        ++ival; ++ival2; ++dval; state_menu_var.a++; sval += "an_sval_";
        cout << ">> ival: "<<ival<<", dval: "<<dval<< ",  state_menu_var.a:"<<state_menu_var.a<< endl;
        Action_post_return_value_variant r = call_menu_option_ifs(   menu_option, state_menu_var, ival, ival2, dval, sval );
    }

    // ***** NOW - A nicer way to call these the menu_option action_functions.
    cout << "\n*** A nicer way to do the above with std::visit.  ***\n";
    ival  = 10; ival2 = 300; dval  = 222.0; sval  = "an_sval_";
    for (auto & menu_option : menu_main.options) {  // test with all the various possibilities.
        ++ival; ++ival2; ++dval; state_menu_var.a++; sval += "an_sval_";
        cout << ">> ival: "<<ival<<", dval: "<<dval<< ",  state_menu_var.a:"<<state_menu_var.a<< endl;
        Action_post_return_value_variant r = call_menu_option_no_visit( menu_option, state_menu_var, ival, ival2, dval, sval );
    }
    cout << "###" << endl;
    return 0;
}
