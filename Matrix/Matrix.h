#include <iostream>
#include <cmath>
using namespace std;

class Matrix {
    int n, m;
    double **a;
    bool exist;
    double Minor(const int &, const int &);
    Matrix ExchangeRow(const int &, const int &);
public:
    Matrix(const int &, const int &, bool p = true);
    Matrix(const Matrix &);
    Matrix & operator =(const Matrix &);
    Matrix operator +(const Matrix &) const;
    Matrix operator -(const Matrix &) const;
    Matrix operator *(const Matrix &) const;
    Matrix operator *(const double &) const;
    double Det() const;
    Matrix Transpose() const;
    double Trace() const;
    Matrix InvertibleMatrix();
    void Print() const;
    ~Matrix();
};
