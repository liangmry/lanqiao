// P2089 烤鸡
#include <iostream>

using namespace std;

int n; // 美味程度，即 总和
const int N = 60000;
int f[12], cnt, res[N][12];

void dfs(int x)
{
    if(x > 10)
    {
        int sumx = 0;
        for(int i=1; i<=10; i++)
        {
            sumx += f[i];
        }
        if(sumx == n)
        {
            cnt++;
            for(int i=1; i<=10; i++)
            {
                res[cnt][i] = f[i];
            }
        }
        return ;
    }

    for(int i=1; i<=3; i++)
    {
        f[x] = i;
        dfs(x+1);
    }
}

int main()
{
    cin >> n;
    if(n > 30) { // 根据 数据范围 特判
        cout << 0;
        return 0;
    }

    dfs(1);
    cout<<cnt<<endl;
    for(int i=1; i<=cnt; i++)
    {
        for(int j=1; j<=10; j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}