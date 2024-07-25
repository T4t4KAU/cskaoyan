#include <iostream>

using namespace std;

const int N = 3, INF = 0x3f3f3f3f; // 结点数
int cost[N];
bool visited[N];

int g[N][N];

// 求最短路径
int dijkstra() {
    memset(cost, INF, sizeof(cost));

    cost[0] = 0;
    for (int i = 0; i < N; i++) {
        int t = -1;
        for (int j = 0; j < N; j++) {
            if (!visited[j] && (t == -1 || cost[j] < cost[t])) {
                t = j; // 选择一个新结点
            }
        }

        visited[t] = true;
        for (int j = 0; j < N; j++) {
            cost[j] = min(cost[j], cost[t]+g[t][j]);
        }
    }

    return cost[N-1];
}


int main() {
    memset(g, INF, sizeof(g));

    // 边
    g[0][1] = 2;
    g[1][2] = 1;
    g[0][2] = 4;

    cout << dijkstra() << endl;
    return 0;
}