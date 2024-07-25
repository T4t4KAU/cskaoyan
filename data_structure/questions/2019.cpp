// 2019 408 algorithm

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

typedef struct node {
    int data;
    struct node *next;
} NODE;

NODE* createNode(int data) {
    NODE* node = (NODE*) malloc(sizeof(NODE));
    node->next = NULL;
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
            tail->next = node;
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
        head = head->next;
    }
    cout << endl;
}

// --------------- 以上为辅助函数 ---------------

NODE* reverseList(NODE *head) {
    if (head == NULL) {
        return NULL;
    }

    NODE *p = head->next;
    NODE *q = head;
    q->next = NULL;

    while (p != NULL) {
        NODE *t = p->next;
        p->next = q;
        q = p;
        p = t;
    }

    return q;
}

NODE *mergeList(NODE *list1, NODE *list2) {
    NODE *p = list1, *q = list2;

    while (p != NULL && q != NULL) {
        NODE *p_next = p->next;
        NODE *q_next = q->next;

        p->next = q;
        q->next = p_next;
        p = p_next;
        q = q_next;
    }

    return list1;
}

NODE* resortList(NODE *head) {
    NODE *fast = head;
    NODE *slow = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    NODE *list1 = head;
    NODE *list2 = slow->next;
    slow->next = NULL;

    return mergeList(list1, reverseList(list2));
}


int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    NODE* list = createList(nums);
    printList(list);
    printList(resortList(list));

    return 0;
}