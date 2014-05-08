#pragma once
#include <iostream>

using namespace std;

class Point {
private:
	double x, y;
public:
	double getX() const {return x;}
	double getY() const {return y;}
	void putX(double);
	void putY(double);
	void print() const;
	Point (double a = 0, double b = 0);
};