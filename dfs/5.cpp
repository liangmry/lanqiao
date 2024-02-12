#include "bits/stdc++.h"
using namespace std;
int n; //火星人给的数字总数
int m; //要加的数
const int N=10003;
bool st[N];//枚举数的状态
int mars[N];//火星人输入的数
int res = 0, arr[N]; //已经选好的排列数
bool ff;
void dfs(int x)
{
    if(ff)
        return ;

    if(x > n)
    {
        res++;
        if(res == m+1)
        {
            ff=true;
            for(int i=1; i<=n; i++)
            {
                cout << arr[i] << " ";
            }
        }
        return ;
    }

    for(int i=1; i<=n; i++)
    {
        if(!res)
        {
            i = mars[x];
        }
        if(!st[i])
        {
            st[i] = true;
            arr[x] = i;
            dfs(x+1);
            st[i] = false;
            arr[x] = 0;
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>mars[i];
    }
    dfs(1);

    return 0;
}