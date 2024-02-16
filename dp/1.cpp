// P1216 [USACO1.5] [IOI1994]数字三角形 Number Triangles
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1005;
int r;
int g[N][N], dp[N][N];

int main()
{
    cin >> r;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= i; j++) {
            cin >> g[i][j];
        }
    }
    dp[1][1] = g[1][1];
    dp[1][0] = 0;
    for(int i = 2; i <= r; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i-1][j]+g[i][j], dp[i-1][j-1]+g[i][j]);
        }
    }

    // 自顶向下递推，最后一行每个点都可能是终点，需要遍历找最大的那个
    int res = 0;
    for(int i = 1; i <= r; i++) {
        res = max(res, dp[r][i]);
    }
    cout << res;

//    自底向上递推，终点只有一个
//    for(int i = r; i >= 1; i--) {
//        for(int j = i; j >= 1; j--) {
//            dp[i][j] = max(dp[i+1][j]+g[i][j], dp[i+1][j+1]+g[i][j]);
//        }
//    }
//    cout << dp[1][1];
    return 0;
}


/*
 * 暴力
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1005;
int r;
int g[N][N];

int dfs(int x, int y) {
    if(x > r or y > x) return 0;
    else return max(dfs(x+1, y)+g[x][y], dfs(x+1, y+1)+g[x][y]);
}

int main()
{
    cin >> r;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= i; j++) {
            cin >> g[i][j];
        }
    }
    int ans = dfs(1, 1);
    cout << ans;
    return 0;
}
 */