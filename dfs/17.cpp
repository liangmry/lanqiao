// Forgery https://www.luogu.com.cn/problem/CF1059B
#include <iostream>

using namespace std;
// 暴力枚举，没用bfs
int n, m;
const int N = 1005;
const int dx[] = {1,1,1,0,0,-1,-1,-1},
        dy[] = {0,-1,1,1,-1,1,0,-1};
// res是目标  g是要做改变的 最后比对两数组
int res[N][N], g[N][N]; // 0->'.'  1->'#'

bool is_common() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(res[i][j] != g[i][j]) return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char ch;
            cin >> ch;
            if(ch == '.') res[i][j] = 0;
            else res[i][j] = 1;
        }
    }
    // 朴素枚举
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            bool f = false;
            for(int k = 0; k < 8; k++) {
                int a = i + dx[k], b = j + dy[k];
                if(a < 1 or a > n or b < 1 or b > m) { // 染色越界不行
                    f = true;
                    break;
                }
                if(res[a][b] == 0) { // 周围必须可以染色
                    f = true;
                    break;
                }
            }
            if(f) continue; // 该点不可操作
            else {
                for(int k = 0; k < 8; k++) {
                    int a = i + dx[k], b = j + dy[k];
                    g[a][b] = 1;
                }
            }
        }
    }
    // 最后比对
    if(is_common()) cout << "YES";
    else cout << "NO";
    return 0;
}