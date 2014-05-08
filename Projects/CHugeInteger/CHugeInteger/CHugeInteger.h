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
	void read();//������� ���������� � ������ �������� ���� � ������ ������ ������
	void Print() const;//������� �� ����� ��������� ��������
	CHugeInteger operator = (const CHugeInteger &); //���������� ���������� =
	bool operator < (const CHugeInteger &) const;//���������� ���������� <
	bool operator > (const CHugeInteger &) const;//���������� ���������� >
	bool operator == (const CHugeInteger &) const;//���������� ���������� ==
	CHugeInteger operator +(const CHugeInteger & b) const;//���������� ���������� +
	CHugeInteger operator -(const CHugeInteger & b) const;//���������� ���������� -
	CHugeInteger operator *(const CHugeInteger & b) const;//���������� ���������� *
	CHugeInteger operator /(const CHugeInteger & b);//���������� ���������� /
	CHugeInteger operator -=(const CHugeInteger & b);//���������� ���������� -=
	CHugeInteger operator %(const CHugeInteger & b) const;//���������� ���������� ������� �� �������
	CHugeInteger mult(const int&, int) const; // ��������� �������� �� ��������
	~CHugeInteger();//����������
};