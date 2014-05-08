#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <time.h>

using namespace std;

void action (int & a) {
    static int i = 0;
    a = i++;
}

int main() {
    int n;
    cin >> n;
    vector <int> v (n);


    time_t t = clock();
    for_each(v.begin(), v.end(), action);
    t = clock() - t;
    cout << "for_each: " << t << " clocks and " << (double) t / CLOCKS_PER_SEC << " seconds" << endl;

    copy(v.begin(), v.end(), ostream_iterator <int> (cout, " "));

    t = clock();
    for (vector <int> :: iterator it = v.begin(); it != v.end(); ++it)
        action(*it);
    t = clock() - t;
    cout << "for: " << t << " clocks and " << (double) t / CLOCKS_PER_SEC << " seconds" << endl;

    copy(v.begin(), v.end(), ostream_iterator <int> (cout, " "));
    return 0;
}

