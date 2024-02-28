// P1149 [NOIP2008 提高组] 火柴棒等式
#include <iostream>

using namespace std;
// 排列型枚举 + 预处理

int n; // 可用火柴总数，固定使用 4根。 火柴必须全部用完
const int match[] = {
        6, 2,5,5,4,5,6,3,7,6
}; // 粗略估计 711 是可以拼接出的 合法的 最大的数
int res;
int arr[4];

int convert_num(int x) {
    if(x >= 0 and x <= 9) return match[x]; // 返回代表的火柴数 ！！！千万要注意 分清楚
    else {
        int sum = 0;
        while(x) {
            sum += match[x%10];
            x /= 10;
        }
        return sum;
    }
}

void dfs(int x, int cnt) {
    if(cnt > n) return ;
    if(x > 3) {
        if(cnt == n and arr[1] + arr[2] == arr[3]) res++;
        return ;
    }

    for(int i = 0; i <= 750; i++) {
        arr[x] = i; // 实际数字
        dfs(x+1, cnt + convert_num(i)); // cnt + 该数字代表的火柴数
    }
}

int main() {
    cin >> n;
    n -= 4;
    dfs(1, 0);
    cout << res;
    return 0;
}