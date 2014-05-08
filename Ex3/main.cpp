#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> arr;
    arr.reserve(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int m;
    cin >> m;
    deque <int> deq;
    deq.push_back(arr[0]);
    int r = 0;
    int l = 0;

    for (int i = 0; i < m; i++) {
        char c;
        cin >> c;
        if (c == 'R') {
            r++;
            while (deq.size() > 0 && arr[r] >= deq.back())
                deq.pop_back();
            deq.push_back(arr[r]);
            cout << deq.front() << " ";
        }
        if (c == 'L') {
            if (arr[l] >= deq.front() && deq.size() != 1)
                deq.pop_front();
            l++;
            cout << deq.front() << " ";
        }
    }
    return 0;
}
