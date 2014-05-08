#pragma once

#include <iostream>
using namespace std;

class Shape {
public:
	virtual double area () const = 0;
	virtual void FigureName () const = 0;
	virtual void Parametres () const = 0;
};