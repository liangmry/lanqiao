// P1135 奇怪的电梯
#include <iostream>
#include <queue>

using namespace std;
// bfs搜索  似乎也可以用dfs，当然就需要更多的剪枝了

const int N = 202;
const int px[] = {1, -1};

int n, sd, fd; // 起点 终点
int dist[N]; // 移动的步长
int cnt[N]; // 不能直接用一个cnt记录，因为有 回溯， cnt的值会比正确答案 大
bool vis[N];
queue<int> q;

int bfs() {
    q.push(sd);
    vis[sd] = true;
    cnt[sd] = 0;

    while(!q.empty()) {

        auto t = q.front(); // 当前楼层
        q.pop();

        for(int i = 0; i < 2; i++) {
            int a;
            if(px[i] == 1) a = t + dist[t]; // 向上走
            else a = t - dist[t]; // 向下走

            if(a < 1 or a > n) continue; // 超过范围
            if(vis[a]) continue; // 已经被访问过

            q.push(a);
            vis[a] = true;
            cnt[a] = cnt[t] + 1;
            if(a == fd) return cnt[fd]; // 到达终点，直接返回
        }
    }
    return -1; // 到达不了终点
}

int main() {
    cin >> n >> sd >> fd;
    if(sd == fd) { // 起点与终点一致， 直接输出并返回
        cout << 0;
        return 0;
    }
    for(int i = 1; i <= n; i++)
        cin >> dist[i];
    int ans = bfs();
    cout << ans;
    return 0;
}