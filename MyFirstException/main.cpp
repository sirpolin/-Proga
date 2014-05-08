#include <iostream>
#include <exception>

using namespace std;

class BadSize: public exception {
public:
    const char* what () const throw () {
        return "So, your size is too much big";
    }
};

class BadIndex: public exception {
public:
    const char* what () const throw () {
        return "So, your index is too much bad";
    }
};

const unsigned int max_size = 100;
class IntArray {
private:
    int * num;
    unsigned int size;
public:
    IntArray (int _size) {
        if (_size <= 0 || _size > max_size)
            throw BadSize();
        num = new int [size = _size];
    }
    int & operator [] (int i) {
        if (i < 0 || i > size - 1)
            throw BadIndex();
        return *(num + i);
    }
    const int & operator [] (int i) const {
        if (i < 0 || i > size - 1)
            throw BadIndex();
        return *(num + i);
    }
};

int main() {
    IntArray arr(101);
    cout << arr[10024];
    arr.num[i];
    return 0;
}

