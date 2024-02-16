// P1746 离开中山路
#include <iostream>
#include <queue>

#define pII pair<int, int> // 存二维坐标

using namespace std;

const int N = 1005;
const int px[] = {1, -1,0,0};
const int py[] = {0, 0, 1, -1};

int n, x1, y1, x2, y2;
int graph[N][N];
int dist[N][N]; // 距离起点的距离
bool vis[N][N];
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

            if(a < 1 || a > n || b < 1 || b > n) continue;
            if(graph[a][b] == 1) continue;
            if(dist[a][b] > 0) continue;
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
    cout << ans;
    return 0;
}