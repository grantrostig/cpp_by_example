#pragma once
#include "point.h"

namespace mylib {
        class point; // forward Declaration
	
        class line {
	private:
                point* point1;
                point* point2;
	public:
                line();
                ~line();
                line(point*, point*);
                //void draw_line();
                void draw_line() {
                    std::cout << "Drawing Line from "<< "(" << point1->x << ',' << point1->y<<")" <<
                    " to " << "(" << point2->x << ',' << point2->y << ")""\n";
                }
        };

}
