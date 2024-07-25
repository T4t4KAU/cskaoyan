#include <iostream>

using namespace std;

// 插入排序
void insert_sort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int x = A[i], j = i-1;
        // 向左遍历元素 将较大元素后移
        while (j >= 0 && A[j] > x) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

int find(int A[], int n, int x) {
    int low = 0, high = n-1;
    while (low < high) {
        int mid = (low + high) >> 1;
        if (A[mid] < x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return high;
}

int test_find() {
    
}

void test_sort() {
    int A[] = {5, 9, 4, 3, 6, 3, 2};
    int n = sizeof(A) / sizeof(int);

    insert_sort(A, n);

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
}


int main() {
    test_sort();

    return 0;
}