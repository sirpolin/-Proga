#pragma once

#include "Circle.h"
#include "Vector.h"
#include <cmath>
#define epsilon 0,00000001

const double pi = 3.1415926;

Circle::Circle(const Point& a, double r): Point(a), R(r) {};
Circle::Circle(const Circle &a): Point (a), R(a.R) {};
double Circle::GetR () const {
	return R;
}
void Circle::PutR (double r) {
	R = r;
}
double Circle::area () const {
	return pi * R * R;
}
void Circle::Parametres () const {
	cout << "My centre is in ";
	this->Print();
	cout << "My radius is " << this->GetR() << endl;
}
void Circle::IntersectCircle(Circle c) const {
	Vector tmp (x, y, c.x, c.y);
	double dis = tmp.Length();;
	if (R == c.R && dis == 0) {
		cout << 3;
		return;
	}
	if ((dis > R + c.R) || (dis < abs(R - c.R)))
		cout << 0;
	else {
		double xh, yh, x1, y1, x2, y2;
		double a = (R * R - c.R * c.R + dis * dis) / (2 * dis);
		double h = sqrt(R * R - a * a);
		xh = x + a * (c.x - x) / dis;
		yh = y + a * (c.y - y) / dis;
		x1 = xh + h * (c.y - y) / dis;
		y1 = yh - h * (c.x - x) / dis;
		x2 = xh - h * (c.y - y) / dis;
		y2 = yh + h * (c.x - x) / dis;
		if (x1 == x2 && y1 == y2)
			cout << 1 << endl << fixed << x1 << " " << y1 << endl;
		else
			cout << 2 << endl << fixed << x1 << " " << y1 << endl << x2 << " " << y1 << endl;
	}
}
void Circle::IntersectLine(double A, double B, double C) const {
    double a = A, b = B, c = C - (A * x + B * y);
    double x0 = -a * c / (a * a + b * b),  y0 = -b * c / (a * a + b * b);
    if (c * c > R * R * (a * a + b * b) + epsilon)
        cout << 0;
    else
        if (abs (c * c - R * R * (a * a + b * b)) < epsilon) {
            cout << 1 << x0 + x << ' ' << y0 + y;
    } else {
        double d = R * R - c * c / (a * a + b * b);
        double mult = sqrt (d / (a * a + b * b));
        double ax, ay, bx, by;
        ax = x0 + b * mult;
        bx = x0 - b * mult;
        ay = y0 - a * mult;
        by = y0 + a * mult;
        cout << 2;
        cout << ax + x << ' ' << ay + y << endl << bx + x << ' ' << by + y;
    }
}
