// P1219 [USACO1.5] 八皇后 Checker Challenge
#include <iostream>
#include <vector>
using namespace std;

const int N = 15;
int n;
bool st[N];
int arr[N][N];
int res;

void dfs(int x, vector<pair<int, int>>& judge) {
    int len = judge.size();
    for (int i = 0; i < len - 1; i++) {
        int x1 = judge[i].first, y1 = judge[i].second;
        for (int j = i + 1; j < len; j++) {
            int x2 = judge[j].first, y2 = judge[j].second;
            if (x1 - y1 == x2 - y2 || x1 + y1 == x2 + y2) { // 判断对角线，利用斜率
                return ;
            }
        }
    }

    if(x > n) {
        if(res < 3) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    if(arr[i][j] == 1) {
                        printf("%d ", j);
                    }
                }
            }
            printf("\n");
        }
        res++;
        return ;
    }

    for(int i = 1; i <= n; i++) { // 按行列同时枚举
        if(!st[i]) {
            st[i] = true;
            arr[x][i] = 1;
            judge.push_back({x, i});
            dfs(x+1, judge);

            st[i] = false;
            arr[x][i] = 0;
            judge.pop_back();
        }
    }
}

int main() {
    scanf("%d", &n);
    vector<pair<int, int>> judge;
    dfs(1, judge);
    cout << res;
    return 0;
}