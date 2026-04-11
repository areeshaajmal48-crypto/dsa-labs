#include <iostream>
using namespace std;

class Node {
public:
    string name;
    int priority;
    Node* next;

    Node(string n, int p) {
        name = n;
        priority = p;
        next = NULL;
    }
};

class BookQueue {
    Node* head;
    string bookName;

public:
    BookQueue(string b) {
        bookName = b;
        head = NULL;
    }

    void addStudent(string n, int p) {
        Node* newNode = new Node(n, p);

        if (head == NULL || p > head->priority) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* t = head;
        while (t->next != NULL && t->next->priority >= p) {
            t = t->next;
        }

        newNode->next = t->next;
        t->next = newNode;
    }

    void removeStudent(string n) {
        if (head == NULL) return;

        if (head->name == n) {
            Node* t = head;
            head = head->next;
            delete t;
            return;
        }

        Node* curr = head;
        Node* prev = NULL;

        while (curr != NULL && curr->name != n) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL) return;

        prev->next = curr->next;
        delete curr;
    }

    void updatePriority(string n, int newP) {
        removeStudent(n);
        addStudent(n, newP);
    }

    void serveStudent() {
        if (head == NULL) {
            cout << "No students waiting for " << bookName << endl;
            return;
        }

        cout << "Serving: " << head->name << " for " << bookName << endl;
        Node* t = head;
        head = head->next;
        delete t;
    }

    void display() {
        cout << "\nBook: " << bookName << endl;

        if (head == NULL) {
            cout << "No reservations\n";
            return;
        }

        Node* t = head;
        while (t != NULL) {
            cout << t->name << "(P" << t->priority << ") -> ";
            t = t->next;
        }
        cout << "NULL\n";
    }

    void count() {
        int c = 0;
        Node* t = head;

        while (t != NULL) {
            c++;
            t = t->next;
        }

        cout << "Total students for " << bookName << ": " << c << endl;
    }
};

int main() {
    BookQueue b1("Data Structures");
    BookQueue b2("Operating Systems");

    b1.addStudent("Ali", 2);
    b1.addStudent("Sara", 3);
    b1.addStudent("Ahmed", 1);

    b2.addStudent("Ayesha", 2);
    b2.addStudent("Usman", 3);

    b1.display();
    b2.display();

    b1.count();
    b2.count();

    b1.updatePriority("Ali", 5);

    cout << "\nAfter updating priority:\n";
    b1.display();

    b2.removeStudent("Usman");

    cout << "\nAfter cancellation:\n";
    b2.display();

    b1.serveStudent();

    cout << "\nAfter serving first student:\n";
    b1.display();

    return 0;
}