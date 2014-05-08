#pragma once
#include "Point.h"

class Polygon {
	Point* vertices;
	unsigned int verticesCount;
public:
	Polygon(unsigned int count = 0);
	Polygon (const Polygon&);
	~Polygon();
	Point& operator [](int);
	const Point& operator [](int) const;	
	Polygon& operator = (const Polygon&);
	double area() const;
	bool check_convex() const;
};