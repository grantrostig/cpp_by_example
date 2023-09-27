#include <iostream>
using namespace std;

int main() {

//var createGreeting = function(greeting) {                     // JavaScript version  https://aspiringcraftsman.com/2012/02/17/javascript-closures-explained/
    //return function(name) {
        //document.write(greeting + ', ' + name + '.');
    //};
//};
//helloGreeting = createGreeting("Hello");
//howdyGreeting = createGreeting("Howdy");
//helloGreeting("John");  // Hello, John.{
//howdyGreeting("Jane");  // Hello, John.{

    //auto greeting_lambda = [] (std::string greeting) {

    //auto greeting_lambda = [&] (std::string greeting) { // makes no difference
    //auto greeting_lambda = [=] (std::string greeting) { // makes no difference
    auto greeting_lambda = []  (std::string & greeting) { // ?
    //auto greeting_lambda = [&] (std::string & greeting) { // ?
    //auto greeting_lambda = [=] (std::string & greeting) { // ?

        //static string my_greeting {greeting};
        //auto name_lambda = [&] (std::string name) { cout << my_greeting << ", " << name << endl; };  // why always prints "hello"?

        string my_greeting {greeting};
        auto name_lambda = [&] (std::string name) { cout << my_greeting << ", " << name << endl; };  // why crashes?

        //string my_greeting {greeting};
        //auto name_lambda = [=] (std::string name) { cout << my_greeting << ", " << name << endl; };
        //auto name_lambda = [&] (std::string name) { cout << my_greeting << ", " << name << endl; };

        return name_lambda;
    };

    // string yo_string {"Yo"};
    static string yo_string {"Yo"};

    //auto hello_greeting = greeting_lambda("Hello");
    //auto howdy_greeting = greeting_lambda("Howdy");
    auto yo_greeting    = greeting_lambda(yo_string);

    //hello_greeting("John");
    //hello_greeting("Sally");
    //howdy_greeting("John");
    //howdy_greeting("Sally");
    yo_greeting(   "John");
    yo_greeting(   "Sally");

    cout << "###" << endl;
    return 0;
}
