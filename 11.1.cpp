#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* lchild;
    TreeNode* rchild;

    TreeNode(int v) {
        value = v;
        lchild = nullptr;
        rchild = nullptr;
    }
};

void showIn(TreeNode* ptr) {
    if (ptr == nullptr)
        return;

    showIn(ptr->lchild);
    cout << ptr->value << " ";
    showIn(ptr->rchild);
}

void showPre(TreeNode* ptr) {
    if (ptr == nullptr)
        return;

    cout << ptr->value << " ";
    showPre(ptr->lchild);
    showPre(ptr->rchild);
}

void showPost(TreeNode* ptr) {
    if (ptr == nullptr)
        return;

    showPost(ptr->lchild);
    showPost(ptr->rchild);
    cout << ptr->value << " ";
}

int main() {

    TreeNode* start = new TreeNode(10);

    start->lchild = new TreeNode(7);
    start->rchild = new TreeNode(15);

    start->lchild->lchild = new TreeNode(3);
    start->lchild->rchild = new TreeNode(9);

    start->rchild->lchild = new TreeNode(12);

    cout << "Inorder: ";
    showIn(start);

    cout << endl;

    cout << "Preorder: ";
    showPre(start);

    cout << endl;

    cout << "Postorder: ";
    showPost(start);

    cout << endl;

    return 0;
}