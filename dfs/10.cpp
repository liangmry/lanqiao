#include <iostream>
using namespace std;

int n, k; // n个数中选k个
const int N = 22;
int arr[N]; // 待选的数字
int res[N]; // 选出来的数字
int cnt; // 结果计数

bool isPrime(int *a) // 判断是否是素数
{
    int sum = 0;
    for(int i = 1; i <= k; i++)
    {
        sum += a[i];
    }
    if(sum <= 1)
        return false;
    for(int i = 2; i * i <= sum; i++)
    {
        if(sum % i == 0)
            return false;
    }
    return true;
}

void dfs(int x, int start) // x当前位置  start当前位置从几开始枚举
{
    //剪枝
    if(x > k)
    {
        if(isPrime(res))
            cnt++;
        return ;
    }

    for(int i = start; i <= n; i++)
    {
        //第x个位置选择当前枚举数的arr映射
        res[x] = arr[i];
        dfs(x+1, i+1);
        // 恢复状态(不写也行)
        res[x] = 0;
    }
}

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    dfs(1, 1);
    cout << cnt;
    return 0;
}