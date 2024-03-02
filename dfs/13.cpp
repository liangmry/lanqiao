// P1025 [NOIP2001 提高组] 数的划分
#include <iostream>
#include <cstring>

using namespace std;
// dfs 组合型枚举

int n, k;
int cnt;

//int mem[200][200];

void dfs(int x, int start, int sum) {
    if(sum > n) return ;
    if(x > k) {
        if(sum == n) cnt++;
        return ;
    }
    for(int i = start; i <= n; i++) { // 这里的循环终止条件，时间上过不去 --> sum+(k-x+1)*i<=n
        dfs(x+1, i, sum+i); // 这里的start是 i，而不是i+1. 因为枚举的数 可能有1 1 5，出现了两个相同的数
    }
}
// 记忆化
/*
int dfs(int x, int start_x, int sum) {
    if(mem[x][start_x][sum] != -1) return mem[x][start_x][sum];
    if(sum > n) return 0;
    if(x > k) {
        if(sum == n) return 1;
        return 0;
    }
    int cnt = 0;
    for(int i = start_x; i <= n; i++) {
        cnt +=  dfs(x+1, i, sum+i);
    }
    mem[x][start_x][sum] = cnt;
    return cnt;
}
*/

int main() {
    cin >> n >> k;
    dfs(1, 1, 0);
    cout << cnt;
    return 0;
}