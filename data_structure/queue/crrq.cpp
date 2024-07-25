// 链式循环队列
// 队列空间只增不减 可重复使用

#include <iostream>

using namespace std;

typedef int ElementType;

struct Node {
    ElementType x;
    struct Node *next = nullptr;
    Node() {}
    Node(ElementType x) {
        this->x = x;
    }
};

struct CrrQueue {
    Node *front = nullptr;
    Node *rear = nullptr;
    bool Empty() { return rear == front; }
    bool Full() { return rear->next == front; }
    int Front(ElementType &x);  // 输出队首
    int Push(ElementType x); // 入队
    int Pop(); // 出队

    CrrQueue() {
        rear = new Node();
        rear->next = rear;
        front = rear;
    }
};

int CrrQueue::Front(ElementType &x) {
    if (Empty()) {
        return -1;
    }
    x = front->x;

    return 0l;
}

int CrrQueue::Push(ElementType x) {
    if (Full()) { // 队满
        Node* node = new Node();
        if (node == nullptr) { // 无法分配
            return -1;
        }
        rear->next = node;
    }

    rear->x = x;
    rear = rear->next;

    return 0;
}

int CrrQueue::Pop() {
    if (Empty()) { // 队空
        return -1;
    }
    front = front->next;

    return 0;
}

int main() {
    CrrQueue Q;
    ElementType x;

    Q.Push(1);
    Q.Push(2);

    Q.Front(x);

    cout << x << endl;

    Q.Pop();

    Q.Front(x);

    cout << x << endl;

    return 0;
}