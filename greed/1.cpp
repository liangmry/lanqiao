// P1007 独木桥
#include <bits/stdc++.h>
using namespace std;
// 贪心
// 找的是时间，不是每个人所花费的时间

const int N = 5e3 + 5;
int length, n, soldiers[N];
int min_len = 0, max_len;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> length >> n;
    if(n == 0) { // 特判
        cout << "0 0";
        return 0;
    }
    for(int i = 1; i <= n; i++) {
        cin >> soldiers[i];
        if(soldiers[i] < length >> 1) {
            min_len = max(min_len, soldiers[i]);
        } else {
            min_len = max(min_len, length + 1 - soldiers[i]);
        }
    }
    sort(soldiers + 1, soldiers + 1 + n);
    max_len = max(length + 1 - soldiers[1], soldiers[n]);
    cout << min_len << ' ' << max_len;
    return 0;
}