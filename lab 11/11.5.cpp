#include <iostream>
using namespace std;

struct DataNode {
    int value;
    DataNode* leftSide;
    DataNode* rightSide;

    DataNode(int x) {
        value = x;
        leftSide = nullptr;
        rightSide = nullptr;
    }
};

DataNode* addNode(DataNode* root, int val) {

    if (root == nullptr) {
        return new DataNode(val);
    }

    if (val < root->value) {
        root->leftSide = addNode(root->leftSide, val);
    }
    else {
        root->rightSide = addNode(root->rightSide, val);
    }

    return root;
}

void printTree(DataNode* root) {

    if (root == nullptr)
        return;

    printTree(root->leftSide);
    cout << root->value << " ";
    printTree(root->rightSide);
}

int smallestValue(DataNode* root) {

    if (root->leftSide == nullptr)
        return root->value;

    return smallestValue(root->leftSide);
}

DataNode* deleteValue(DataNode* root, int key) {

    if (root == nullptr)
        return nullptr;

    if (key < root->value) {
        root->leftSide = deleteValue(root->leftSide, key);
    }

    else if (key > root->value) {
        root->rightSide = deleteValue(root->rightSide, key);
    }

    else {

        if (root->leftSide == nullptr && root->rightSide == nullptr) {
            delete root;
            return nullptr;
        }

        else if (root->leftSide == nullptr) {
            DataNode* temp = root->rightSide;
            delete root;
            return temp;
        }

        else if (root->rightSide == nullptr) {
            DataNode* temp = root->leftSide;
            delete root;
            return temp;
        }

        int nextValue = smallestValue(root->rightSide);
        root->value = nextValue;
        root->rightSide = deleteValue(root->rightSide, nextValue);
    }

    return root;
}

int main() {

    DataNode* first = nullptr;

    first = addNode(first, 50);
    first = addNode(first, 30);
    first = addNode(first, 70);
    first = addNode(first, 20);
    first = addNode(first, 40);
    first = addNode(first, 60);
    first = addNode(first, 80);

    cout << "BST Before Deletion: ";
    printTree(first);

    cout << endl;

    int removeNum;

    cout << "Enter value to delete: ";
    cin >> removeNum;

    first = deleteValue(first, removeNum);

    cout << "BST After Deletion: ";
    printTree(first);

    return 0;
}
