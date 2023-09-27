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

class Shape {
    // virtual Shape () = 0;
    //virtual int display () = 0;
    //virtual int move ( int x, int y) = 0;
};

class Square : public Shape {
public:
            User_target 	user_and_target;
            std::string		directory_locator;
            //InteractionResult operator()( ) { cout << "opr():retrieving dropbox user name:"<< user_and_target.user.user_id<< ":\n"; return { 42, 0 }; };
            InteractionResult operator()( Square 	const & 	arg1 ) const { cout << "opr():retrieving dropbox user name:"<< user_and_target.user.user_id<< ":\n"; return { 42, 0 }; };
            //InteractionResult operator()( Dropbox 	        	arg1 ) const { cout << "opr():retrieving dropbox user name:"<< user_and_target.user.user_id<< ":\n"; return { 42, 0 }; };

            InteractionResult operator()( int arg )   			  { cout << "opr():retrieving dropbox user name:"<< user_and_target.user.user_id<< ":\n"; return { 42, 0 }; };
            InteractionResult operator()( int 		const & 	arg1 ) const { cout << "opr():retrieving dropbox user name:"<< user_and_target.user.user_id<< ":\n"; return { 42, 0 }; };
            InteractionResult doit( 	  int 		const & 	arg1 ) const { cout << "do_it:retrieving dropbox user name:"<< user_and_target.user.user_id<< ":\n"; return { 442, 0 }; };
    static 	InteractionResult doit_static(int 		const & 	arg1 ) /*const is invalid here b/c no this */
                                                                  { cout << "do_it:retrieving dropbox user name:"/*<< user_and_target.user.user_id*/<< ":\n"; return { 442, 0 }; }; // todo: why can't I reference a data member in a static fn member?  Would the data have to be static too? because it is not constructed early enough?
            InteractionResult operator()( Square 	const & 	arg1, int arg2 ) const { cout << "opr():retrieving dropbox user name:"<< user_and_target.user.user_id<< ":\n"; return { 942, 90 }; };
            InteractionResult operator()( Square 	        	arg1, int arg2 ) const { cout << "opr():retrieving dropbox user name:"<< user_and_target.user.user_id<< ":\n"; return { 942, 90 }; };
    // possible future sub-classes: business or personal
};
// struct Task_vrnt_o;  todo: broken with "using below" why?
class Circle : public Shape {
public:
            User_target 	user_and_target;
            //InteractionResult operator()( ) { cout << "opr():retrieving fb      user name:"<< user_and_target.user.user_id<< ":\n"; return { 43, 0 }; };
            InteractionResult operator()( Circle 	const & 	arg1 ) const { cout << "opr():retrieving fb      user name:"<< user_and_target.user.user_id<< ":\n"; return { 43, 0 }; };
            //InteractionResult operator()( Facebook 		   		arg1 ) { cout << "opr():retrieving fb      user name:"<< user_and_target.user.user_id<< ":\n"; return { 43, 0 }; };

            InteractionResult operator()( int 					arg1 ) { cout << "opr():retrieving fb      user name:"<< user_and_target.user.user_id<< ":\n"; return { 43, 0 }; };
            InteractionResult operator()( int 		const & 	arg1 ) const { cout << "opr():retrieving fb      user name:"<< user_and_target.user.user_id<< ":\n"; return { 43, 0 }; };
            InteractionResult doit( 	  int 		const & 	arg1 ) const { cout << "do_it:retrieving fb      user name:"<< this->user_and_target.user.user_id<< ":\n"; return { 443, 0 }; };
    static 	InteractionResult doit_static(int 		const & 	arg1 )       { cout << "do_it:retrieving fb      user name:"/*<< user_and_target.user.user_id*/<< ":\n"; return { 443, 0 }; };
            InteractionResult operator()( Circle 	const & 	arg1, int arg2 ) const { cout << "opr():retrieving fb      user name:"<< user_and_target.user.user_id<< ":\n"; return { 943, 90 }; };
            InteractionResult operator()( Circle 	        	arg1, int arg2 ) const { cout << "opr():retrieving fb      user name:"<< user_and_target.user.user_id<< ":\n"; return { 943, 90 }; };
    // possbile future sub-classes: user/page/group/??
};

/* using  Target_vrnt_o 	= std::variant< Square, Circle >; // Type represents one set of possible classes (sum type, discriminated union), these classes will be visited by the appropiately matched function having the individualized code for the task to be performed.
struct Task_o 		{
    int 			    priority 				{99};
    float 			    received_time_of_day 	{99};   // todo: change this to int and try to use it ;)
    std::string 	    region					{"*init*"};
    Target_vrnt_o		target_fo_vrnt;
};*/

using  Shape_vrnt 		= std::variant< Circle, Square >;
using  Queue_vrnts 		= std::vector< Shape_vrnt >;
using  Queue_ptrs 		= std::vector< Shape >;

InteractionResult const process_shape_overloaded( Shape_vrnt & shape_vrnt ) {
    /* auto fo_overload_set1 = Overloaded_visitor {
                        //Square 	{ { {"jack o1","pass"},{"fred","pass"} }, {"/root"} },
                        //Circle 	{ { {"jill o1","pass"},{"jane","pass"} }            },
                        //Square 	{ {"jack o1","pass"},{"fred","pass"} }, {"/root"} },
                        //Circle 	{ {"jill o1","pass"},{"jane","pass"}             },
    }; */
    auto fo_overload_set2 = Overloaded_visitor {
                        []( Square 	const & arg)     -> InteractionResult { cerr<<"pto::lamba: fo_set2: retrieving dropbox. \n"; return {1,2};},
                        []( Circle	const & arg)     -> InteractionResult { cerr<<"pto::lamba: fo_set2: retrieving facebook.\n"; return {3,4};}
    };
    InteractionResult action_result2 = std::visit( fo_overload_set2, shape_vrnt );
    // another way to get same result using auto templating??
    InteractionResult action_result5 = std::visit( Overloaded_visitor {	[] (auto const & arg )->InteractionResult
                      { cout<<"pto::lambda:r5 retrieving overloaded auto Company, calling doit.\n";	auto ret = arg.doit( 42 ); return ret; }, }, shape_vrnt );  // Overloaded not needed in auto template case  [
    return action_result5;
}

void process_queue_vrnt( Queue_vrnts queue_vrnts ) {  // https://stackoverflow.com/questions/66961406/c-variant-visit-overloaded-function
    for ( Shape_vrnt & shape_vrnt : queue_vrnts ) {
        cout << "process t_o ++++++" << endl;
        auto interaction_result = process_shape_overloaded( shape_vrnt );
        cout << std::get<int>( interaction_result.data ) <<","<< interaction_result.error << endl << "++++++" << endl;
    }
};

/* class Possibility_base {
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

Possibility_base try_it_base( Possibility  state ) {
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
    Square my_square;
    Circle my_circle;

/*    if ( std::holds_alternative< North >( res )) {
        cerr<< "In main(North)::get<>::to_string():" << std::get<North>(res).to_string() << endl;
    } else if ( std::holds_alternative< East >( res )) {
        cerr<< "In main(East )::get<>::to_string() :" << std::get<East>(res).to_string() << endl;
    } else if ( std::holds_alternative< South >( res )) {
        cerr<< "In main(South )::get<>::to_string() :" << std::get<South>(res).to_string() << endl;
    } */

    Queue_vrnts 				queue_vrnts {};
    Shape_vrnt 				    my_shape;

    queue_vrnts.push_back(my_square);
    queue_vrnts.push_back(my_circle);

    process_queue_vrnt( queue_vrnts );

    // cout << std::visit( []( auto arg ) { return arg.to_string(); } , try_it( my_north ) ) << endl;
    cout << "###" << endl;
    return 0;
}
