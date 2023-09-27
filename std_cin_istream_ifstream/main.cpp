// copyright (c) Grant Rostig, grantrostig.com, Boost 1.0 license
#include <bits/stdc++.h>
#include <iostream>
#include <stacktrace>
#include <source_location>

using std::cin; using std::cout; using std::cerr; using std::clog; using std::endl; using std::string;  // using namespace std;
using namespace std::string_literals;

/* few items for debugging purposes */
/// define if asserts are NOT to be checked.  Put in *.h file not *.CPP
//#define 	NDEBUG
/// define GR is Debugging.  Put in *.h file not *.CPP
//#define  	GR_DEBUG
//#ifdef   	GR_DEBUG
//#endif  # GR_DEBUG
/// gives a source location for printing.  Used for debugging.
#define LOGGER_( msg )   using loc = std::source_location;std::cerr<<"\n\r["<<loc::current().file_name()<<':'<<std::setw(3)<<loc::current().line()<<','<<std::setw(2)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<".\n";
/// gives a source location for printing.  Used for debugging.
#define LOGGERS( msg, x )using loc = std::source_location;std::cerr<<"\n\r["<<loc::current().file_name()<<':'<<std::setw(3)<<loc::current().line()<<','<<std::setw(2)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<",{"<<x<<"}.\n";
//#define LOGGER_( msg )
//#define LOGGERS( msg,x )
/// gives a source location for printing.  Used for debugging.
std::string
source_loc() {
    using loc = std::source_location;
    //using ts = std::to_string;  // todo??: why not?  alternative approach?
    std::string result {"\n"s+loc::current().file_name() +":"s +std::to_string(loc::current().line()) +std::to_string(loc::current().column())+"]`"s +loc::current().function_name()+"`."s};
    return result;
}
/// Prints a stack trace of crash location for printing.  Used for debugging.
auto crash_tracer(int const signal_number) ->void { cout << "CRASH_ERROR: signal#, stack trace:<<<" << signal_number << ">>>,<<<" << std::stacktrace::current() << "<<<END STACK TRACE.\n"; exit(1); }
/// Prints a stack trace of crash location for printing.  Used for debugging.
auto crash_signals_register() -> void {    // signals that cause "terminate" and sometimes "core dump"  https://en.wikipedia.org/wiki/Signal_(IPC)
    std::signal( SIGABRT, crash_tracer );
    std::signal( SIGALRM, crash_tracer );
    std::signal( SIGBUS,  crash_tracer );
    std::signal( SIGFPE,  crash_tracer );
    std::signal( SIGHUP,  crash_tracer );
    std::signal( SIGILL,  crash_tracer );
    std::signal( SIGINT,  crash_tracer );
    std::signal( SIGKILL, crash_tracer );
    std::signal( SIGPIPE, crash_tracer );
    std::signal( SIGPOLL, crash_tracer );
    std::signal( SIGPROF, crash_tracer );
    std::signal( SIGQUIT, crash_tracer );
    std::signal( SIGSEGV, crash_tracer );
    std::signal( SIGSYS,  crash_tracer );
    std::signal( SIGTERM, crash_tracer );
    std::signal( SIGTRAP, crash_tracer );
    std::signal( SIGUSR1, crash_tracer );
    std::signal( SIGUSR2, crash_tracer );
    std::signal( SIGVTALRM, crash_tracer );
    std::signal( SIGXCPU, crash_tracer );
    std::signal( SIGXFSZ, crash_tracer );
    std::signal( SIGVTALRM, crash_tracer );
}

int error_gen_func(int const param) {
    crash_signals_register();

    // Geneate various types of errors.
    //int a {99}; float b {0}; auto result {a/b};
    int a {99}; int b {0}; auto result {a/b};
    cout << "Is this NAN?:" << result <<endl;

    std::vector<int> my_vec { 99, 33};
    int check_at = my_vec.at( param );

    throw 1.9f;
    throw std::exception();
    int check_square = my_vec[ param ];

    return result;
}


int main ( int argc, char* arv[] ) { string my_arv {*arv}; cout << "~~~ argc,argv:"<<argc<<","<<*arv<<"."<<endl; // crash_signals_register();
    //cin.exceptions( std::istream::failbit );  // todo??: it seems fail bit is triggered on EOF on cin?

    cout << "Will not get there if any failure!" << error_gen_func(999);

    // Test cin in various ways.
    string response1 {"NA"}, response2 {"NA"};
    try {
    while ( response1 != "q" && not cin.eof() ) {
        cout << "Enter two values (q ?, or CTRL-D to exit):";
        cin >> response1;  // strangely ^D works there.
        cin >> response2;  // todo??: strangely ^D DOES NOT work there.
        //if ( cin.eof() ) cout << "EOF\n";
        //cin.clear();  // does not flush out cin.
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //cin.clear();  // does not flush out cin.

        cout << "Response one and two are:" << response1 <<","<< response2 <<"."<< endl;
    }
    }
    catch (const std::ios_base::failure& e) {
        LOGGER_();
        std::cout << "Caught a standard ios_base::failure error:'" << e.what() << ", error code:{" << e.code() << "}.\n";
        if ( e.code() == std::io_errc::stream)
            std::cout << "The error code is std::io_errc::stream\n";
    }
    catch(std::filesystem::filesystem_error const& e) {
        LOGGER_();
        std::cout << "Caught a standard std::filesystem::filesystem_error:'" << e.what() << ", error code:{" << e.code() << "}.\n";
        std::cout
            << "path1(): " << e.path1() << '\n'
            << "path2(): " << e.path2() << '\n'
            << "code().value():    " << e.code().value() << '\n'
            << "code().message():  " << e.code().message() << '\n'
            << "code().category(): " << e.code().category().name() << '\n';
                        // All functions have non-throwing equivalents
                        // std::error_code ec;
                        // std::filesystem::copy_file(from, to, ec); // does not throw
                        // std::cout << "\nNon-throwing form sets error_code: " << ec.message() << '\n';
    }

    catch (const std::system_error& e) {
        LOGGER_();
        std::cout << "Caught a standard system_error error:'" << e.what() << ", error code:{" << e.code() << "}.\n";
    }
    catch (const std::runtime_error& e) {           // this executes if f() throws std::underflow_error (base class rule)
        LOGGER_();
        std::cout << " a standard runtime?/underflow? was caught, with message '" << e.what() << "'\n";
    }
    catch (const std::exception& e) {               // this executes if f() throws std::logic_error (base class rule)
        LOGGER_();
        std::cout << " a standard?/logic error? exception was caught, with message '" << e.what() << "'\n";
    }
    catch (int i ) {                                   // this executes if f() throws int
        LOGGER_();
        std::cout << " a int exception was caught, with value '" << i << "'\n";
    }
    catch (...) {                                   // this executes if f() throws any other unrelated type, a catch-all catch.
        LOGGER_();
        std::cout << " a catchall exception was caught, with no? message.\n";
    }

    cout << "###" << endl;
    return 0;
}

