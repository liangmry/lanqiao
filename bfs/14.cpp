// P2658 汽车拉力比赛
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

#define PII pair<int, int>
// 二分答案 + bfs
using namespace std;

const int N = 505;
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
int n, m;
int height[N][N]; // 海拔
int flag[N][N]; // 存放路标的位置
queue<PII> q;
bool vis[N][N];
int x1, y1; // 存放任意一个路标的坐标，在code里事实上存放了最后一个路标的位置
int cnt_flag; // 有多少个路标

bool check(int mid) {
    // 初始化数组 清空队列
    memset(vis, 0, sizeof vis);
    while(!q.empty()) q.pop();

    q.push({x1, y1}); // 放入路标位置
    vis[x1][y1] = true;

    int cnt = 1; // 现在搜到的路标

    while(!q.empty()) {
        auto t = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a < 1 or a > n or b < 1 or b > m) continue;
            if(vis[a][b]) continue;
            if(abs(height[a][b] - height[t.first][t.second]) > mid) continue; // 向数值较小方找

            vis[a][b] = true;
            q.push({a, b});
            if(flag[a][b] == 1) {
                cnt ++;
                // 全部找到，说明此距离可以满足，直接退出
                if(cnt == cnt_flag) return true;
            }
        }
    }
    return false;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%d", &height[i][j]);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%d", &flag[i][j]);
            if(flag[i][j] == 1) {
                x1 = i;
                y1 = j;
                cnt_flag++;
            }
        }
    }
    // 二分搜索
    int l = -1, r = 1e9+1;
    while(l + 1 < r) {
        int mid = (l + r) / 2;
        if(check(mid)) {
            r = mid; // 最大值最小问题
        } else {
            l = mid;
        }
    }
    printf("%d\n", r);
    return 0;
}

// 保留了另一种 纯靠数组 的bfs写法
/*
bool check(int mid) {
    q[0] = {x1, y1};
    st[x1][y1] = true;
    int cnt = 1;   //统计当前已到达的路标的个数
    int hh = 0, tt = 0;

    while(hh <= tt) {
        auto t = q[hh ++];

        for(int i = 0; i < 4; i ++) {
            int a = t.x + dx[i], b = t.y + dy[i];

            if(a < 1 || a > n || b < 1 || b > m) continue;
            if(st[a][b]) continue;
            if(abs(high[t.x][t.y] - high[a][b]) > mid) continue;

            q[++tt] = {a, b};
            st[a][b] = true;

            if(flag[a][b] == 1) {
                cnt ++;
                if(cnt == cnt_flag) {
                    return true;
                }
            }
        }
    }
    return false;
}
 */
