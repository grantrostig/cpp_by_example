/* NOT PRODUCTION CODE, just playing around */
#include <iostream>
#include <vector>
#include <variant>
#include <functional>
#include <queue>
using std::cout, std::endl, std::cin, std::cerr;

using InteractionResultData_Vrnt = std::variant< std::monostate, bool, char, int >;
struct InteractionResult {
        InteractionResultData_Vrnt  	data 		{};  // the most important data value of the item processed. ie. name or code or ID.
        int		   						error 		{};	 // any error that occurred.
       };

template<class... Ts>  				// variadic ie. any number of any type are handled. Below we use several in the contructor of our one object. // ... is a parameter pack.
struct Overloaded_visitor : Ts... { 		// inherit from all those types  todo:  how does this work??
    using Ts::operator()...;  		// all of those operator()s.  // new in c++17.
};
template<class... Ts>
Overloaded_visitor(Ts...) -> Overloaded_visitor<Ts...>;  // deduction guide.  -> = returns.

template<class... Ts2>  				// variadic ie. any number of any type are handled. Below we use several in the contructor of our one object. // ... is a parameter pack.
struct Match_target : Ts2... { 		// inherit from all those types  todo:  how does this work??
    using Ts2::operator()...;  		// all of those operator()s.  // new in c++17.
};
template<class... Ts2>
Match_target(Ts2...) -> Match_target<Ts2...>;  // deduction guide.  -> = returns.


using    Priority 	= int;

class User {
public:
    std::string user_id;
    std::string passw;  // no pw if user is a target user we have right to see.
};
class User_target {
public:
    User user;		// our user account for entry into the system.
    User target;  	// the user which has the data, if other than ourselves.
};
/*class Retrieve_rss {
    std::string		url;
};
class Retrieve_yt // user vs channel?
{
    User_target 	user_and_target;
    std::string		pw;
};
class Retrieve_tw {
    User_target 	user_and_target;
};
class Retrieve_plain_wsite {
    std::string		url;
    // plain vs wix vs wpress vs ...
};
class Retrieve_wpress_wsite : Retrieve_plain_wsite {
    User_target 	user_and_target;
};
class Retrieve_fs {
    User			super_user;
    std::string		file_name;
};*/

class Dropbox {
public:
            User_target 	user_and_target;
            std::string		directory_locator;
            //InteractionResult operator()( ) { cout << "opr():retrieving dropbox user name:"<< user_and_target.user.user_id<< ":\n"; return { 42, 0 }; };
            InteractionResult operator()( Dropbox 	const & 	arg1 ) const { cout << "opr():retrieving dropbox user name:"<< user_and_target.user.user_id<< ":\n"; return { 42, 0 }; };
            //InteractionResult operator()( Dropbox 	        	arg1 ) const { cout << "opr():retrieving dropbox user name:"<< user_and_target.user.user_id<< ":\n"; return { 42, 0 }; };

            InteractionResult operator()( int arg )   			  { cout << "opr():retrieving dropbox user name:"<< user_and_target.user.user_id<< ":\n"; return { 42, 0 }; };
            InteractionResult operator()( int 		const & 	arg1 ) const { cout << "opr():retrieving dropbox user name:"<< user_and_target.user.user_id<< ":\n"; return { 42, 0 }; };
            InteractionResult doit( 	  int 		const & 	arg1 ) const { cout << "do_it:retrieving dropbox user name:"<< user_and_target.user.user_id<< ":\n"; return { 442, 0 }; };
    static 	InteractionResult doit_static(int 		const & 	arg1 ) /*const is invalid here b/c no this */
                                                                  { cout << "do_it:retrieving dropbox user name:"/*<< user_and_target.user.user_id*/<< ":\n"; return { 442, 0 }; }; // todo: why can't I reference a data member in a static fn member?  Would the data have to be static too? because it is not constructed early enough?
            InteractionResult operator()( Dropbox 	const & 	arg1, int arg2 ) const { cout << "opr():retrieving dropbox user name:"<< user_and_target.user.user_id<< ":\n"; return { 942, 90 }; };
            InteractionResult operator()( Dropbox 	        	arg1, int arg2 ) const { cout << "opr():retrieving dropbox user name:"<< user_and_target.user.user_id<< ":\n"; return { 942, 90 }; };
    // possible future sub-classes: business or personal
};
// struct Task_vrnt_o;  todo: broken with "using below" why?
class Facebook {
public:
            User_target 	user_and_target;
            //InteractionResult operator()( ) { cout << "opr():retrieving fb      user name:"<< user_and_target.user.user_id<< ":\n"; return { 43, 0 }; };
            InteractionResult operator()( Facebook 	const & 	arg1 ) const { cout << "opr():retrieving fb      user name:"<< user_and_target.user.user_id<< ":\n"; return { 43, 0 }; };
            //InteractionResult operator()( Facebook 		   		arg1 ) { cout << "opr():retrieving fb      user name:"<< user_and_target.user.user_id<< ":\n"; return { 43, 0 }; };

            InteractionResult operator()( int 					arg1 ) { cout << "opr():retrieving fb      user name:"<< user_and_target.user.user_id<< ":\n"; return { 43, 0 }; };
            InteractionResult operator()( int 		const & 	arg1 ) const { cout << "opr():retrieving fb      user name:"<< user_and_target.user.user_id<< ":\n"; return { 43, 0 }; };
            InteractionResult doit( 	  int 		const & 	arg1 ) const { cout << "do_it:retrieving fb      user name:"<< this->user_and_target.user.user_id<< ":\n"; return { 443, 0 }; };
    static 	InteractionResult doit_static(int 		const & 	arg1 )       { cout << "do_it:retrieving fb      user name:"/*<< user_and_target.user.user_id*/<< ":\n"; return { 443, 0 }; };
            InteractionResult operator()( Facebook 	const & 	arg1, int arg2 ) const { cout << "opr():retrieving fb      user name:"<< user_and_target.user.user_id<< ":\n"; return { 943, 90 }; };
            InteractionResult operator()( Facebook 	        	arg1, int arg2 ) const { cout << "opr():retrieving fb      user name:"<< user_and_target.user.user_id<< ":\n"; return { 943, 90 }; };
    // possbile future sub-classes: user/page/group/??
};

/* function is a pointer
struct 	Task; 		//  "" : pointer to function member which does the work for that type of argument
//using  Task_fn 		= InteractionResult (*)( Task );  // todo:?? define a task that takes any funtion
typedef InteractionResult (*Task_fn)( Task ) ; 		  // todo:?? define a task that takes any funtion
struct 	Task    		{ 	int 		    priority; Task_fn			action_fn; };
using  	Queue   	   	= std::vector< 		Task >;  // yes this should be std::queue, but I wanted to use range_for and am too lazy to do that now, so making it a vector is a kludge.

InteractionResult const process_task( Task & task ) {
    //auto action_result = task.action_fo_vrnt. (task);
    auto action_result = task.action_fn(task);
    return action_result;
}

// function is std::function
struct Task_sfn;  	//  _sfn : std::function member which does the work for that type of argument
using Task_vrnt_sfn = std::variant< Retrieve_dropbox, Retrieve_fb >; // a function with the individualized code for the task to be performed.
using  Task_sfn_fn 	= std::function< Task_vrnt_sfn >();
struct Task_sfn    	{  	int 		    priority; Task_sfn_fn		action_sfn_fn; };
using  Queue_sfn   	= std::vector< 		Task_sfn >;

InteractionResult const process_task_sfn( Task_sfn & task ) {  // from RED book (2nd Ed) P 175
    InteractionResult action_result;
    auto my_fn = task.action_sfn_fn;  // todo: are operator() members static?  Getting strange compiler error about reference to non-static.
    //auto action_result = task.action_fo_vrnt. (task);
    if ( std::holds_alternative< Retrieve_dropbox > ( task.action_sfn_fn ) ) {
        Retrieve_dropbox my_fn = std::get< Retrieve_dropbox > ( task.action_sfn_fn() ) ;
        action_result = task.action_sfn_fn(task);
    }
    else if ( std::holds_alternative< Retrieve_fs > ( task.action_sfn_fn ) ) {
        action_result = task.action_sfn_fn(task);
    }
    return action_result;
} */

// function is operator() //  _o : overload on operator() member which does the work for that type of argument
using  Target_vrnt_o 	= std::variant< Dropbox, Facebook >; // Type represents one set of possible classes (sum type, discriminated union), these classes will be visited by the appropiately matched function having the individualized code for the task to be performed.

struct Task_o 		{
    int 			    priority 				{99};
    float 			    received_time_of_day 	{99};   // todo: change this to int and try to use it ;)
    std::string 	    region					{"*init*"};
    Target_vrnt_o		target_fo_vrnt;
};
using  Queue_o 		= std::vector< Task_o >;

InteractionResult const process_task_overloaded( Task_o & task ) {
    // unseen examples using function objects
    // unusual examples using classes which support operator() without parameters
    auto fo_overload_set0 = Overloaded_visitor < Dropbox, Facebook > {  										// debugging initializers: User 	u1 	{"name1","pass1"}; //User_target ut1 {u1,u1};
                                    { { {"jack o0","pass"},{"fred","pass"} }, {"/root"} },
                                    { { {"jill o0","pass"},{"jane","pass"} } 	        },
    };
    auto fo_overload_set1 = Overloaded_visitor {
                                                                                                                // todo: would this work too? : new Dropbox { { {"jack o1","pass"},{"fred","pass"} }, {"/root"} },
                        Dropbox 	{ { {"jack o1","pass"},{"fred","pass"} }, {"/root"} },
                        Facebook 	{ { {"jill o1","pass"},{"jane","pass"} }            },
    };
    // unusual example using lambdas placed into the Overloaded class object which support operator() due to the fact they are lambdas, and take one parameter.
    auto fo_overload_set2 = Overloaded_visitor {
                        []( Dropbox 	const & arg)     -> InteractionResult { cerr<<"pto::lamba: fo_set2: retrieving dropbox. \n"; return {1,2};},
                        []( Facebook	const & arg)     -> InteractionResult { cerr<<"pto::lamba: fo_set2: retrieving facebook.\n"; return {3,4};}
    };
                                // visit/run, the correct function() with type signature, based on the type of the data
    InteractionResult action_result0 = std::visit( fo_overload_set0, task.target_fo_vrnt );
    InteractionResult action_result1 = std::visit( fo_overload_set1, task.target_fo_vrnt );
    InteractionResult action_result2 = std::visit( fo_overload_set2, task.target_fo_vrnt );

    // todofirst: unusual example using lambdas placed into the Overloaded class object which support operator() due to the fact they are lambdas, and take 2 parameters.  Several attempts of using nested variants.
    /* int  my_target9_int 	  = 42;
    //std::variant< std::variant< Target_vrnt_o, int> >  my_target9__vrnt 	  {{ task.target_fo_vrnt ,42}};
    std::variant< std::variant< Target_vrnt_o, int> >  	my_target9b_vrnt;
    std::variant< Target_vrnt_o, int>   			   	my_target9c_vrnt;
    //my_target9b_vrnt =  { task.target_fo_vrnt, my_target9_int };
    my_target9c_vrnt =  { task.target_fo_vrnt, my_target9_int };
    auto fo_overload_set9 = Overloaded_visitor {
    auto fo_overload_set9 = Overloaded_visitor {
                        []( Dropbox 	const & arg1, int 		const & arg2)     -> InteractionResult { cerr<<"pto::lamba: fo_set9: retrieving dropbox.           "<<arg1.user_and_target.user.user_id<<", int:"<<arg2<<endl; return {1,2};},
                        []( Facebook	const & arg1, int 		const & arg2)     -> InteractionResult { cerr<<"pto::lamba: fo_set9: retrieving facebook.          "<<arg1.user_and_target.user.user_id<<", int:"<<arg2<<endl; return {3,4};},
                        []( Dropbox 	      & arg1, int 		      & arg2)     -> InteractionResult { cerr<<"pto::lamba: fo_set9: retrieving dropbox.           "<<arg1.user_and_target.user.user_id<<", int:"<<arg2<<endl; return {1,2};},
                        []( Facebook	      & arg1, int 		      & arg2)     -> InteractionResult { cerr<<"pto::lamba: fo_set9: retrieving facebook.          "<<arg1.user_and_target.user.user_id<<", int:"<<arg2<<endl; return {3,4};},
                        []( int 		const & arg2, Dropbox 	const & arg1)     -> InteractionResult { cerr<<"pto::lamba: fo_set9: retrieving dropbox  reversed. "<<arg1.user_and_target.user.user_id<<", int:"<<arg2<<endl; return {1,2};},
                        []( int 		const & arg2, Facebook	const & arg1)     -> InteractionResult { cerr<<"pto::lamba: fo_set9: retrieving facebook reversed. "<<arg1.user_and_target.user.user_id<<", int:"<<arg2<<endl; return {3,4};},
                        []( int 		      & arg2, Dropbox 	      & arg1)     -> InteractionResult { cerr<<"pto::lamba: fo_set9: retrieving dropbox  reversed. "<<arg1.user_and_target.user.user_id<<", int:"<<arg2<<endl; return {1,2};},
                        []( int 		      & arg2, Facebook	      & arg1)     -> InteractionResult { cerr<<"pto::lamba: fo_set9: retrieving facebook reversed. "<<arg1.user_and_target.user.user_id<<", int:"<<arg2<<endl; return {3,4};}
    };
    InteractionResult action_result9 = std::visit( fo_overload_set9, task.target_fo_vrnt, my_target9_int ); */

    // typical examples using lambdas 	ie. 1) operator() is used only, with one parameter.
    InteractionResult action_result3 = std::visit( Overloaded_visitor {
                        []( Dropbox 	const & arg)->InteractionResult { cout<<"pto::lambda: retrieving o3 dropbox\n";  return {1,2};},
                        []( Facebook	const & arg)->InteractionResult { cout<<"pto::lambda: retrieving o3 facebook\n"; return {3,4};}
                      }, task.target_fo_vrnt );

    // todofirst:non-typical examples using lambdas 	ie. 2) operator() is used only, with two parameters.  2 different attempts, one of which is commented out line by line.
    /* 																		// std::variant< decltype (Task_o::priority) , decltype (Task_o::region) > my_targetA_p_vrnt {task.priority};
                                                                            // std::variant< decltype (Task_o::priority) , decltype (Task_o::region) > my_targetA_r_vrnt {task.region};
                                                                            // class My_c { public: decltype (Task_o::priority) m1 ; decltype (Task_o::region) m2; };
    My_c	my_c { task.priority, task.region};
    std::variant< My_c > my_targetA_vrnt {my_c};
    InteractionResult action_resultA = std::visit( Overloaded_visitor {
                        []( decltype (Task_o::priority)         arg1, decltype (Task_o::region)   arg2 )->InteractionResult { cout<<"pto::lambda: retrieving o3 dropbox\n";  return {1,2};},
                        []( decltype (Task_o::region)           arg2, decltype (Task_o::priority) arg1 )->InteractionResult { cout<<"pto::lambda: retrieving o3 dropbox\n";  return {1,2};},
                                                                            //}, my_targetA_p_vrnt, my_targetA_r_vrnt );
                      }, my_targetA_vrnt ); */

    //									ie. 3) operator() is used, then calls another member function of function object.
    InteractionResult action_result4 = std::visit( Overloaded_visitor {
                        []( Dropbox 	const & arg)->InteractionResult { cout<<"pto::lambda: retrieving r4 dropbox, calling doit. \n"; auto ret = arg.doit( 42 ); return ret; },
                        []( Facebook   	const & arg)->InteractionResult { cout<<"pto::lambda: retrieving r4 facebook, calling doit.\n"; auto ret = arg.doit( 42 ); return ret; },
                      }, task.target_fo_vrnt );
    // using auto templating??
    InteractionResult action_result5 = std::visit( Overloaded_visitor {	[] (auto const & arg )->InteractionResult
                      { cout<<"pto::lambda:r5 retrieving overloaded auto Company, calling doit.\n";	auto ret = arg.doit( 42 ); return ret; }, }, task.target_fo_vrnt );  // Overloaded not needed in auto template case  [
    InteractionResult action_result6 = std::visit( [] (auto const & arg )->InteractionResult
                      { cout<<"pto::lambda:r6 retrieving auto Company, calling doit.\n"; 			auto ret = arg.doit(441); return ret; }, task.target_fo_vrnt );
    InteractionResult action_result7 = std::visit( [] (auto const & arg )->InteractionResult
                      { cout<<"pto::lambda:r7 retrieving auto Company, calling doit_static.\n"; 	auto ret = arg.doit_static(442); return ret; }, task.target_fo_vrnt );
    InteractionResult action_result8 = std::visit( [] (auto const & arg )->InteractionResult
                      { cout<<"pto::lambda:r8 retrieving auto Company, calling ().\n"; 				auto ret = arg(443); return ret; }, task.target_fo_vrnt );
    return action_result8;
    /* is this "auto..." equivalent to "auto" on 2nd above line?
    auto function_object_overload_set = Overloaded {
        [&kludge_state ]  			   ( std::function< InteractionResult(State_menu &              ) > &af)
            { auto r = af( kludge_state );
              cerr << "\n [] state overload.\n";
              return r; }, 						// to be invoked via operator() on the function object (AKA lambda) or any callable object.
        [&kludge_state, &current_menu] ( std::function< InteractionResult(State_menu &, Menu const &) > &af)
            { auto r = af( kludge_state, current_menu );
              cerr << "\n [] state,menu overload.\n";
              return r; }, 						// to be invoked via operator() on the function object (AKA lambda) or any callable object.
    };
    auto fo_return_type_overloaded_set = [ & ] (auto... args) -> InteractionResult
                                                    { return function_object_overload_set( args...); };  // not needed if all return types are the same, which is the current case and that is used in the return type of this function.
    InteractionResult action_result = std::visit( fo_return_type_overloaded_set,
                                                    menu_selection.menu_action_fn_variant );
    return action_result; */
}

/* InteractionResult const process_task_2param( Task_o & task ) {
    using Fo_args 	= std::variant< {Just_company, Priority}, {Just_company} >;
    Priority 		priority 		{-2};
    Fo_args		my_fo_args { priority, task };
    struct { std::variant<> ; } variant_with_single_and_multiple_prameter_fn_signature;  // todo :make this an anonymous (unnamed??) type.
    InteractionResult action_result1 = std::visit( Overloaded {
        []( int priority, Dropbox const & arg				 )->InteractionResult { auto ret = arg.doit( 42 ); cout<<"retrieving o4 lamba dropbox\n"; return ret; },
        [](  			  Dropbox const & arg, int priority )->InteractionResult { auto ret = arg.doit( 42 ); cout<<"retrieving o4 lamba dropbox\n"; return ret; },
        []( int priority, Facebook      const & arg				 )->InteractionResult { auto ret = arg.doit( 42 ); cout<<"retrieving o4 lamba dropbox\n"; return ret; },
        []( 		      Facebook 	   const & arg, int priority )->InteractionResult { auto ret = arg.doit( 42 ); cout<<"retrieving o4 lamba dropbox\n"; return ret; },
                      }, 1, variant_with_single_and_multiple_prameter_fn_signature );
    return action_result1;
}*/

/* void process_queue( Queue queue_tasks ) {
    for ( Task & task : queue_tasks ) {
        cout << "process t   ++++++" << endl;
        auto interaction_result = process_task( task );
        cout << std::get<int>( interaction_result.data ) <<","<<interaction_result.error << endl << "++++++" << endl;
    }
}
// void process_queue_sfn( Queue_sfn queue_tasks_sfn ) {  // https://stackoverflow.com/questions/66961406/c-variant-visit-overloaded-function
    for ( Task_sfn & task_sfn : queue_tasks_sfn ) {
        cout << "process t_o ++++++" << endl;
        auto interaction_result = process_task_sfn( task_sfn );
        cout << std::get<int>( interaction_result.data ) <<","<<interaction_result.error << endl << "++++++" << endl;
    }
}; */

/*void process_queue_o( Queue_o queue_tasks_o ) {  // https://stackoverflow.com/questions/66961406/c-variant-visit-overloaded-function
//    for ( Task_o & task_o : queue_tasks_o ) {
//        cout << "process t_o ++++++" << endl;
//        auto interaction_result = process_task_overloaded( task_o );
//        cout << std::get<int>( interaction_result.data ) <<","<< interaction_result.error << endl << "++++++" << endl;
//    }
//}; */

//#define LET  auto;
//try_it( Possibility_variant  state ) -> int {

class Possibility_base {
public:
    int i;
    //virtual std::string to_string() = 0;
    virtual std::string to_string() {return "base";};
    //virtual std::string to_string() { cerr <<"Possiblilty::to_string() is returning hw."<<endl; return "hw";};
};

class North : public Possibility_base {
public:
    double d;
    virtual std::string to_string() override final { cerr <<"North is my ::to_string() is returning hw."<<endl; return "North";};
    //std::string to_string() override { cerr <<"North is my ::to_string() is returning hw."<<endl; return "North";};
};
class East  : public Possibility_base {
public:
    double d;
    std::string to_string() override final { return "East";};
};
class West  : public Possibility_base {
public:
    double d;
    virtual std::string to_string() override final { return "West";};  // todo: what if anything does virtual do on this line that also has override and final?
};
class South : public Possibility_base {
public:
    double d;
    virtual std::string to_string() override final { return "South";};
};

using Possibility = std::variant< North, East, West, South >;

Possibility try_it( Possibility  state ) {
    return std::visit( Overloaded_visitor {
                    []( North arg ) -> Possibility { East my_east; Possibility my_east_possibility = my_east; return my_east_possibility; },
                    []( auto  arg ) -> Possibility { West my_west; Possibility my_west_possibility = my_west; return my_west_possibility; },
                } , state );
};

/* Possibility_base try_it_base( Possibility  state ) {
    return std::visit( Overloaded_visitor {
                    []( North arg ) -> Possibility_base { East my_east; Possibility_base my_east_possibility_base { my_east }; return my_east_possibility_base; },
                    []( auto  arg ) -> Possibility_base { West my_west; Possibility_base my_west_possibility_base = my_west; return my_west_possibility_base; },
                } , state );
};

Possibility_base try_it_derived( Possibility  state ) {
    return std::visit( Match_target {
                    //[]( North ) -> Possibility_base { return East; },
                    //[]( auto  ) -> Possibility_base { return West; },

                    //[]( North ) -> East { East my_east; return my_east; },
                    //[]( auto  ) -> West { West my_west; return my_west; },

                    //[]( North ) -> Possibility_base { East my_east; return my_east; },
                    //[]( auto  ) -> Possibility_base { West my_west; return my_west; },

                    //[]( North ) -> Possibility_base { East my_east; return std::move(my_east); },
                    //[]( auto  ) -> Possibility_base { West my_west; return std::move(my_west); },
                } , state );
};
*/

int main() {
    North my_north;
    auto res = try_it( my_north );
    South my_south;
    res = try_it( my_south );

/*    if ( std::holds_alternative< North >( res )) {
        cerr<< "In main(North)::get<>::to_string():" << std::get<North>(res).to_string() << endl;
    } else if ( std::holds_alternative< East >( res )) {
        cerr<< "In main(East )::get<>::to_string() :" << std::get<East>(res).to_string() << endl;
    } else if ( std::holds_alternative< South >( res )) {
        cerr<< "In main(South )::get<>::to_string() :" << std::get<South>(res).to_string() << endl;
    } */

    cout << std::visit( []( auto arg ) { return arg.to_string(); } , try_it( my_north ) ) << endl;
    // cout << try_it( my_north ).to_string() << endl;  // todo: why can't I do this?  Scalla can.



    /*auto junk1 = std::get< res.index() >(res);

    auto junk2 = std::get< 0 >(res);
    //size_t my_index { res.index() };
    size_t constexpr my_index { 1 };
    auto junk3 = std::get< my_index >(res);
    */

    /********************;  // todo: why doesn't a C style cast just shut up and work??
    //auto k1 = reinterpret_cast<East>(res);
    //auto k3 = static_cast<East>(res);
    //auto k2 = dynamic_cast<East>(res); // todo: NO - works on pointers dummy!
    //auto kkkk = dynamic_cast<East>(res).to_string();
    //cout << res.to_string() << endl;
    //cout << res.to_string() << endl; */

    /* union Example_union {  // to contrast to std::variant
        std::string 		my_string;
        int 				my_int; // ordering matters
        //double			my_double;
        //Example_union() 									{};
        //Example_union( int i )			:(my_int=i) 	{};
        //Example_union( int i )			: my_int(i) 	{};
        //Example_union( std::string& s_)	: my_string(s_) {};
        ~Example_union() 									{} ;
        //~Example_union() = default;
        //Example_union& operator=(std::string& s) { my_string = s; return *this; };
    };
    Example_union my_u2  {10};
    Example_union my_u1  (10);
    new (&my_u.my_string ) std::string;  // Placement new. if vector then need <int>
    Example_union my_u2.my_string { std::string ("junk") };
    Example_union my_u3.my_string = { "junk" };
    Example_union my_u  {"initialization"};
    my_u.my_string = "initial assignment";  // why doesn't this just write into the union? need "placement new"
    cerr << "my_string:" << my_u.my_string << endl;
    my_u.my_string.~basic_string<char>();  // call destructor
    //Example_union my_u.my_int  = 10;
    my_u.my_int = 42;  // need "placement new"
    cerr << "my_int   :" << my_u.my_int<< endl;
    cerr << "my_string:" << my_u.my_string << endl; */
    /* Retrieve_dropbox  	retrieve_dropbox 	{};
    Retrieve_fb  		retrieve_fb			{};
    Queue 				queue_tasks {};
    Task 				my_task;

    my_task.action_fn = retrieve_dropbox.doit;
    my_task.action_fn = Retrieve_dropbox::doit;
    queue_tasks.push_back(my_task);

    my_task.action_fn = retrieve_fb;
    queue_tasks.push_back(my_task);
    process_queue( queue_tasks ); */

    /* Dropbox  	dropbox_o 					{};
    Facebook  	facebook_o 					{};
    Task_o 		my_task_o 					{ 9, 1, "CDT", dropbox_o };
    Queue_o 	queue_tasks_o 				{ my_task_o };
    my_task_o							=   { 3, 5, "IST", facebook_o};
    queue_tasks_o.push_back( my_task_o );  // todo: could I use emplace? or is that only during init? */

//    process_queue_o( queue_tasks_o );
    cout << "###" << endl;
    return 0;
}
