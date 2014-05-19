#include <string>
#include <iostream>
#include <vector>

using namespace std;

int find_min(const string & str, const string & delim) {
    vector <int> v;
    for (int i = 0; i < delim.size(); ++i)
        v.push_back(str.find_first_of(delim[i]));
    int max = v[0];
    for (vector <int> :: iterator it = v.begin(); it != v.end(); ++it)
        if (*it > max)
            max = *it;
    int min = max;
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        if (*it < min && *it != -1)
            min = *it;
    return min;
}

unsigned split(const string& str, const string& delim, vector<string>& res) {
    res.clear();
    string cur;
    string tmp_str = str;
    int found = find_min(tmp_str, delim);
    while (found != -1) {
        cur = tmp_str;
        res.push_back(tmp_str.erase(found));
        tmp_str = cur.substr(found + 1);
        found = find_min(tmp_str, delim);
    }
    res.push_back(tmp_str);
    return res.size();
}

int main() {
    string str;
    string delim;
    getline(cin, str);
    getline(cin, delim);
    vector<string> v;
    cout << split(str, delim, v);
    cout << endl;
    for (vector <string> :: iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << endl;
    return 0;
}

