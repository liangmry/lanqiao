// 献给阿尔吉侬的花束 https://www.acwing.com/problem/content/description/1103/?utm_source=wechat_session&utm_medium=social&utm_oi=1237383479098585088
#include <iostream>
#include <queue>
#include <cstring>
#define PII pair<int, int>
using namespace std;
// 简单bfs

const int N = 205;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int n, m, sx, sy, fx, fy;
char g[N][N];
bool vis[N][N];
int dis[N][N];

int bfs() {
    queue<PII> q;
    vis[sx][sy] = 1;
    q.push({sx, sy});

    while(!q.empty()) {
        auto t = q.front();
        q.pop();
        if(t.first == fx && t.second == fy) return dis[fx][fy];

        for(int i = 0; i < 4; i++) {
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a >= 1 && a <= n && b >= 1 && b <= m && vis[a][b] == 0 && g[a][b] != '#') {
                vis[a][b] = 1;
                dis[a][b] = dis[t.first][t.second] + 1;
                q.push({a, b});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> g[i][j];
                if(g[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                if(g[i][j] == 'E') {
                    fx = i;
                    fy = j;
                }
            }
        }
        int ans = bfs();
        if(ans == -1) cout << "oop!" << '\n';
        else cout << ans << '\n';
        memset(vis, 0, sizeof vis);
        memset(dis, 0, sizeof dis);
    }
    return 0;
}