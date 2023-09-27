#ifndef STATE_APPLICATION_H
#define STATE_APPLICATION_H
#include <string>
#include <vector>
#include <iostream>
#include <ostream>
// used to determine when to perform pagination.
struct Panel_dimensions {
    size_t height {};   // NOTE: usually the actual height/lines.
                        // BUT when 'proposed_dimensions' it designates the minimum number of
                        // new lines to be added for pagination calculation,
                        // also takinginto account wrapping when exceeding the width.
    size_t width {};  	// NOTE: usually the actual number of characters on a line,
                        // or the max width of any of the multiple lines.
                        // BUT when 'proposed_dimensions' it may add enough characters
                        // to wrap the line, resulting in more height.
};

std::ostream& operator<< ( std::ostream& os, Panel_dimensions const & pd);

class State_application { // holds all data used by the user's application, but not state for the menu system.
    bool 			         is_data_saved {true};  		// the user has unsaved data input/editing that has not been committed to disk.
public:
    Panel_dimensions         panel_dimensions {.height = 15, .width = 80};
    Panel_dimensions         used_dimensions {0,0};
    int 				     int_data {42};
    std::vector<std::string> vec_data {"my_string_1", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_2", "my_string_9" };
    bool getIs_data_saved()  const;
    void setIs_data_saved(   bool value);
};
#endif // STATE_APPLICATION_H
