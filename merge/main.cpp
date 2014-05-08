#include <iostream>
#include <vector>
#include <utility>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector <vector <int> > a;
    a.reserve(n);
    for (int i = 0; i < n; ++i) {
        vector <int> tmp;
        int tmp_int;
        tmp.reserve(m);
        for (int j = 0; j < m; ++j) {
            cin >> tmp_int;
            tmp.push_back(move(tmp_int));
        }
        a.push_back(move(tmp));
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cout << a[i][j] << " ";
    return 0;
}
