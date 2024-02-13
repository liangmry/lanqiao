// P1088 [NOIP2004 普及组] 火星人
#include <iostream>

using namespace std;
// 全排列问题，但是 首次枚举 的一组数字需要 指定
int n, m; // n 火星人的手指数， m 另外要加上的一个数字
const int N = 10005;
int mars[N]; // 火星人给定的第一组数字
bool st[N];
int arr[N]; // 保存输出
int cnt;
bool ff;

void dfs(int x) {
    if(ff) return ; // 已经找到了，不要再向后枚举，因此时间复杂度得以降低

    if(x > n)
    {
        cnt++;
        if(cnt == m+1) // m+1 的原因：火星人给定的第一组数列 cnt为 1
        {
            ff=true; // 找到了那组数列
            for(int i=1; i<=n; i++)
            {
                cout << arr[i] << " ";
            }
        }
        return ;
    }

    for(int i = 1; i <= n; i++) {
        if(cnt == 0) {
            i = mars[x]; // 很重要！！好好体会
        }
        if(!st[i]) {
            st[i] = true;
            arr[x] = i; // 很重要！！好好体会
            dfs(x+1);

            // 恢复状态
            st[i] = false;
            arr[x] = 0; // 可以省略
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> mars[i];
    dfs(1);
    return 0;
}