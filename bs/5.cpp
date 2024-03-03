#include <iostream>
#define ll long long
using namespace std;
// 二分答案--面向答案编程

int n, k; // n根原木 需要k小段
const int N = 1e5+5;
int arr[N];
int li; // 枚举结果,对结果做二分查找
ll res;

// 二分查找
int bSearch() {
    int l = 0, r = li+1;
    while(l + 1 < r) {
        int mid = (l + r) / 2;
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            sum += (arr[i] / mid);
            if(sum >= k) break; // 提前结束，防止数据溢出
        }
        if(sum >= k) { // 左边的要求越短，能切的条数越多
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        li = max(li, arr[i]);
    }

    cout << bSearch();

    /* 暴力
    for(int i = l; i >= 0; i--) {
        ll sum = 0;
        for(int j = 1; j <= n; j++) {
            sum += (arr[j] / i);
        }
        if(sum == k) {
            res = i;
            break;
        }
    }
    if(res < 1) {
        cout << 0;
    } else {
        cout << res;
    }
     */
    return 0;
}