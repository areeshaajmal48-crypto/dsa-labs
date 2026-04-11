#include <iostream>
#include <stack>
using namespace std;

struct Action {
    char ch;
    string type; // "insert" or "delete"
};

class TextEditor {
private:
    string text;
    stack<Action> undoStack;
    stack<Action> redoStack;

public:
    void typeChar(char c) {
        text += c;

        Action act;
        act.ch = c;
        act.type = "insert";

        undoStack.push(act);

        while (!redoStack.empty()) redoStack.pop();

        cout << "Typed: " << c << endl;
    }

    void deleteChar() {
        if (text.empty()) {
            cout << "Nothing to delete\n";
            return;
        }

        char removed = text.back();
        text.pop_back();

        Action act;
        act.ch = removed;
        act.type = "delete";

        undoStack.push(act);

        while (!redoStack.empty()) redoStack.pop();

        cout << "Deleted: " << removed << endl;
    }

    void undo() {
        if (undoStack.empty()) {
            cout << "Nothing to undo\n";
            return;
        }

        Action last = undoStack.top();
        undoStack.pop();

        if (last.type == "insert") {
            text.pop_back();
        }
        else if (last.type == "delete") {
            text += last.ch;
        }

        redoStack.push(last);

        cout << "Undo done\n";
    }

    void redo() {
        if (redoStack.empty()) {
            cout << "Nothing to redo\n";
            return;
        }

        Action last = redoStack.top();
        redoStack.pop();

        if (last.type == "insert") {
            text += last.ch;
        }
        else if (last.type == "delete") {
            text.pop_back();
        }

        undoStack.push(last);

        cout << "Redo done\n";
    }

    void showText() {
        cout << "Current Text: " << text << endl;
    }
};

int main() {
    TextEditor editor;
    int choice;
    char ch;

    do {
        cout << "\n--- Text Editor Menu ---\n";
        cout << "1. Type character\n";
        cout << "2. Delete character\n";
        cout << "3. Undo\n";
        cout << "4. Redo\n";
        cout << "5. Show text\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter character: ";
            cin >> ch;
            editor.typeChar(ch);
            break;

        case 2:
            editor.deleteChar();
            break;

        case 3:
            editor.undo();
            break;

        case 4:
            editor.redo();
            break;

        case 5:
            editor.showText();
            break;
        }

    } while (choice != 6);

    return 0;
}