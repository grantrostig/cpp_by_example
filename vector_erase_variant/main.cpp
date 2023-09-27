#include <iostream>
#include <vector>
#include <string>
#include <variant>
#include <iterator>

struct S1 { int a {}; };
struct S2 { std::string b {}; };
using Struct_variant = std::variant< S1, S2 >;

int main() {
    std::vector<Struct_variant> struct_vector { S1 {1}, S2 {"hello"}, S1 {3}};
    size_t index_to_erase {1};  // NOTE: assume we only know the index, *not* the iterator.
    auto variant_itr = struct_vector.begin();

    // following line requires either a std::vist, or an "if std::holds_alternative" to handle types.

    //auto offset = sizeof (Struct_variant) * index_to_erase;
    //variant_itr =  struct_vector.begin() + offset;

    // for (int i = 0; i != index_to_erase; i++) variant_itr++;  // works

    struct_vector.erase(variant_itr);

    auto begin = struct_vector.begin();
    std::advance( begin, index_to_erase );
    struct_vector.erase( begin );
    std::cout << struct_vector.size() << std::endl;
}
