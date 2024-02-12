#include <iostream>

using namespace std;

int n;
const int N = 5005;
int dp[N][N]; // 高精度

int main() {
    cin >> n;
    dp[0][0] = 1;
    dp[1][0] = 1;
    int k = 1; // 当前数字的最大位数
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < k; j++) {
            dp[i][j] += dp[i-1][j] + dp[i-2][j]; // 递推公式
            if(dp[i][j] >= 10) { // 进位判断
                dp[i][j+1] += dp[i][j]/10; // 加十位前的数字，预防可能会很大
                dp[i][j] %= 10; // 最后一步让它保留个位
            }
        }
        if(dp[i][k]) k++; // 位数加一
    }
    for(int i = k-1; i >= 0; i--) // 倒序输出
        cout << dp[n][i];
    return 0;
}