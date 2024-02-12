#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define PII pair<int, int>

using namespace std;

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
            if(dist[t.first][t.second]+1 >= meteor[a][b]) continue; // 该点被砸过

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
    memset(meteor, 0x3f, sizeof meteor);
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