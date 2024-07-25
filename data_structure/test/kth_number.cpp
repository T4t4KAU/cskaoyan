// 快速选择算法

#include <iostream>

using namespace std;

int quick_select(vector<int> &A, int left, int right, int k) {
    if (left == right) {
        return A[left];
    }

    int x = A[left], i = left-1, j = right+1;
    while (i < j) {
        while (A[++i] < x);
        while (A[--j] > x);
        if (i < j) swap(A[i], A[j]);
    }

    int p = j - left + 1; // 计算枢轴
    if (k <= p) {
        return quick_select(A, left, j, k);
    }
    return quick_select(A, j+1, right, k-p);
}

int main() {
    vector<int> A = {2, 4, 1, 5, 3};
    cout << quick_select(A, 0, 4, 3) << endl;

    return 0;
}