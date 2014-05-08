#pragma once
#include "Polygon.h"
#include <cmath>
#include <cstdlib>
#include <cstring>

Polygon::Polygon(unsigned int count) {
	vertices = new Point [verticesCount = count];
}
Polygon::Polygon(const Polygon & p): verticesCount(p.verticesCount) {
	vertices = new Point [verticesCount];	
	memcpy(vertices, p.vertices, sizeof(int) * verticesCount);
}	
Polygon::~Polygon() {
	delete [] vertices;
}
Point& Polygon:: operator [](int a) {
	Point& tmp = vertices[a];
	return tmp;
}
const Point& Polygon::operator [](int a) const {
	const Point& tmp = vertices[a];
	return tmp;
}
Polygon& Polygon::operator =(const Polygon &p) {
	if (this == &p)
		return *this;
	Point* tmp = new Point [p.verticesCount];
	delete [] vertices;
	vertices = tmp;
	memcpy(vertices, p.vertices, sizeof(int) * verticesCount);
	return *this;
}
double Polygon::area() const {
	double tmpArea = 0;
	for (int i = 1; i < verticesCount; ++i) {
		tmpArea += (vertices[i].getX() - vertices[i - 1].getX()) * 
				   (vertices[i].getY() + vertices[i - 1].getY());
	}
	tmpArea += (vertices[0].getX() - vertices[verticesCount - 1].getX()) * 
			   (vertices[0].getY() + vertices[verticesCount - 1].getY());
	return abs(tmpArea) / 2;
}