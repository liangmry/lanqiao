// P1605 迷宫
#include <iostream>

using namespace std;
// dfs 搜索 回溯
int n, m, t; // t 障碍数
const int px[] = {0, 0, 1, -1}, py[] = {1, -1, 0, 0};
const int N = 7;
int g[N][N]; // 1表示障碍
int sx, sy, fx, fy;
bool st[N][N];
int res;

void dfs(int x, int y) {
    if(x == fx and y == fy) {
        res++;
        return ;
    }

    for(int i = 0; i < 4; i++) {
        int a = x + px[i], b = y + py[i];
        if(a < 1 or a > n or b < 1 or b > m) continue;
        if(!st[a][b] and g[a][b] == 0) {
            st[a][b] = true;
            dfs(a, b);
            // 回溯
            st[a][b] = false;
        }
    }
}

int main() {
    cin >> n >> m >> t >> sx >> sy >> fx >> fy;
    while(t--) {
        int a, b;
        cin >> a >> b;
        g[a][b] = 1;
    }
    st[sx][sy] = true; // 起点也要标记为走过！！！
    dfs(sx, sy);
    cout << res;
    return 0;
}