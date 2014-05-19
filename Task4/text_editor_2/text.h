#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <list>
#include <iostream>

using namespace std;

class Text
{
public:
    list <string> storage;
    unsigned int current_column;
    list <string> :: iterator current_string;
    Text(const char &);
};

#endif // TEXT_H
