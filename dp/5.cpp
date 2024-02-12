#include <iostream>

using namespace std;

int n;
// 关键在于对边界量，做好正确的抽象
int dfs(int x, int surplus) {    // x剩余待排的数 ， surplus栈中的数目
    if(x <= 0)  return 1;
    else if(surplus == 0) return dfs(x-1, surplus+1); // 只能入栈 ，待排的数目-1
    else return dfs(x, surplus-1) + dfs(x-1, surplus+1); // 出栈待排的剩余的数目不变
}

int main() {
    cin >> n;
    int ans = dfs(n, 0);
    cout << ans;
    return 0;
}