#include <iostream>
#include <algorithm>
using namespace std;

const int a = 9, b = 16;
bool st[9];
int cnt;

void dfs(int x, int a2, int b2)
{
    if(x > 7)
    {
        if(a2==a && b2==b)
            cnt++;
        return ;
    }
    // 组合问题，但是有两组组合要同时考虑
    for(int i=0; i<=5; i++)
    {
        for(int j=0; j<=5; j++)
        {
            if(i+j>=2 && i+j<=5)
                dfs(x+1, a2+i, b2+j);
        }
    }
}

int main()
{
    dfs(1, 0, 0);
    cout<<cnt;
    return 0;
}