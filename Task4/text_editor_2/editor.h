#ifndef EDITOR_H
#define EDITOR_H

#include "text.h"
#include <stack>
class Editor
{
    stack <Text> current_text;
    stack <Text> buffer;
public:
    Editor();
    void add_symbol (const char &);
    void move_left ();
    void move_right();
    void move_up();
    void move_down();
    void delete_symbol();
    void drop_buffer();
    void undo();
    void redo();
    void output_text () const;

};

#endif // EDITOR_H
