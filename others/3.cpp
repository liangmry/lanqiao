// P1886 滑动窗口 /【模板】单调队列
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, k;
int arr[N];

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    deque<int> q;
    for(int i = 1; i <= n; i++) {
        if(q.empty()) q.push_back(i);
        else {
            while(!q.empty() && arr[i] <= arr[q.back()]) { // 没写等于号
                q.pop_back();
            }
            q.push_back(i);
        }
        if(q.front() <= i - k) q.pop_front();
        if(i >= k) {
            cout << arr[q.front()] << ' ';
        }
    }
    cout << '\n';
    q.clear();
    for(int i = 1; i <= n; i++) {
        if(q.empty()) q.push_back(i);
        else {
            while(!q.empty() && arr[i] >= arr[q.back()]) { // 没写等于号
                q.pop_back();
            }
            q.push_back(i);
        }
        if(q.front() <= i - k) q.pop_front();
        if(i >= k) {
            cout << arr[q.front()] << ' ';
        }
    }
    return 0;
}