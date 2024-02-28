// 二维费用的背包问题 https://www.acwing.com/problem/content/8/
#include <iostream>
#include <algorithm>
using namespace std;
// 有两个变量需要在选物品时考虑

int n, v, m; // n个物品 容量v 可承受质量m
const int N = 1005;
int volume[N], weight[N], value[N];
//int f[N][105][105]; 三维数组的下标太大了
int f[N][N];

// dfs 返回价值
int dfs(int x, int surV, int surW) { // 第x个物品 剩余容积surV 剩余质量surW
    if(surV <= 0 or surW <= 0) return 0; // 终止条件 服务于递推
    if(x > n) return 0;
    if(surV < volume[x] or surW < weight[x]) return dfs(x+1, surV, surW); // 只能不选
    else return max(dfs(x+1, surV, surW), dfs(x+1, surV-volume[x], surW-weight[x])+value[x]);
}

int main() {
    cin >> n >> v >> m;
    for(int i = 1; i <= n; i++) {
        cin >> volume[i] >> weight[i] >> value[i];
    }
//    cout << dfs(1, v, m);

    // 改成递推 从下向上--从结尾向开头
    /*  三维
    for(int i = n; i >= 1; i--) {
        for(int j = 0; j <= v; j++) {
            for(int k = 0; k <= m; k++) {
                if(j < volume[i] or k < weight[i]) f[i][j][k] = f[i+1][j][k];
                else f[i][j][k] = max(f[i+1][j][k], f[i+1][j-volume[i]][k-weight[i]]+value[i]);
            }
        }
    }
    cout << f[1][v][m];
     */

    // 背包数组 降维
    // 没能完成！！！
//    for(int i = n; i >= 1; i--) {
//        for(int j = 0; j <= volume[i]; j++) {
//            for(int k = 0; k <= weight[i]; k++) {
//                f[j][k] = max(f[j][k], f[j-volume[i]][k-weight[i]]+value[i]);
//            }
//        }
//    }

    // 现在完成了，以下是失败原因：
    // 如果 j 和 k 从 0 开始遍历，
    // 那么在状态转移方程中可能会用到 f[j - volume[i]][k - weight[i]]，--- 出现负数下标！！！
    // 而这会超出数组 f 的范围
    for(int i = 1; i <= n; i++) {
        for(int j = v; j >= volume[i]; j--) {
            for(int k = m; k >= weight[i]; k--) {
                f[j][k] = max(f[j][k], f[j - volume[i]][k - weight[i]] + value[i]);
            }
        }
    }
    cout << f[v][m] << endl;
    return 0;
}