#include <iostream>
#include <vector>

using namespace std;

const int N = 5;

int g1[N][N] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
};

vector<vector<int>> g2 = {
    {1, 3}, 
    {4},
    {5, 4},
    {1},
    {3},
    {5},
};

bool visited[N];

void dfs1(int x) {
    
}

void dfs2(int x) {
    visited[x] = true;
    for (auto t : g2[x]) {
        if (!visited[x]) {
            dfs2(t);
        }
    } 
}

int main() {

}