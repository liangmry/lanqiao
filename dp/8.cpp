// P2437 蜜蜂路线
#include <iostream>

using namespace std;
// 高精度 + 斐波那契数列
int m, n;
const int N = 1005;
int dp[N][N];
int len = 1;

void func(int x) {
    for(int i = 1; i <= len; i++) {
        dp[x][i] = dp[x-1][i] + dp[x-2][i];
    }
    for(int i = 1; i <= len; i++) {
        if(dp[x][i] >= 10) {
            dp[x][i+1] += dp[x][i]/10;
            dp[x][i] %= 10;
        }
    }
    if(dp[x][len+1]) len++;
}

int main() {
    cin >> m >> n;
    dp[m][1] = 1;
    dp[m+1][1] = 1;
    for(int i = m+2; i <= n; i++)
        func(i);
    for(int i = len; i >= 1; i--)
        cout << dp[n][i];
    return 0;
}