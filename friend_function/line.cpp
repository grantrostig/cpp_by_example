#include <iostream>
#include "line.h"

mylib::line::line() {
        point1 = new point(12, 10);
        point2 = new point(12, 50);
}

mylib::line::~line() {
	delete point1;
	delete point2;
}

mylib::line::line(point* p1, point* p2) {
	point1 = p1;
	point2 = p2;
}

void mylib::line::draw_line() {
	std::cout << "Drawing Line from "<< "(" << point1->x << ',' << point1->y<<")" << 
		" to " << "(" << point2->x << ',' << point2->y << ")""\n";
}
