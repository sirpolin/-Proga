#include <iostream>
#include <cmath>
using namespace std;

class Matrix {
	int n, m;
	double **a;
	bool exist;
	double Minor(const int &, const int &); //  Минор
	Matrix ExchangeRow(const int &, const int &); // поменять строки местами
public:
	Matrix(const int &, const int &, bool p = true); //Конструктор
	Matrix(const Matrix &); // cpy ctor
	Matrix & operator =(const Matrix &); // Перегрузка операции =
	Matrix operator +(const Matrix &) const; // Перегрузка операции + 
	Matrix operator -(const Matrix &) const; // Перегрузка операции - 
	Matrix operator *(const Matrix &) const; // Перегрузка операции * 
	Matrix operator *(const double &) const; // Перегрузка операции *
	double Det() const; // детерменант 
	Matrix Transpose() const; // транспонирование матрицы 
	double Trace() const; // след матрицы
	Matrix InvertibleMatrix(); //обратная матрица
	void Print() const;   //показать матрицу
	~Matrix(); // деструктор
};