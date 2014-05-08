#pragma once
#include "Point.h"
#include <cmath>

Point::Point(double _x, double _y): x(_x), y(_y) {}
void Point::putX(double a) {
	x = a;
}
void Point::putY(double a) {
	y = a;
}
void Point::Print() const {
	cout << x << " " << y << endl;
}
bool Point::operator <(const Point & A) const {
	if (this->y < A.y || this->y == A.y && this->x < A.x)
		return true;
	else
		return false;
}
bool Point::operator ==(const Point & A) const {
	if (this->x == A.x && this->y == A.y)
		return true;
	else
		return false;
}
double Point::Distance(Point & A) const {
	return sqrt(pow(x - A.x, 2) + pow(y - A.y, 2));
}
