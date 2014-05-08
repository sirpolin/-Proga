#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Text {
    vector <string> storage;
    unsigned int current_string;
    unsigned int current_column;
    Text () {
        current_string = 0;
        current_column = 0;
    }
};


class Editor {
    stack <Text> current_text;
    stack <Text> buffer;
public:
    void move_left () {
        drop_buffer();
        Text tmp = current_text.top();
        if (tmp.current_column > 0)
            tmp.current_column--;
        else {
            tmp.current_string--;
            tmp.current_column = tmp.storage[tmp.current_string].size() - 1;
        }

        current_text.push(tmp);
    }
    void move_right () {
        drop_buffer();
        Text tmp = current_text.top();
        if (tmp.current_column == tmp.storage[tmp.current_string].size() - 1) {
            tmp.current_column = 0;
            tmp.current_string++;
        } else {
            tmp.current_column++;
        }
        current_text.push(tmp);
    }
    void move_up () {
        drop_buffer();
        Text tmp = current_text.top();
        if (tmp.current_string > 0)
            if (tmp.storage[--tmp.current_string].size() < tmp.current_column)
                tmp.current_column = tmp.storage[tmp.current_string].size() - 1;
        current_text.push(tmp);
    }
    void move_down() {
        drop_buffer();
        Text tmp = current_text.top();
        if (tmp.current_string <= tmp.storage.size())
            if (tmp.storage[++tmp.current_string].size() < tmp.current_column)
             tmp.current_column = tmp.storage[tmp.current_string].size() - 1;
        current_text.push(tmp);
    }
    void delete_symbol () { ////TODO_CHECK_\n
        drop_buffer();
        Text tmp = current_text.top();
        if (tmp.storage[tmp.current_string].size() == 0) {
            tmp.storage.erase(tmp.storage.begin() + tmp.current_string);
            tmp.current_column = 0;
        } else
            tmp.storage[tmp.current_string].erase(tmp.current_column, 1);
        current_text.push(tmp);
    }
    void drop_buffer () {
        while(!buffer.empty())
            buffer.pop();
    }
    void undo () {
        if (current_text.size() == 1) {
            cout << "\x1b[31m" << "Nothing to undo" << endl << "\x1b[39;49m";
        } else {
        buffer.push(current_text.top());
        current_text.pop();
        }
    }
    void redo () {
        if (buffer.empty()) {
            cout << "\x1b[31m" << "Nothing to redo" << endl << "\x1b[39;49m";
        } else {
        current_text.push(buffer.top());
        buffer.pop();
        }
    }
    void input_file () {
        string tmp_string;
        Text tmp_text;
        ifstream fin ("input.txt");
        while (getline(fin, tmp_string)) {
            tmp_text.storage.push_back(tmp_string);
        }
        current_text.push(tmp_text);
    }
    void output_text () const {
        for (unsigned int i = 0; i < current_text.top().storage.size(); ++i) {
            for (unsigned int j = 0; j < current_text.top().storage[i].size(); ++j)
                if (i == current_text.top().current_string &&
                    j == current_text.top().current_column)
                    cout << "\x1b[32;1m" << current_text.top().storage[i][j];
                else
                    cout << "\x1b[39;49m" << current_text.top().storage[i][j];
            cout << endl;
        }
    }
};
