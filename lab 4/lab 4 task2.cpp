#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> s1;
    stack<int> s2;

public:
    void enqueue(int value) {
        s1.push(value);
        cout << "Inserted: " << value << endl;
    }

    int dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int val = s2.top();
        s2.pop();
        return val;
    }

    int front() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    void display() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return;
        }

        stack<int> temp1 = s1;
        stack<int> temp2 = s2;

        while (!temp1.empty()) {
            temp2.push(temp1.top());
            temp1.pop();
        }

        cout << "Queue elements: ";
        while (!temp2.empty()) {
            cout << temp2.top() << " ";
            temp2.pop();
        }
        cout << endl;
    }
};

int main() {
    QueueUsingStacks q;
    int choice, value;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Front\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
        }
        else if (choice == 2) {
            int x = q.dequeue();
            if (x != -1)
                cout << "Removed: " << x << endl;
        }
        else if (choice == 3) {
            int x = q.front();
            if (x != -1)
                cout << "Front: " << x << endl;
        }
        else if (choice == 4) {
            q.display();
        }

    } while (choice != 5);

    return 0;
}