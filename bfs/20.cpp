// P1767 家族
#include <iostream>
#include <queue>
#include <string>
#define PII pair<int, int>

using namespace std;
// 连通问题 + 预处理字符串 主要是对 空格 和 回车
const int N = 202;
const int dx[] = {0,0,1,-1},
        dy[] = {1,-1,0,0};
int n;
int g[N][N];
int lens[N];

queue<PII> q;
bool vis[N][N];

void bfs(int x, int y) {
    while(!q.empty()) q.pop();
    vis[x][y] = true;
    q.push({x, y});

    while(!q.empty()) {
        auto t = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a < 0 or a >= n or b < 0 or b >= lens[a]) continue;
            if(g[a][b] == 0) continue;
            if(vis[a][b]) continue;

            vis[a][b] = true;
            q.push({a, b});
        }
    }
}

int main() {
    cin >> n;
    int cnt = 0;
//    getchar();
    string s;
    getline(cin,s); // getchar不行，不知道为什么
    for(int i = 0; i < n; i++) {
        getline(cin, s); // 前面可能输入空格，不能用cin
        lens[i] = s.size();
        for(int j = 0; j < lens[i]; j++) {
            if(isalpha(s[j])) g[i][j] = 1;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < lens[i]; j++) {
            if(g[i][j] == 1 and !vis[i][j]) {
                bfs(i, j);
                cnt ++;
            }
        }
    }
    cout << cnt;
    return 0;
}