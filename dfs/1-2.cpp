// P9242 [蓝桥杯 2023 省 B] 接龙数列
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5+5;
int n; // 数列的长度
string s[N];

int mem[N][12];

int get_end(string s) {
    return *(s.end()-1) - '0';
}

int get_first(string s) {
    return *(s.begin()) - '0';
}

// 记忆化
// 别忘记 memset
// 另外 需要多个else if

int dfs(int x, int end) {
    if(mem[x][end] != -1) return mem[x][end];
    int num = 0;
    if(x > n) {
        num =  0;
    }
    else if(end == 10 or get_first(s[x]) == end) {
        num =  max(dfs(x+1, get_end(s[x]))+1, dfs(x+1, end));
    }
    else if(get_first(s[x]) != end)
        num =  dfs(x+1, end);
    mem[x][end] = num;
    return mem[x][end];
}


int main() {
    memset(mem, -1, sizeof mem);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> s[i];
    int cnt = dfs(1, 10);
    cout << n - cnt;
    return 0;
}