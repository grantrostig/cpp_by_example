// adapted from officer-tuba's posting, not sure of source.
#include <iostream>
#include <string>

// trivial/contrived test class
template <typename T>
class Handler {
public:
    Handler(T data) : _data{data} { }
    T get_Data() { return  _data;}
private:
    T _data;
};

//deduction guide - forces instantiation of Handler<const char*> to be Handler<std::string>
Handler(const char* c) -> Handler<std::string>;

//trivial test function - explicitly requires a Handler<std::string>
void TestHandler(Handler<std::string> handler) {
    std::cout << handler.get_Data() << '\n';
}

int main() {
    //test with Handler<std::string>
    std::string 	d1			{"std::string data"};
    Handler 		strHandler	{d1};
    TestHandler(strHandler);

    //test with Handler<const char*>
    //note: the TestHandler call would not compile without the deduction guide above
    Handler 	charHandler		{"const char* data"};
    TestHandler(charHandler);

    using namespace std::string_literals;
    Handler 	charHandlerS		{"const char* data with string_literals"s};
    TestHandler(charHandlerS);

    return 0;
}
