#include <iostream>
#include <algorithm>
using namespace std;

int n;
const int N = 12;
int sour[N], bitter[N];
int st[N]; // 0未考虑 1选 2不选
int res = 1e9;

void dfs(int x)
{
    if(x > n)
    {
        int sum1 = 1, sum2 = 0;
        bool ff = false;
        for(int i = 1; i <= n; i++)
        {
            if(st[i] == 1)
            {
                ff = true;
                sum1 *= sour[i];
                sum2 += bitter[i];
            }
        }
        if(ff)
            res = min(res, abs(sum1-sum2));
        return ;
    }
    //选
    st[x] = 1;
    dfs(x+1);
    st[x] = 0;
    //不选
    st[x] = 2;
    dfs(x+1);
    st[x] = 0;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> sour[i] >> bitter[i];
    dfs(1);
    cout << res;
    return 0;
}