#include<iostream>
using namespace std;

// 指数级枚举

int n;
const int N = 20;
int st[N];//状态 0未定  1不选  2选

void dfs(int x)
{
    if(x > n)
    {
        for(int i = 1; i <= n; i++)
        {
            if(st[i] == 2)
            {
                cout << i << " ";
            }
        }
        cout << endl;
        return ;
    }

    //不选
    st[x] = 1;
    dfs(x+1);
    st[x]=0; //恢复状态

    //选
    st[x] = 2;
    dfs(x+1);
    st[x] = 0;
}

int main()
{
    cin >> n;
    dfs(1); //第一个位置
    return 0;
}