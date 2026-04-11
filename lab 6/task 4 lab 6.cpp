#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string n) {
        name = n;
        next = NULL;
    }
};

class PatientList {
    Node* head;

public:
    PatientList() {
        head = NULL;
    }

    void addPatient(string n) {
        Node* newNode = new Node(n);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* t = head;
        while (t->next != NULL) {
            t = t->next;
        }
        t->next = newNode;
    }

    void removePatient(string n) {
        if (head == NULL) {
            cout << "No patients\n";
            return;
        }

        if (head->name == n) {
            Node* t = head;
            head = head->next;
            delete t;
            cout << "Patient removed\n";
            return;
        }

        Node* curr = head;
        Node* prev = NULL;

        while (curr != NULL && curr->name != n) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "Patient not found\n";
            return;
        }

        prev->next = curr->next;
        delete curr;
        cout << "Patient removed\n";
    }

    void display() {
        if (head == NULL) {
            cout << "No patients in queue\n";
            return;
        }

        Node* t = head;
        cout << "Queue: ";
        while (t != NULL) {
            cout << t->name << " -> ";
            t = t->next;
        }
        cout << "NULL\n";
    }

    void countPatients() {
        Node* t = head;
        int count = 0;

        while (t != NULL) {
            count++;
            t = t->next;
        }

        cout << "Total patients: " << count << endl;
    }
};

int main() {
    PatientList p;

    p.addPatient("Ali");
    p.addPatient("Sara");
    p.addPatient("Ahmed");
    p.addPatient("Ayesha");

    p.display();
    p.countPatients();

    p.removePatient("Sara");

    p.display();
    p.countPatients();

    return 0;
}