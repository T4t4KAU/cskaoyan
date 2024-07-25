#include <iostream>
#include <cmath>

using namespace std;

int minDistance(int s1[], int s2[], int s3[], int n1, int n2, int n3) {
    int res = abs(s1[0] - s2[0]) + abs(s1[0] - s3[0]) + abs(s2[0] - s3[0]);

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            for (int k = 0; k < n3; k++) {
                res = min(abs(s1[i] - s2[j]) + abs(s2[j] - s3[k]) + abs(s3[k] - s1[i]), res);
            }
        }
    }

    return res;
}

int main() {
    int s1[] = {-1, 0, 9};
    int s2[] = {-25, -10, 10, 11};
    int s3[] = {2, 9, 17, 30, 41};

    int n1 = sizeof(s1) / sizeof(int);
    int n2 = sizeof(s2) / sizeof(int);
    int n3 = sizeof(s3) / sizeof(int);

    cout << minDistance(s1, s2, s3, n1, n2, n3) << endl;

    return 0;
}