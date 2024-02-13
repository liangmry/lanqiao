// P1157 组合的输出
#include <iostream>
#include <iomanip>

using namespace std;
// 组合型枚举
// 不要求位置顺序
// 重点要与 排列型枚举 区分
int n, r;
const int N = 22;
int arr[N]; // 保存枚举结果
// bool st[N]; // 可以不需要 st数组，因为每次都是枚举当前数的下一个数

void dfs(int x, int start) { // start当前位置从几开始枚举
    if(x > r) {
        for(int i = 1; i <= r; i++) {
            cout << setw(3) << arr[i]; // setw()函数 控制 输出的 场宽
        }
        cout << endl;
        return ; // 别忘记 return
    }
    for(int i = start; i <= n; i++) {
        arr[x] = i;
        dfs(x+1, i+1);
    }
}

int main() {
    cin >> n >> r;
    dfs(1, 1);
    return 0;
}