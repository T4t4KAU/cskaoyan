#include <iostream>

using namespace std;

typedef struct node {
    int weight;
    struct node *left;
    struct node *right;
} NODE;

NODE *createNode(int weight) {
    NODE *node = new NODE;

    node->right = node->left = NULL;
    node->weight = weight;
    return node;
}

// --------------- 以上为辅助函数 ---------------

void count(NODE *root, int height, int &sum) {
    if (root != NULL) {
        sum += height * root->weight;
        count(root->left, height+1, sum);
        count(root->right, height+1, sum);
    }
}

int countWPL(NODE *root) {
    int sum;

    sum = 0;
    count(root, 1, sum);
    return sum;
}

int main() {
    NODE *root = createNode(3);
    root->left = createNode(4);
    root->right = createNode(5);
    root->left->left = createNode(6);
    root->right->left = createNode(7);

    cout << countWPL(root) << endl;

    return 0;
}