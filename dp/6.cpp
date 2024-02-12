// P1028 [NOIP2001 普及组] 数的计算
#include <iostream>

using namespace std;

int n;
const int N = 1e3+5;
int dp[N][N];

int dfs(int x, int end) {
    if(x <= 0) return 1;
    else return dfs(x/2, x) + dfs(x-1, end);
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        dp[0][i] = 1; // 这个初始化的式子也是靠画树，得出的
    for(int i = 1; i <= n / 2; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = dp[i/2][i] + dp[i-1][j];
        }
    }
    cout << dp[n/2][n];
    return 0;
}


// 一个错误的思路--》到纠正
// 通过画搜索树发现的错误

//int dfs(int x, int end) {
//    if(x <= 0) return 1;
////    if(x > end) return 0;
//    else return dfs(x/2, x) + dfs(x-1, end);
//    // 选
////    dfs(x/2, x);
//    // 不选
////    dfs(x/2-1, end);  **** 这个写错了
//}
//
//int main() {
//    cin >> n;
//    int ans = 0;
//    ans = dfs(n/2, n);
////    for(int i = n/2; i >= 1; i--) {
////        ans += dfs(i, n);
////    }
//    cout << ans;
//    return 0;
//}