// P4554 小明的游戏
#include <iostream>
#include <deque>
#include <cstring>
#define PII pair<int, int>
using namespace std;
// 双端队列bfs
// 满足队列的两端性 单调性 -- push_front() 和 push_back()

int n, m, x1, y1, x2, y2;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int N = 505;
char g[N][N];
// 基础两件套
deque<PII> q;
bool vis[N][N];
int dist[N][N]; // 类似于记录每条边的权值

int bfs() {
    q.push_back({x1, y1});
    vis[x1][y1] = true;
    dist[x1][y1] = 0;

    while(!q.empty()) {
        auto t = q.front();
        q.pop_front();
        char ch = g[t.first][t.second];

        for(int i = 0; i < 4; i++) {
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a < 0 or a >= n or b < 0 or b >= m) continue;
            if(vis[a][b]) continue;

            vis[a][b]  =true;
            if(g[a][b] == ch) {
                dist[a][b] = dist[t.first][t.second];
                q.push_front({a, b}); // 插入队头
            } else {
                dist[a][b] = dist[t.first][t.second] + 1;
                q.push_back({a, b}); // 插入队尾
            }
            if(a == x2 and b == y2) return dist[a][b];
        }
    }
    return -1;
}

int main() {
    while(true) {
        cin >> n >> m;
        if(n == 0 and m == 0) break;
        // 由测试本次的数据可知是从 0 开始的
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> g[i][j];
            }
        }
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = bfs();
        cout << ans << endl;
        q.clear();
        memset(g, 0, sizeof g);
        memset(dist, 0, sizeof dist);
        memset(vis, false, sizeof vis);
    }


    return 0;
}