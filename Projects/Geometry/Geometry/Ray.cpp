#pragma once
#include "Ray.h"

Ray::Ray() {}
Ray::Ray(Point a, Vector b) : beginning(a), direction(b) {}
bool Ray::Contain(Point A) const {
	Vector a(this->beginning.getX(),this->beginning.getY(),A.getX(),A.getY());
	if (a.Pseudoscalar_product(this->direction) == 0 &&
		a.Scalar_product(this->direction) >= 0)
		return true;
	else
		return false;
}
double Ray::Distance(Point A) const {
	Vector a(this->beginning.getX(),this->beginning.getY(),A.getX(),A.getY());
	if (a.Cosinus(this->direction) > 0)
		return  a.Sinus(this->direction) * a.Length();
	else
		return a.Length();
}