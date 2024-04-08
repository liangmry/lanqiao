// P1126 机器人搬重物
#include <bits/stdc++.h>

using namespace std;

enum DIR {
    east = 0,
    south,
    western,
    north
};

// 根据四个方向而来
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

struct POS {
    int x, y;
    int dis;
    int dir;
};

const int MAXN = 55;
int n, m;
int sx, sy, fx, fy, direction;
int g[MAXN][MAXN];
bool vis[MAXN][MAXN][4];

bool judge(int x, int y) {
    return x >= 1 and x <= n-1 and y >= 1 and y <= m-1;
}

int bfs() {
    if(g[fx][fy] == 1 or !judge(fx, fy)) return -1;
    queue<POS> q;
    q.push({sx, sy, 0, direction});
    vis[sx][sy][direction] = true;

    while(!q.empty()) {
        auto t = q.front();
        q.pop();
        int x = t.x, y = t.y, d_dis = t.dis, d_dir = t.dir;
        if(x == fx and y == fy) return d_dis;

        for(int i = 1; i <= 3; i++) {
            int a = x + i * dx[d_dir], b = y + i * dy[d_dir];
            if(!judge(a, b)) continue;
            if(g[a][b] == 1) break; // ***不明白为什么这里必须 break ****
            if(vis[a][b][d_dir]) {// 如果已经访问过，则继续下一个位置
                continue;
            }

            vis[a][b][d_dir] = true;
            POS next = {a, b, d_dis + 1, d_dir};
            q.push(next);
        }

        POS next;
        // 左转
        int next_dir = d_dir - 1;
        if(next_dir == -1) next_dir = north;
        if(!vis[x][y][next_dir]) {
            vis[x][y][next_dir] = true;
            next = {x, y, d_dis + 1, next_dir};
            q.push(next);
        }

        // 右转
        next_dir = d_dir + 1;
        if(next_dir == 4) next_dir = east;
        if(!vis[x][y][next_dir]) {
            vis[x][y][next_dir] = true;
            next = {x, y, d_dis + 1, next_dir};
            q.push(next);
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> g[i][j];
            // 机器人的体积占 4个格子
            if(g[i][j] == 1) g[i-1][j] = g[i][j-1] = g[i-1][j-1] = 1;
        }
    }
    char ch;
    cin >> sx >> sy >> fx >> fy >> ch;
    if(ch == 'E') direction = 0;
    else if(ch == 'S') direction = 1;
    else if(ch == 'W') direction = 2;
    else direction = 3;
    cout << bfs();
    return 0;
}

// 答案
/*
 * #include <cstdio>
#include <queue>

enum DIR {
    //方向定义
    EAST = 0,
    SOUTH,
    WEST,
    NORTH
};

struct POS {
    int x, y;//坐标
    int dir;//方向
    int dis;//距离

};

const int MAXN = 54;
struct MAZE {
    int row, col;//长宽
    int x1, y1;//起点
    int x2, y2;//终点
    int map[MAXN][MAXN];//迷宫数据
    bool visit[MAXN][MAXN][4];//访问性
    int dir;
};

int bfs(MAZE &maze);

int main() {
    MAZE maze={};
    scanf("%d %d", &maze.row, &maze.col);

    int i, j;
    for (i=1; i<=maze.row; i++) {
        for (j=1; j<=maze.col; j++) {
            scanf("%d", &maze.map[i][j]);
            //注意机器人体积
            if (maze.map[i][j]==1) {
                maze.map[i-1][j]=1;
                maze.map[i][j-1]=1;
                maze.map[i-1][j-1]=1;
            }
        }
    }

    char dir;
    scanf("%d %d %d %d %c", &maze.x1, &maze.y1, &maze.x2, &maze.y2, &dir);
    if (dir=='S') {
        maze.dir = SOUTH;
    } else if (dir=='W') {
        maze.dir = WEST;
    } else if (dir == 'N') {
        maze.dir = NORTH;
    } else {
        maze.dir = EAST;
    }

    //特别处理
    if (maze.x2<1||maze.x2>=maze.row||maze.y2<1||maze.y2>=maze.col||maze.map[maze.x2][maze.y2]==1) {
        printf("-1\n");
        return 0;
    }

    printf("%d\n", bfs(maze));

    return 0;
}

int bfs(MAZE &maze) {
    std::queue<POS> q;

    //起点
    POS cur;
    cur.x   = maze.x1;
    cur.y   = maze.y1;
    cur.dir = maze.dir;
    cur.dis = 0;
    q.push(cur);
    maze.visit[maze.x1][maze.y1][maze.dir] = true;

    //开始遍历
    POS next;
    const int dx[4] = {0,1,0,-1};
    const int dy[4] = {1,0,-1,0};
    //const int dx[4] = {1,0,-1,0};
    //const int dy[4] = {0,1,0,-1};

    int i;
    while (q.empty()!=true) {
        cur = q.front();
        q.pop();

        //判断是否终点
        if (cur.x==maze.x2&&cur.y==maze.y2) {
            return cur.dis;
        }

        //开始走路
        for (i=1; i<=3; i++) {
            next.x = cur.x + dx[cur.dir]*i;
            next.y = cur.y + dy[cur.dir]*i;

            //判断是否在迷宫内
            if (next.x<1||next.x>=maze.row||next.y<1||next.y>=maze.col||maze.map[next.x][next.y]==1)  {
                break;
            } else if (maze.visit[next.x][next.y][cur.dir]==false) {
                maze.visit[next.x][next.y][cur.dir] = true;
                next.dis = cur.dis + 1;
                next.dir = cur.dir;
                q.push(next);
            }
        }

        //左转
        next.x = cur.x;
        next.y = cur.y;
        next.dir = cur.dir - 1;
        if (next.dir==-1) {
            next.dir = NORTH;
        }
        if (maze.visit[next.x][next.y][next.dir]==false) {
            maze.visit[next.x][next.y][next.dir] = true;
            next.dis = cur.dis + 1;
            q.push(next);
        }

        //右转
        next.dir = cur.dir + 1;
        if (next.dir==4) {
            next.dir = EAST;
        }
        if (maze.visit[next.x][next.y][next.dir]==false) {
            maze.visit[next.x][next.y][next.dir] = true;
            next.dis = cur.dis + 1;
            q.push(next);
        }
    }

    return -1;
}
 */