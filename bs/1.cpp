#include <iostream>

using namespace std;
// 二分查找模板代码，抽象为“分蓝红区域”。b站视频“BV1d54y1q7k7”，题目是acwing里的付费题目，在此只给出样例
/* 样例
6 3
1 2 2 3 3 4
3
3 4 结果
4
5 5 结果
5
-1 -1 结果
 */

int n, q; // n个数  q次查询
const int N = 1e5+5;
int arr[N];

int func1(int num) {
    int l = -1, r = n;
    while(l + 1 != r) {
        int mid = (l + r) / 2;
        if(arr[mid] < num) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if(arr[r] == num) return r;
    else return -1;
}

int func2(int num) {
    int l = -1, r = n;
    while(l + 1 != r) {
        int mid = (l + r) / 2;
        if(arr[mid] <= num) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if(arr[l] == num) return l;
    else return -1;
}

int main() {
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while(q--) {
        int x;
        cin >> x;
        cout << func1(x) << " " << func2(x) << endl;
    }
    return 0;
}