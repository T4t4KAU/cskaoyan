#include <iostream>
#include <queue>

using namespace std;

typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void inorder(BiTree root, int height, int count[]) {
    if (root == NULL) {
        return;
    }

    inorder(root->lchild, height+1, count);
    count[height]++;
    inorder(root->rchild, height+1, count);
}

// 算法设计思想：使用一个数组记录每层的结点个数
// 遍历二叉树，当访问到某层的结点时，将数组中记录的结点个数加一
// 找到数组中的最大值

int countTreeWidth(BiTree root, int h) {
    int *count = (int*) malloc(sizeof(int)*h);
    int width = 0;

    memset(count, 0, sizeof(int)*h); // 清空数组

    inorder(root, 0, count); // 中序遍历
    for (int i = 0; i < h; i++) {
        width = max(width, count[i]);
    }

    free(count); // 释放空间

    return width;
}

int main() {

}