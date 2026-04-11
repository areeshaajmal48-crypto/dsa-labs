#include <iostream>
using namespace std;

struct Package {
    int id;
    string address;
    int startTime;
    int endTime;
};

class DeliveryQueue {
private:
    Package* arr;
    int frontIndex;
    int rearIndex;
    int size;
    int capacity;

public:
    DeliveryQueue(int cap) {
        capacity = cap;
        arr = new Package[capacity];
        frontIndex = 0;
        rearIndex = -1;
        size = 0;
    }

    void enqueue(int id, string address, int start, int end) {
        if (size == capacity) {
            cout << "Queue is full\n";
            return;
        }

        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = { id, address, start, end };
        size++;

        cout << "Package " << id << " added\n";
    }

    void dequeue() {
        if (size == 0) {
            cout << "No packages to deliver\n";
            return;
        }

        cout << "Delivered Package ID: " << arr[frontIndex].id << endl;
        frontIndex = (frontIndex + 1) % capacity;
        size--;
    }

    void front() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return;
        }

        Package p = arr[frontIndex];
        cout << "Front Package -> ID: " << p.id
            << ", Address: " << p.address
            << ", Time Window: " << p.startTime << "-" << p.endTime << endl;
    }

    void timeToDeliver(int currentTime) {
        if (size == 0) {
            cout << "No packages\n";
            return;
        }

        Package p = arr[frontIndex];

        if (currentTime >= p.startTime && currentTime <= p.endTime) {
            cout << "Package " << p.id << " can be delivered now\n";
            dequeue();
        }
        else {
            cout << "Package " << p.id << " expired or not in time window, skipping...\n";
            dequeue();
        }
    }

    void display() {
        if (size == 0) {
            cout << "No packages in queue\n";
            return;
        }

        cout << "\nPending Packages:\n";
        int i = frontIndex;

        for (int count = 0; count < size; count++) {
            Package p = arr[i];
            cout << "ID: " << p.id
                << ", Address: " << p.address
                << ", Time: " << p.startTime << "-" << p.endTime << endl;

            i = (i + 1) % capacity;
        }
    }

    ~DeliveryQueue() {
        delete[] arr;
    }
};

int main() {
    int cap;
    cout << "Enter max number of packages: ";
    cin >> cap;

    DeliveryQueue dq(cap);

    int choice, id, start, end, currentTime;
    string address;

    do {
        cout << "\n1. Add Package\n2. Deliver Package\n3. View Front\n4. Check Time Delivery\n5. Display All\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Package ID: ";
            cin >> id;
            cout << "Enter Address: ";
            cin >> address;
            cout << "Enter Start Time: ";
            cin >> start;
            cout << "Enter End Time: ";
            cin >> end;

            dq.enqueue(id, address, start, end);
        }
        else if (choice == 2) {
            dq.dequeue();
        }
        else if (choice == 3) {
            dq.front();
        }
        else if (choice == 4) {
            cout << "Enter current time: ";
            cin >> currentTime;
            dq.timeToDeliver(currentTime);
        }
        else if (choice == 5) {
            dq.display();
        }

    } while (choice != 6);

    return 0;
}