#include "Matrix.h"

int main() {
    int na, ma, nb, mb;
    double k;
    cout << "Input number of lines in matrix A" << endl;
    cin >> na;
    cout << "Input number of columns in matrix A" << endl;
    cin >> ma;
    cout << "Input number of lines in matrix B" << endl;
    cin >> nb;
    cout << "Input number of columns in matrix B" << endl;
    cin >> mb;
    cout << "Input the multiplier k" << endl;
    cin >> k;
    cout << "Matrix A:" << endl;
    Matrix a(na, ma);
    cout << endl;
    cout << "Matrix B:" << endl;
    Matrix b(nb, mb), c(na ,mb, false);
    cout << endl;
    cout << "Det A: " << endl;
    double det = a.Det();
    cout << (abs(det) == 0 ? 0 : det);
    cout << "Trace A:" << endl;
    cout << a.Trace() << endl;
    cout << "Transpose A: " << endl;
    (a.Transpose()).Print();
    cout << "Invertible A: " << endl;
    (a.InvertibleMatrix()).Print();
    c = a + b;
    cout << "A + B =" <<endl;
    c.Print();
    c = a - b;
    cout << "A - B =" << endl;
    c.Print();
    c = a * b;
    cout << "A * B =" << endl;
    c.Print();
    Matrix g(na, ma, false);
    g = a * k;
    cout << "A * k = "<<endl;
    g.Print();
    return 0;
}
