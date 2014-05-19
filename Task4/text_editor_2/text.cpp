#include "text.h"

Text::Text(const char & src)
{
    string tmp_str;
    tmp_str += src;
    storage.push_front(tmp_str);
    current_column = 1;
    current_string = storage.begin();
}
