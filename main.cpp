#include "buffer.h"
#include <iostream>

using namespace std;

/* Private function prototypes */
void ExecuteCommand(EditorBuffer & buffer, const string & line);

/* Main program */
int main() {
    EditorBuffer buffer;

    while (true) {
        cout << "*";
        string cmd;
        getline(cin, cmd);
        if (cmd != "") ExecuteCommand(buffer, cmd);
        buffer.display();
    }

    return 0;
}
/*
* Executes a single editor command.
*/
void ExecuteCommand(EditorBuffer & buffer, const string & line) {
    switch (toupper(line[0])) {
    case 'I': for (int i = 1; i < line.length(); i++) {
            buffer.insertCharacter(line[i]);
        }
        break;
    case 'R': buffer.deleteCharacter(); break;
    case 'F': buffer.moveCursorForward(); break;
    case 'B': buffer.moveCursorBackward(); break;
    case 'J': buffer.moveCursorToStart(); break;
    case 'E': buffer.moveCursorToEnd(); break;
    case 'U': buffer.moveCursorUp(); break;
    case 'D': buffer.moveCursorDown(); break;
    case 'Q': exit(0);
    default: cout << "Illegal command" << endl; break;
    }
}
