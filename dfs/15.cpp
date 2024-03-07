// P1019 [NOIP2000 提高组] 单词接龙
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
const int N = 22;
string words[N];
int g[N][N]; // 第i个串 和 第j个串 能接龙多长
char start;
int used[N]; // 记录每个单词的使用次数
int res;

void dfs(string dragon, int x) { // 当前龙串  选到第x个串
    res = max(res, (int)dragon.size());
    used[x] ++;
    for(int i = 0; i < n; i++) {
        if(g[x][i] and used[i] < 2) { // 第x串 能接 第i串 且 使用次数小于2
            dfs(dragon + words[i].substr(g[x][i]), i);
        }
    }
    used[x] --; // 回溯
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }
    cin >> start;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // if(i == j) continue; // 对于相同的串不能接龙 --->更正：没关系
            /*
         in:    1
                envelope
                e
         out:   15
             */

            // k=1必须要有一个重叠的部分   k < 不能<= 因为不能是包含关系
            for(int k = 1; k < min(words[i].size(), words[j].size()); k++) {
                if(words[i].substr(words[i].size()-k, k) == words[j].substr(0, k)) {
                    g[i][j] = k;
                    break; // 重叠越少 接龙长度越长
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(start == words[i][0]) {
            dfs(words[i], i);
        }
    }
    cout << res;
    return 0;
}