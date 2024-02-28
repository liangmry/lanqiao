// 棋盘问题 https://www.acwing.com/problem/content/description/1116/
#include <iostream>

using namespace std;

int n, k;
const int N = 10;
char chessboard[N][N];
bool st[N]; // 记录第i列的状态
int res;
// 行列 枚举同时考虑，保证每行每列只有一个棋子
void dfs(int x, int cnt) // 枚举到第x行
{
    if(cnt == k)
    {
        res++;
        return ;
    }
    if(x > n) return ;

    for(int i=1; i<=n; i++)
    {
        if(!st[i] && chessboard[x][i]=='#') // 第i列未放棋子 且能放
        {
            st[i] = true;
            dfs(x+1, cnt+1);
            st[i] = false; // 回溯状态
        }
    }
    //  #.
    //  .#
    // 强行进入第二行第二列，否则该地方会直接退出函数，永远不会被访问
    // 同时指的是进入，还没判断要不要放，所以cnt没有+1
    dfs(x+1, cnt);
}

int main()
{
    while(cin>>n>>k, n>0&&k>0)
    {
        for(int i=1; i<=n; i++)
            scanf("%s", chessboard[i]+1);
        res = 0;
        dfs(1, 0);
        printf("%d\n", res);
    }
    return 0;
}