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
    T* data;
    int maxSize;
    int topIndex;

public:
    myStack(int size) {
        maxSize = size;
        data = new T[maxSize];
        topIndex = -1;
    }

    void push(T value) {
        if (isFull()) {
            cout << "Stack is full. Cannot insert element.\n";
            return;
        }
        topIndex++;
        data[topIndex] = value;
        cout << value << " pushed into stack.\n";
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to pop.\n";
            return T();
        }
        T removedValue = data[topIndex];
        topIndex--;
        return removedValue;
    }

    T top() const {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return T();
        }
        return data[topIndex];
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    bool isFull() const {
        return topIndex == maxSize - 1;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Stack elements (top to bottom): ";
        for (int i = topIndex; i >= 0; i--) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    ~myStack() {
        delete[] data;
    }
};

int main() {
    int size;
    cout << "Enter the size of stack: ";
    cin >> size;

    myStack<int> stack(size);

    int choice, value;

    do {
        cout << "\n------ Stack Menu ------\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. View Top\n";
        cout << "4. Check if Empty\n";
        cout << "5. Check if Full\n";
        cout << "6. Display Stack\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            stack.push(value);
            break;

        case 2:
            cout << "Popped value: " << stack.pop() << endl;
            break;

        case 3:
            cout << "Top element: " << stack.top() << endl;
            break;

        case 4:
            if (stack.isEmpty())
                cout << "Stack is empty.\n";
            else
                cout << "Stack is not empty.\n";
            break;

        case 5:
            if (stack.isFull())
                cout << "Stack is full.\n";
            else
                cout << "Stack is not full.\n";
            break;

        case 6:
            stack.display();
            break;
        }

    } while (choice != 0);

    cout << "Program ended.\n";
    return 0;
}