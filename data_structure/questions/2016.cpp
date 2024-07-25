#include <iostream>

using namespace std;

void quickSort(vector<int> &A, int left, int right, int k) {
    if (left == right) {
        return;
    }

    int i = left-1, j = right+1, x = A[left];
    while (i < j) {
        while (A[++i] < x);
        while (A[--j] > x);
        if (i < j) swap(A[i], A[j]);
    }

    int p = j - left + 1;
    if (k <= p) {
        quickSort(A, left, j, k);
    } else {
        quickSort(A, j+1, right, k-p);
    }
}

void partition(vector<int> &A) {
    int n = A.size(), k = A.size() / 2;

    quickSort(A, 0, n-1, k);

    vector<int> A1, A2;
    for (int i = 0; i < k; i++) {
        A1.push_back(A[i]);
    }

    for (int i = k; i < n; i++) {
        A2.push_back(A[i]);
    }

    for (auto x : A1) {
        cout << x << " ";
    }
    cout << endl;

    for (auto x :  A2) {
        cout << x <<  " ";
    }
    cout << endl;
}

int main() {
    vector<int> A = {13, 20, 9, 3, 7, 4, 2, 5, 6, 8, 10, 11};

    partition(A);

    return 0;
}