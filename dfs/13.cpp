#include <iostream>
using namespace std;

const int match[] = {
        6, 2,5,5,4,5,6,3,7,6
};
int n; //一共n根， 全部用完---- n-4
// 指数级枚举，每个位置从0到16（最少2根 n-4 -4）
int cnt, arr[4];

int plus_matches(int i)
{
    if(i>=0 && i<=9) return match[i]; // 不能使用match[i], 因为i>9时会越界， 直接判断下标
    else
    {
        int sum = 0;
        while(i)
        {
            sum += match[i%10];
            i /= 10;
        }
        return sum;
    }
}

void dfs(int x, int sum) // sum当前用了几根
{
    if(sum > n-4)
        return ;
    if(x > 3)
    {
        if(sum == n-4 && (arr[1]+arr[2]==arr[3]))
        {
            cnt++;
        }
        return ;
    }
    for(int i = 0; i <= 800; i++) // 最初枚举数的范围有误，因为要保证等式成立，多跟火柴拼起来表示一个较大数
    {
        arr[x] = i;
        dfs(x+1, sum+ plus_matches(i));
        arr[x] = 0;
    }
}

int main()
{
    cin >> n;
    dfs(1, 0);
    cout << cnt;
    return 0;
}