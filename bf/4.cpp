// P3392 涂条纹
#include <bits/stdc++.h>
using namespace std;
// dfs做了枚举

const int N = 52;
int n, m;
char g[N][N];
int nums[4]; // 染色方案
int ans = 1e9;

void dyeing() {
    // 每次拷贝一份g数组
    char g2[N][N];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            g2[i][j] = g[i][j];
        }
    }
    int cnt = 0;
    for(int i = 1; i <= nums[1]; i++) {
        for(int j = 1; j <= m; j++) {
            if(g2[i][j] != 'W') cnt++;
        }
    }
    for(int i = nums[1] + 1; i <= nums[1] + nums[2]; i++) {
        for(int j = 1; j <= m; j++) {
            if(g2[i][j] != 'B') cnt++;
        }
    }
    for(int i = nums[1] + nums[2] + 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(g2[i][j] != 'R') cnt++;
        }
    }
    ans = min(ans, cnt);
}

void dfs(int x) {
    int sum = 0;
    for(int i = 1; i <= 3; i++) sum += nums[i];
    if(sum > n) return ;

    if(x > 3) {
        if(sum == n) {
            dyeing();
        }
        return ;
    }

    for(int i = 1; i <= n - 2; i++) {
        nums[x] = i;
        dfs(x + 1);
        nums[x] = 0;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    dfs(1);
    printf("%d", ans);
    return 0;
}