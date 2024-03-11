// UCV2013H - Slick https://www.luogu.com.cn/problem/SP15436
#include <iostream>
#include <queue>
#include <map>
#include <cstring>
#define PII pair<int, int>

using namespace std;
// 连通问题

const int N = 300;
const int dx[] = {0,0,1,-1},
        dy[] = {1,-1,0,0};
int n, m;
int g[N][N];
map<int, int> res; // 记录面积：连通块个数
bool vis[N][N];

int bfs(int x, int y) {
    queue<PII> q;
    q.push({x, y});
    vis[x][y] = true; // md折腾半天，这个点忘记标记了
    int filed = 1;

    while(!q.empty()) {
        auto t = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a < 1 or a > n or b < 1 or b > m) continue;
            if(g[a][b] == 0) continue;
            if(vis[a][b]) continue;

            vis[a][b] = true;
            filed++;
            q.push({a, b});
        }
    }
    return filed;
}

int main() {

    while(true) {
        cin >> n >> m;
        if(n == 0 and m == 0) break;
        memset(g, 0, sizeof g);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> g[i][j];
            }
        }
        int cnt = 0;
        memset(vis, 0, sizeof vis);
        res.clear();


        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(g[i][j] == 1 and !vis[i][j]) {
                    res[bfs(i, j)]++;
                    cnt ++;
                }
            }
        }
        cout << cnt << endl;
        for(auto &t: res) {
            cout << t.first << ' ' << t.second << endl;
        }
    }
    return 0;
}