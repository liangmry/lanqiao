// P1747 好奇怪的游戏
#include <iostream>
#include <queue>
#include <cstring>
#define PII pair<int, int>

using namespace std;

const int N = 60;
const int px[] = {1,1,2,2,2,2,-1,-1,-2,-2,-2,-2};
const int py[] = {-2,2,-2,-1,1,2,-2,2,-1,1,-2,2};
queue<PII> q;
bool vis[N][N];
int dist[N][N];

int bfs(int x, int y) {
    if(x == 1 and y == 1) return 0; // 起点就是终点
    vis[x][y] = true;
    q.push({x, y});
    dist[x][y] = 0;

    while(!q.empty()) {
        auto t = q.front();
        q.pop();

        for(int i = 0; i < 12; i++) {
            int a = t.first + px[i], b = t.second + py[i];
            if(a < 1 or a > 30 or b < 1 or b > 30) continue; // 这里的范围限定 要看清楚题意！！
            if(vis[a][b]) continue;

            dist[a][b] = dist[t.first][t.second] + 1; // 不要加错了 不是[x][y] 很马虎！！！
            vis[a][b] = true;
            q.push({a, b});
            if(a == 1 and b == 1) return dist[1][1];
        }
    }
    return 0;
}

int main() {
    int n = 2;
    while(n--) {
        int x, y;
        cin >> x >> y;
        int ans = bfs(x, y);
        cout << ans << endl;
        while(!q.empty()) q.pop();
        memset(vis, 0, sizeof vis);
        memset(dist, 0, sizeof dist);
    }
    return 0;
}