#include <iostream>
#include <map>
#include <list>
#include <stdio.h>

using namespace std;

int main() {
    unsigned int m;
    scanf("%u", &m);
    int tmp;
    map <int, list <int> :: iterator> um;
    list <int> l;
    unsigned int sizeof_list = 0;
    while (1) {
        scanf("%d", &tmp);
        if (feof(stdin))
            return 0;
        map <int, list <int> :: iterator> :: iterator iter = um.find(tmp);
        if (iter == um.end()) {
            printf("%d ", 1);
            if (sizeof_list < m) {
                l.push_front(tmp);
                um.insert(pair <int, list <int> :: iterator> (tmp, l.begin()));
                ++sizeof_list;
            } else {
                um.erase(*(--l.end()));
                l.pop_back();
                l.push_front(tmp);
                um.insert(pair <int, list <int> :: iterator> (tmp, l.begin()));
            }
        } else {
            printf("%d ", 0);
            l.erase(iter->second);
            l.push_front(tmp);
            iter->second = l.begin();
        }

    }
    return 0;
}
