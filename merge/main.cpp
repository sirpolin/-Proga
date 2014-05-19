#include <vector>
#include <iostream>
#include <queue>
using namespace std;

struct my_class {
    vector <int> :: iterator Iter;
    int Position;
    bool operator < (const my_class& T) const {
        return *Iter > *T.Iter;
    }
    my_class(vector <int> :: iterator _iter, int _Position): Iter(_iter), Position(_Position) { }
    friend ostream & operator << (ostream & out, const my_class & T) {
        out << *T.Iter;
        return out;
    }
};

int main() {
    int N, M, temp, K;
    cin >> N >> M;
    priority_queue <my_class> The;
    vector <int>* Pointer = new vector <int>[N];
    vector <int> Not;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            cin >> temp;
            Pointer[i].push_back(temp);
        }
    for (int i = 0; i < N; ++i)
        The.push(my_class(Pointer[i].begin(), i));
    K = N * M;
    while (K--) {
        my_class it = The.top();
        Not.push_back(*it.Iter);
        The.pop();
        ++it.Iter;
        if (it.Iter != Pointer[it.Position].end())
            The.push(it);
    }
    for (vector <int> :: iterator iter = Not.begin(); iter != Not.end(); ++iter)
        cout << *iter << " ";
    return 0;
}
