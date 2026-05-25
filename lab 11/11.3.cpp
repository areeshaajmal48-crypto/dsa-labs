#include <iostream>
using namespace std;

struct NodeData {
    int item;
    NodeData* leftPtr;
    NodeData* rightPtr;

    NodeData(int v) {
        item = v;
        leftPtr = nullptr;
        rightPtr = nullptr;
    }
};

NodeData* insertNode(NodeData* root, int val) {

    if (root == nullptr) {
        return new NodeData(val);
    }

    if (val < root->item) {
        root->leftPtr = insertNode(root->leftPtr, val);
    }
    else {
        root->rightPtr = insertNode(root->rightPtr, val);
    }

    return root;
}

void printData(NodeData* root) {

    if (root == nullptr)
        return;

    printData(root->leftPtr);
    cout << root->item << " ";
    printData(root->rightPtr);
}

bool checkValue(NodeData* root, int key) {

    if (root == nullptr)
        return false;

    if (root->item == key)
        return true;

    if (key < root->item)
        return checkValue(root->leftPtr, key);

    return checkValue(root->rightPtr, key);
}

int main() {

    NodeData* start = nullptr;

    start = insertNode(start, 45);
    start = insertNode(start, 25);
    start = insertNode(start, 70);
    start = insertNode(start, 10);
    start = insertNode(start, 30);
    start = insertNode(start, 60);
    start = insertNode(start, 90);

    cout << "BST in Sorted Form: ";
    printData(start);

    cout << endl;

    int findNum;

    cout << "Enter value to search: ";
    cin >> findNum;

    if (checkValue(start, findNum)) {
        cout << "Value Found in BST";
    }
    else {
        cout << "Value Not Found in BST";
    }

    return 0;
}
