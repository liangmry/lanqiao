// 完全背包问题 https://www.acwing.com/problem/content/3/
#include <iostream>
#include <algorithm>
using namespace std;

int n, v; // n个物品 容量是v
const int N = 1005;
int volume[N], value[N];
int f[N][N];

// 暴力dfs
int dfs(int x, int surV) { //第x位 剩余背包容量surV
    if(surV <= 0) return 0;
    if(x > n) return 0;
    if (surV < volume[x]) return dfs(x+1, surV);
        // 选的时候，不用x+1，因为可能 继续选x
    else return max(dfs(x+1, surV), dfs(x, surV-volume[x])+value[x]);
}

int main() {
    cin >> n >> v;
    for(int i = 1; i <= n; i++) {
        cin >> volume[i] >> value[i];
    }
//    cout << dfs(1, v);

    // 改成 递推
    for(int i = n; i >= 1; i--) {
        for(int j = 0; j <= v; j++) {
            if(j < volume[i]) f[i][j] = f[i+1][j];
            else f[i][j] = max(f[i+1][j], f[i][j-volume[i]]+value[i]);
        }
    }
    cout << f[1][v];
    return 0;
}