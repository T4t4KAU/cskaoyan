#include <iostream>

using namespace std;

void quick_sort(int A[], int left, int right) {
    if (left >= right) {
        return;
    }

    int x = A[(left + right) >> 1]; // 取中间元素为基元
    int i = left-1, j = right+1;

    while (i < j) {
        do i++; while (A[i] < x); 
        do j--; while (A[j] > x);
        if (i < j) swap(A[i], A[j]); // 交换元素
    }

    quick_sort(A, left, j); // 对左序列排序
    quick_sort(A, j+1, right); // 对右序列排序
}

void test_sort() {
    int A[] = {5, 9, 4, 3, 6, 3, 2};
    int n = sizeof(A) / sizeof(int);

    quick_sort(A, 0, n-1);

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
}

int main() {
    test_sort();

    return 0;
}