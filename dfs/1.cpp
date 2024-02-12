/*
 * 接龙数列
 * 对于一个长度为 K 的整数数列：A1, A2, . . . , AK，我们称之为接龙数列当且仅当 Ai 的首位数字恰好等于 Ai−1 的末位数字 (2 ≤ i ≤ K)。
例如 12, 23, 35, 56, 61, 11 是接龙数列；12, 23, 34, 56 不是接龙数列，因为 56的首位数字不等于 34 的末位数字。所有长度为 1 的整数数列都是接龙数列。
现在给定一个长度为 N 的数列 A1, A2, . . . , AN，请你计算最少从中删除多少个数，可以使剩下的序列是接龙序列？
 */
//动态规划
#include <bits/stdc++.h>
using namespace std;
int n, dp[10];
int main()
{
    cin >> n;
    int maxn=-1;
    for(int i=0; i<n; i++)
    {
        string s;
        cin >> s;
        int a=s[0]-'0', b=s.back()-'0';
        dp[b]=max(dp[b], dp[a]+1);
        maxn = max(maxn, dp[b]);
    }
    cout << n-maxn;
    return 0;
}