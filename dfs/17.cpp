#include <iostream>
using namespace std;

int a[5][5], ans;

void dfs(int i, int j, int op)
{
    // 行号不能超4， 列号与该行相关，也不能超
    if(i > 4 || i+j>4)
        return ;
    //三个操作码
    if(op == 0)
        a[i][j] = a[i-1][j] & a[i-1][j+1];
    else if(op == 1)
        a[i][j] = a[i-1][j] | a[i-1][j+1];
    else if (op == 2)
        a[i][j] = a[i-1][j] ^ a[i-1][j+1];
    //若最后一个数为1，则满足条件
    if(i==4&&j==0&&a[i][j]==1)
        ans++;
    // 对行和列的移动做判断
    if(i+j<=3)
        j++;
    else
    {
        i++;
        j=0;
    }
    // dfs
    dfs(i, j, 0);
    dfs(i, j, 1);
    dfs(i, j, 2);
}

int main() {
    a[0][0] = 1, a[0][2] = 1, a[0][4] = 1;
    //dfs的起始位置为第一行，因为第0行已经填好了数
    dfs(1, 0, 0);
    dfs(1, 0, 1);
    dfs(1, 0, 2);
    cout<<ans;
    return 0;
}
