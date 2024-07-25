#include <iostream>

using namespace std;

const int SIZE = 100;

// 查找
int find(int A[], int x) {
    if (A[x] != x) {
        A[x] = find(A, A[x]);
    }
    return A[x];
}

// 合并
void merge(int A[], int root1, int root2) {
    A[find(A, root1)] = find(A, root2);
}

void init(int A[]) {
    for (int i = 0; i < SIZE; i++) {
        A[i] = i;
    }
}

int main() {
    int A[SIZE] = {0};
    init(A);

    merge(A, 1, 2);
    merge(A, 3, 4);

    cout << find(A, 1) << endl;
    cout << find(A, 3) << endl;

    merge(A, 2, 4); 

    cout << find(A, 1) << endl;
    cout << find(A, 3) << endl;

    return 0;
}