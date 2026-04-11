#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertAtPosition(int val, int pos) {
        Node* n = new Node(val);

        if (pos == 1) {
            n->next = head;
            head = n;
            return;
        }

        Node* t = head;
        for (int i = 1; i < pos - 1 && t != NULL; i++) {
            t = t->next;
        }

        if (t == NULL) {
            cout << "Invalid position\n";
            return;
        }

        n->next = t->next;
        t->next = n;
    }

    void deleteAtPosition(int pos) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        if (pos == 1) {
            Node* t = head;
            head = head->next;
            delete t;
            return;
        }

        Node* t = head;
        for (int i = 1; i < pos - 1 && t != NULL; i++) {
            t = t->next;
        }

        if (t == NULL || t->next == NULL) {
            cout << "Invalid position\n";
            return;
        }

        Node* del = t->next;
        t->next = del->next;
        delete del;
    }

    void search(int val) {
        Node* t = head;
        int pos = 1;

        while (t != NULL) {
            if (t->data == val) {
                cout << "Found at position " << pos << endl;
                return;
            }
            t = t->next;
            pos++;
        }

        cout << "Not found\n";
    }

    void countNodes() {
        Node* t = head;
        int count = 0;

        while (t != NULL) {
            count++;
            t = t->next;
        }

        cout << "Total nodes: " << count << endl;
    }

    void display() {
        Node* t = head;

        while (t != NULL) {
            cout << t->data << " -> ";
            t = t->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList l;
    int choice, val, pos;

    do {
        cout << "\n1.Insert at position\n2.Delete at position\n3.Search\n4.Count nodes\n5.Display\n0.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value and position: ";
            cin >> val >> pos;
            l.insertAtPosition(val, pos);
            break;

        case 2:
            cout << "Enter position: ";
            cin >> pos;
            l.deleteAtPosition(pos);
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> val;
            l.search(val);
            break;

        case 4:
            l.countNodes();
            break;

        case 5:
            l.display();
            break;
        }

    } while (choice != 0);

    return 0;
}