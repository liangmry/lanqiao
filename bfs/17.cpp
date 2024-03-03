// P1506 拯救oibh总部
#include <iostream>
#include <queue>
#define PII pair<int, int>

using namespace std;
// 染色问题

int n, m;
const int N = 505;
const int dx[] = {1,-1,0,0},
        dy[] = {0,0,1,-1};
int g[N][N];
bool vis[N][N];
queue<PII> q;
int cnt;

void bfs(int x, int y) {
    q.push({x, y});
    vis[x][y] = true;

    while(!q.empty()) {
        auto t = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a < 0 or a > n+1 or b < 0 or b > m+1) continue;
            if(g[a][b] == 1) continue;
            if(vis[a][b]) continue;

            vis[a][b] = true;
            q.push({a, b});
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char ch;
            cin >> ch;
            if(ch == '*') g[i][j] = 1;
            else g[i][j] = 0;
        }
    }

    bfs(0, 0);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!vis[i][j] and g[i][j] == 0) cnt ++;
        }
    }
    cout << cnt;
    return 0;
}