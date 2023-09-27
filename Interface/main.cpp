// Copyright Grant Rostig 2019
#include <iostream>
#include <chrono>
#include <bits/unique_ptr.h>

using namespace std;

struct Person_interface {  // make this class "pure virtual" by making all functions virtual=0, except for the default constructor and destructor, this allows some compiler optimizations over just an "abstract class"
    std::string name {"No Name Yet"};
    int         age {};
    Person_interface() {
        cout << "Person_interface()\n";
    }
    ~Person_interface() {
        cout << "~Person_interface()\n";
    }
    virtual void rename( std::string new_name )=0;
    virtual void birthday()=0;
};

struct Child : public Person_interface {
    Child() {
        cout << "Child()\n";
        // will also call parent() automatically
    }
    ~Child() {
        cout << "~Child()\n";
        // will also call parent() automatically
    }
    void rename( std::string new_name ) override {
        cout << "Child::rename()\n";
        name = new_name;                            // this->name = new_name;
    }
    void birthday() override {
        cout << "Child::birthday()\n";
        ++age;
    }
};

struct Student : public Child {
    string name_enrollment {};
    Student() {
        cout << "Student()\n";
    }

    void rename(std::string new_name) override final {
        cout << "Student::rename()\n";
        name_enrollment = new_name;
        Child::rename( new_name );
    };
};

int main() {
    Child               child1;
    Person_interface *  person_ptr;
    person_ptr =        &child1;
    person_ptr->birthday();         // calls child's birthday, not person's version (which is NULL anyway).
    cout << child1.age << endl;

    Student             student1;
//    std::unique_ptr<Child>   child_ptr;  // todo: redo code with unique_ptr.
    Child *             child_ptr;
    child_ptr =         &student1;
    person_ptr =        &student1;
    child_ptr->rename("Student Bob");   // calls student's rename, not child's.
    person_ptr->birthday();             // would call student's birthday (if it existed), but gets child's birthday through inheritance.
    cout << "child and person name: " << child_ptr->name <<", "<< person_ptr->name << endl;



    cout << "###" << std::endl;
    return 0;
}