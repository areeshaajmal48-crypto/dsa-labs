#include <iostream>
using namespace std;

class myCarStack {
private:
    string cars[8];
    int topPos;

public:
    myCarStack() {
        topPos = -1;
    }

    bool isEmpty() {
        return topPos == -1;
    }

    bool isFull() {
        return topPos == 7;
    }

    void push(string car) {
        if (isFull()) {
            cout << "Parking is full\n";
            return;
        }
        cars[++topPos] = car;
        cout << "Car " << car << " parked\n";
    }

    string pop() {
        if (isEmpty()) {
            return "";
        }
        return cars[topPos--];
    }

    string top() {
        if (isEmpty()) return "";
        return cars[topPos];
    }

    void display() {
        if (isEmpty()) {
            cout << "No cars parked\n";
            return;
        }

        cout << "Cars in parking (top to bottom):\n";
        for (int i = topPos; i >= 0; i--) {
            cout << cars[i] << endl;
        }
    }

    int count() {
        return topPos + 1;
    }

    bool search(string car) {
        for (int i = 0; i <= topPos; i++) {
            if (cars[i] == car)
                return true;
        }
        return false;
    }

    void removeCar(string car) {
        if (isEmpty()) {
            cout << "Parking is empty\n";
            return;
        }

        myCarStack temp;
        bool found = false;

        while (!isEmpty()) {
            string current = pop();

            if (current == car) {
                cout << "Car " << car << " removed\n";
                found = true;
                break;
            }
            else {
                temp.push(current);
            }
        }

        while (!temp.isEmpty()) {
            push(temp.pop());
        }

        if (!found) {
            cout << "Car not found\n";
        }
    }
};

int main() {
    myCarStack parking;
    int choice;
    string carNum;

    do {
        cout << "\n--- Parking Menu ---\n";
        cout << "1. Park new car\n";
        cout << "2. Remove car\n";
        cout << "3. Show parked cars\n";
        cout << "4. Total cars\n";
        cout << "5. Search car\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter car number: ";
            cin >> carNum;
            parking.push(carNum);
            break;

        case 2:
            cout << "Enter car number to remove: ";
            cin >> carNum;
            parking.removeCar(carNum);
            break;

        case 3:
            parking.display();
            break;

        case 4:
            cout << "Total cars: " << parking.count() << endl;
            break;

        case 5:
            cout << "Enter car number to search: ";
            cin >> carNum;
            if (parking.search(carNum))
                cout << "Car found\n";
            else
                cout << "Car not found\n";
            break;
        }

    } while (choice != 6);

    return 0;
}