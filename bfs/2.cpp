// P1443 马的遍历
#include <iostream>
#include <queue>
#include <cstring>
#define PII pair<int, int>

using namespace std;
// 数据量较大，dfs速度不够  （二维数组 20 以内使用dfs吧！！）
// 改用bfs （回溯 用 队列 已经处理了！！！）

const int px[] = {2, 2, 1, 1, -1, -1, -2, -2};
const int py[] = {1, -1, 2, -2, 2, -2, 1, -1};
const int N = 405;

int n, m, sx, sy;
queue<PII> q;
bool vis[N][N]; // 访问状态
int dist[N][N]; // 距离

void bfs() {
    vis[sx][sy] = true;
    dist[sx][sy] = 0;
    q.push({sx, sy});

    while(!q.empty()) {
        auto t = q.front();
        int x = t.first, y = t.second;
        q.pop(); // 出队

        for(int i = 0; i <= 7; i++) {
            int a = x + px[i], b = y + py[i];
            if(a < 1 or a > n or b < 1 or b > m) continue; // 超范围
            if(vis[a][b]) continue;  // 被访问过，返回

            vis[a][b] = true; // 已经访问
            dist[a][b] = dist[x][y] + 1; // 距离 + 1
            q.push({a, b}); // 入队
        }
    }
}

int main() {
    cin >> n >> m >> sx >> sy;
    memset(dist, -1, sizeof dist);
    bfs();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}