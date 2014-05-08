#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

class CHugeInteger  {
    int* num;
    int size;
    CHugeInteger substring(const int &) const;
    CHugeInteger addNum(const int &) const;
    CHugeInteger revolution();
public:
    CHugeInteger(int s = 0);
    ~CHugeInteger();
    CHugeInteger(const CHugeInteger & src);
    CHugeInteger operator =(const CHugeInteger &);
    void convert (const int &);
    CHugeInteger mult(const int &, const int &) const;

    CHugeInteger operator +(const CHugeInteger &) const;
    CHugeInteger operator +(const int &) const;
    friend CHugeInteger operator + (const int &, const CHugeInteger &);

    CHugeInteger operator -(const CHugeInteger &) const;
    CHugeInteger operator -(const int &) const;

    CHugeInteger operator *(const CHugeInteger &) const;
    CHugeInteger operator *(const int &) const;
    friend CHugeInteger operator * (const int &, const CHugeInteger &);

    CHugeInteger operator -=(const CHugeInteger &);

    CHugeInteger operator /(const CHugeInteger &) const;
    CHugeInteger operator /(const int &) const;

    CHugeInteger operator %(const CHugeInteger & b) const;
    CHugeInteger operator %(const int &) const;

    bool operator ==(const CHugeInteger &) const;
    bool operator >(const CHugeInteger &) const;
    bool operator <(const CHugeInteger &) const;

    friend ostream & operator << (ostream &, const CHugeInteger &);
    friend istream & operator >> (istream &, CHugeInteger &);
};
