#include <iostream>

using namespace std;

void shell_sort(int A[], int n, int d) {
    while (d > 0) {
        for (int i = d; i < n; i++) {
            int temp = A[i], j = i;
            while (j >= d && A[j-d] > temp) {
                A[j] = A[j-d];
                j -= d;
            }
            A[j] = temp;
        }
        d = d / 2;
    }
}

void test_sort() {
    int A[] = {5, 9, 4, 3, 6, 3, 2};
    int n = sizeof(A) / sizeof(int);

    shell_sort(A, n, n/2);

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
}

int main() {
    test_sort();

    return 0;
}