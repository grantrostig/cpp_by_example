#include <iostream>
using namespace std;

int
main() {
    cout << "Content-type: text/html\r\n\r\n"
         << "<!DOCTYPE html>" //
         << "<html lang=\"en\">"
         << "<head>"
         << "<meta charset=\"UTF-8\" />"
         << "<title>C++ CGI</title>"
         << "</head> "
         << "<body>"
         << "<h1>Hello from C++ CGI!</h1>"
         << "Enter info below:";

    char *query_string = getenv("QUERY_STRING");
    std::string name;
    if(query_string != nullptr) {
        std::string qs{query_string};
        size_t      itr{qs.find("name=")};
        if(itr != std::string::npos) { name = qs.substr(itr + 5); }
    }
    cout << "<form method='get'>"
         << "   <label for= 'nameid'>Name (44 or more characters):</label>"
         << "   <input type= 'text' id= 'nameid' name= 'name' "
         << "       value= '" << name << "'"
         << "       required minlength= '44' maxlength= '999' size= '44' />"

         << "   <input type= 'submit' value= 'Submit'>"
         << "</form>" << endl;

    if(!name.empty()) {
        cout << "<p>$$ Hello, " << name << "!</p>";
    } else {
        cout << "<p>$$ Got no input from you.</p>";
    }

    cout << "</body></html>" << endl;
    return 0;
}
