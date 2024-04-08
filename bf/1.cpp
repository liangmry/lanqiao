// P2241 统计方形（数据加强版）
#include <bits/stdc++.h>
#define ll long long
using namespace std;
// 枚举问题注意开 ll

int n, m;
ll cnt_square, rectangles; // 会很大

int main() {
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            rectangles += i * j; // 计算所有的矩形个数

            // *** 这个很难想到 ***
            cnt_square += min(i, j); // 任意给定一个坐标，此时可能的正方形个数

            /* 速度太慢了这样
             * // 正方形：向右下角扩展
            for(int k = 1; ; k++) {
                if(i + k > n || j + k > m) break;
                cnt_square ++;
            }

             out of for:
             cnt_square += n * m;
             */

        }
    }
    cout << cnt_square << ' ' << rectangles - cnt_square; // 矩阵里除了 正方形 就是 长方形
    return 0;
}