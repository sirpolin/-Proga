#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main() {
    multimap <int, string> s;
    //vector <pair <int, string> > v;
    pair <int, string> tmp;
    string tmp_str;
    while (getline(cin, tmp_str)) {
        int space = tmp_str.find(" ");
        tmp.first = atoi(tmp_str.substr(0, space).c_str());
        tmp_str.erase(0, space + 1);
        tmp.second = tmp_str;
        s.insert(tmp);
    }

    for (auto it = s.begin(); it != s.end(); ++it)
        cout << it->first << " " << it->second << endl;
    return 0;
}

