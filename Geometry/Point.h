#pragma once
#include <iostream>

using namespace std;

class Point {
protected:
	double x, y;
public:
	double getX() const {return x;}
	double getY() const {return y;}
	void putX(double);
	void putY(double);
	void Print() const;
	Point (double a = 0, double b = 0);
	bool operator < (const Point&) const;
	bool operator == (const Point&) const;
    double Distance (Point &) const;
};
