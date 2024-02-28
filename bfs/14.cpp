// P2658 汽车拉力比赛
#include<iostream>
#include<algorithm>
#include<cstring>

#define x first
#define y second

using namespace std;
typedef pair<int, int> PII;

const int N = 510;

int n, m;
int high[N][N];
int flag[N][N];
int cnt_flag = 0;  //统计路标总数
PII q[N * N];
int x1 = 0, y1 = 0;
bool st[N][N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool check(int mid) {
    q[0] = {x1, y1};
    st[x1][y1] = true;
    int cnt = 1;   //统计当前已到达的路标的个数
    int hh = 0, tt = 0;

    while(hh <= tt) {
        auto t = q[hh ++];

        for(int i = 0; i < 4; i ++) {
            int a = t.x + dx[i], b = t.y + dy[i];

            if(a < 1 || a > n || b < 1 || b > m) continue;
            if(st[a][b]) continue;
            if(abs(high[t.x][t.y] - high[a][b]) > mid) continue;

            q[++tt] = {a, b};
            st[a][b] = true;

            if(flag[a][b] == 1) {
                cnt ++;
                if(cnt == cnt_flag) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            scanf("%d", &high[i][j]);
        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            scanf("%d", &flag[i][j]);
        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            scanf("%d", &flag[i][j]);
            if(flag[i][j] == 1) {
                cnt_flag ++;
            }
        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(flag[i][j] == 1) {
                x1 = i, y1 = j;
                break;
            }
        }
    }

    int l = -1, r = 1e9 + 10;
    while(l + 1 < r) {
        int mid = (l + r) / 2;
        // printf("%d\n", mid);
        memset(q, 0, sizeof q);
        memset(st, false, sizeof st);
        if(check(mid)) {
            r = mid;
        }
        else l = mid;
    }

    printf("%d\n", r);
    return 0;
}