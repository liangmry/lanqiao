// P2240 【深基12.例1】部分背包问题
#include <bits/stdc++.h>
using namespace std;
// 对浮点数做大小比较相当麻烦，尽量用整数

int n, T;
double ans;
struct object {
    int w, v;
};
struct cmp {
    bool operator()(const object & a, const object & b) {
        return a.v * b.w > b.v * a.w;
    }
};
vector<object> arr;

int main() {
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    cin >> n >> T;
    for(int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        arr.push_back({w, v});
    }
    sort(arr.begin(), arr.end(), cmp());
    for(int i = 0; i < n; i++) {
        if(T >= arr[i].w) {
            T -= arr[i].w;
            ans += arr[i].v * 1.0;
        } else {
            ans += arr[i].v * 1.0 * T / arr[i].w;
            break;
        }
    }
    printf("%.2lf", ans);
    return 0;
}