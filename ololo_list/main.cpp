#include <iostream>
#include <stack>

using namespace std;

bool is_open (char a) {
    if (a == '(' || a == '[' || a == '{')
        return true;
    return false;
}

bool is_good (char a, char b) {
    if (a == '{' && b == '}' ||
        a == '[' && b == ']' ||
        a == '(' && b == ')')
        return true;
    return false;
}


int main () {
    char symbol;
    stack <int> a;
    while (cin >> symbol) {
        if (is_open(symbol))
            a.push(symbol);
        else {
            if (a.empty()) {
                cout << "no";
                return 0;
            }
            char tmp = a.top();
            a.pop();
            if(!is_good(tmp, symbol)) {
                cout << "no";
                return 0;
            }
        }
    }
    if(a.empty())
        cout << "yes";
    else
        cout << "no";
    return 0;
}
