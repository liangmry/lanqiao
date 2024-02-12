#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int ans;

void dfs(int x, int start, int sum)
{
    if(sum > n) return ;
    if(x > k)
    {
        if(sum == n)
            ans++;
        return ;
    }

    // 不降原则，后面枚举的数字一定比前面大,再做一个剪枝
    for(int i = start; sum+i*(k-x+1) <= n; i++)
    {
        // 1 1 5
        // 有两个是重复的，所以下面的形参不是i+1
        dfs(x+1, i, sum+i);
    }
}

int main()
{
    cin >> n >> k;
    dfs(1, 1, 0);
    cout << ans;
    return 0;
}