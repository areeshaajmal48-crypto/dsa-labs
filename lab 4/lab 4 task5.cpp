#include <iostream>
using namespace std;

class PrintQueue {
private:
    string* arr;
    int frontIndex;
    int rearIndex;
    int size;
    int capacity;

public:
    PrintQueue(int cap) {
        capacity = cap;
        arr = new string[capacity];
        frontIndex = 0;
        rearIndex = -1;
        size = 0;
    }

    void enqueue(string document_name) {
        if (size == capacity) {
            cout << "Printer queue is full\n";
            return;
        }

        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = document_name;
        size++;

        cout << "Added: " << document_name << endl;
    }

    void dequeue() {
        if (size == 0) {
            cout << "No documents to print\n";
            return;
        }

        string doc = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        size--;

        cout << "Printing: " << doc << endl;
    }

    void front() {
        if (size == 0) {
            cout << "No documents in queue\n";
            return;
        }

        cout << "Next document: " << arr[frontIndex] << endl;
    }

    void display() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Pending print jobs: ";
        int i = frontIndex;

        for (int count = 0; count < size; count++) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }

    ~PrintQueue() {
        delete[] arr;
    }
};

int main() {
    int cap;
    cout << "Enter maximum number of print jobs: ";
    cin >> cap;

    PrintQueue pq(cap);

    int choice;
    string name;

    do {
        cout << "\n1. Add Print Job\n2. Print Document\n3. View Next Document\n4. Display Queue\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter document name: ";
            cin >> name;
            pq.enqueue(name);
        }
        else if (choice == 2) {
            pq.dequeue();
        }
        else if (choice == 3) {
            pq.front();
        }
        else if (choice == 4) {
            pq.display();
        }

    } while (choice != 5);

    return 0;
}