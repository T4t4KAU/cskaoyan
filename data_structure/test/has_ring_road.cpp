#include <iostream>

using namespace std;

const int N = 5;

// 有环图
int g1[N][N] = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
};

// 无环图
int g2[N][N] = {
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
};

int nodes[N]; // 顶点

int find(int x) {
    if (nodes[x] != x) {
        nodes[x] = find(nodes[x]);
    }
    return nodes[x];
}

// 检查图是否存在环路
bool has_ring_road(int g[N][N]) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            // x->y 存在路径
            if (g[x][y] != 0) {
                int rx = find(x);
                int ry = find(y);
                if (rx != ry) {
                    nodes[rx] = ry;
                } else {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    for (int i = 0; i < N; i++) {
        nodes[i] = i;
    }
    cout << has_ring_road(g1) << endl;

    for (int i = 0; i < N; i++) {
        nodes[i] = i;
    }
    cout << has_ring_road(g2) << endl;

    return 0;
}