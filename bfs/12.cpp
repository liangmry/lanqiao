// P1379 八数码难题
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;
// bfs + 哈希表 + dfs的回溯

const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
string start1;
string end1 = "123804765";
unordered_map<string, int> dist;
queue<string> q;

int bfs() {
    dist[start1] = 0;
    q.push(start1);

    while(!q.empty()) {
        auto t = q.front();
        q.pop();
        if(t == end1) {
            return dist[t];
        }

        int distance = dist[t];
        int a = t.find('0'); // 0 的位置可以与 任何数的位置交换
        int x1 = a / 3, y1 = a % 3; // 一维数组下标 变二维 --> 字符串变为3*3的矩阵

        for(int i = 0; i < 4; i++) {
            int x2 = x1 + dx[i], y2 = y1 + dy[i];
            if(x2 < 0 or x2 > 2 or y2 < 0 or y2 > 2) continue;

            int tmp = x2 * 3 + y2; // 二维下标 变 一维
            swap(t[a], t[tmp]); // 在字符串中将两个数互换
            if(!dist.count(t)) { // 下一个位置尚未被访问
                dist[t] = distance + 1;
                q.push(t);
            }
            // 回溯 恢复现场,给下一个方向做准备
            swap(t[a], t[tmp]);
        }
    }
    return -1;
}

int main() {
    cin >> start1;
    int ans = bfs();
    cout << ans;
    return 0;
}