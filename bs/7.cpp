// P1024 [NOIP2001 提高组] 一元三次方程求解
#include <iostream>
using namespace std;
// 二分每个区间
double a, b, c, d;
int cnt;

double res(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

double bs(int i, int j) {
    double l = i, r = j;
    while (r - l >= 0.001) { // 当区间 [l, r] 的长度大于等于 0.001 时，继续进行二分搜索。  0.01 就不行
        double mid = l + (r - l) / 2;
        if (res(mid) * res(r) <= 0) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if(res(r) == 0) return r;
    else return -1;
}

int main() {
    cin >> a >> b >> c >> d;

    double ans = 0;

    for (int i = -100; i < 100; i++) {
        double f1 = res(i);
        if (f1 == 0) {
            // 原本写的 printf("%.2lf ", i); 一直输出0，必须做类型转换
            // nnd我还以为是哪里错了
            printf("%.2lf ", (double)i);
            cnt++;
        }
        double f2 = res(i + 1);
        if (f1 * f2 < 0) {
            ans = bs(i, i + 1);

            printf("%.2lf ", ans);
            cnt++;
        }
        if (cnt == 3) break;
    }
    return 0;
}