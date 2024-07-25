#include <iostream>

using namespace std;

const int N = 100;
int temp[N];

void merge_sort(int A[], int left, int right) {
    if (right <= left) {
        return;
    }

    int mid = (left + right) >> 1;
    merge_sort(A, left, mid);
    merge_sort(A, mid+1, right);

    int i = left, j = mid+1, k = 0;
    while (i <= mid && j <= right) {
        if (A[i] < A[j]) {
            temp[k++] = A[i++];
        } else {
            temp[k++] = A[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = A[i++];
    }

    while (j <= right) {
        temp[k++] = A[j++];
    }

    for (i = left; i <= right; i++) {
        A[i] = temp[i-left];
    }
}

void test_sort() {
    int A[] = {5, 9, 4, 3, 6, 3, 2};
    int n = sizeof(A) / sizeof(int);

    merge_sort(A, 0, n-1);

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
}

int main() {
    test_sort();

    return 0;
}