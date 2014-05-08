#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct my_pair {
    int id;
    int count;
    my_pair(int _id, int _count) : id(_id), count(_count) {}

    bool operator < (const my_pair & a) const {
        if (this->id < a.id)
            return true;
        return false;
    }
};

istream & operator >> (istream & in, my_pair & src) {
    int _id, _count;
    in >> _id >> _count;
    src.id = _id;
    src.count = _count;
    return in;
}

bool Less (const my_pair & a, const my_pair & b) {
    if (a.count > b.count)
        return true;
    return false;
}

int main() {/*
    int n;
    cin >> n;
    vector <my_pair> a;
    my_pair tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        a.push_back(my_pair(tmp_id, tmp_count));
    }
    sort(a.begin(), a.end());
    vector <my_pair> :: iterator it = a.begin() + 1, res = a.begin();
    while (it != a.end()) {
        if (res->id == it-> id)
            res->count += it->count;
        else {
            res++;
            res->id = it->id;
            res->count = it->count;
        }
        it++;
    }
    res++;
    sort(a.begin(), res, Less);
    for (int i = 0; i < 3; ++i)
        cout << a[i].id << ' ' << a[i].count << endl;*/
    vector <int> ololo (5,2);
    cout << endl << sizeof(ololo);
    return 0;
}

