// P1164 小A点菜
#include <iostream>

using namespace std;

int n, m; // n种菜，m元钱
const int N = 102;
int dish[N];

int dp[105][10005];

// 暴力
//int dfs(int x, int surplus) { // 第x道菜，剩余的钱
//    if(x > n){ // 所有菜都选完了
//        if(surplus == 0) return 1;
//        else return 0;
//    }
//    return dfs(x+1, surplus-dish[x]) + dfs(x+1, surplus);
//}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> dish[i];
//    int ans = dfs(1, m);
//    cout << ans;

    // 递推
    dp[n+1][0] = 1;
    for(int i = n; i >= 1; i--) {
        for(int j = 0; j <= m; j++) {
            dp[i][j] = dp[i+1][j-dish[i]] + dp[i+1][j];
        }
    }
    cout << dp[1][m];
    return 0;
}