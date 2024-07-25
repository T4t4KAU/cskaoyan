#include <iostream>

using namespace std;

// 选择排序
void select_sort(int A[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (A[j] < A[i]) {
                swap(A[i], A[j]);
            }
        }
    }
}

void test_sort() {
    int A[] = {5, 9, 4, 3, 6, 3, 2};
    int n = sizeof(A) / sizeof(int);

    select_sort(A, n);

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
}

int main() {
    test_sort();

    return 0;   
}