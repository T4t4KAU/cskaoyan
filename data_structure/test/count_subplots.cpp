#include <iostream>

using namespace std;

const int N = 5;

int g1[N][N] = {
    {0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 1, 0},
};

int g2[N][N] = {
    {0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 1, 0, 1},
    {0, 0, 0, 1, 0},
};

int A[N];

int find(int x) {
    if (A[x] != x) {
        A[x] = find(A[x]);
    }
    return A[x];
}

// 计算极大连通子图个数
int count_subplots(int g[N][N]) {
    int c = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (g[i][j] != 0) {
                A[find(i)] = find(j);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (A[i] == i) {
            c++;
        }
    }

    return c;
}

int main() {
    for (int i = 0; i < N; i++) {
        A[i] = i;
    }

    cout << count_subplots(g1) << endl;

    for (int i = 0; i < N; i++) {
        A[i] = i;
    }

    cout << count_subplots(g2) << endl;

    return 0;
}