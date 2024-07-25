#include <iostream>

using namespace std;

typedef struct node {
    char data[10];
    struct node *left, *right;
} BTree;

BTree *createNode(string data) {
    BTree *node = new BTree;

    memcpy(node->data, data.c_str(), 10);
    node->left = node->right = NULL;

    return node;
}

// --------------- 以上为辅助函数 ---------------

void inOrder(BTree *root, int height, string &s) {
    if (root == NULL) {
        return;
    } else if (root->left == NULL && root->right == NULL) {
        s += root->data;
    } else {
        if (height > 1) s += "(";
        inOrder(root->left, height + 1, s);
        s += root->data;
        inOrder(root->right, height + 1, s);
        if (height > 1) s += ")";
    }
}

string convertExpression(BTree *root) {
    string expr = "";
    inOrder(root, 1, expr);
    return expr;
}

int main() {
    BTree *root1 = createNode("*");
    root1->left = createNode("+");
    root1->right = createNode("*");
    root1->left->left = createNode("a");
    root1->left->right = createNode("b");
    root1->right->left = createNode("c");
    root1->right->right = createNode("-");
    root1->right->right->right = createNode("d");

    cout << convertExpression(root1) << endl;
}