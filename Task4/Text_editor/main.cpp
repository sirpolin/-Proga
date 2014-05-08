#include "Text_editor.h"

int main() {
    Editor foo;
    foo.input_file();
    foo.output_text();
    char manip;
    while (cin >> manip) {
        switch (manip) {
        case '<':
            foo.move_left();
            break;
        case '>':
            foo.move_right();
            break;
        case '^':
            foo.move_up();
            break;
        case '|':
            foo.move_down();
            break;
        case '#':
            foo.delete_symbol();
            break;
        case '@':
            foo.undo();
            break;
        case '$':
            foo.redo();
            break;
        case '!':
            cout << "_____________________________________________________" << endl;
            cout << "\x1b[32;1mGoodbye! ^^\x1b[39;49m" << endl;
            return 0;
        }
        foo.output_text();
        cout << "_____________________________________________________" << endl;
    }
    cout << "Hello World!" << endl;
    return 0;
}

