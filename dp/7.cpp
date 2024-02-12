// P1464 Function
#include <iostream>
#include <cstring>
#define ll long long

using namespace std;

const int N = 22;
ll mem[N][N][N];
// 整理好逻辑 mem.abc 等于return的值
ll dfs(ll a, ll b, ll c) {
    if(a <= 0 or b <= 0 or c <= 0) return 1;
    if(a > 20 or b > 20 or c > 20) {
        return dfs(20,20,20); // 范围太大不确定，会造成数组越界
    }
    else if(a < b and b < c) {
        if(mem[a][b][c-1] == 0) mem[a][b][c-1] = dfs(a,b,c-1);
        if(mem[a][b-1][c-1] == 0) mem[a][b-1][c-1] = dfs(a,b-1,c-1);
        if(mem[a][b-1][c] == 0) mem[a][b-1][c] = dfs(a,b-1,c);
        mem[a][b][c] = mem[a][b][c-1] + mem[a][b-1][c-1] - mem[a][b-1][c];
    }

    else {
        if(mem[a-1][b][c] == 0) mem[a-1][b][c] = dfs(a-1,b,c);
        if(mem[a-1][b-1][c] == 0) mem[a-1][b-1][c] = dfs(a-1,b-1,c);
        if(mem[a-1][b][c-1] == 0) mem[a-1][b][c-1] = dfs(a-1,b,c-1);
        if(mem[a-1][b-1][c-1] == 0) mem[a-1][b-1][c-1] = dfs(a-1,b-1,c-1);
        mem[a][b][c] = mem[a-1][b][c] + mem[a-1][b-1][c] + mem[a-1][b][c-1] - mem[a-1][b-1][c-1];
    }
    return mem[a][b][c];
}

int main() {
    ll a, b, c;
    while(1)//无限输入，直到“-1 -1 -1”
    {
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1) return 0;//-1 -1 -1就直接结束，不运算了。

        printf("w(%lld, %lld, %lld) = ", a, b, c);
        printf("%lld\n", dfs(a, b, c));
    }
    return 0;
}