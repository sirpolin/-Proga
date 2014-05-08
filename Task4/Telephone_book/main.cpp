#include "Book.h"

int main() {
    Book b;
    string n, e;
    n = "Polin";
    e = "Polin@phystech.edu";
    b.add_new(n, 9266745528, e);
    b.output_all();
    b.add_number(n, 9271140966);
    b.output_all();
    b.replace_number(n, 9266745528, 9288279037);
    b.output_all();
    cout << "----------------------------------" << endl;
    n = "Volodin";
    b.add_new(n, 9998881223);
    b.output_all();
    b.add_number(n, 1234567890);
    b.output_all();
    cout << "----------------------------------" << endl;
    b.find_name(9288279037);
    b.find_number(n);
    b.del_abonent(n);
    b.output_all();
    b.find_name(9271140966);
    cout << "----------------------------------" << endl;
    n = "Polin";
    b.del_number(n, 9288279037);
    b.output_all();
    return 0;
}

