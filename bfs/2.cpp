#include <iostream>
#include <queue>
#define PII pair<int, int>

using namespace std;

const int px[] = {2,2,1,1,-2,-2,-1,-1};
const int py[] = {1,-1,2,-2,1,-1,2,-2};
const int N= 405;

int n, m, x, y; // x y 马的起点
int vis[N][N], dist[N][N]; // 是否访问   距离
queue<PII> q;

void bfs() {
    dist[x][y] = 0;
    q.push({x, y});
    vis[x][y] = true;
    while(!q.empty()) {
        auto t = q.front();
        q.pop();

        for(int i = 0; i < 8; i++) {
            int a = t.first + px[i], b = t.second + py[i];
            if(a < 1 || b < 1 || a > n || b > m) continue; // 超范围
            if(vis[a][b]) continue; // 被访问过，返回

            q.push({a, b}); // 入队
            vis[a][b] = true; // 设置为已被访问
            dist[a][b] = dist[t.first][t.second] + 1; // 步加
        }
    }
}

int main()
{
    cin >> n >> m >> x >> y;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dist[i][j] = -1;
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