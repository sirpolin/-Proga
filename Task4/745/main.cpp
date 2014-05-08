#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    set <string> s;
    char manip;
    string tmp;
    while (true) {
        cin >> manip;
        switch (manip) {
        case '+':
            cin >> tmp;
            s.insert(tmp);
            break;
        case '-':
            cin >> tmp;
            if (s.find(tmp) != s.end())
                s.erase(tmp);
            break;
        case '?':
            cin >> tmp;
            if (s.find(tmp) == s.end())
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
            break;
        case '#':
            return 0;
        }
    }
}

