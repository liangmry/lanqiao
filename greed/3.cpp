// P1223 排队接水
#include <bits/stdc++.h>
using namespace std;

int n;
double ans;

struct person {
    int id, time;
};

bool cmp(const person & a, const person & b) {
    return a.time < b.time;
}

int main() {
    vector<person> peo;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        peo.push_back({i, t});
    }
    sort(peo.begin(), peo.end(), cmp);
    for(int i = 0; i < n; i++) {
        if(i != n - 1) ans += 1.0 * (n - i - 1) * peo[i].time;
        cout << peo[i].id << ' ';
    }
    printf("\n%.2lf", ans / n);
    return 0;
}