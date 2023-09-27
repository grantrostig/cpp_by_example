#pragma once
#include "line.h"
//#include "line.cpp"
#include <iostream>

namespace mylib {

        class line; //Forward Declaration
        class point {
		//Non-member frunction is declared as friend
                friend void print_point(const point&);

                //friend class line; // todo class Line has been declared as friend to Point
                //friend void line::draw_line();  // todo
	private:
		int x;
		int y;
	public:
                point();
                explicit point(int x, int y);
		int get_x(void) const;
		int get_y(void) const;
	}; //End of class declaration

	//Non-Member free standing function 
        void print_point(const point &);

	class A {
	private:
		int adata;
	public: 
                int foo(); //define later
                int bar();
	};

	class B {
		int data = 100;
		//Member function of class A is made friend of Class B
		friend int A::foo();
	};
}

