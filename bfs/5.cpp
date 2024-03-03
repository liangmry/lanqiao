// P2895 [USACO08FEB] Meteor Shower S
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define PII pair<int, int>

using namespace std;
// 有外界干扰的迷宫问题
const int N = 305;
const int px[] = {1,-1,0,0};
const int py[] = {0,0,1,-1};
int meteor[N][N];
queue<PII> q;
bool vis[N][N];
int dist[N][N]; // 我移动

int bfs() {
    vis[0][0] = true;
    dist[0][0] = 0;
    q.push({0,0});

    while(!q.empty()) {
        auto t = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int a = t.first + px[i], b = t.second + py[i];

            if(a < 0 or b < 0) continue; // 保证在第一象限内
            if(vis[a][b]) continue; // 不能重复走某一点
            if(dist[t.first][t.second]+1 >= meteor[a][b]) continue; // 该点被砸过 ---注意！！ 不是dist[a][b]>=.. （因为还没赋值）

            vis[a][b] = true;
            dist[a][b] = dist[t.first][t.second] + 1;
            q.push({a, b});
            if(meteor[a][b] > 1e9) return dist[a][b];
        }
    }
    return -1;
}

int main()
{
    // 表示还有很长的时间后，才会砸下来 --> 表示安全区域
    memset(meteor, 0x3f, sizeof meteor); // 直接初始化较大的数，再用min，否则容易出错
    int m;
    cin >> m;
    while(m--) {
        int x, y, t;
        cin >> x >> y >> t;
        meteor[x][y] = min(meteor[x][y], t); // 先砸下来，该点就已经不能走了
        for(int i = 0; i < 4; i++) {
            int a = x + px[i], b = y + py[i];
            if(a < 0 or b < 0 or a > 301 or b > 301) continue;
            meteor[a][b] = min(meteor[a][b], t);
        }
    }

    int ans = bfs();
    cout << ans;
    return 0;
}

// 错误案例 --
/*
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define PII pair<int, int>

using namespace std;

int n;
const int N = 305;
const int dx[] = {0,0,0,1,-1},
          dy[] = {0,1,-1,0,0};
int g[N][N];
queue<PII> q;
bool vis[N][N];
int dist[N][N];

void boom(int x, int y, int t) {
    for(int i = 0; i <= 4; i++) {
        int a = x + dx[i], b = y + dy[i];
        if(a < 0 or a >= N or b < 0 or b >= N) continue;
        if(g[a][b] == 0) g[a][b] = t;
        else g[a][b] = min(g[a][b], t);
    }
}

int bfs() {
    q.push({0, 0});
    vis[0][0] = true;

    while(!q.empty()) {
        auto t = q.front();
        q.pop();

        for(int i = 1; i <= 4; i++) {
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a < 0 or a >= N or b < 0 or b >= N) continue;
            if(vis[a][b]) continue;
            if(dist[t.first][t.second] + 1 >= g[a][b] and g[a][b] != 0) continue; // 这里需要判断 两次

            vis[a][b] = true;
            dist[a][b] = dist[t.first][t.second] + 1;
            q.push({a, b});
            if(g[a][b] == 0) return dist[a][b];
        }
    }
    return -1;
}

int main() {
//    memset(g, 0x3f, sizeof g);
    cin >> n;
    while(n--) {
        int x, y, t;
        cin >> x >> y >> t;
        boom(x, y, t);
    }
    cout << bfs();
    return 0;
}
 */