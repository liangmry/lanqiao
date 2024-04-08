// 骑士的移动 Knight Moves https://www.luogu.com.cn/problem/UVA439
#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#define PII pair<int, int>
using namespace std;

const int N = 10;
int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
int sx, sy, fx, fy;
string s1, s2;
bool vis[N][N];
int dis[N][N];

int bfs() {
    queue<PII> q;
    q.push({sx, sy});
    vis[sx][sy] = 1;

    while(!q.empty()) {
        auto t = q.front();
        if(t.first == fx and t.second == fy) return dis[fx][fy];
        q.pop();
        for(int i = 0; i < 8; i++) { // 这里是 8
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a >= 1 and a <= 8 and b >= 1 and b <= 8 and vis[a][b] == 0) {
                vis[a][b] = 1;
                dis[a][b] = dis[t.first][t.second] + 1;
                q.push({a, b});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
    while(cin >> s1 >> s2) {
        sx = s1[1] - '0', sy = s1[0] - 'a' + 1;
        fx = s2[1] - '0', fy = s2[0] - 'a' + 1;
        int ans = bfs();
        cout << "To get from " << s1 << " to " << s2 << " takes " << ans << " knight moves.\n";
        memset(vis, 0, sizeof vis);
        memset(dis, 0, sizeof dis);
    }
    return 0;
}