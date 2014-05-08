#pragma once
#include "Vector.h"
#include <cmath>

Vector::Vector (double x1, double y1, double x2, double y2) {
	beginning.putX(x1);
	end.putX(x2);
	beginning.putY(y1);
	end.putY(y2);
}
Vector::Vector(Point a, Point b): beginning(a), end(b) {}
void Vector::put_end(Point a) {
	end = a;
}
void Vector::put_beginning(Point a) {
	beginning = a;
}
double Vector::Scalar_product(Vector A) const {
	return (A.end.getX() - A.beginning.getX()) * (this->end.getX()  - this->beginning.getX()) +
			(A.end.getY() - A.beginning.getY()) * (this->end.getY() - this->beginning.getY());
}
double Vector::Pseudoscalar_product (Vector A) const {
	return (this->end.getX() - this->beginning.getX()) * (A.end.getY() - A.beginning.getY()) -
			(A.end.getX() - A.beginning.getX()) * (this->end.getY() - this->beginning.getY());
}
double Vector::Length() const {
	return sqrt(pow(this->end.getX() - this->beginning.getX(), 2) +
				pow(this->end.getY() - this->beginning.getY(), 2));
}
double Vector::Sinus(Vector A) const {
	return this->Pseudoscalar_product(A) / (A.Length() * this->Length());
}
double Vector::Cosinus(Vector A) const {
	return this->Scalar_product(A) / (A.Length() * this->Length());
}
double Vector::Angle(Vector A) const {
	return asin(this->Sinus(A));
}
double Vector::Polar_angle() const {
	return atan2((end.getY() - beginning.getY()),(end.getX() - beginning.getX()));
}