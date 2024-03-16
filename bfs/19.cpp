// P1331 海战
#include <iostream>
#include <queue>
#define PII pair<int, int>

using namespace std;
// 连通块问题 + 两船不能相邻
/*
*这道题的难点在于判断是否有船相邻。
 通过 别人 模拟的数据可以得出结论：
 如果图是不和法的，一定存在如下结构：
# #
. #
或
# #
# .
或
# .
# #
或
. #
# #
即在一个2*2的方格中有三个#。所以就能得出代码：
*/

const int N = 1005;
const int dx[] = {1,-1,0,0},
        dy[] = {0,0,1,-1};
int n, m;
char g[N][N];
int cnt;
queue<PII> q;
bool vis[N][N];

void bfs(int x, int y) {
    while(!q.empty()) q.pop();

    vis[x][y] = true;
    q.push({x, y});
    while(!q.empty()) {
        auto t = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a < 0 or a >= n or b < 0 or b >= m) continue;
            if(g[a][b] == '.') continue;
            if(vis[a][b]) continue;

            vis[a][b] = true;
            q.push({a, b});
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%s", g[i]);
    }
    // 依次判断各四个方块
    int f;
    for(int i = 0; i <= n-1; i++) {
        f = 0;
        for(int j = 0; j <= m-1; j++) {
            // 不能这样做
//            if(g[i][j] == '#' or g[i+1][j] == '#' or g[i][j+1] == '#' or g[i+1][j+1] == '#') {
//                f++;
//            }
            // 正确做法
            if(g[i][j] == '#') f++;
            if(g[i+1][j] == '#') f++;
            if(g[i][j+1] == '#') f++;
            if(g[i+1][j+1] == '#') f++;
            if(f == 3) {
                printf("Bad placement.");
                return 0;
            }
            f = 0;
        }

    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] == '#' and !vis[i][j]) {
                cnt ++;
                bfs(i, j);
            }
        }
    }
    printf("There are %d ships.", cnt);
    return 0;
}