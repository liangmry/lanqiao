// 173. 矩阵距离 https://www.acwing.com/problem/content/description/175/
#include <iostream>
#include <queue>
#include <algorithm>
#define PII pair<int, int>
using namespace std;
// 求曼哈顿距离，但可简化为bfs向四个方向延申
// 因为bfs本身就是求 最短 的
int n, m;
const int N = 1005;
char g[N][N];
int dist[N][N];
queue<PII> q;
bool vis[N][N];
const int dx[] = {1,-1,0,0},
        dy[] = {0,0,1,-1};

void bfs() {
    while(!q.empty()) {
        auto t = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a < 1 or a > n or b < 1 or b > m) continue;
            if(vis[a][b]) continue;

            vis[a][b] = true;
            dist[a][b] = dist[t.first][t.second] + 1;
            q.push({a, b});
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> g[i][j];
            if(g[i][j] == '1') {
                q.push({i, j});
                vis[i][j] = true;
                dist[i][j] = 0;
            }
        }
    }
    bfs();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}