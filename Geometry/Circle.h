#pragma once

#include "Point.h"
#include "Shape.h"

class Circle: public Shape, Point {
	double R;
public:
	Circle(double x = 0, double y = 0, double r = 1): Point(x,y), R(r) {};
	Circle (const Point&, double);
	Circle(const Circle&);
	double GetR() const;
	void PutR (double);
	void FigureName () const {cout << "I'm a Circle!)" << endl;}
	double area () const;
	void Parametres () const;
    void IntersectCircle(Circle) const;
    void IntersectLine (double, double, double) const;
};
