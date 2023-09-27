// Inspired by original author Officer-tuba who modeled this after std::experimental_scope_failure
// Modified by Grant Rostig
// Boost 1.0 license
#include <exception>
#include <functional>
#include <iostream>
#include <source_location>
#include <vector>
#include <cassert>

namespace grostig_tools {
class exception_location {  // was called failure_checkpoint
    int                     _location_id;
    std::source_location    _location;
    using                   Line_offset         = decltype( std::source_location::current().line() );
    Line_offset             _line_offset;       // distance from constructor to the likely location of the anticipated std::exception
    static int              _loc_sequence_counter;
public:
    explicit exception_location( Line_offset line_offset = 1, const std::source_location location = std::source_location::current() )
        : _location_id      {++_loc_sequence_counter}
        , _location         {location}
        , _line_offset      {line_offset}
    { }
    ~exception_location() {
        if ( std::uncaught_exceptions() && _location_id == _loc_sequence_counter ) {
            std::cout << "EXCEPTION ~loc:`" << _location.file_name() << "," << _location.function_name()<< "[ " << static_cast<long>(_location.line()) + _line_offset << '\n';
        }
    }
};
int exception_location::_loc_sequence_counter {0};
}  // diagnostic

namespace testing {
void trigger_exception1( std::function< void () > passed_trigger_exception ) {
    grostig_tools::exception_location e_loc0;
    std::array< int, 4 >{}.at( 4 ); // should throw and trigger e_loc0
}

void trigger_exception2() {
    grostig_tools::exception_location e_loc0; // won't do anything
    std::cout << "Hello from " << std::source_location::current().function_name() << '\n';

    grostig_tools::exception_location e_loc1;
    try { testing::trigger_exception1( [](){} );    // TODO??: testing::trigger_exception1( &nullptr() );
        grostig_tools::exception_location e_loc0;
    } catch ( std::exception & e ) {
        grostig_tools::exception_location e_loc1;
        std::cout << std::source_location::current().function_name()<<":"<< e.what() <<std::endl;
        throw 99999;
    };

    grostig_tools::exception_location e_loc2 {2};
    std::vector<int>{}.at(0); // should throw and trigger e_loc2

    assert( false && "Logic errror: stop here.");
    grostig_tools::exception_location e_loc3;
}
}  // test

int main() {
    std::cout <<"~~~"<<std::endl;
    try {
        grostig_tools::exception_location e_loc0; // won't do anything
        testing::trigger_exception2();
        return 0;
    }
    catch ( ... ) {
        std::cout << "main().catch:Encountered an exception:EXIT_FAILURE.\n";
        return EXIT_FAILURE;
    }
    std::cout <<"###"<<std::endl;
return EXIT_SUCCESS;
}
