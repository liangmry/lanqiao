// P2385 [USACO07FEB] Bronze Lilypad Pond B
#include <iostream>
#include <queue>
#define PII pair<int, int>
using namespace std;

int n, m, m1,m2;
queue<PII> q;
const int N = 33;
bool vis[N][N];
int g[N][N];
int sx, sy, fx, fy;
int dist[N][N];

int bfs(int *dx, int *dy) {
    q.push({sx, sy});
    vis[sx][sy] = true;
    dist[sx][sy] = 0;

    while(!q.empty()) {
        auto t = q.front();
        q.pop();

        for(int i = 0; i < 8; i++) {
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a < 1 or a > n or b < 1 or b > m) continue;
            if(g[a][b] == 0 or g[a][b] == 2) continue;
            if(vis[a][b]) continue;

            vis[a][b] = true;
            dist[a][b] = dist[t.first][t.second] + 1;
            q.push({a, b});
            if(a == fx and b == fy) return dist[a][b];
        }
    }
    return -1;
}

int main() {
    cin >> n >> m >> m1 >> m2;
    int dx[8] = {m1,m1,-m1,-m1,m2,m2,-m2,-m2};
    int dy[8] = {m2,-m2,m2,-m2,m1,-m1,m1,-m1};
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> g[i][j];
            if(g[i][j] == 3) {
                sx = i, sy = j;
            } else if(g[i][j] == 4) {
                fx = i, fy = j;
            }
        }
    }
    cout << bfs(dx, dy);
    return 0;
}