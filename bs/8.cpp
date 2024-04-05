// P1678 烦恼的高考志愿
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;
int n, m;
int school[N], student[N];

int bs(int x) {
    int l = 0, r = n + 1;
    while(l + 1 < r) {
        int mid =  (l + r) / 2;
        if(school[mid] <= x) l = mid;
        else r = mid;
    }
    if(l == 0) return -1;
    else return l;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &school[i]);
    for(int i = 1; i <= m; i++) scanf("%d", &student[i]);
    sort(school + 1, school + 1 + n);

    unsigned long long res = 0; // 所有学生都是零分，相当于 m * 1e5 --> 1e11
    for(int i = 1; i <= m; i++) {
        int f = bs(student[i]);
        if(f == -1) res += abs(student[i] - school[1]);
        else res += min(abs(student[i] - school[f]), abs(student[i] - school[f+1]));
    }
    printf("%llu", res);
    return 0;
}