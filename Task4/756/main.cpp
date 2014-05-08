#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector <int> arr (n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    map <int, int> m;
    for (int i = 0; i < k; ++i)
        if (m.find(arr[i]) != m.end())
            m.find(arr[i])->second++;
        else
            m.insert(pair <int, int> (arr[i], 1));

    cout << m.begin()->first << '\n';

    for (int i = 0, j = k; j < n; ++i, ++j) {
        if (m.find(arr[i])->second == 1)
            m.erase(m.find(arr[i])->first);
        else
            m.find(arr[i])->second--;
        if (m.find(arr[j]) == m.end())
            m.insert(pair <int, int> (arr[j], 1));
        else
            m.find(arr[j])->second++;

        cout << m.begin()->first << '\n';
    }
    return 0;
}
