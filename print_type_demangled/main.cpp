#include <bits/stdc++.h>
#include <string>
#include <iostream>
//#include <ranges>

#include <typeinfo>
#include <cstdlib>
#include <memory>
#include <cxxabi.h>

using std::endl, std::cin, std::cout, std::cerr, std::string;

//#define LOGGER_( msg )   using loc = std::source_location;std::cerr<<"["<<loc::current().file_name()<<':'<<loc::current().line()<<','<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<".\n";
//#define LOGGER2( msg, x )using loc = std::source_location;std::cerr<<"["<<loc::current().file_name()<<':'<<loc::current().line()<<','<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<",{"<<x<<"}.\n";

auto
demangle( std::type_info const & my_type)->std::string {
    using buffer_t = std::unique_ptr< char, decltype( &std::free)>;
    int result;
    buffer_t buffer{ abi::__cxa_demangle( my_type.name(), nullptr, nullptr, &result), &std::free};
    return 0 == result ? buffer.get() : "Error: in demangling.";
}

template <typename T>
std::string demangle() noexcept {
    return demangle(typeid(T));
}

int main() {
    std::string my_string {"abc:hello:my:friend:"};
    auto range_to_sv { [] (auto && my_range) { return std::string_view( my_range ); }};

    auto range_transform_string {
        my_string
        | std::views::split(':')
        | std::views::drop(1)
        | std::views::transform( range_to_sv )
        | std::views::join
    };
    cout << demangle( typeid( range_to_sv)) << endl;
    cout << demangle( typeid( range_transform_string)) << endl;
    cout << "my_string demangled:" << demangle( typeid(my_string) ) << endl;
    cout << "int demangled:"       << demangle<int>() << endl;
    [[maybe_unused]] int i;
    //cout << "int demangled:"       << demangle(i) << endl;
    //cout << "int demangled:"       << demangle(my_string) << endl;

    std::ranges::for_each( range_transform_string, [](const auto& single_character){ cout << single_character; });
    cout << endl;

    // todo??: why does this program CRASH! in qt creator, but seem to work when run from shell?
    cout << "###" << endl;
    return 0;
}
