// 附近最小 https://www.lanqiao.cn/problems/2415/learning/?page=1&first_category_id=1&second_category_id=3&tags=2023
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
// 滑动窗口 + 单调队列
const int N = 2e6+5;
int n, k;
int arr[N];
deque<int> q;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &k);
    for(int i = n+1; i <= n+k; i++)
        arr[i] = 1e9;

    for(int i = 1; i <= n+k; i++) {
        if(q.empty()) {
            q.push_back(i);
        } else {
            // 注意 判空语句 必须 在前
            while(!q.empty() and arr[q.back()] > arr[i]) { // 后面的元素比i大 弹出
                q.pop_back();
            }
            q.push_back(i); // 插入到后面 维护队列单调递增（从头至尾）
        }
        // 这个滑动的条件 手动模拟 即可得到
        if(q.front() < i - 2 * k) q.pop_front(); // 窗口开始向右滑动
        if(i > k) printf("%d ", arr[q.front()]);
    }
    return 0;
}