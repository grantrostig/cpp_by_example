#include <iostream>
#include <string>
using namespace std;
// base derived function super this self

class Super_class {
public:
    virtual void print() const {
        cout<<"Super:print."<<endl;
    }
};
class Sub_class : Super_class {
public:
    void print() const override final {
        Super_class::print();
        cout<<"Sub  :print."<<endl;
    }
};
int main()  {
    Sub_class sub_class {};
    sub_class.print();
    cout << "###" << endl;
    return 0;
}
