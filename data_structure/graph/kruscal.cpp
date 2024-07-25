#include <iostream>

using namespace std;

const int N = 5;

int nodes[N];

// 查找
int find(int x) {
    if (nodes[x] != x) {
        nodes[x] = find(nodes[x]);
    }
    return nodes[x];
}

struct Edge {
    int x, y, w;
    bool operator<(const Edge &e) const {
        return this->w < e.w;
    }
};

Edge edges[2*N] = {
    {1, 2, 1},
    {1, 3, 2},
    {1, 4, 3},
    {2, 3, 2},
    {3, 4, 4},
};

int kruscal(int m) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        int rx = find(edges[i].x);
        int ry = find(edges[i].y);
        if (rx != ry) {
            sum += edges[i].w;
            nodes[rx] = ry; 
        }
    }

    return sum;
}

int main() {
    for (int i = 0; i < N; i++) {
        nodes[i] = i;
    }

    int m = sizeof(edges) / sizeof(Edge);
    sort(edges, edges+m);

    int res = kruscal(m);
    cout << res << endl;

    return 0;
}