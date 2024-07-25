#include <iostream>

using namespace std;

bool search(int A[], int left, int right, int x) {
    int low = left, high = right;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (A[mid] < x) {
            low = mid + 1;
        } else if (A[mid] > x) {
            high = mid - 1;
        } else {
            return true;
        }
    }

    return false;
}

void quickSort(int A[], int left, int right) {
    if (left == right) {
        return;
    }

    int x = A[left], i = left-1, j = right+1;
    while (i < j) {
        do i++; while (A[i] < x);
        do j--; while (A[j] > x);
        if (i < j) swap(A[i], A[j]);
    }

    quickSort(A, left, j);
    quickSort(A, j+1, right);
}

int findMiniNum(int A[], int n) {
    quickSort(A, 0, n-1);

    int left = 0;
    for (left = 0; left < n; left++) {
        if (A[left] > 0) {
            break;
        }
    }

    for (int i = 1; i <= A[n-1]+1; i++) {
        if (!search(A, left, n-1, i)) {
            return i;
        }
    }

    return -1;
}


int main() {
    int A[] = {-5, 3, 2, 3};
    cout << findMiniNum(A, 4) << endl;

    int B[] = {1, 2, 3};
    cout << findMiniNum(B, 3) << endl;

    return 0;
}