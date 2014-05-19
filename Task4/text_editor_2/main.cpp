#include "editor.h"
#include <iostream>
#include <cstdio>

int main() {
    Editor foo;
    char input;
    while (scanf("%c", &input)) {
        switch (input) {
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
            //foo.delete_symbol();
            break;
        case '@':
            //foo.undo();
            break;
        case '$':
            //foo.redo();
            break;
        case '!':
            cout << "_____________________________________________________" << endl;
            cout << "\x1b[32;1mGoodbye! ^^\x1b[39;49m" << endl;
            return 0;
        default:
            foo.add_symbol(input);
            break;
        }
        foo.output_text();
        cout << "_____________________________________________________" << endl;
    }
    cout << "Hello World!" << endl;
    return 0;
}

