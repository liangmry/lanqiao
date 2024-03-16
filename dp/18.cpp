// P1130 红牌
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
// 递推 / 动态规划

int n, m; // n组 m步
const int N = 2002;
int arr[N][N];
int res = 1e9;
int f[N][N];
int mem[N][N];

// 暴力 / mem
int dfs(int x, int y) { // x组 y步骤
    if(mem[x][y]) return mem[x][y];
    if(y > m) {
        return 0;
    }
    else {
        mem[x][y] = min(dfs(x, y + 1), dfs(x % n + 1, y + 1)) + arr[x][y]; // 第一次写时：取余操作错误
        return mem[x][y];
    }
}
int main() {
    cin >> m >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        res = min(res, dfs(i, 1));
    }
    cout << res;

    // dp存疑，循环内外层要互换，暂时不知道为什么
//    for(int i = n; i >= 1; i--) {
//        for(int j = m; j >= 1; j--) {
//            f[i][j] = min(f[i][j+1], f[i % n + 1][j+1]) + arr[i][j];
//        }
//        res = min(res, f[i][1]);
//    }
//    cout << res;
    return 0;
}