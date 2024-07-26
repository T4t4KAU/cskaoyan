#include <iostream>

using namespace std;

int search(int S[], int n, int k) {
    int low = 0, high = n-1;

    while (low < high) {
        int mid = (low + high) >> 1;
        if (S[mid] < k) {
            low = mid + 1;
        } else if (S[mid] > k) {
            high = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}

// 1 2 2 2 2 3 4 5 6 7
int getAmountOfK(int S[], int n, int k) {
    int m = search(S, n, k), i;
    
    for (i = m; i>=0 && S[i] == k; i--);
    return m - i + 1;
}

int main() {
    int S[] = {1, 2, 2, 2, 2, 3, 4, 5, 6, 7};
    int n = sizeof(S) / sizeof(int);

    int x = search(S, n, 2);
    cout << x << endl;
}