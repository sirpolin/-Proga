#pragma once
#include "Point.h"
#include "Vector.h"
#include <cmath>

class Ray {
private:
	Point beginning;
	Vector direction;
public:
	Ray();
	Ray(Point, Vector);
	bool Contain(Point) const;
	double Distance(Point) const;
};