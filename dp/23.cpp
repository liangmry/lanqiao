// P1048 [NOIP2005 普及组] 采药
#include <iostream>
#include <algorithm>

using namespace std;
// 01背包 正序递推 和 背包降维 依旧不是很懂（懒得看），暂且放弃

const int N = 105, M = 1005;
int n, T;
int drug[N], times[N];
int f[N][M]; // f[N][N] md第二维开小了,怪不得过不了

int dfs(int x, int surplus) {
    if(x > n) return 0;
    // 不能选x
    if(surplus < times[x]) return dfs(x+1, surplus);
        // 选或不选x
    else return max(dfs(x+1, surplus), dfs(x+1, surplus-times[x]) + drug[x]);
}

int main() {
    // 加速cin cout 可以用，但没必要，当作了解即可
    // 关闭输入输出缓存，使效率提升
    ios::sync_with_stdio(false);
    // 解除cin和cout的默认绑定，来降低IO的负担使效率提升
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T >> n;
    for(int i = 1; i <= n; i++) {
        cin >> times[i] >> drug[i];
    }
    //cout << dfs(1, T);

    // dp
    for(int i = n; i >= 1; i--) {
        for(int j = 0; j <= T; j++) {
            if(j < times[i]) f[i][j] = f[i+1][j];
            else f[i][j] = max(f[i+1][j], f[i+1][j-times[i]] + drug[i]);
        }
    }
    cout << f[1][T];
    return 0;
}