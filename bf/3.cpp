// P1618 三连击（升级版）
#include <bits/stdc++.h>
using namespace std;

int a, b, c;
bool flag;
vector<int> arr = {1,2,3,4,5,6,7,8,9};

int main() {
    scanf("%d %d %d", &a, &b, &c);
    do {
        int x = arr[0] * 100 + arr[1] * 10 + arr[2];
        int y = arr[3] * 100 + arr[4] * 10 + arr[5];
        int z = arr[6] * 100 + arr[7] * 10 + arr[8];
        if(x * b == y * a && y * c == z * b) {
            flag = 1;
            printf("%d %d %d\n", x, y, z);
        }
    } while(next_permutation(arr.begin(), arr.end()));
    if(!flag) printf("No!!!");
    return 0;
}