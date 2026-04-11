#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class MyQueue {
private:
    queue<int> q;

public:
    void enqueue(int value) {
        q.push(value);
    }

    int dequeue() {
        if (q.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int val = q.front();
        q.pop();
        return val;
    }

    int front() {
        if (q.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return q.front();
    }

    bool isEmpty() {
        return q.empty();
    }

    int size() {
        return q.size();
    }

    void display() {
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }

    void reverseFirstK(int k) {
        int n = q.size();

        if (k <= 1 || k > n) {
            return;
        }

        stack<int> s;

        for (int i = 0; i < k; i++) {
            s.push(q.front());
            q.pop();
        }

        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }

        for (int i = 0; i < n - k; i++) {
            q.push(q.front());
            q.pop();
        }
    }
};

int main() {
    MyQueue q;
    int n, value, k;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.enqueue(value);
    }

    cout << "Original Queue: ";
    q.display();

    cout << "Enter K: ";
    cin >> k;

    q.reverseFirstK(k);

    cout << "Updated Queue: ";
    q.display();

    return 0;
}