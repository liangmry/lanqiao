// 跳台阶 https://www.acwing.com/problem/content/823/
#include <iostream>

using namespace std;
// 斐波那契数列
// 1. 递归
int dfs(int x) {
    if(x == 0) return 1;
    else if(x == 1) return 1;
    else return dfs(x-1) + dfs(x-2);
}

// 2. 递推
const int N = 17;
int f[N];

int main() {
    int n;
    cin >> n;
    f[0] = f[1] = 1;
    for(int i = 2; i <= n; i++) {
        f[i] = f[i-1] + f[i-2];
    }
    cout << f[n];

    /* 2-2. 递推的内存优化
    int a = 1, b = 1, c = 0;
    for(int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    cout << c;
    */
    return 0;
}