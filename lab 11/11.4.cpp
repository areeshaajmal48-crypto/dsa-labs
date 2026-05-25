#include <iostream>
using namespace std;

struct MyNode {
    int number;
    MyNode* leftPart;
    MyNode* rightPart;

    MyNode(int x) {
        number = x;
        leftPart = nullptr;
        rightPart = nullptr;
    }
};

MyNode* insertData(MyNode* root, int val) {

    if (root == nullptr) {
        return new MyNode(val);
    }

    if (val < root->number) {
        root->leftPart = insertData(root->leftPart, val);
    }
    else {
        root->rightPart = insertData(root->rightPart, val);
    }

    return root;
}

void display(MyNode* root) {

    if (root == nullptr)
        return;

    display(root->leftPart);
    cout << root->number << " ";
    display(root->rightPart);
}

int getMin(MyNode* root) {

    if (root->leftPart == nullptr)
        return root->number;

    return getMin(root->leftPart);
}

int getMax(MyNode* root) {

    if (root->rightPart == nullptr)
        return root->number;

    return getMax(root->rightPart);
}

int main() {

    MyNode* start = nullptr;

    start = insertData(start, 45);
    start = insertData(start, 20);
    start = insertData(start, 70);
    start = insertData(start, 10);
    start = insertData(start, 30);
    start = insertData(start, 60);
    start = insertData(start, 90);

    cout << "BST Elements: ";
    display(start);

    cout << endl;

    cout << "Minimum Value: " << getMin(start) << endl;
    cout << "Maximum Value: " << getMax(start) << endl;

    return 0;
}
