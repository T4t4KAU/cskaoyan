#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> PII;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

const int N = 5;
int g[N][N] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
};
int d[N][N];

int bfs(int a, int b, int n, int m) {
    queue<PII> q;
    q.push({a, b});

    while (!q.empty()) {
        auto s = q.front();
        q.pop();
        g[s.first][s.second] = 1;
        for (int i = 0; i < 4; i++) {
            int x = s.first + dx[i];
            int y = s.second + dy[i];
            if (x < 0 || x >= N || y < 0 || y >= N) {
                continue;
            }

            if (g[x][y] == 0) {
                g[x][y] = 1;
                d[x][y] = d[s.first][s.second] + 1;
                q.push({x, y});
            }
        }
    }

    return d[n][m];
}

int main() {
    int res = bfs(0, 0, N-1, N-1);
    cout << res << endl;

    return 0;
}