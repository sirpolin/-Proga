#include <iostream>
#include <map>
#include <string>
#include <set>
#include <utility>

typedef unsigned long long my_int;

using namespace std;

struct Abonent {
    string Name;
    string Email;
    set <my_int> Numbers;
};

class Book {
public:
    map <string, Abonent> Names;
    map <my_int, string> Numbers;
    void add_new (string, my_int, string = "null");
    void output_all () const;
    void output_pairs() const;
    void add_number (string, my_int);
    void replace_number (string, my_int, my_int);
    void find_name (my_int) const;
    void find_number (string) const;
    void del_abonent (string);
    void del_number (string, my_int);
};
