// P2249 【深基13.例1】查找
#include <iostream>

using namespace std;
// 二分查找
const int N = 1e6+5;
int n, m;
int arr[N];

int bs(int x) {
    int l = 0, r = n+1;
    while(l+1 < r) {
        int mid = (l+r) / 2;
        if(arr[mid] < x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if(arr[r] == x) {
        return r;
    } else {
        return -1;
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int x; // 表示的是数字
    while(m--) {
        cin >> x;
        int num = bs(x);
        cout << num << " ";
    }
    return 0;
}