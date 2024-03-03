// P1873 [COCI 2011/2012 #5] EKO / 砍树
#include <iostream>
#define ll long long
using namespace std;
// 想办法分成两段，且递增

const int N = 1e6+5;
int n, m;
int arr[N];
int highest; // 二分的最右边

int bSearch() {
    int l = 0, r = highest+1;
    while(l + 1 < r) {
        int mid = (l + r) / 2;
        // 计算能砍到的树长之和
        ll sum = 0; // 数据范围不够，要ll
        // 如果要使用max(),两边数据类型都要定义为ll
        for(int i = 1; i <= n; i++) {
            if(arr[i] > mid) {
                sum += (arr[i] - mid);
            }
        }
        // 移动指针
        if(sum >= m) { // 要找满足要求的，左边的规定为满足要求
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

// 或者sum不定义为ll，在sum加和的过程中，一旦大于等于m，就结束相加，约束sum的大小
int bSearch2() {
    int l = 0, r = highest+1;
    while(l + 1 < r) {
        int mid = (l + r) / 2;
        // 计算能砍到的树长之和
        ll sum = 0; // 数据范围不够，要ll
        // 如果要使用max(),两边数据类型都要定义为ll
        for(int i = 1; i <= n; i++) {
            if(arr[i] > mid) {
                sum += (arr[i] - mid);
                // 增加了这句
                if(sum >= m) {
                    break;
                }
            }
        }
        // 移动指针
        if(sum >= m) { // 要找满足要求的，左边的规定为满足要求
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        highest = max(highest, arr[i]);
    }

    // 朴素法--时间肯定超
    /*
    int res = 0;
    for(int i = highest; i >= 0; i--) {
        int sum = 0;
        for(int j = 1; j <= n; j++) {
            if(arr[j] > i) {
                sum += (arr[j] - i);
            }
        }
        if(sum >= m) {
            res = i;
            break;
        }
    }
    cout << res;
    */

    int res = bSearch2();
    cout << res;
    return 0;
}