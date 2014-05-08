#pragma once
#include "Point.h"

class Segment {
private:
	Point a, b;
public:
	Segment (double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0);
	Segment (Point, Point);
	int count_whole_points() const;
	double Distance (const Point &) const;
	bool onSegment(const Point &) const;
	bool isSegmentIntersection(const Segment &) const;
};