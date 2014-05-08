#pragma once
#include "Segment.h"
#include "Vector.h"
#define pi 3.14159265
#define epsilon 0.000001
#include <cmath>
#include <cstdlib>

Segment::Segment (double x1, double y1, double x2, double y2) {
	a.putX(x1);
	b.putX(x2);
	a.putY(y1);
	b.putY(y2);
}
Segment::Segment (Point _a, Point _b) : a(_a), b(_b) {
}

int Segment::count_whole_points() const {
	int n1 = a.getX() - b.getX(), n2 = a.getY() - b.getY();
	int c;
    while (n2) {
       c = n1 % n2;
       n1 = n2;
       n2 = c;        
    }
    return abs(n1) - 1;
}
double Segment::Distance(const Point & A) const {
	Vector seg1(a, b), seg2(b, a), vct1(a, A), vct2(b, A);
	if (seg1.Cosinus(vct1) < 0)
		return vct1.Length();
	if (seg2.Cosinus(vct2) < 0)
		return vct2.Length();
	if (vct1.Sinus(seg1) >= -1 && vct1.Sinus(seg1) <= 1)
		return  abs(vct1.Sinus(seg1)) * vct1.Length();
	else
		return 0;
}
bool Segment::onSegment(const Point &_p) const{
	double x1 = a.getX();
	double y1 = a.getY();
	double x2 = b.getX();
	double y2 = b.getY();
	double x = _p.getX();
	double y = _p.getY();
	int x_1 = x1 - x, x_2 = x2 - x;
    int y_1 = y1 - y, y_2 = y2 - y;
	return (y_2 * x_1 - x_2 * y_1 == 0 &&
			min(x1, x2) <= x && x <= max(x1, x2) && 
			min(y1, y2) <= y && y <= max(y1, y2));
}
bool Segment::isSegmentIntersection(const Segment &_s) const {
	Point P0 = a;
	Point P1 = b;
	Point P2 = _s.a;
	Point P3 = _s.b;
	Vector V02(P0,P2), V03(P0,P3), V12(P1,P3), V23(P2,P3);
	Vector V20(P2,P0), V21(P2,P1), V30(P3,P0), V32(P3,P2); 
	double d1 = V02.Pseudoscalar_product(V03);
	double d2 = V12.Pseudoscalar_product(V23);
	double d3 = V20.Pseudoscalar_product(V21);
	double d4 = V30.Pseudoscalar_product(V32);
	if ((d1 < 0 && d2 > 0 || d1 > 0 && d2 < 0) &&
		(d3 < 0 && d4 > 0 || d3 > 0 && d4 < 0)) {
		return true;
	}
	if (d1 == 0 && _s.onSegment(P0))
		return true;
	if (d2 == 0 && _s.onSegment(P1))
		return true;
	if (d3 == 0 && this->onSegment(P2))
		return true;
	if (d4 == 0 && this->onSegment(P3))
		return true;
	return false;
}