// 2015 408 algorithm

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef struct node {
    int data;
    struct node *link;
} NODE;

NODE* createNode(int data) {
    NODE* node = (NODE*) malloc(sizeof(NODE));
    node->link = NULL;
    node->data = data;
    return node;
}

NODE* createList(vector<int> &nums) {
    if (nums.size() <= 0) {
        return NULL;
    }

    NODE *head = NULL; // 创建头指针 用于返回
    NODE* tail = NULL; // 创建尾指针 用于插入
    for (auto num : nums) {
        NODE* node = createNode(num);
        if (tail != NULL) {
            tail->link = node;
        } else {
            head = node;
        }
        tail = node;
    }

    return head;
}

void printList(NODE *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->link;
    }
    cout << endl;
}

// --------------- 以上为辅助函数 ---------------

NODE* removeRepeatNode(node *head) {
    unordered_map<int, bool> map;

    node *p = head, *q = NULL;
    while (p != NULL) {
        int data = abs(p->data);
        if (!map[data]) {
            map[data] = true;
            q = p;
            p = p->link;
        } else {
            q->link = p->link;
            free(p);
            p = q->link;
        }
    }

    return head;
}

int main() {
    vector<int> nums = {1, -1, 2, -2, 5, 6, 7, 8};
    NODE* list = createList(nums);
    printList(list);
    printList(removeRepeatNode(list));

    return 0;
}