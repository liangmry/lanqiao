// P1008 [NOIP1998 普及组] 三连击
#include <bits/stdc++.h>
using namespace std;
// 和 P1618 类似

int a, b, c;
vector<int> arr = {1,2,3,4,5,6,7,8,9};

int main() {
    a = 1, b = 2, c = 3;
    do {
        int x = arr[0] * 100 + arr[1] * 10 + arr[2];
        int y = arr[3] * 100 + arr[4] * 10 + arr[5];
        int z = arr[6] * 100 + arr[7] * 10 + arr[8];
        if(x * b == y * a && y * c == z * b) {
            printf("%d %d %d\n", x, y, z);
        }
    } while(next_permutation(arr.begin(), arr.end()));
    return 0;
}