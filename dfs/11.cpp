#include <iostream>
using namespace std;

char arr[32][62];
bool st[32][62]; // 此位置是否遍历过
int res; // 连通块大小 更新
int cnt;

void dfs(int x, int y)
{
    if(x < 1 || x > 30 || y < 1 || y > 60 || arr[x][y] == '0')
        return ;
    if(!st[x][y])
    {
        st[x][y] = true;
        if(arr[x][y] == '1')
        {
            cnt++;
        }
        dfs(x+1, y);
        dfs(x-1, y);
        dfs(x, y+1);
        dfs(x, y-1);
        // 没有恢复状态，路径间是相互的，只要从一方找到另一方即可？？？？
    }


}

int main()
{
    for(int i = 1; i <= 30; i++)
    {
        for(int j = 1; j <= 60; j++)
            cin >> arr[i][j];
    }
    for(int i = 1; i <= 30; i++)
    {
        for(int j = 1; j <= 60; j++)
        {
            cnt = 0;
            dfs(i, j);
            if(cnt > res)
                res = cnt;
        }

    }
    cout << res;
    return 0;
}