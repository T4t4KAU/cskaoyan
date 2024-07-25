#include <iostream>

using namespace std;

typedef struct node {
    char data;
    struct node *next;
} NODE;

NODE* createNode(char data) {
    NODE* node = (NODE*) malloc(sizeof(NODE));
    node->next = NULL;
    node->data = data;
    return node;
}

NODE* createList(vector<char> &chars) {
    if (chars.size() <= 0) {
        return NULL;
    }

    NODE *head = NULL; // create head pointer for returning
    NODE* tail = NULL; // create tail pointer for inserting
    for (auto c : chars) {
        NODE* node = createNode(c);
        if (tail != NULL) {
            tail->next = node;
        } else {
            head = node;
        }
        tail = node;
    }

    return head;
}

// 获取尾结点
NODE *getTailNode(NODE* head) {
    while (head->next != NULL) {
        head = head->next;
    }
    return head;
}

// --------------- 以上为辅助函数 ---------------

// p1先遍历表A 结束后遍历表B
// p2先遍历表B 结束后遍历表A
// 相遇点即公共后缀起点
NODE* getStartOfSuffix(NODE *A, NODE *B) {
    NODE *p1 = A, *p2 = B;

    while (p1 != p2) {
        if (p1->next != NULL) {
            p1 = p1->next;
        } else {
            p1 = B;
        }

        if (p2->next != NULL) {
            p2 = p2->next;
        } else {
            p2 = A;
        }
    }

    return p1;
}

int main() {
    vector<char> s1 = {'l', 'o', 'a', 'd'};
    vector<char> s2 = {'b', 'e'};
    vector<char> s3 = {'i', 'n', 'g'};

    NODE* A = createList(s1);
    NODE* B = createList(s2);
    NODE* C = createList(s3);

    getTailNode(A)->next = C;
    getTailNode(B)->next = C;

    NODE *p = getStartOfSuffix(A, B);
    cout << p->data << endl;

    return 0;
}