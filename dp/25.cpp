// P1802 5 倍经验日
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e3 + 5;
int n, drugs;
int lose[N], win[N], use[N];
ll f[N][N];

int dfs(int x, int bag) {
    // 差点又写错，题目没审清楚
    // 分经验值  和 现有药量

    // 正确的
    if(x > n) return 0;
    // 为了写dp，还应该继续做剪枝。 因为当bag < 0 时，就只能被打败了
    bag -= use[x];
    // 能打过： 选择 打败 或者 不打败
    if(bag >= 0) return max(dfs(x+1, bag) + win[x], dfs(x+1, bag)+lose[x]); // 这里还有错误，dp是对的。我对他的题目表述非常怀疑
        // 那就记住这个细节，max中 这两个数的 dfs部分 肯定是 不同的

        // 根本打不过：只能被打败
    else return dfs(x+1, bag)+ lose[x];

    // 错误的
    /*
    if(x > n) return 0;
    bag -= use[x];
    // 能打过： 选择 打败 或者 不打败
    if(bag >= 0) return max(dfs(x+1, bag + win[x]), dfs(x+1, bag+lose[x])); ****主要是这里，没有加上经验值******
    // 根本打不过：只能被打败
    else return dfs(x+1, bag + lose[x]); ****此处同理****
     */

}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> drugs;
    for(int i = 1; i <= n; i++) {
        cin >> lose[i] >> win[i] >> use[i];
    }
//    cout << 5 * dfs(1, drugs);

    // dp
    for(int i = n; i >= 1; i--) {
        for(int j = 0; j <= drugs; j++) {
            if(j >= use[i]) {
                f[i][j] = max(f[i+1][j-use[i]] + win[i], f[i+1][j] + lose[i]);
            } else {
                f[i][j] = f[i+1][j] + lose[i];
            }
        }
    }
    cout << 5 * f[1][drugs];
    return 0;
}