// P1162 填涂颜色
#include <iostream>
#include <queue>
#define PII pair<int, int>

using namespace std;
// 闭合圈类的问题
const int N = 35;
const int px[] = {0,0,1,-1};
const int py[] = {1, -1, 0,0};

int n;
int g[N][N];
queue<PII> q;
bool vis[N][N];

void bfs(int x, int y) {
    vis[x][y] = true;
    q.push({x, y});

    while(!q.empty()) {
        auto t = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int a = t.first + px[i], b = t.second + py[i];

            if(a < 0 or a > n+1 or b < 0 or b > n+1) continue; // 更大，更外围的一圈
            if(g[a][b] == 1) continue;
            if(vis[a][b]) continue; // 已经被访问过，不再访问

            vis[a][b] = true;
            q.push({a, b});
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }
    // 从更边界的地方开始，因为本题只有一个圈
    bfs(0, 0);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(vis[i][j] == false and g[i][j] == 0) {
                g[i][j] = 2;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


/*
 * 做对比
 * 以下是第一次做的时候的思路
 * 当时主要目标是找边界
 *
#include <iostream>
#include <queue>
#include <vector>
#define PII pair<int, int>
using namespace std;

const int N = 35;
const int px[] = {1,-1,0,0};
const int py[] = {0,0,1,-1};

int n;
int g[N][N]; // 输入的图
queue<PII> q;
bool connect[N][N]; // bfs专用判断访问  一个能到边界，相当于它经过的路径上的节点也能到边界
vector<PII> nodes; // 搜索路上经过的节点

bool bfs(int x, int y) {
    bool vis[N][N];  // bfs专用判断访问
    q.push(make_pair(x, y)); // 入队
    vis[x][y] = true;
    nodes.push_back({x, y});

    while(!q.empty()) {
        auto t = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int a = t.first+px[i], b = t.second+py[i];

            if(a < 1 or a > n or b < 1 or b > n) { // 搜索到边界，说明不在圈内
                return true;
            }
            if(connect[a][b]) return true; // 与之相关的节点能找到边界
            if(g[a][b] == 1) continue; // 碰到圈了
            if(vis[a][b]) continue;

            nodes.push_back({a, b});
            vis[a][b] = true;
        }
    }
    return false;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> g[i][j];
            nodes.clear();
            if(!connect[i][j] and g[i][j] == 0) {
                if(bfs(i, j)) {
                    for(auto &t: nodes) {
                        connect[t.first][t.second] = true;
                    }
                }
            }
        }
    }
    for(int i = 1; i <= n ;i++) {
        for(int j = 1;  j <= n; j++) {
            if(!connect[i][j] && g[i][j] == 0)
                cout << 2 << " ";
            else if(connect[i][j])
                cout << g[i][j] << " ";
            else if(g[i][j] == 1)
                cout << 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
 */

// 上面的方法可行，但是每次bfs都要清空队列，并且vis要初始化
// 重要的是对初始点做对判断 {x, y} 而非 {t.first, t.second}

/* 比较笨的方法：每个点都判断能否到达边界
#include <iostream>
#include <queue>
#include <cstring>
#define PII pair<int, int>

using namespace std;

int n;
const int N = 33;
int g[N][N];
queue<PII> q;
bool vis[N][N];
const int dx[] = {1,-1,0,0},
          dy[] = {0,0,1,-1};

void bfs(int x, int y) {
    while(!q.empty()) q.pop();
    memset(vis, 0, sizeof vis);

    q.push({x, y});
    vis[x][y] = true;

    while(!q.empty()) {
        auto t = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a < 1 or a > n or b < 1 or b > n) {
                g[x][y] = 0;
                continue;
            }
            if(g[a][b] == 1) continue;
            if(vis[a][b]) continue;

            vis[a][b] = true;
            q.push({a, b});
        }
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> g[i][j];
            if(g[i][j] == 0) {
                g[i][j] = 2;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(g[i][j] == 2) {
                bfs(i, j);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
 */