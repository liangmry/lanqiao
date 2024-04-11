// P1746 离开中山路
#include <iostream>
#include <queue>
// 新增 双向bfs 写法

#define pII pair<int, int> // 存二维坐标

using namespace std;

const int N = 1005;
const int px[] = {1, -1,0,0};
const int py[] = {0, 0, 1, -1};

int n, x1, y1, x2, y2;
int graph[N][N];
int dist[N][N]; // 距离起点的距离
bool vis[N][N]; // 是否访问过该节点
queue<pII> q;

int bfs(int x, int y) {
    q.push({x, y});
    dist[x][y] = 0;
    vis[x][y] = true;

    while(!q.empty()) {
        auto t = q.front();
        q.pop();
        for(int i = 0; i <= 3; i++) {
            int a = t.first+px[i], b = t.second+py[i];

            if(a < 1 || a > n || b < 1 || b > n) continue; // 超范围
            if(graph[a][b] == 1) continue; // 走不通
            if(dist[a][b] > 0) continue; // 访问过 和下一条语句可以合并
            if(vis[a][b]) continue;

            vis[a][b] = true;
            q.push({a, b});
            dist[a][b] = dist[t.first][t.second] + 1;

            if(a == x2 && b == y2) return dist[x2][y2];
        }
    }
    return dist[x2][y2];
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            char ch;
            cin >> ch;
            if(ch == '0') graph[i][j] = 0;
            else graph[i][j] = 1;
        }
    }
    cin >> x1 >> y1 >> x2 >> y2;
    int ans = bfs(x1, y1);
    cout << ans-1;
    return 0;
}

/*
 * 双向bfs，关键是写两个队列时，别写错变量了
#include <bits/stdc++.h>
#define PII pair<int, int>
using namespace std;

const int N = 1005;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int g[N][N];
int n, sx, sy, fx, fy;
queue<PII> q1, q2;
bool vis1[N][N], vis2[N][N];
int dis1[N][N], dis2[N][N];

bool judge(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

int bfs() {
    if(sx == fx && sy == fy) return 0;
    vis1[sx][sy] = 1;
    dis1[sx][sy] = 0;
    q1.push({sx, sy});

    vis2[fx][fy] = 1;
    dis2[fx][fy] = 0;
    q2.push({fx, fy});

    while(!q1.empty() && !q2.empty()) {
        auto t1 = q1.front();
        q1.pop();
        int x = t1.first, y = t1.second;
        if(vis2[x][y]) return dis1[x][y] + dis2[x][y]; // 找是否有交点

        for(int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if(judge(a, b) && !vis1[a][b] && g[a][b] == 0) {
                vis1[a][b] = 1;
                dis1[a][b] = dis1[x][y] + 1;
                q1.push({a, b});
            }
        }

        auto t2 = q2.front();
        q2.pop();
        x = t2.first, y = t2.second;
        if(vis1[x][y]) return dis1[x][y] + dis2[x][y]; // 找是否有交点

        for(int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if(judge(a, b) && !vis2[a][b] && g[a][b] == 0) {
                vis2[a][b] = 1;
                dis2[a][b] = dis2[x][y] + 1;
                q2.push({a, b});
            }
        }
    }
    return -1;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            char ch;
            cin >> ch;
            if(ch == '0') g[i][j] = 0;
            else g[i][j] = 1;
        }
    }
    cin >> sx >> sy >> fx >> fy;
    cout << bfs() << endl;
    return 0;
}
 */