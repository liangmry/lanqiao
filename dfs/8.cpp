// P1706 全排列问题
#include <iostream>

using namespace std;
// 全排列 每个位置都可以放任何数，前提是它还没有被放置
int n;
const int N = 10;
bool st[N];
int ans[N]; // 记录选好的数列

void dfs(int x) {
    if(x > n) {
        for(int i = 1; i <= n; i++) {
            printf("%5d", ans[i]); // 要求5个场宽
        }
        printf("\n");
        return ;
    }
    for(int i = 1; i <= n; i++) {
        if(!st[i]) {
            st[i] = true;
            ans[x] = i;
            dfs(x+1);

            // 恢复状态
            st[i] = false;
            ans[x] = 0; // 也可以不用写这句话
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}