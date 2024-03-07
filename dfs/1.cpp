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

// 暴力思路
/*
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int N = 1e5+5;
int n; // 数列的长度
string s[N];
int cnt = -1;

int get_end(string s) {
    return *(s.end()-1) - '0';
}

int get_first(string s) {
    return *(s.begin()) - '0';
}

 1.
char end_ch 我想用char来判断选不选，但是 == '' 不能用，改用int来判断
void dfs(int x, char end_ch, int plus_cnt) { // 对第x个字符串做选择  当前数列的最后一个字符
    if(x > n) {
        cnt = max(cnt, plus_cnt);
        return ;
    }
    if(end_ch == *(s[x].begin()) or plus_cnt == 0) { // 第x个字符串可以接龙
        dfs(x+1, *(s[x].end()-1), plus_cnt+1);
    }
    else {
        dfs(x+1, end_ch, plus_cnt);
    }
}



2.
void dfs(int x, int end, int plus_cnt) {
    if(plus_cnt + (n-x+1) <= cnt) return ; // 剩下的就算全选，也不必cnt大
    if(x > n) {
        cnt = max(cnt, plus_cnt);
        return ;
    }
    if(end == -1 or get_first(s[x]) == end) { // 当前没选任何一个数 or 可以接龙
        dfs(x+1, get_end(s[x]), plus_cnt+1); // 选择s[x]
    }
    dfs(x+1, end, plus_cnt); // 不选s[x]
}



 3. 为了做记忆化，对 2 的 void 改成返回值类型为 int
int dfs(int x, int end) {
    if(x > n) {
        return 0;
    }
    if(end == -1 or get_first(s[x]) == end) {
        return max(dfs(x+1, get_end(s[x]))+1, dfs(x+1, end));
    }
    return dfs(x+1, end);
}


4. 记忆化
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

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> s[i];
//    dfs(1, -1, 0);
    cout << n - cnt;
    return 0;
}
 */