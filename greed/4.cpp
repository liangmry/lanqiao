// P1803 凌乱的yyy / 线段覆盖
#include <bits/stdc++.h>
using namespace std;
// 贪心 往往伴随着 排序

int n;
struct cpe {
    int st, fin;
};
// *** 正确的 排序规则 是重点 ***
bool cmp(const cpe & a, const cpe & b) { // 只看右端点，右端点越靠左越好
    return a.fin < b.fin;
}

int main() {
    cin >> n;
    vector<cpe> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i].st >> arr[i].fin;
    }
    sort(arr.begin(), arr.end(), cmp);

    int ans = 0, flag = 0;
    for(int i = 0; i < n; i++) {
        if(flag <= arr[i].st) {
            ans++;
            flag = arr[i].fin;
        }
    }
    cout << ans;
    return 0;
}