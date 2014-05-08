#include "Vector.h"
#include "Point.h"
#include "Segment.h"
#include "Circle.h"
#include <iomanip>

int main () {
    double x, y, r, a, b, c;
    cin >> x >> y >> r >> a >> b >> c;
    Circle C(x, y, r);
    C.IntersectLine(a, b, c);
	return 0;
}
