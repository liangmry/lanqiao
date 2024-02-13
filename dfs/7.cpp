// P2036 [COCI2008-2009 #2] PERKET
#include <iostream>
#include <algorithm>

using namespace std;
// 指数型枚举

const int N = 12;
int n;
int sour[N], bitter[N];
int res = 1e9;

void dfs(int x, int s, int b) {
    if(x > n) {
        if(s == 1 and b == 0) return ; // 至少要加一种配料
        res = min(res, abs(s-b));
        return ;
    }

    // 选
    dfs(x+1, s*sour[x], b+bitter[x]); // 选择的话，酸 苦 都选了

    // 不选
    dfs(x+1, s, b);
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> sour[i] >> bitter[i];
    }
    dfs(1, 1, 0);
    cout << res;
    return 0;
}