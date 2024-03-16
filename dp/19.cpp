// 数字组合 https://www.acwing.com/problem/content/description/280/
#include <iostream>

using namespace std;

const int N = 102, M = 10002;
int n, m;
int arr[N];
int f[N][M];

// 暴力
int dfs(int x, int sum) {
    if(sum > m) return 0;
    if(x > n) {
        if(sum == m) return 1;
        else return 0;
    }
    return dfs(x+1, sum+arr[x]) + dfs(x+1, sum);
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
//    cout << dfs(1, 0);

    // dp
    // 初始化
    for(int i = 1; i <= n; i++) {
        f[n+1][m] = 1;
    }
    for(int i = n; i >= 1; i--) {
        for(int j = m; j >= 0; j--) {
            f[i][j] = f[i+1][j+arr[i]] + f[i+1][j];
        }
    }
    cout << f[1][0];
    return 0;
}