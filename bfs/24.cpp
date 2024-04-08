// P3956 [NOIP2017 普及组] 棋盘
#include <iostream>
#include <queue>
using namespace std;
// bfs + 优先级队列  重载运算符 时千万注意 大于 还是 小于 符号

const int N = 2001;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0,0, 1, -1};
int m, n;
int g[N][N]; // 0无色  else有色
bool vis[N][N];

struct piece {
    int x, y;
    int dis;
    bool flag;
    bool operator<(const piece & a) const {
        return dis > a.dis; // 默认是大根堆，要找花费最小，所以.....
    }
};

int bfs() {
    priority_queue<piece> q;
    piece now;
    now.x = 1, now.y = 1;
    now.dis = 0;
    now.flag = 0;
    vis[1][1] = true;
    q.push(now);

    while(!q.empty()) {
        piece now = q.top();
        q.pop();
        if(now.x == m and now.y == m) return now.dis;

        for(int i = 0; i < 4; i++) {
            piece next;
            int a = now.x + dx[i], b = now.y + dy[i];
            if(a >= 1 and a <= m and b >= 1 and b <= m and !vis[a][b]) {
                if(g[a][b] != 0) { // 有颜色
                    if(g[a][b] == g[now.x][now.y]) {
                        next.dis = now.dis;
                        next.flag = 0;
                        vis[a][b] = true;
                        next.x = a, next.y = b;
                        q.push(next);
                    } else {
                        next.dis = now.dis + 1;
                        next.flag = 0;
                        vis[a][b] = true;
                        next.x = a, next.y = b;
                        q.push(next);
                    }
                } else { // 无色
                    if(now.flag == 0) { // 可以使用魔法
                        g[a][b] = g[now.x][now.y];
                        next.dis = now.dis + 2;
                        next.flag = true;
                        vis[a][b] = true;
                        next.x = a, next.y = b;
                        q.push(next);
                    }
                }
                // 每个if里写进push，等重复的操作，不能写在公共部分，不知道为什么。可能是更新或者重复的原因吗？（我都不知道自己在说什么）
                // vis[a][b] = true;
                // next.x = a, next.y = b;
                // q.push(next);
            }

        }
        // 恢复状态
        // 可以不用，不知道具体原因，大概是最短路径不回头吗？
//        if(now.flag == 1) {
//            g[now.x][now.y] = 0;
//            now.flag = false;
//        }
    }
    return -1;
}

int main() {
    cin >> m >> n;
    int x, y, c;
    while(n--) {
        cin >> x >> y >> c;
        g[x][y] = c + 1;
    }
    cout << bfs();
    return 0;
}