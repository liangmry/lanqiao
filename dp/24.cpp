// P1616 疯狂的采药
#include <iostream>
#include <algorithm>

using namespace std;
// 完全背包 + 降维
const int N = 1e4 + 5, M = 1e7 + 5;
int n, T;
int times[N], values[N];
int f[N][M];

int dfs(int x, int surplus_t) {
    if(x > n) return 0;
    if(surplus_t < times[x]) return dfs(x+1, surplus_t);
    else return max(dfs(x+1, surplus_t), dfs(x, surplus_t-times[x]) + values[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T >> n;
    for(int i = 1; i <= n; i++) {
        cin >> times[i] >> values[i];
    }
//    cout << dfs(1, T);

    // 必须降维，优化空间
    for(int i = n; i >= 1; i--) {
        for(int j = 0; j <= T; j++) {
            if(j < times[i]) f[i][j] = f[i+1][j];
            else f[i][j] = max(f[i+1][j], f[i][j-times[i]] + values[i]);
        }
    }
    cout << f[1][T];

//    ll f[M];
//    for(int i = n; i >= 1; i--) {
//        for(int j = times[i]; j <= T; j++) {  // 从可以选开始 推到 T，最后输出f[T]
//            f[j] = max(f[j], f[j-times[i]]+values[i]);
//        }
//    }
//    cout << f[T];

    return 0;
}