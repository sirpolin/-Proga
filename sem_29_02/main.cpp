#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {

    /*
    int n;
    cin >> n;
    set <int> s;
    int tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        s.insert(tmp);
    }
    set <int> :: iterator it = s.begin();
    while  (it != s.end()) {
        cout << *it << " ";
        it++;/bin/bash
    }
    cout << endl;
    cout << s.count(1);
    */
    char s [] = "ABACABA\n";
    map <char, int> m;
    int i = 0;
    while (s[i] != '\n') {
        if (m.find(s[i]) != m.end())
            m.find(s[i])->second++;
        else
           m.insert(pair<char, int> (s[i], 1));
        i++;
    }
    map <char, int> :: iterator it = m.begin();
    while (it != m.end()) {
        cout << it->first << " " << it->second << endl;
        it++;
    }
    return 0;
}

