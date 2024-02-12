#include <iostream>
using namespace std;

int n, m;
const int N = 104;
int arr[N][N];
bool st[N][N]; //当前位置是否滑行到过
const int px[] = {0, 1, -1, 0};
const int py[] = {1, 0, 0, -1};
int res;
int dp[N][N]; // 记忆化搜索，当用到该节点时直接调用数组

int dfs(int x, int y) // 求深度
{
    if(x < 1 || x > n || y < 1 || y > m)
        return 0;
    if(dp[x][y])
        return dp[x][y];

    int mx = 0;
    for(int i = 0; i <= 3; i++)
    {
        if(!st[x][y])
        {
            st[x][y] = true; // 标记为已被访问
            int a = x+px[i], b = y+py[i];
            if(arr[x][y] > arr[a][b] && a>=1 && a<=n && b>=1 && b<=m)
            {
                mx = max(mx, dfs(a, b));
            }
            // 恢复状态
            st[x][y] = false;
        }
    }
    dp[x][y] = mx + 1;
    return dp[x][y];
}


int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> arr[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            res = max(res, dfs(i, j));
        }
    cout << res;
    return 0;
}