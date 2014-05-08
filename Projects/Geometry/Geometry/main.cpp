#include "Vector.h"
#include "Point.h"
#include "Segment.h"
#include "Circle.h"
#include <iomanip>

int main () {
	double x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	Circle c1(x1, y1, r1), c2(x2, y2, r2);
	c1.IntersectCircle(c2);
	return 0;
}