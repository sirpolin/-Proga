#include <iostream>
#include <string>
#include <deque>

using namespace std;

void ok () {
    cout << "ok" << endl;
}

void error() {
    cout << "error" << endl;
}

int main () {
    string manip;
    deque <long long> deq;
    long long num;
    while (true) {
        cin >> manip;
        switch (manip[1]) {
        case 'u':
            cin >> num;
            if (manip[6] == 'r') {
                deq.push_front(num);
                ok();
            } else {
                deq.push_back(num);
                ok();
            }
            break;
        case 'o':
            if (deq.empty()) {
                error();
                break;
            }
            if (manip[5] == 'r') {
                cout << deq.front() << endl;
                deq.pop_front();
            } else {
                cout << deq.back() << endl;
                deq.pop_back();
            }
            break;
        case 'r':
            if (deq.empty())
                error();
            else
                cout << deq.front() << endl;
            break;
        case 'a':
            if (deq.empty())
                error();
            else
                cout << deq.back() << endl;
            break;
        case 'i':
            cout << deq.size() << endl;
            break;
        case 'l':
            deq.clear();
            ok();
            break;
        case 'x':
            cout << "bye";
            return 0;
        }
    }
    return 0;
}
