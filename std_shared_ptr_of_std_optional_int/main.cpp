#include <iostream>
#include <optional>
#include <memory>

using namespace std;


int main()
{
    std::optional<int> my_optional_int_data {55};
    int 			   my_int_data {};

    //std::shared_ptr<int> data_location_direct {};
    // data_location_direct. = &my_int_data; TODO: syntax error

    //std::shared_ptr<std::optional<int>> data_location {};
    // data_location = &my_optional_int_data; TODO: syntax error

    std::shared_ptr<std::optional<int>> data_location2 {&my_optional_int_data};  // todo: TODO why does this generate a error: free(): invalid pointer
    cout << "###" << endl;
    return 0;
}
