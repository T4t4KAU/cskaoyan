#include <iostream>
#include <vector>

using namespace std;

// 2 4 6 8 11
int getMiddleElement(vector<int> &A, vector<int> &B) {
    int i = 0, j = 0, k = 0, x;
    while (i < A.size() && j < B.size()) {
        if (A[i] < B[j]) {
            i++; k++; x = A[i-1];
        } else {
            j++; k++; x = B[j-1];
        }

        if (k == A.size()) {
            return x;
        }
    }

    return 0;
}

int main() {
    vector<int> s1 = {11, 13, 15, 17, 19};
    vector<int> s2 = {2, 4, 6, 8, 20};

    cout << getMiddleElement(s1, s2) << endl;

    return 0;
}