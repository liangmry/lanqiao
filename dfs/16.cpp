#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll res = 1e9;
ll n, m;
const int N = 32;
double arr[N]; // 输入的瓜
double suf[N];

ll min(ll a, ll b)
{
    return a < b ? a : b;
}

void dfs(int x, double sum, int cnt) // 当前选到第x个瓜  当前瓜的总重  切了几次瓜
{
    if(cnt >= res)
        return ;
    if(sum > m)
        return ;
    if(sum + suf[x] < m)
        return ;
    if(x > n)
    {
        if(sum == m)
        {
            res = min(res, cnt);
        }
        return ;
    }

    //选整个
    dfs(x+1, sum+arr[x], cnt);

    //选一半
    dfs(x+1, sum+arr[x]/2, cnt+1);

    // 不选
    dfs(x+1, sum, cnt);
}
int main()
{
    // 请在此输入您的代码
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lf", &arr[i]);
    }
// sort内的参数，注意数组的范围 [ ）原本我写的是arr+1,arr+n 明显少了最后一个元素（因为我是从1到n的数组）
    sort(arr+1, arr+n+1, greater<>());  //从大到小排序，先切质量大的，题干要求最少切几次
    for(int i = n; i >= 1; i--)
        suf[i] = arr[i] + suf[i+1]; //当前瓜及其之后所有瓜的总质量=从1到下一个瓜的总质量+当前瓜的质量
    dfs(1, 0, 0);
    if(res == 1e9)
    {
        printf("%d", -1);
        return 0;
    }
    printf("%lld", res);
    return 0;
}