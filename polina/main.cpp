#include <iostream>
#include <set>
using namespace std;


int main () {
    int n, steps;
    cin >> n >> steps;
    int temp = steps;
    int *arr = new int [n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    multiset <int> my_multiset;
    multiset <int>::iterator it;

    for (int i = 0; i < steps; ++i) {
        my_multiset.insert(arr[i]);
    }
    cout << *my_multiset.begin() << '\n';

    it = my_multiset.find(arr[0]);
    if (it != my_multiset.end()) {
        my_multiset.erase(it);
    }

    while (steps != n) {
        my_multiset.insert(arr[steps]);

        cout << *my_multiset.begin() << '\n';
        if (steps != n - 1) {
            it = my_multiset.find(arr[steps - temp + 1]);
            if (it != my_multiset.end()) {
                my_multiset.erase(it);
            }
        }

        steps++;
    }
    return 0;
}
