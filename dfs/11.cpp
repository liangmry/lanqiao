// P1683 入门
#include <iostream>

using namespace std;
// 搜索， “没有” 利用st数组回溯了 （多多思考哪些需要回溯）
// 本题，没有做恢复状态，因为走过之后不能重复计数----或者说只有这样才满足题意

int n, m;
const int N = 22;
const int px[] = {0, 0, 1, -1};
const int py[] = {1, -1, 0, 0};
char g[N][N];
int sx, sy; // 起点
bool st[N][N]; // 走不走过这块砖
int cnt = 1;

void dfs(int x, int y) {
    if(x < 1 or x > n or y < 1 or y > m)
        return ;
    for(int i = 0; i <= 3; i++) {
        int a = x + px[i], b = y + py[i];
        if(!st[a][b]) {
            st[a][b] = true;
            if(g[a][b] == '#') continue; // 不能走的砖
            if(a < 1 or a > n or b < 1 or b > m) continue;
            cnt++;
            dfs(a, b);
        }

    }
}

int main() {
    cin >> m >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> g[i][j];
            if(g[i][j] == '@') {
                sx = i, sy = j;
            }
        }
    }
    st[sx][sy] = true;
    dfs(sx, sy);
    cout << cnt;
    return 0;
}