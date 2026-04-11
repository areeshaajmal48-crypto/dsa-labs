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

    void insertAtBeginning(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }

    void insertAtEnd(int val) {
        Node* n = new Node(val);

        if (head == NULL) {
            head = n;
            return;
        }

        Node* t = head;
        while (t->next != NULL) {
            t = t->next;
        }
        t->next = n;
    }

    void deleteByValue(int val) {
        if (head == NULL) {
            cout << "Empty list\n";
            return;
        }

        if (head->data == val) {
            Node* t = head;
            head = head->next;
            delete t;
            return;
        }

        Node* curr = head;
        Node* prev = NULL;

        while (curr != NULL && curr->data != val) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "Not found\n";
            return;
        }

        prev->next = curr->next;
        delete curr;
    }

    void display() {
        Node* t = head;

        if (t == NULL) {
            cout << "Empty list\n";
            return;
        }

        while (t != NULL) {
            cout << t->data << " -> ";
            t = t->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList l;

    l.insertAtBeginning(10);
    l.insertAtBeginning(5);
    l.insertAtEnd(20);
    l.insertAtEnd(30);

    l.display();

    l.deleteByValue(20);

    l.display();

    return 0;
}
