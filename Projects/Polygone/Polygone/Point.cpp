#pragma once
#include "Point.h"

void Point::putX(double a) {
	x = a;
}
void Point::putY(double a) {
	y = a;
}
void Point::print() const {
	cout << x << " " << y << endl;
}

Point::Point(double _x, double _y) {
	x = _x;
	y = _y;
}