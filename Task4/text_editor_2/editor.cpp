#include "editor.h"

Editor::Editor()
{
}
void Editor::add_symbol(const char & src) {
    if (current_text.empty()) {
        string tmp_string;
        tmp_string += src;
        Text tmp (src);
        current_text.push(tmp);
    }
    else {
        Text tmp = current_text.top();
        tmp.current_column++;
        *(tmp.current_string) += src;
        if (src == '\n') {
            tmp.current_column = 0;
            string tmp_str;
            tmp.current_string = tmp.storage.insert(tmp.current_string, tmp_str);
        }
        current_text.push(tmp);
    }
}


void Editor::move_left() {
    Text tmp = current_text.top();
    if (tmp.current_column == 0 && tmp.current_string != tmp.storage.begin()) {
        tmp.current_string--;
        tmp.current_column = tmp.current_string->size();
    }
    if (tmp.current_column != 0)
        tmp.current_column--;
    current_text.push(tmp);
}

void Editor::move_right() {
    Text tmp = current_text.top();
    list <string> :: iterator last_str = --tmp.storage.end();
    if (tmp.current_column == tmp.current_string->size() && tmp.current_string != last_str) {
        tmp.current_string++;
        tmp.current_column = 0;
    }
    if (tmp.current_column != tmp.current_string->size())
        tmp.current_column++;
    current_text.push(tmp);
}

void Editor::move_up() {
    Text tmp = current_text.top();
    if (tmp.current_string != tmp.storage.begin()) {
        list <string> :: iterator prev_str = tmp.current_string;
        --prev_str;
        if (tmp.current_column > prev_str->size()) {
            tmp.current_string = prev_str;
            tmp.current_column = prev_str->size();
        } else {
            tmp.current_string = prev_str;
        }
    }
    current_text.push(tmp);
}

void Editor::move_down() {
    Text tmp = current_text.top();
    list <string> :: iterator last_str = tmp.storage.end();
    --last_str;
    if (tmp.current_string != last_str) {
        list <string> :: iterator next_str = tmp.current_string;
        ++next_str;
        if (tmp.current_column > next_str->size()) {
            tmp.current_string = next_str;
            tmp.current_column = next_str->size();
        } else {
            tmp.current_string = next_str;
        }
    }
    current_text.push(tmp);
}

void Editor::output_text () const {
    Text beg = current_text.top();
    for (list <string> :: iterator it = beg.storage.begin(); it != beg.storage.end(); ++it) {
        for (unsigned int i = 0; i < it->size(); ++i) {
            if (it == beg.current_string && i == beg.current_column)
                cout << "\x1b[32;1m" << (*it)[i];
            else
                cout << "\x1b[0m" << (*it)[i];
        }
    }
    cout << endl;
}
