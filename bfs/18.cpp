// P3395 路障
#include <iostream>
#include <queue>
#include <cstring>
#define PII pair<int, int>

using namespace std;

int T, n;
const int N = 1005;
const int dx[] = {1,-1,0,0},
        dy[] = {0,0,1,-1};
int g[N][N];
bool vis[N][N];
int dist[N][N];
queue<PII> q;

bool bfs() {
    if(n == 1) return true; // 特判
    vis[1][1] = true;
    dist[1][1] = 0;
    q.push({1,1});

    while(!q.empty()) {
        auto t = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a < 1 or a > n or b < 1 or b > n) continue;
            if(vis[a][b]) continue;
            if(dist[t.first][t.second] + 1 >= g[a][b]) continue; // 这里的g要注意 安全的点 表现为数字巨大

            vis[a][b] = true;
            dist[a][b] = dist[t.first][t.second] + 1;
            q.push({a, b});
            if(a == n and b == n) return true;
        }
    }
    return false;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        memset(g, 0x3f, sizeof g); // 必须要初始化为大数
        if(!q.empty()) q.pop();
        memset(dist, 0, sizeof dist);
        memset(vis, 0, sizeof vis);

        scanf("%d", &n);
        int nt = 2*n-2;
        int x, y, k = 1;
        while(nt--) {
            scanf("%d %d", &x, &y);
            k++; // 表示时间，这一秒结束时安放，第一个时间设为2
            g[x][y] = k;
        }
        if(bfs()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}