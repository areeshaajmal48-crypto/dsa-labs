#include <iostream>
using namespace std;

struct BNode {
    int num;
    BNode* leftSide;
    BNode* rightSide;

    BNode(int x) {
        num = x;
        leftSide = nullptr;
        rightSide = nullptr;
    }
};

BNode* addValue(BNode* root, int val) {

    if (root == nullptr) {
        return new BNode(val);
    }

    if (val < root->num) {
        root->leftSide = addValue(root->leftSide, val);
    }
    else {
        root->rightSide = addValue(root->rightSide, val);
    }

    return root;
}

void displayTree(BNode* root) {

    if (root == nullptr)
        return;

    displayTree(root->leftSide);
    cout << root->num << " ";
    displayTree(root->rightSide);
}

int main() {

    BNode* head = nullptr;

    head = addValue(head, 50);
    head = addValue(head, 30);
    head = addValue(head, 70);
    head = addValue(head, 20);
    head = addValue(head, 40);
    head = addValue(head, 60);
    head = addValue(head, 80);

    cout << "BST Elements in Ascending Order: ";
    displayTree(head);

    return 0;
}
