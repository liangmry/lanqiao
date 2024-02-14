// P1451 求细胞数量
// P1596 [USACO10OCT] Lake Counting S
#include <iostream>
#include <queue>
#define PII pair<int, int>
// 洪水灌溉型问题 bfs 或 dfs都可
// 我这里使用 bfs

using namespace std;

const int N = 105;
const int dx[] = {1,-1, 0, 0},
        dy[] = {0,0,1,-1};
int n, m;
char g[N][N];
queue<PII> q;
bool vis[N][N];
int cnt;

void bfs(int x,int y) {
    q.push({x, y});
    vis[x][y] = true;

    while(!q.empty()) {
        auto t = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a < 1 or a > n or b < 1 or b > m) continue;
            if(g[a][b] == '0') continue; // 0不是细胞，重新换方向搜索
            if(vis[a][b]) continue;

            q.push({a, b});
            vis[a][b] = true;
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(g[i][j] != '0' and !vis[i][j]) { //该点是水 并且 没有访问标记过
                bfs(i, j);
                cnt ++;
            }
        }
    }
    cout << cnt;
    return 0;
}
