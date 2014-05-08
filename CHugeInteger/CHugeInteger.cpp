#include "CHugeInteger.h"

CHugeInteger::CHugeInteger(int s) {
    size = s;
    num = new int[size];
    for (int i = 0; i < size; ++i)
        num[i] = 0;
}

CHugeInteger::~CHugeInteger() {
    delete []num;
}

CHugeInteger::CHugeInteger(const CHugeInteger & src) {
    size = src.size;
    num = new int[size];
    for (int i = 0; i < size; ++i)
        num[i] = src.num[i];
}

CHugeInteger CHugeInteger::operator = (const CHugeInteger & src) {
    if (this == &src)
        return *this;
    delete [] num;
    num = new int[size = src.size];
    for (int i = 0; i < size; ++i)
        num[i] = src.num[i];
    return *this;
}

void CHugeInteger::convert(const int & b) {
    string str;
    stringstream ss;
    ss << b;
    ss >> str;
    size = str.length();
    num = new int[size];
    for (int i = 0; i < size ; i++)
        num[i] = str[size - i - 1] - '0';
}

CHugeInteger CHugeInteger::operator + (const CHugeInteger & b) const {
    CHugeInteger c(max(size, b.size) + 1);
    int count = 0;
    for (int i = 0; i < c.size - 1; ++i) {
        int a = 0, d = 0;
        if (i < size)
            a = num[i];
        if (i < b.size)
            d = b.num[i];
        c.num[i] = (a + d + count) % 10;
        count = (a + d + count) / 10;
    }
    if (count == 1)
        c.num[c.size - 1] = 1;
    else
        c.size--;
    return c;
}
CHugeInteger CHugeInteger::operator + (const int & b) const {
    CHugeInteger tmp;
    tmp.convert(b);
    return *this + tmp;
}
CHugeInteger operator + (const int & b, const CHugeInteger & _num) {
    CHugeInteger tmp;
    tmp.convert(b);
    return _num + tmp;
}

CHugeInteger CHugeInteger::operator-(const CHugeInteger & b) const {
    CHugeInteger c(size);
    if (*this == b) {
        c.size = 1;
        return c;
    }
    int count = 0;
    for (int i = 0; i < size; ++i) {
        int temp1 = num[i] - count;
        int temp2 = b.num[i];
        if (i >= b.size)
            temp2 = 0;
        if (temp1 >= temp2) {
            c.num[i] = temp1 - temp2;
            count = 0;
        } else {
            c.num[i] = 10 + temp1 - temp2;
            count = 1;
        }
    }
    for (int i = size - 1; i > 0; --i) {
        if (!c.num[i])
            c.size--;
        else
            break;
    }
    return c;
}
CHugeInteger CHugeInteger::operator -(const int & b) const {
    CHugeInteger tmp;
    tmp.convert(b);
    return *this - tmp;
}

CHugeInteger CHugeInteger::mult(const int & b, const int & shift) const {
    CHugeInteger c(size + shift + 1);
    int count = 0;
    for (int i = shift; i < size+shift; i++) {
        c.num[i] = (num[i - shift] * b + count) % 10;
        count = (num[i - shift] * b + count) / 10;
    }
    if (count != 0)
        c.num[c.size - 1] = count;
    else
        c.size--;
    return c;
}

CHugeInteger CHugeInteger::operator *(const CHugeInteger & b) const {
    CHugeInteger c(1);
    if ((size == 1 && num[0] == 0) || (b.size == 1 && b.num[0] == 0))
        return c;
    for (int i = 0; i < size; ++i)
        c = b.mult(num[i], i) + c ;
    if (c.num[c.size - 1] == 0)
        --c.size;
    return c;
}
CHugeInteger CHugeInteger::operator * (const int & b) const {
    CHugeInteger tmp;
    tmp.convert(b);
    return *this * tmp;
}
CHugeInteger operator * (const int & b, const CHugeInteger & _num) {
    CHugeInteger tmp;
    tmp.convert(b);
    return _num * tmp;
}

CHugeInteger CHugeInteger::operator -=(const CHugeInteger & b) {
    *this = *this - b;
    return *this;
}

CHugeInteger CHugeInteger::substring(const int & b) const {
    CHugeInteger c(b);
    for (int i = size - 1, j = c.size - 1; j >= 0; --j, --i)
        c.num[j] = num[i];
    return c;
}

CHugeInteger CHugeInteger::addNum(const int & b) const {
    if (size == 1 && num[0] == 0 ) {
        if (b == 0)
            return *this;
        else {
            CHugeInteger d(1);
            d.num[0] = b;
            return d;
        }
    }
    CHugeInteger c(size + 1);
    for (int i = size; i > 0; --i)
        c.num[i] = num[i - 1];
    c.num[0] = b;
    return c;
}

CHugeInteger CHugeInteger::revolution() {
    CHugeInteger c = *this;
    for (int i = 0; i < size; i++) {
        num[i] = c.num[size - 1 - i];
    }
    return *this;
}

CHugeInteger CHugeInteger::operator /(const CHugeInteger & b) const {

    if ((size == 1 && num[0] == 0) || ((*this) < b)) {
        CHugeInteger s(1);
        return s;
    }
    CHugeInteger temp = this->substring(b.size);
    if (temp < b)
        temp = this->substring(b.size + 1);
    int d = size - temp.size;
    int count1 = 0;
    int count2 = d - 1;
    CHugeInteger c(d + 1);
    for (int j = 0; j < d + 1 ; ++j) {
        for (int i = 2; i <= 10; ++i) {
            if (temp < b.mult(i, 0)) {
                --i;
                c.num[count1] = i;
                ++count1;
                temp -= b.mult(i, 0);
                break;
            }
        }
        if (count2 < 0)
            return (c.revolution());

        temp = temp.addNum(num[count2]);
        --count2;

        for (int i = 1; i < d + 1; ++i) {
            if (temp < b) {
                if (count2 < 0) {
                    c.num[count1] = 0;
                    ++count1;
                    return (c.revolution());
                }
                temp = temp.addNum(num[count2]);
                --count2;
                c.num[count1] = 0;
                ++count1;
            }
            else
                break;
        }
    }
    return (c.revolution());
}
CHugeInteger CHugeInteger::operator /(const int & b) const {
    CHugeInteger tmp;
    tmp.convert(b);
    return *this / tmp;
}

CHugeInteger CHugeInteger::operator %(const CHugeInteger & b) const{
    CHugeInteger temp, a = *this;
    temp = a / b;
    temp = temp * b;
    if (temp == 0)
        return 0;
    return a - temp;
}
CHugeInteger CHugeInteger::operator %(const int & b) const {
    CHugeInteger tmp;
    tmp.convert(b);
    return *this % tmp;
}


bool CHugeInteger::operator ==(const CHugeInteger & b) const {
    int i;
    if (size != b.size)
        return 0;
    for (i = size - 1; i >= 0 ; --i) {
        if (num[i] == b.num[i])
            continue;
        return 0;
    }
    if (i < 0)
        return 1;
}

bool CHugeInteger::operator >(const CHugeInteger & b) const {
    int i;
    if (size > b.size)
        return 1;
    if (size < b.size)
        return 0;
    for (i = size - 1; i >= 0 ; --i) {
        if (num[i] == b.num[i])
            continue;
        if (num[i] > b.num[i])
            return 1;
        else
            return 0;
    }
    if (i < 0)
        return 0;
}

bool CHugeInteger::operator <(const CHugeInteger & b) const {
    if (!(*this > b) && !(*this == b))
        return 1;
    else
        return 0;
}

ostream & operator << (ostream & out , const CHugeInteger & _num) {
        for (int i = _num.size - 1; i >= 0 ; --i)
            out << _num.num[i];
        return out;
}

istream & operator >> (istream & in, CHugeInteger & _num) {
    string number;
    in >> number;
    _num.size = number.length();
    _num.num = new int[_num.size];
    for (int i = 0; i < _num.size ; i++)
        _num.num[i] = number[_num.size - i - 1] - '0';
    return in;
}
