#include <iostream>
using namespace std;

class TicketQueue {
private:
    int* arr;
    int frontIndex;
    int rearIndex;
    int size;
    int capacity;

public:
    TicketQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        frontIndex = 0;
        rearIndex = -1;
        size = 0;
    }

    void enqueue(int ticket_id) {
        if (size == capacity) {
            cout << "Queue is full\n";
            return;
        }

        if (ticket_id < 1000 || ticket_id > 9999) {
            cout << "Enter a valid 4-digit ticket ID\n";
            return;
        }

        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = ticket_id;
        size++;

        cout << "Ticket " << ticket_id << " added\n";
    }

    void dequeue() {
        if (size == 0) {
            cout << "No tickets to resolve\n";
            return;
        }

        int ticket = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        size--;

        cout << "Ticket " << ticket << " resolved\n";
    }

    void front() {
        if (size == 0) {
            cout << "No pending tickets\n";
            return;
        }

        cout << "Next ticket: " << arr[frontIndex] << endl;
    }

    void display() {
        if (size == 0) {
            cout << "No pending tickets\n";
            return;
        }

        cout << "Pending tickets: ";
        int i = frontIndex;

        for (int count = 0; count < size; count++) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }

    ~TicketQueue() {
        delete[] arr;
    }
};

int main() {
    int cap;
    cout << "Enter maximum number of tickets: ";
    cin >> cap;

    TicketQueue tq(cap);

    int choice, id;

    do {
        cout << "\n1. Add Ticket\n2. Resolve Ticket\n3. View Next Ticket\n4. Display All\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter 4-digit ticket ID: ";
            cin >> id;
            tq.enqueue(id);
        }
        else if (choice == 2) {
            tq.dequeue();
        }
        else if (choice == 3) {
            tq.front();
        }
        else if (choice == 4) {
            tq.display();
        }

    } while (choice != 5);

    return 0;
}