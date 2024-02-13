// 递归实现指数型枚举 https://www.acwing.com/problem/content/94/
#include <iostream>

using namespace std;

int n;
const int N = 17;
bool st[N];

void dfs(int x) { // 第x个数要不要选
    if(x > n) { // 选择完毕
        for(int i = 1; i <= n; i++) {
            if(st[i]) cout << i << " ";
        }
        cout << endl;
        return ;
    }
    // 不选, 有些步骤其实不用写
    st[x] = false;
    dfs(x+1);
    st[x] = false; // 恢复状态

    // 选
    st[x] = true;
    dfs(x+1);
    st[x] = false;
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}