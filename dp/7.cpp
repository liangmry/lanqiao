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

// new 2024-3-16
/*
 * #include <iostream>
#define ll long long
using namespace std;

const int N = 22;
ll a, b, c;
ll mem[N][N][N];

ll w(ll x, ll y, ll z) {
    if(x <= 0 or y <= 0 or z <= 0) return 1;
    if(x > 20 or y > 20 or z > 20) return w(20, 20, 20);

    if(mem[x][y][z]) return mem[x][y][z]; // ******** 执行顺序要做修改，不然几个很大的x, y, z 传进来会造成数组越界 *********
    ll res;
    if(x < y and y < z) res = w(x, y, z-1) + w(x, y-1, z-1) - w(x, y-1, z);
    else res = w(x-1, y, z) + w(x-1, y-1, z) + w(x-1, y, z-1) - w(x-1, y-1, z-1);
    mem[x][y][z] = res;
    return res;
}

int main() {
    while(scanf("%lld %lld %lld", &a, &b, &c)) {
        if(a == -1 and b == -1 and c == -1) break;
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(a, b, c));
    }
    return 0;
}
 */