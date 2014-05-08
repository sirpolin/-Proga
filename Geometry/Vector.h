#pragma once
#include "Point.h"

class Vector {
private:
	Point beginning, end;
public:
	Vector (double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0);
	Vector (Point, Point);
	Point get_beginning() const {return beginning;}
	Point get_end() const {return end;}
	void put_beginning(Point);
	void put_end(Point);
	double Scalar_product (Vector) const;
	double Pseudoscalar_product (Vector) const;
	double Length() const;
	double Sinus (Vector) const;
	double Cosinus (Vector) const;
	double Angle (Vector) const;
	double Polar_angle() const;
};