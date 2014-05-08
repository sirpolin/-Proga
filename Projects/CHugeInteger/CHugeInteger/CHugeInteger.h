#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class CHugeInteger  {      
	int* num;
	int size;
	CHugeInteger substring(int);
	CHugeInteger addNum(int);    
	CHugeInteger revolution(); // perevorot chisla   
public:      
	CHugeInteger(int s = 0);
	CHugeInteger(const CHugeInteger & src);
	void read();//функция считывания с экрана забивает сама в массив каждый символ
	void Print() const;//выводит на экран результат операции
	CHugeInteger operator = (const CHugeInteger &); //перегрузка операторра =
	bool operator < (const CHugeInteger &) const;//перегрузка операторра <
	bool operator > (const CHugeInteger &) const;//перегрузка операторра >
	bool operator == (const CHugeInteger &) const;//перегрузка операторра ==
	CHugeInteger operator +(const CHugeInteger & b) const;//перегрузка операторра +
	CHugeInteger operator -(const CHugeInteger & b) const;//перегрузка операторра -
	CHugeInteger operator *(const CHugeInteger & b) const;//перегрузка операторра *
	CHugeInteger operator /(const CHugeInteger & b);//перегрузка операторра /
	CHugeInteger operator -=(const CHugeInteger & b);//перегрузка операторра -=
	CHugeInteger operator %(const CHugeInteger & b) const;//перегрузка операторра остаток от деления
	CHugeInteger mult(const int&, int) const; // умножение длинного на короткое
	~CHugeInteger();//деструктор
};