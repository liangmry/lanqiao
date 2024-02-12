// P1036 [NOIP2002 普及组] 选数
#include <iostream>

using namespace std;

int n, k;
const int N = 25;
int num[N];
int res;

bool is_prime(int x) {
    if(x <= 1) return false;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

void dfs(int x, int sum, int start) { // 选到第x个数  当前总和  从第几个数开始选
    if(x > k) {
        if(is_prime(sum)) res++;
        return ;
    }
    for(int i = start; i <= n; i++) {
        dfs(x+1, sum+num[i], i+1); // num[i],不是[x]
        }
}

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> num[i];
    dfs(1, 0, 1);
    cout << res;
    return 0;
}