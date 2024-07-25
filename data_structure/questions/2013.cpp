#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

int findMainElement(int A[], int n) {
    int *count = new int[n], x;
    memset(count, 0, sizeof(int)*n);

    for (int i = 0; i < n; i++) {
        count[A[i]]++;
        if (count[A[i]] > n/2) {
            x = A[i];
        }
    }
    delete[] count;

    return x;
}

int main() {
    int nums[] = {0,5,5,3,5,7,5,5};
    int n = sizeof(nums) / sizeof(int);
    cout << findMainElement(nums, n) << endl;

    return 0;
}