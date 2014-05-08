#include <iostream>

using namespace std;

template <class Type>
void my_swap(Type & a, Type & b) {
    Type tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int a, b;
    cin >> a >> b;
    my_swap(a, b);
    cout << a << " " << b;
    return 0;
}

template <typename T>
class Point {
    T x, y;
public:
    Point T(T a, T b): x(a), y(b) {}
    void Draw () const;
};
template <typename T>
void Point::Draw() const {

}
