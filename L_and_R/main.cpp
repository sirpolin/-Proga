#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    unsigned int n;
    cin >> n;
    vector <int> array(n);
    for (unsigned int i = 0; i < n; ++i)
        cin >> array[i];
    unsigned int m;
    cin >> m;
    vector <int> result;
    deque <int> deq;
    deq.push_back(array[0]);
    unsigned int r = 0;
    unsigned int l = 0;

    for (unsigned int i = 0; i < m; ++i) {
        char c;
        cin >> c;
        if (c == 'R') {
            ++r;
            while (deq.size() > 0 && array[r] >= deq.back())
                deq.pop_back();
            deq.push_back(array[r]);
            result.push_back(deq.front());
        }
        if (c == 'L') {
            if (array[l] >= deq.front() && deq.size() != 1) deq.pop_front();
            ++l;
            result.push_back(deq.front());
        }
    }
    for (unsigned int i = 0; i < result.size(); ++i)
        cout << result[i] << ' ';
    return 0;
}
