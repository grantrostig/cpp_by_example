// Friend_Function.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "point.h"
#include "line.h"
using namespace std;
int main()
  {
    mylib::point p1(12, 3);
    //std::cout << "X : " << p1.get_x() << "\tY : " << p1.get_y() << '\n';
    mylib::print_point(p1);

    mylib::line line1{};
    line1.draw_line();
    mylib::line line2(new mylib::point(23, 40), new mylib::point(50, 50));
    line2.draw_line();

    /*  mylib::A aobj;
      aobj.foo();*/

  cout << "###" << endl;
  return 0;
}
