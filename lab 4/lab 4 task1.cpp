#include <iostream>
using namespace std;

template <typename T>
class AbstractQueue {
public:
    virtual void enQueue(T value) = 0;
    virtual T deQueue() = 0;
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractQueue() {}
};

template <typename T>
class myQueue : public AbstractQueue<T> {
private:
    T* arr;
    int frontIndex;
    int rearIndex;
    int size;
    int capacity;

public:
    myQueue(int cap) {
        capacity = cap;
        arr = new T[capacity];
        frontIndex = 0;
        rearIndex = -1;
        size = 0;
    }

    void enQueue(T value) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = value;
        size++;
    }

    T deQueue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        T value = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        size--;
        return value;
    }

    T front() const {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[frontIndex];
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        int i = frontIndex;
        for (int count = 0; count < size; count++) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }

    ~myQueue() {
        delete[] arr;
    }
};

int main() {
    int cap;
    cout << "Enter queue size: ";
    cin >> cap;

    myQueue<int> q(cap);

    int choice, value;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Front\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            q.enQueue(value);
        }
        else if (choice == 2) {
            cout << "Removed: " << q.deQueue() << endl;
        }
        else if (choice == 3) {
            cout << "Front: " << q.front() << endl;
        }
        else if (choice == 4) {
            q.display();
        }

    } while (choice != 5);

    return 0;
}