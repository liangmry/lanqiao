// P1102 A-B 数对
#include <iostream>
#include <algorithm>

using namespace std;
// 转换为二分问题，减法转成加法，再查找相应的数

const int N = 2e5+5;
int n, c;
int arr[N];
long long cnt; // 两层循环，可能会有 1e10 这么大

int bs1(int x) {
    int l = 0, r = n+1;
    while(l + 1 < r) {
        int mid = (l + r) / 2;
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

int bs2(int x) {
    int l = 0, r = n+1;
    while(l + 1 < r) {
        int mid = (l + r) / 2;
        if(arr[mid] <= x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if(arr[l] == x) {
        return l;
    } else {
        return -1;
    }
}

int main() {
    cin >> n >> c;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    sort(arr+1, arr+1+n); // 下标从1开始的
    for(int i = 1; i <= n; i++) {
        int a = arr[i] + c;
        int ai = bs1(a);
        if(ai != -1) {
            int bi = bs2(a);
            cnt += (bi-ai+1);
        }
    }
    cout << cnt;
    return 0;
}