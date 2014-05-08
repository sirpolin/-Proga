#include "Point.h"
#include "Polygon.h"

int main () {
	int n;
	cin >> n;
	Polygon P(n);
	for (int i = 0; i < n; ++i) {
		double x, y;
		cin >> x >> y;
		Point T(x,y);
		P[i] = T;
	}
	cout << P.area();
	return 0;
}