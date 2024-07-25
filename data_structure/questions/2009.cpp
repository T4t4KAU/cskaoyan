#include <iostream>

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

    NODE *head = NULL; // create head pointer for returning
    NODE* tail = NULL; // create tail pointer for inserting
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

// solution:
// 设置前后指针 让后指针先走k步
// 前后指针同时向前 直到后指针遍历结束
// 返回前指针元素
int getLastK(NODE *head, int k) {
    NODE *fast = head;
    NODE *slow = head;

    while (fast != NULL && k > 0) {
        fast = fast->link;
        k--;
    }

    if (k > 0) {
        return 0;
    }

    while (fast != NULL) {
        fast = fast->link;
        slow = slow->link;
    }

    cout << slow->data << endl;

    return 1;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    NODE* list = createList(nums);
    getLastK(list, 2);

    return 0;
}