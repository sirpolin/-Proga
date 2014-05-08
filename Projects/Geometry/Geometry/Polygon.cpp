#pragma once
#include "Polygon.h"
#include "Vector.h"
#include "Segment.h"
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>

struct polar_angle {
    double angle;
    double length;
    unsigned int i;
};

bool cmp(polar_angle A, polar_angle B) {
    if ((A.angle - B.angle) > epsilon)
        return 0;
    else {
        if (abs(A.angle - B.angle) <= epsilon)
            if (A.length < B.length)
                return 0;
    }
    return 1;
}
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
    for (unsigned int i = 1; i < verticesCount; ++i) {
        tmpArea += (vertices[i].getX() - vertices[i - 1].getX()) *
                   (vertices[i].getY() + vertices[i - 1].getY());
    }
    tmpArea += (vertices[0].getX() - vertices[verticesCount - 1].getX()) *
               (vertices[0].getY() + vertices[verticesCount - 1].getY());
    return abs(tmpArea) / 2;
}
long double Polygon::perimeter() const {
    long double tmpPer = 0;
    for (unsigned int i = 1; i < verticesCount; ++i) {
        Vector A (vertices[i], vertices[i - 1]);
        tmpPer += A.Length();
    }
    Vector A (vertices[0], vertices[verticesCount - 1]);
    tmpPer += A.Length();
    return tmpPer;
}
bool Polygon::check_convex() const {
    unsigned int count_pos = 0, count_neg = 0;
    for (unsigned int i = 2; i < verticesCount; ++i) {
        Vector a(vertices[i - 2], vertices[i - 1]),
               b(vertices[i - 1], vertices[i]);
        if (count_pos > 0 && count_neg > 0)
            return false;
        if (a.Pseudoscalar_product(b) >= 0)
            count_pos++;
        else
            count_neg++;
    }
    unsigned int n = verticesCount - 1;
    Vector a(vertices[n - 1], vertices[n]),
           b(vertices[n], vertices[0]);
    if (a.Pseudoscalar_product(b) >= 0)
            count_pos++;
        else
            count_neg++;
    Vector c(vertices[n], vertices[0]),
           d(vertices[0], vertices[1]);
    if (c.Pseudoscalar_product(d) >= 0)
            count_pos++;
        else
            count_neg++;
    if (count_pos > 0 && count_neg > 0)
            return false;
    return true;
}
int Polygon::operator ~ () const {
    unsigned int count = 0;
    for (unsigned int i = 1; i < verticesCount; ++i) {
        Segment A(vertices[i - 1], vertices[i]);
        count += A.count_whole_points();
    }
    Segment A(vertices[verticesCount - 1], vertices[0]);
    count += A.count_whole_points();
    count += verticesCount;
    return abs(this->area() - (count / 2) + 1);
}
bool Polygon::check_belong(Point A) const {
    double sum = 0;
    for (unsigned int i = 1; i < verticesCount; ++i) {
        Vector a(A, vertices[i - 1]), b(A, vertices[i]);
        sum += a.Angle(b);
    }
    Vector a(A, vertices[verticesCount - 1]), b(A, vertices[0]);
    sum += a.Angle(b);
    if (abs(sum) <= epsilon)
        return false;
    else
        return true;
}
void Polygon::print() const {
    for (unsigned int i = 0; i < this->verticesCount; ++i)
        cout << this->vertices[i].getX() << " " << this->vertices[i].getY() << endl;
}
void Polygon::graham_scan(Polygon & ans) {

    const unsigned int n = this->verticesCount;
    Point p0 = this->vertices[0];
    for (unsigned int i = 1; i < n; ++i)
        if (this->vertices[i] < p0)
            p0 = this->vertices[i];
    ans[0] = p0;
    polar_angle * arr = new polar_angle[n];
    Vector Ox (0, 0, 1, 0);
    for (unsigned int i = 0; i < n; ++i) {
        if (this->vertices[i] == p0) {
            arr[i].angle = 0;
            arr[i].length = 0;
            arr[i].i = i;
            if (i != 0)
                swap(arr[i], arr[0]);
        } else {
            Vector tmp (p0, this->vertices[i]);
            arr[i].angle = tmp.Polar_angle();
            while(abs(arr[i].angle) < 0)
                arr[i].angle += 2 * 3.14159265;
            arr[i].length = tmp.Length();
            arr[i].i = i;
        }
    }
    stable_sort(arr + 1, arr + n, cmp);
    ans[1] = this->vertices[arr[1].i];
    ans.verticesCount = 2;
    for (unsigned int i = 2; i < n; ++i) {
        Vector C(ans[ans.verticesCount - 2], ans[ans.verticesCount - 1]),
               D(ans[ans.verticesCount - 1], this->vertices[arr[i].i]);
        while ((C.Pseudoscalar_product(D) < 0) || (this->vertices[arr[i].i] == ans[ans.verticesCount - 1])) {
            --(ans.verticesCount);
            C = Vector(ans[ans.verticesCount - 2], ans[ans.verticesCount - 1]);
            D = Vector(ans[ans.verticesCount - 1], this->vertices[arr[i].i]);
        }
        ans.vertices[ans.verticesCount] = this->vertices[arr[i].i];
        ++(ans.verticesCount);
    }
}