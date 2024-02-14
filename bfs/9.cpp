// P1596 [USACO10OCT] Lake Counting S
#include <iostream>
#include <queue>
#define PII pair<int, int>
// 洪水灌溉型问题 bfs 或 dfs都可

using namespace std;

const int N = 105;
const int dx[] = {1,1,1,0,0,-1,-1,-1},
        dy[] = {1,-1,0,1,-1,1,0,-1};
int n, m;
char g[N][N];
queue<PII> q; // 在定义了namespace之后写
bool vis[N][N];
int cnt;

void bfs(int x,int y) {
    q.push({x, y});
    vis[x][y] = true;

    while(!q.empty()) {
        auto t = q.front();
        q.pop();

        for(int i = 0; i < 8; i++) {
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a < 1 or a > n or b < 1 or b > m) continue;
            if(g[a][b] != 'W') continue;
            if(vis[a][b]) continue;

            q.push({a, b});
            vis[a][b] = true;
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(g[i][j] == 'W' and !vis[i][j]) { //该点是水 并且 没有访问标记过
                bfs(i, j);
                cnt ++;
            }
        }
    }
    cout << cnt;
    return 0;
}


/*dfs解法
 *
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
const int N = 102;
char field[N][N];
bool st[N][N]; // 0未淹没 1淹没
int ans;
const int px[] = {1,1,1,0,0,-1,-1,-1},
        py[] = {1,-1,0,1,-1,1,0,-1}; // 未包括自身的点

void dfs(int x, int y)
{
    for(int i=0; i<=7; i++)
    {
        // 不能是x += px[i]，y += py[i];
        // 因为会改变原来的x，y。而我是for循环，关键在此
        int a = x+px[i], b = y+py[i];
        if(!st[a][b])
        {
            if(field[a][b]=='W' && a>=0 && a<n && b>=0 && b<m)
            {
                st[a][b] = true;
                dfs(a, b);
                // 不能回溯
                // 也许不是不用回溯，而是本质上就不需要使用 st数组
            }
        }

    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
        scanf("%s", field[i]);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(!st[i][j] && field[i][j]=='W')
            {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
 */