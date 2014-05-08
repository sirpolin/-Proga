#include <iostream>
#include <set>

using namespace std;

int main() {
    set <int> s;
    int tmp;
    const int max_num = 1000000000;
    char manip;
    unsigned int n;
    cin >> n;
    bool flag = true;
    int last;
    for (unsigned int i = 0; i < n; ++i) {
        cin >> manip >> tmp;
        if (manip == '+') {
            if (flag) {
                s.insert(tmp);
            }
            else {
                s.insert((tmp + last) % max_num);
            }
            flag = true;
        } else {
            flag = false;
            if (s.lower_bound(tmp) != s.end())
               last = *s.lower_bound(tmp);
            else
               last = -1;
            cout << last << endl;
        }
    }
    return 0;
}

