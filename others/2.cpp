// P3912 素数个数
#include <bits/stdc++.h>
using namespace std;
// 欧拉筛算是练习了一次，大一就用过了，但是一直不能自己写出来，希望这次能学会

int n;
int cnt;

const int M = 1e8;
bool status[M+2];
int primes[M+2];

void sieve() {
    status[0] = status[1] = 1;
    int p = 0;
    for(int i = 2; i <= n; i++) {
        if(!status[i]) {
            primes[++p] = i;
        }
        for(int j = 1; i * primes[j] <= n && j <= p; j++) { // 这里第一个 小于的条件 必须写，不然会越界
            status[i * primes[j]] = 1;
            if(i % primes[j] == 0) break; // 避免重复筛
        }
    }
}

int main() {
    cin >> n;
    sieve();
    cout << cnt;
    return 0;
}