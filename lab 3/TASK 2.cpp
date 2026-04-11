#include <iostream>
using namespace std;

template <typename T>
class AbstractStack {
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractStack() {}
};

template <typename T>
class myStack : public AbstractStack<T> {
private:
    T* stackArr;
    T* minArr;
    int size;
    int topPos;
    int minPos;

public:
    myStack(int s) {
        size = s;
        stackArr = new T[size];
        minArr = new T[size];
        topPos = -1;
        minPos = -1;
    }

    void push(T value) {
        if (isFull()) {
            cout << "Stack is full\n";
            return;
        }

        topPos++;
        stackArr[topPos] = value;

        if (minPos == -1 || value <= minArr[minPos]) {
            minPos++;
            minArr[minPos] = value;
        }

        cout << value << " added to stack\n";
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return T();
        }

        T removed = stackArr[topPos];
        topPos--;

        if (removed == minArr[minPos]) {
            minPos--;
        }

        return removed;
    }

    T top() const {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return T();
        }
        return stackArr[topPos];
    }

    bool isEmpty() const {
        return topPos == -1;
    }

    bool isFull() const {
        return topPos == size - 1;
    }

    T getMin() const {
        if (minPos == -1) {
            cout << "Stack is empty\n";
            return T();
        }
        return minArr[minPos];
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack (top to bottom): ";
        for (int i = topPos; i >= 0; i--) {
            cout << stackArr[i] << " ";
        }
        cout << endl;
    }

    ~myStack() {
        delete[] stackArr;
        delete[] minArr;
    }
};

int main() {
    int s;
    cout << "Enter stack size: ";
    cin >> s;

    myStack<int> st(s);

    int choice, value;

    do {
        cout << "\n1. Push element\n";
        cout << "2. Pop element\n";
        cout << "3. Show top element\n";
        cout << "4. Check empty\n";
        cout << "5. Check full\n";
        cout << "6. Display stack\n";
        cout << "7. Show minimum element\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            st.push(value);
            break;

        case 2:
            cout << "Removed: " << st.pop() << endl;
            break;

        case 3:
            cout << "Top: " << st.top() << endl;
            break;

        case 4:
            cout << (st.isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
            break;

        case 5:
            cout << (st.isFull() ? "Stack is full\n" : "Stack is not full\n");
            break;

        case 6:
            st.display();
            break;

        case 7:
            cout << "Minimum: " << st.getMin() << endl;
            break;
        }

    } while (choice != 8);

    cout << "Program ended\n";
    return 0;
}