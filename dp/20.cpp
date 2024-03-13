// P1507 NASA的食物计划
#include <iostream>
#include <algorithm>

using namespace std;
// 二维01背包

const int N = 52;
int V, W, n;
int v[N], w[N], c[N];
int f[N][402][402];

// 暴力
int dfs(int x, int sur_v, int sur_w) { // 剩余体积 剩余质量
    if(x > n) {
        return 0;
    } else {
        if(sur_v < v[x] or sur_w < w[x]) { // 不能选x
            return dfs(x+1, sur_v, sur_w);
        } else {
            return max(dfs(x+1, sur_v-v[x], sur_w-w[x]) + c[x], dfs(x+1, sur_v, sur_w));
        }
    }
}

int main() {
    cin >> V >> W >> n;
    for(int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i] >> c[i];
    }
//    cout << dfs(1, V, W);

    // dp
    for(int i = n; i >= 1; i--) {
        for(int j = 0; j <= V; j++) {
            for(int k = 0; k <= W; k++) {
                if(j < v[i] or k < w[i]) f[i][j][k] = f[i+1][j][k];
                else f[i][j][k] = max(f[i+1][j-v[i]][k-w[i]]+c[i], f[i+1][j][k]);
            }
        }
    }
    cout << f[1][V][W];
    return 0;
}