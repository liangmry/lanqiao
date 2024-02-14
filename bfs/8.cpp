// P2298 Mzc和男家丁的游戏
#include <iostream>
#include <queue>
#define PII pair<int, int>

using namespace std;
// bfs 常用于寻找 最短路径

const int N = 2005;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}; // 四联通
int n, m, sx, sy, fx,fy;
char g[N][N];
// bfs 三件套
queue<PII> q;
int dist[N][N];
bool vis[N][N];

int bfs() {
    if(sx == fx and sy == fy) return 0;
    q.push({sx, sy});
    vis[sx][sy] = true;
    dist[sx][sy] = 0;

    while(!q.empty()) {
        auto t = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int a = t.first + dx[i], b = t.second + dy[i];

            if(a < 1 or a > n or b < 1 or b > m) continue;
            if(g[a][b] == '#') continue; // 不能走 这种路
            if(vis[a][b]) continue;

            q.push({a, b});
            vis[a][b] = true;
            dist[a][b] = dist[t.first][t.second] + 1;
            if(a == fx and b == fy) return dist[fx][fy];
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> g[i][j]; // '#' 不能走
            if(g[i][j] == 'm') {
                sx = i, sy = j;
            } else if(g[i][j] == 'd') {
                fx = i, fy = j;
            }
        }
    }
    int ans = bfs();
    if(ans == -1) {
        cout << "No Way!";
    } else {
        cout << ans;
    }
    return 0;
}