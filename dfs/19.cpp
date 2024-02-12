#include <iostream>
#include <algorithm>
using namespace std;

int m, n; // 列 行
const int N = 22;
char arr[N][N];
int sx, sy; // 第一块砖的坐标
const int px[] = {1,0,-1,0}, py[] = {0,1,0,-1};
int ans = 1; // 初始位置也在计数范围内
bool st[N][N];

void dfs(int x, int y) // 当前位置（x,y）
{

    for(int i = 0; i <= 3; i++)
    {
        // 不能回溯， 每个走过的点只能计数一次， 类比于求最少的计数答案
        if(!st[x+px[i]][y+py[i]])
        {
            st[x+px[i]][y+py[i]] = true;
            if(arr[x+px[i]][y+py[i]] == '.' && x+px[i]>=1 && x+px[i]<=n &&
               y+py[i]>=1 && y+py[i]<=m)
            {
                ans++;
                dfs(x+px[i], y+py[i]);
            }

        }

    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> m >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == '@')
            {
                sx = i;
                sy = j;
            }
        }
    }
    st[sx][sy] = true;
    dfs(sx, sy);
    cout<<ans;

    return 0;
}