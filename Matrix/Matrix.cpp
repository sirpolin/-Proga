#include "Matrix.h"

Matrix::Matrix(const int & _n, const int & _m, bool p) {
    exist = true;
    n = _n;
    m = _m;
    a = new double * [n];
    for (int i = 0; i < n; ++i)
        a[i] = new double[m];
    if (p) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];
    } else {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                a[i][j] = 0;
    }
}

Matrix::Matrix(const Matrix & M) {
    n = M.n;
    m = M.m;
    a = new double * [n];
    for (int i = 0; i < n; ++i)
        a[i] = new double[m];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            a[i][j] = M.a[i][j];
}

//

Matrix & Matrix:: operator = (const Matrix & M) {
    if (this == &M)
        return *this; //
    for (int i = 0; i < n; ++i)
        delete [] a[i];
    delete []a;
    n = M.n;
    m = M.m;
    a = new double * [n];
    for (int i = 0; i < n; ++i)
        a[i] = new double[m];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            a[i][j] = M.a[i][j];
    return *this;
}



Matrix Matrix::operator + (const Matrix & M) const {
    Matrix temp(n, m, false);
    if (n == M.n && m == M.m) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                temp.a[i][j] = a[i][j] + M.a[i][j];
    }
    else
        temp.exist = false;
    return temp;
}

Matrix Matrix::operator - (const Matrix & M) const {
    Matrix temp(n, m, false);
    if (n == M.n && m == M.m) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                temp.a[i][j] = a[i][j] - M.a[i][j];
    }
    else
        temp.exist = false;
    return temp;
}

Matrix Matrix::operator * (const Matrix & M) const {
    int k;
    Matrix temp(n, M.m, false);
    if (m == M.n) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < M.m; ++j)
                for (k = 0, temp.a[i][j] = 0; k < m; ++k)
                    temp.a[i][j] += a[i][k] * M.a[k][j];
    }
    else
        temp.exist = false;
    return temp;
}

Matrix Matrix::operator * (const double & M) const {
    Matrix temp(n, m, false);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            temp.a[i][j] = a[i][j] * M;
    temp.exist = true;
    return temp;
}

double Matrix::Det() const {
    if ((n != m) || !exist) {
        cerr << "error" <<endl;
        return 0;
    }
    Matrix temp(n, n, false);
    temp = *this;
    double det = 1;
    int j, count = 1;
    for (int i = 0; i < n - 1; ++i) {
        for (j = i; j < n; ++j)
            if (temp.a[j][i] != 0)
                break;
        if (j == n)
            return 0;
        else
            if (i != j) {
                count *= (-1);
                temp = temp.ExchangeRow(i, j);
            }
            det *= temp.a[i][i];
            for (j = i + 1; j < n; ++j) {
                double mul = temp.a[j][i] / temp.a[i][i];
                for (int k = i + 1; k < n; ++k)
                    temp.a[j][k] -= temp.a[i][k] * mul;
            }
    }
    return det * temp.a[n-1][n-1] * count;
}

Matrix Matrix::Transpose() const {
    Matrix temp(m, n, false);
    if (exist) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                temp.a[i][j] = a[j][i];
    }
    else
        temp.exist = false;
    return temp;         //
}

double Matrix::Trace() const {
    if ((n != m) || !exist) {
        cerr <<"error"<<endl;
        return 0;
    }
    double sum = 0;
    int i, j;
    if (exist) {
        for (i = 0, j = 0; i < n, j < m; ++i, ++j)
            sum += a[i][j];
    }
    return sum;
}

Matrix Matrix::InvertibleMatrix() {
    if (n != m || !exist || !(this->Det())) {
        cerr << "error" << endl;
        this->exist = false;
        return *this;
    }
    Matrix temp(n, n, false);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            temp.a[i][j] = this->Minor(i, j);

    }
    return (temp.Transpose()) * (1 / this->Det());
}

Matrix Matrix::ExchangeRow(const int & l, const int & k) {
    double *Arr = new double[m];
    for (int i = 0; i < m; ++i) {
        Arr[i] = a[k][i];
        a[k][i] = a[l][i];
        a[l][i] = Arr[i];
    }
    return *this;
}

double Matrix::Minor(const int & k, const int & b) {
    Matrix temp(n - 1, n - 1, false);
    int count1 = 0, count2 = 0;
    for (int i = 0; i < temp.n; ++i) {
        if (i == k)
            count1++;
        for (int j = 0; j < temp.m; ++j) {
            if (j == b)
                count2++;
            temp.a[i][j] = a[i + count1][j + count2];
        }
        count2 = 0;
    }
    if ((k + b) % 2)
        return (-1) * temp.Det();
    return temp.Det();
}

void Matrix::Print() const {
    if (exist) {
        for (int i = 0; i < n; ++i)  {
            for (int j = 0; j < m; ++j)
                cout << a[i][j]<< " ";
            cout << endl;
        }
    }
    else
        cout << "No Matrix" << endl;
    cout << endl;
}

Matrix::~Matrix() {
    for (int i = 0; i < n; ++i)
        delete [] a[i];
    delete []a;
}
