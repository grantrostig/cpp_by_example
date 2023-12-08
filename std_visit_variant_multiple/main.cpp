/* NOT PRODUCTION QUALITY CODE, just shows learning/teaching example, not real programming, don't copy this style, just playing around
   Study: std::visit std::variant with inheritance and running function objects.
   Preparation for password_manager and file_maintenance projects.
 * Author: Grant Rostig
 * License: BOOST
#include <iostream>
#include <vector>
#include <variant>
#include <functional>
#include <queue>*/
#include <bits/stdc++.h>
using std::cout, std::endl, std::cin, std::cerr;

template<class... Ts>  				// variadic ie. any number of any type are handled. Below we use several in the contructor of our one object. // ... is a parameter pack.
struct Overloaded_visitor : Ts... { 		// inherit from all those types  todo:  how does this work??
    using Ts::operator()...;  		// all of those operator()s.  // new in c++17.
};
template<class... Ts> Overloaded_visitor(Ts...) -> Overloaded_visitor<Ts...>;  // deduction guide.  -> = returns.

using InteractionResultData_Vrnt = std::variant< std::monostate, bool, char, int, std::string >;
struct InteractionResult {
        InteractionResultData_Vrnt  	data 		{};  // the most important data value of the item processed. ie. name or code or ID.
        int		   						error 		{};	 // any error that occurred.
        InteractionResult( InteractionResultData_Vrnt data, int    error ): data{data}, error{error} {};
        InteractionResult( InteractionResultData_Vrnt data, double error ): data{data}, error(error) {};
        //InteractionResult( InteractionResultData_Vrnt data, long double error ): data(data), error{error} {};  // todo: narrowing error! does anyone use {} here?  I thought () was required!!
       };

/* not used class User {
public:
    std::string user_id;
    std::string passw;  // no pw if user is a target user we have right to see.
};
class User_target {
public:
    User user;		// our user account for entry into the system.
    User target;  	// the user which has the data, if other than ourselves.
};

//not used class Shape {
    // virtual Shape () = 0;
    //virtual int display () = 0;
    //virtual int move ( int x, int y) = 0;
};*/

class Square // : public Shape
{
public:
    std::string	name;
    double 		d;
            /* User_target 	user_and_target;
            std::string		directory_locator;
            //InteractionResult operator()( ) { cout << "opr():retrieving dropbox user name:"<< user_and_target.user.user_id<< ":\n"; return { 42, 0 }; };
            InteractionResult operator()( Square 	const & 	arg1 ) const { cout << "opr():retrieving dropbox user name:"<< user_and_target.user.user_id<< ":\n"; return { 42, 0 }; };
            //InteractionResult operator()( Dropbox 	        	arg1 ) const { cout << "opr():retrieving dropbox user name:"<< user_and_target.user.user_id<< ":\n"; return { 42, 0 }; };

            InteractionResult operator()( int arg )   			  { cout << "opr():retrieving dropbox user name:"<< user_and_target.user.user_id<< ":\n"; return { 42, 0 }; };
            InteractionResult operator()( int 		const & 	arg1 ) const { cout << "opr():retrieving dropbox user name:"<< user_and_target.user.user_id<< ":\n"; return { 42, 0 }; };
            InteractionResult doit( 	  int 		const & 	arg1 ) const { cout << "do_it:retrieving dropbox user name:"<< user_and_target.user.user_id<< ":\n"; return { 442, 0 }; };
    static 	InteractionResult doit_static(int 		const & 	arg1 ) { cout << "do_it:retrieving dropbox user name:"<< ":\n"; return { 442, 0 }; }; // todo: why can't I reference a data member in a static fn member?  Would the data have to be static too? because it is not constructed early enough?
            InteractionResult operator()( Square 	const & 	arg1, int arg2 ) const { cout << "opr():retrieving dropbox user name:"<< user_and_target.user.user_id<< ":\n"; return { 942, 90 }; };
            InteractionResult operator()( Square 	        	arg1, int arg2 ) const { cout << "opr():retrieving dropbox user name:"<< user_and_target.user.user_id<< ":\n"; return { 942, 90 }; };
            */
};
class Circle // : public Shape
{
public:
    std::string	name;
    int 		a;
            /* User_target 	user_and_target;
            //InteractionResult operator()( ) { cout << "opr():retrieving fb      user name:"<< user_and_target.user.user_id<< ":\n"; return { 43, 0 }; };
            InteractionResult operator()( Circle 	const & 	arg1 ) const { cout << "opr():retrieving fb      user name:"<< user_and_target.user.user_id<< ":\n"; return { 43, 0 }; };
            //InteractionResult operator()( Facebook 		   		arg1 ) { cout << "opr():retrieving fb      user name:"<< user_and_target.user.user_id<< ":\n"; return { 43, 0 }; };

            InteractionResult operator()( int 					arg1 ) { cout << "opr():retrieving fb      user name:"<< user_and_target.user.user_id<< ":\n"; return { 43, 0 }; };
            InteractionResult operator()( int 		const & 	arg1 ) const { cout << "opr():retrieving fb      user name:"<< user_and_target.user.user_id<< ":\n"; return { 43, 0 }; };
            InteractionResult doit( 	  int 		const & 	arg1 ) const { cout << "do_it:retrieving fb      user name:"<< this->user_and_target.user.user_id<< ":\n"; return { 443, 0 }; };
    static 	InteractionResult doit_static(int 		const & 	arg1 )       { cout << "do_it:retrieving fb      user name:"<< ":\n"; return { 443, 0 }; };
            InteractionResult operator()( Circle 	const & 	arg1, int arg2 ) const { cout << "opr():retrieving fb      user name:"<< user_and_target.user.user_id<< ":\n"; return { 943, 90 }; };
            InteractionResult operator()( Circle 	        	arg1, int arg2 ) const { cout << "opr():retrieving fb      user name:"<< user_and_target.user.user_id<< ":\n"; return { 943, 90 }; };
            */
};
//using Moving 				= int;
//using Not_moving 			= double;
class Moving {
public:
    int		speed;
};
class Not_moving{
public:
    double 	energy_savings;
};

using Shape_vrnt 			= std::variant< Circle, Square >;
using Motion_vrnt			= std::variant< Moving, Not_moving >;
using Queue_vrnts_record 	= struct { Shape_vrnt 	shape_vrnt; Motion_vrnt 	motion_vrnt; } ;  // todo: is this use of struct a good idea? versus my typical: struct Queue_rec {  Shape_vrnt a; Color_vrnt b; };

using Queue_vrnts_records 	= std::vector< Queue_vrnts_record >;

using V1 = std::variant<int, std::string, Circle>;
using V3 = std::variant<int, std::string, Not_moving>;
using V2 = std::variant<int, std::string, int>;
//void q(){
    //std::visit( Overloaded_visitor {
                    //[] () {};
                //})
//}

InteractionResult const process_shape_overloaded( Queue_vrnts_record queue_vrnts_record ) { // was this: Shape_vrnt & shape_vrnt, Color_vrnt motion_vrnt ) {
    /* not used auto fo_overload_set1 = Overloaded_visitor {
                        //Square 	{ { {"jack o1","pass"},{"fred","pass"} }, {"/root"} },
                        //Circle 	{ { {"jill o1","pass"},{"jane","pass"} }            },
                        //Square 	{ {"jack o1","pass"},{"fred","pass"} }, {"/root"} },
                        //Circle 	{ {"jill o1","pass"},{"jane","pass"}             },
    }; */
    auto fo_overload_set2 = Overloaded_visitor {  // note: this incomplete set of visitors compiles, but does not run, failing with missing ...alternative???....
                        []( Square 	const & shape, Moving motion) -> InteractionResult { cout<<"Lamba:fo_set2: target1: "<< &shape << ",2:"<<&motion<<"\n"; return {"Square", motion.speed};},
                        []( Circle	const & shape, Moving motion) -> InteractionResult { cout<<"Lamba:fo_set2: target1: "<< &shape << ",2:"<<&motion<<"\n"; return {"Circle", motion.speed};}
    };
    auto fo_overload_set3 = Overloaded_visitor {  // todo: try to pass in ostream by capture []
                        []( Square const & shape, Moving motion) 	-> InteractionResult { cout<<"Lamba:fo_set3: target1: "<< &shape << ",2:"<<&motion<<"\n"; return {"Square", motion.speed};},
                        []( Square const & shape, Not_moving motion)-> InteractionResult { cout<<"Lamba:fo_set3: target1: "<< &shape << ",2:"<<&motion<<"\n"; return {"Square", motion.energy_savings};},
                        []( Circle const & shape, Moving motion) 	-> InteractionResult { cout<<"Lamba:fo_set3: target1: "<< &shape << ",2:"<<&motion<<"\n"; return {"Circle", motion.speed};},
                        []( Circle const & shape, Not_moving motion)-> InteractionResult { cout<<"Lamba:fo_set3: target1: "<< &shape << ",2:"<<&motion<<"\n"; return {"Circle", motion.energy_savings};}
                        //[]( Not_moving motion, Circle const & shape) -> InteractionResult { cout<<"Lamba:fo_set3: target1: "<< &shape << ",2:"<<&motion<<"\n"; return {"Circle", motion.energy_savings};}
    };
    //InteractionResult action_result1 = std::visit( fo_overload_set1, queue_vrnts_record.shape_vrnt, queue_vrnts_record.motion_vrnt );
    //InteractionResult action_result2 = std::visit( fo_overload_set2, queue_vrnts_record.shape_vrnt, queue_vrnts_record.motion_vrnt );
    InteractionResult action_result3 = std::visit( fo_overload_set3, queue_vrnts_record.shape_vrnt, queue_vrnts_record.motion_vrnt );
/*  //InteractionResult action_result5 = std::visit(  // todo: WOW!! Overloaded not needed in auto template case.
                          [] (auto const& shape, auto const& motion ) -> InteractionResult {
                              cout<<"auto templating overloaded_visitor: why same address??? "<< &shape <<".\n";
                              InteractionResult ret { 				//InteractionResult ret (  	 // todo: simple "(" works, why can't I use "= ("?
                                  "Auto lambda5-return value preparation::auto templating lamda set5:look at Motion to deduce type: ",
                                   motion  				// todo: note I'm cheating here, where I have two constructors each handling the two variants.
                                                        //       Somehow it converts a un-get'ed variant to a number! or is it the int or double???
                              };
                              return ret;
                          },
                          queue_vrnts_record.shape_vrnt,
                          queue_vrnts_record.motion_vrnt
                      ); */

    //return action_result1;
    //return action_result2;
    return action_result3;
    //return action_result5;
}

void process_queue_of_vrnt_records( Queue_vrnts_records queue_vrnts_records ) {  // https://stackoverflow.com/questions/66961406/c-variant-visit-overloaded-function
    for ( Queue_vrnts_record & queue_vrnts_record : queue_vrnts_records ) {
        cout << "Queue element ++++++." << endl;
        InteractionResult interaction_result = process_shape_overloaded( queue_vrnts_record );
        cout << "Post  element ======;data: " << std::get<std::string>( interaction_result.data ) <<", Motion: "<< interaction_result.error << endl;
        // cout << std::visit( []( auto arg ) { return arg.to_string(); } , interaction_result ) << endl;
    }
};

int main() {
    Square 				my_square_shape 	{"square1",11};
    Circle 				my_circle_shape 	{"circle1",12};
    Moving				my_moving_motion 	{2};
    Not_moving			my_not_moving_motion {22.22};
    Queue_vrnts_records	queue_vrnts_records {};

    queue_vrnts_records.push_back( {my_square_shape, my_moving_motion} );
    queue_vrnts_records.push_back( {my_square_shape, my_not_moving_motion} );

    my_moving_motion 						= {3};
    my_not_moving_motion 					= {33.33};
    queue_vrnts_records.push_back( {my_circle_shape, my_moving_motion} );
    queue_vrnts_records.push_back( {my_circle_shape, my_not_moving_motion} );

    process_queue_of_vrnt_records( queue_vrnts_records );
    cout << "###" << endl;
    return 0;
}
