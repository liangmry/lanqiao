// P1332 血色先锋队
#include <iostream>
#include <queue>
#include <vector>
#define PII pair<int, int>
using namespace std;
// 多源bfs
const int N = 505;
const int px[] = {1,0,0,-1};
const int py[] = {0,1,-1,0};

int n, m, a, b;
vector<PII> src; // 感染源的坐标，一起入队
int dist[N][N]; // 扩散时间
bool vis[N][N]; // 是否被访问
queue<PII> q;

void bfs() {
    for(auto &t: src) {
        dist[t.first][t.second] = 0;
        q.push({t.first, t.second});
        vis[t.first][t.second] = true;
    }

    while(!q.empty()) {
        auto t = q.front();
        q.pop(); // 别忘记出队

        for(int i = 0; i < 4; i++) {
            int x2 = t.first+px[i], y2 = t.second+py[i];

            if(x2 < 1 or x2 > n or y2 < 1 or y2 > m) continue; // 超范围
            if(vis[x2][y2]) continue; // 已经被访问过

            q.push({x2, y2});
            vis[x2][y2] = true;
            dist[x2][y2] = dist[t.first][t.second] + 1;
        }
    }
}

int main()
{
    cin >> n >> m >> a >> b;
    for(int i = 1; i <= a; i++) {
        int x, y;
        cin >> x >> y;
        src.push_back({x, y});
    }
    bfs();
    for(int i = 1; i <= b; i++) {
        int x, y;
        cin >> x >> y;
        cout << dist[x][y] << endl;
    }
    return 0;
}