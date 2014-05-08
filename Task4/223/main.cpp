#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> arr (n);
    for (unsigned int i = 0; i < n; ++i)
        cin >> arr[i];
    int x;
    cin >> x;
    unsigned int count = 0;
    for (unsigned int i = 0; i < n; ++i)
        if (arr[i] == x)
            ++count;
    cout << count;
    return 0;
}

