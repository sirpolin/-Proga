#include "Book.h"

void Book::add_new (string name, my_int number, string email /*= "null"*/) {
    Abonent tmp;
    tmp.Name = name;
    tmp.Numbers.insert(number);
    tmp.Email = email;
    Names.insert(pair  <string, Abonent> (name, tmp));
    Numbers.insert(pair <my_int, string> (number, name));
}
void Book::output_all () const {
    for (map <string, Abonent> :: const_iterator it = Names.begin(); it != Names.end(); ++it) {
            cout << it->second.Name << " ";
            for (set <my_int> :: iterator it_2 = it->second.Numbers.begin(); it_2 != it->second.Numbers.end(); ++it_2) {
                cout << *it_2 << " ";
            }
            if (it->second.Email != "null")
                cout << it->second.Email;
            cout << endl;
    }
}
void Book::output_pairs() const {
    for (map <my_int, string> :: const_iterator it = Numbers.begin(); it != Numbers.end(); ++it) {
        cout << it->second << " " << it->first << endl;
    }
}

void Book::add_number (string name, my_int number) {
    if (Names.find(name) == Names.end())
        cout << "Error. This name (" << name << ") was not found" << endl;
    else {
        Names.find(name)->second.Numbers.insert(number);
        Numbers.insert(pair <my_int, string> (number, name));
    }
}
void Book::replace_number(string name, my_int old_number, my_int new_number) {
    if (Names.find(name) == Names.end())
        cout << "Error. This name (" << name << ") was not found" << endl;
    else
        if (Numbers.find(old_number) == Numbers.end())
            cout << "Error. This number (" << old_number << ") was not found" << endl;
        else {
            Numbers.erase(old_number);
            Names.find(name)->second.Numbers.erase(old_number);
            this->add_number(name, new_number);
        }
}
void Book::find_name(my_int number) const {
    if (Numbers.find(number) == Numbers.end())
        cout << "Error. This number (" << number << ") was not found" << endl;
    else
        cout << Numbers.find(number)->second << endl;
}
void Book::find_number(string name) const {
    if (Names.find(name) == Names.end())
        cout << "Error. This name (" << name << ") was not found" << endl;
    else {
        for (set <my_int> :: iterator it = Names.find(name)->second.Numbers.begin();
             it != Names.find(name)->second.Numbers.end(); ++it)
            cout << *it << " ";
        }
        cout << endl;
}
void Book::del_abonent(string name) {
    if (Names.find(name) == Names.end())
        cout << "Error. This name (" << name << ") was not found" << endl;
    else {
        while (Numbers.find(*Names.find(name)->second.Numbers.begin()) != Numbers.end())
            Numbers.erase(*Names.find(name)->second.Numbers.begin());
        Names.erase(name);
    }
}

void Book::del_number(string name, my_int number) {
    if (Names.find(name) == Names.end())
        cout << "Error. This name (" << name << ") was not found" << endl;
    else
        if (Numbers.find(number) == Numbers.end())
            cout << "Error. This number (" << number << ") was not found" << endl;
        else {
            Numbers.erase(number);
            Names.find(name)->second.Numbers.erase(number);
        }
}

