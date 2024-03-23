// 牛的学术圈 I https://www.acwing.com/problem/content/3748/
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;
int n, m;
int paper[N];

int bs() {
    int l = 0, r = n + 1;
    while(l + 1 < r) {
        int mid = (l + r) / 2;
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            if(paper[i] >= mid) {
                sum++;
                if(sum >= mid) break;
            }
        }

        if(sum >= mid) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &paper[i]);
    sort(paper + 1, paper + 1 + n);
    int tmp = bs();

    for(int i = n; i >= 1; i--) {
        if(m == 0) break;
        if(paper[i] <= tmp) {
            paper[i] ++;
            m --;
        }
    }
    // sort(paper + 1, paper + 1 + n); // 不加也能过
    cout << bs();
    return 0;
}