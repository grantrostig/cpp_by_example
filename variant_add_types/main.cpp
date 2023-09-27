#include <string>
#include <variant>

int main()
{
    using variant_base = std::variant< int, double >;

    using variant_derived_and_flattened = std::variant< std::string, variant_base >;
    // the above does not produce the desired
    // std::variant< int, double, std::string >
    static_assert( std::is_same< variant_base, variant_derived_and_flattened >{} );
}
