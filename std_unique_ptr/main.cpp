#include <iostream>
#include <memory>
#include <functional>
int main() {
    //int i = 99.2;
    int 			i2 		();
    int 			i3 		{ 99.2 };
    int 			j 		{ 99 }; // could prevent narrowing depending on value, possibly "initalizer list stuff"
    int 			my_int 	{ 667 };
    int * 			jJ 		{ new int { my_int } };
    int * 			jB 		{ new int ( 66.7 ) };
    //int * 			jD 		{ new int { 66.7 } };
    int * 			jC 		{ new int ( 66.7 ) };
    unsigned int * 		jA 		{ new unsigned int ( 66.7 ) };
    //unsigned int * 				j3 		{ new int { 66.7 } };

    std::unique_ptr<int>		j7   	{ std::unique_ptr<int>() };
    std::unique_ptr<int> 		R8 	= { std::unique_ptr<int>() };
    std::unique_ptr<int> 		j8 	= std::unique_ptr<int>();
    std::unique_ptr<int> 		r8	( std::unique_ptr<int>() );
    std::unique_ptr<int> 		r9 		(( std::unique_ptr<int>() ));  // todo: did this actually call default constructor??
    std::unique_ptr<int> 		r0 		();
    std::unique_ptr<int> 		r1 		;

    int 		 *        		j2 		= { new int (66.2) };
    int 		 *        		jx 		= { new int {66.2} };
    std::unique_ptr<int>	  	j4   	{ 		std::make_unique<int>( 66 )   };
    std::unique_ptr<int>		j5   	{ 		std::make_unique<int>()       };
    auto  						a6   	{ 		std::make_unique<int>         };  // todo: what is this type?
    std::unique_ptr<int>		jM   	{ 		std::make_unique<int>         };
    std::unique_ptr<int> 		u1 	 	{ 		std::make_unique<int> ( 66.2 )};
    std::unique_ptr<int> 		j1 	 	{       std::make_unique<int> { 66.2 }};
    std::unique_ptr<int> 	    u2 	 	{       std::make_unique<int> () = { 66.2 }  };
    std::unique_ptr<int> 		jK 		= std::make_unique<int>( 66.2 );
    std::unique_ptr<int> 		j9 		= std::unique_ptr<int> ( new int {66.2} );
    std::unique_ptr<int> 		u9 		= std::unique_ptr<int> ( new int (66)   );
    std::cout << " j:" <<  u9.get() << std::endl;
    std::cout << "*j:" << *u9 	    << std::endl;
    std::cout << "###" << std::endl;
    return 0;
}
