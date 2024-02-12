#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1005;
int n, m; // m背包容积
int v[N], w[N]; // 体积  价值
int f[N][N];

// 递推 动态规划
// 还可以空间优化
// 更进一步可以用滚动数组
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }

    for(int i = n; i >= 1; i--) { // 画递归搜索树 一目了然
        for(int j = 0; j <= m; j++) { // j相当于spV，表示背包当前剩余容积
            if(j < v[i]) f[i][j] = f[i+1][j];
            else f[i][j] = max(f[i+1][j-v[i]]+w[i], f[i+1][j]);
        }
    }
    cout << f[1][m]; // 最终状态 第一个物品，背包容积初始
    return 0;
}


/*
 * 暴力
const int N = 1005;
int n, m; // m背包容积
int v[N], w[N]; // 体积  价值

// 返回的是价值
int dfs(int x, int spV) { // 当前选到第x个物品  背包剩余容积 (只有这两个变量影响到边界的条件)
    if(x > n) return 0;
    else if(v[x] > spV) return dfs(x+1, spV);
    else if(v[x] <= spV) return max(dfs(x+1, spV-v[x])+w[x], dfs(x+1, spV));
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    int ans = dfs(1, m);
    cout << ans;
    return 0;
}
 */



/*
 * 记忆化
const int N = 1005;
int n, m; // m背包容积
int v[N], w[N]; // 体积  价值
int mem[N][N];

// 返回的是价值
int dfs(int x, int spV) { // 当前选到第x个物品  背包剩余容积
    if(mem[x][spV]) return mem[x][spV];
    int sum = 0;
    if(x > n) sum = 0;
    else if(v[x] > spV) sum = dfs(x+1, spV);
    else if(v[x] <= spV) sum = max(dfs(x+1, spV-v[x])+w[x], dfs(x+1, spV));
    mem[x][spV] = sum;
    return sum;
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    int ans = dfs(1, m);
    cout << ans;
    return 0;
}

 */